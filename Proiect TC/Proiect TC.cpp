// Ivan Andreea-Paula: Prajitura, Cofetarie, Angajat;
// clasa Prajitura va reprezenta un anumit sortiment de prajitura

#include <string>
#include <iostream>
#include <stdexcept>
#include <cstring>

using namespace std;

///////////////////////////////////////////////////////////
// 0. Zona globala - functii globale
string getAdmin(Cofetarie c) { return c.administrator; };

void printFullName(Angajat a) {
	string fullName = a.nume + " " + a.prenume;
	cout << fullName << endl;
};

///////////////////////////////////////////////////////////

class Cofetarie {
	//1. Atribute
private:
	static int nrCofetarii;
	static int codCaen;
	const int id;
	string nume;
	string adresa;
	string administrator;
	string* prajituri;
	int nrPrajituri;

public:

	//2. Destructor
	~Cofetarie() {
		if (this->prajituri != nullptr) {
			delete[] this->prajituri;
		};
	}

	//3. Constructori
	Cofetarie(
		string administrator = "Necunoscut",
		string nume = "Necunoscut",
		string adresa = "Necunoscuta",
		int nrPrajituri = 0,
		string* prajituri = nullptr)
		: id(++nrCofetarii) {
		this->administrator = administrator;
		this->nume = nume;
		this->adresa = adresa;
		this->nrPrajituri = nrPrajituri;
		this->prajituri = prajituri;
	}


	Cofetarie(
		string adresa,
		string* prajituri,
		int nrPrajituri)
		: id(++nrCofetarii) {
		this->nume = "Necunoscut";
		this->administrator = "Necunoscut";
		this->nrPrajituri = nrPrajituri;
		this->adresa = adresa;
		this->prajituri = new string[nrPrajituri];
		for (int i = 0; i < nrPrajituri; i++) {
			this->prajituri[i] = prajituri[i];
		};
		delete[] prajituri;
	}

	Cofetarie(
		string adresa,
		string* prajituri,
		int nrPrajituri,
		string administrator)
		: id(++nrCofetarii) {
		this->nume = "Necunoscut";
		this->administrator = administrator;
		this->nrPrajituri = nrPrajituri;
		this->adresa = adresa;
		this->prajituri = new string[nrPrajituri];
		for (int i = 0; i < nrPrajituri; i++) {
			this->prajituri[i] = prajituri[i];
		};
		delete[] prajituri;
	};

	
	/// 3*. Constructor de copiere
	Cofetarie(const Cofetarie& c) : id(c.id) {
		this->nrPrajituri = c.nrPrajituri;
		if (c.prajituri != nullptr) {
			this->prajituri = new string[c.nrPrajituri];
			for (int i = 0; i < c.nrPrajituri; i++) {
				this->prajituri[i] = c.prajituri[i];
			}
		else {
			this->prajituri = nullptr;
		}
		this->nume = c.nume;
		this->administrator = c.administrator;
		this->adresa = c.adresa;
	}

	static void afisareCodCaen() {
		cout << "Codul CAEN al cofetariei este: " <<
			Cofetarie::codCaen << endl;

	}

	void afisare() const {
		cout << "Cofetarie ID: " << id << "\nNume: " << nume << "\nAdministrator: "
			<< administrator << "\nAdresa: " << adresa << "\nNr Prajituri: " << nrPrajituri
			<< "\nPrajituri: ";
		for (int i = 0; i < nrPrajituri; i++) {
			cout << prajituri[i] << (i < nrPrajituri - 1 ? ", " : "");
		}
		cout << endl;
	}

	//4. Getteri
	const int getId() { return this->id; };
	string getNume() { return this->nume; };
	string getAdresa() { return this->adresa; };
	string getAdministrator() { return this->administrator; };
	string* getPrajituri() { return this->prajituri; };
	int getNrPrajituri() { return this->nrPrajituri; };

	//5. Setteri 

		
	//atributul id = de tip const => 
	// nu poate fi modificat dupa atribuire => 
	// nu putem declara setter pentru el;

	void setAdresa(string adr) {
		if (!adr.empty()) {
			this->adresa = adr;
		}
		else {
			this->adresa = "Necunoscuta";
		}
	};

	void setAdministrator(string admin) { 
		if (!admin.empty()) {
			this->administrator = admin;
		}
		else {
			this->administrator = "Necunoscuta";
		}
	};

	void setPrajituri(string* prajituriNoi, int nrPrahituriNoi) {
		if (this->prajituri != nullptr) {
			delete[] this->prajituri;
		}
		if (prajituriNoi != nullptr) {
			this->prajituri = new string[nrPrajituriNoi];
			for (int i = 0; i < nr PrajituriNoi; i++) {
				this->prajituri[i] = prajituriNoi[i];
			}
		}
		else {
			this->prajituri = nullptr;
		}
		this->nrPrajituri = nrPrajituriNoi;
	}


	//6. Functii statice - getteri si setteri
	static int getNrCofetarii() { return Cofetarie::nrCofetarii; }
	static int getCodCaen() { return Cofetarie::codCaen };

	void setNrCofetarii(int nr) {
		if (nr > 0) {
			Cofetarie::nrCofetarii = nr;
		}
		else {
			throw std::invalid_arugment("Numarul cofetariilor nu poate fi mai mic de 1");
		}
	};

	void setCodCaen(int cod) {
		if (cod >= 1000) {
			Cofetari::codCaen = cod;
		}
		else {
			throw std::invalid_argument("Codul CAEN nu poate avea mai putin de 4 cifre");
		}
	};

	//7. Alte functii
	void afisare() const {
		cout << "Cofetarie ID: " << id
			<< "\nNume: " << nume
			<< "\nAdministrator: " << administrator
			<< "\nAdresa: " << adresa
			<< "\nNr Prajituri: " << nrPrajituri
			<< "\nPrajituri: ";
		for (int i = 0; i < nrPrajituri; i++) {
			cout << prajituri[i] << (i < nrPrajituri - 1 ? ", " : "");
		}
		cout << endl;
	}

	/////8. Functii friend
	friend string getAdmin(Cofetarie c);
};

///////////////////////////////////////////////////////////


class Angajat {
	//1. Atribute

private:
	static int nrAngajati;
	const int id;
	const long long CNP;
	string nume;
	string prenume;
	char* functie;

public:
	//2. Destructor

	~Angajat() {
		if (this->functie != nullptr) {
			delete[] this->functie;
			this->functie = nullptr;
		}
	}
	//3. Constructori

	Angajat(
		string nume = "Necunoscut",
		string prenume = "Necunoscut")
		: id(++nrAngajati), CNP(0000000000000) {
		this->nume = nume;
		this->prenume = prenume;
		this->functie = new char[strlen("Necunoscut") + 1];
		strcpy_s(this->functie, strlen("Necunoscut") + 1, "Necunoscut");
	}

	Angajat(
		string nume,
		string prenume,
		long long cnp,
		char* functie)
		: id(++nrAngajati), CNP(cnp) {
		this->nume = nume;
		this->prenume = prenume;
		this->functie = new char[strlen(functie) + 1];
		strcpy_s(this->functie, strlen(functie) + 1, functie);
	};

	Angajat(
		string nume,
		string prenume,
		long long CNP)
		: id(++nrAngajati), CNP(CNP) {
		this->nume = nume;
		this->prenume = prenume;
		this->functie = nullptr;
	};

	/// 3*. Constructor de copiere
	Angajat(const Angajat& a) : id(a.id), CNP(a.CNP) {
		if (a.functie != nullptr) {
			this->functie = new char[strlen(a.functie) + 1];
			strcpy_s(this->functie, strlen(functie) + 1, functie);
		}
		else {
			this->functie = nullptr;
		}

		this->nume = a.nume;
		this->prenume = a.prenume;
	}

	//4. Getteri
	const int getId() { return this->id; };
	const long long getCNP() { return this->CNP; };
	string getNume() { return this->nume; };
	string getPrenume() { return this->prenume; };
	char* getFunctie() { return this->functie; };

	//5. Setteri 

	//atributulele id si CNP = de tip const => 
	// nu pot fi modificate dupa atribuire => 
	// nu putem declara setter pentru ele;


	void setNume(string newNume) { 
		if (newNume == "") {
			this->nume = "Necunoscut";
		} else {
			this->nume = newNume;
		};
	};

	void setPrenume(string newPrenume) {
		if (newPrenume == "") {
			this->prenume = "Necunoscut";
		}
		else {
			this->prenume = newPrenume;
		};
	};

	void setFunctie(char* newFunctie) {
		if (this->functie != nullptr) {
			delete[] functie;
		}
		if (newFunctie != nullptr) {
			this->functie = char[strlen(newFunctie) + 1];
			strcpy_s(this->functie, strlen(functie) + 1, functie);
		}
		else {
			this->functie = nullptr;
		}
	}

	//6. Functii statice - getteri si setteri
	static int getNrAngajati() { return Angajati::nrAngajati; };

	void setNrAngajati(int nr) {
		if (nr > 0) {
			Angajati::nrAngajati = nr;
		}
		else {
			throw std::invalid_argument(
				"numarul angajatilor trebuie sa fie de cel putin 1");
		}
	};



	// 7. Alte functii
	static void afisareNrAngajati() {
		cout << "Numarul angajatilor este: " <<
			Angajat::nrAngajati << endl;

	}

	void determinareSexAngajat(long long CNP) {
		int primaCifra = CNP / 1000000000000 % 10;

		if (primaCifra == 2 || primaCifra == 6) {
			cout << "Femeie" << endl;
		}
		else if (primaCifra == 1 || primaCifra == 5) {
			cout << "Barbat" << endl;
		}
		else {
			cout << "CNP invalid" << endl;
		}
	}

	void afisare() const {
		cout << "Angajat ID: " << id << "\nNume: " << nume << "\nPrenume: " << prenume
			<< "\nCNP: " << CNP << "\nFunctie: " << (functie ? functie : "Necunoscut") << endl;
	}

	/////8. Functii friend
	friend string printFullName(Angajat a);
};

///////////////////////////////////////////////////////////


class Prajitura {
	//1. Atribute

private:
	static int nrPrajituri;
	const int id;
	string nume;
	float pret;
	int nrIngrediente;
	string* ingrediente;
	int nrBucati;

public:
	//2. Destructor

	~Prajitura() {
		if (ingrediente != nullptr) {
			delete[] ingrediente;
		}
		nrPrajituri--;
	};
	//3. Constructori

	Prajitura()
		:id(++nrPrajituri),
		ingrediente(nullptr),
		nrIngrediente(0),
		nrBucati(0) {
		this->nume = "Necunoscut";
		this->pret = 0.0;

	};

	Prajitura(
		string nume,
		float pret,
		int nrIngrediente,
		string* ingrediente,
		int nrBucati)
		:id(++nrPrajituri) {
		this->nrIngrediente = nrIngrediente;
		this->nume = nume;
		this->pret = pret;
		this->nrBucati = nrBucati;
		this->ingrediente = new string[nrIngrediente];
		for (int i = 0; i < nrIngrediente; i++) {
			this->ingrediente[i] = ingrediente[i];
		}
		delete[] ingrediente;
	};

	Prajitura(
		string nume,
		float pret,
		int nrBucati)
		:id(++nrPrajituri) {
		this->nrIngrediente = 0;
		this->nume = nume;
		this->pret = pret;
		this->nrBucati = nrBucati;
		this->ingrediente = nullptr;
	};

	/// 3*. Constructor de copiere
	Prajitura(const Prajitura& p) : id(p.id) {
		this->nrIngrediente = p.nrIngrediente;
		if (p.nrIngrediente != nullptr) {
			this->ingrediente = new string[p.nrIngrediente];
			for (int i = 0; i < p.nrIngrediente; i++) {
				this->ingrediente[i] = p.ingrediente[i];
			}
		}
		else {
			this->ingrediente = nullptr;
		}

		this->nume = p.nume;
		this->pret = p.pret;
		this->nrBucati = p.nrBucati;
	}

	//4. Getteri
	const int getId() { return this->id; };
	string getNume() { return this->nume; };
	float getPret() { return this->pret; }
	int getNrIngrediente() { return this->nrIngrediente; };
	string* getIngrediente() { return this->ingrediente; };
	int getNrBucati() { return this->nrBucati; };

//5. Setteri 

	//atributul id = de tip const => 
	// nu poate fi modificat dupa atribuire => 
	// nu putem declara setter pentru el;

	void setNume(string newName) {
		if (newName == "") {
			this->nume = "Necunoscut";
		}
		else {
			this->nume = newName;
		}
	};

	void setPret(float newPrice) {
		if (newPrice <= 0) {
			std::invalid_argument("Pretul nu poate fi mai mic de 0");
		}
	}

	void setNrIngrediente(int nr) {
		if (nr < 1) {
			throw std::invalid_argument("Numarul ingredientelor nu poate fi mai mic de 1");
		}
		else {
			this->nrIngrediente = nrIngrediente;
		}
	};
	
	void setIngrediente(string* newIngredients, int nrNewIngredients) {
		if (this->ingrediente != nullptr) {
			delete[] this->ingrediente;

		} if (newIngredients != nullptr) {
			string* ingrediente = new string[nrNewIngredients];
			for (int i = 0; i < nrIngrediente; i++) {
				this->ingrediente[i] = ingrediente[i];
			}
		}
		else {
			this->ingrediente = nullptr;
		}
	}
	void setNrBucati(int newNr) { 
		if (newNr < 0) {
			throw std::invalid_argument("Numarul de bucati nu poate fi un numar negativ");
		}
		else {
			this->nrBucati = newNr;
		}
	};


	//6. Functii statice - getteri si setteri
	static int getNrPrajituri() { return Prahitura::nrPrajituri; };

	void setNrPrajituri(int nr) {
		if (nr < 1) {
			throw std::invalid_argument("Numarul sortimentelor nu poate fi mai mic de 1");
		}
		else {
			Prajitura::nrPrajituri = nr;
		}
	};


	//7. Alte functii 

	static void afisareNumarSortimente() {
		cout << "Numarul de sortimente al cofetariei este: " <<
			Prajitura::nrPrajituri << endl;

	}

	void afisare() const {
		cout << "Prajitura ID: " << id << "\nNume: " << nume << "\nPret: " << pret
			<< "\nNr Ingrediente: " << nrIngrediente << "\nIngrediente: ";
		for (int i = 0; i < nrIngrediente; i++) {
			cout << ingrediente[i] << (i < nrIngrediente - 1 ? ", " : "");
		}
		cout << "\nNr Bucati: " << nrBucati << endl;
	}

};
///////////////////////////////////////////////////////////

int Cofetarie::nrCofetarii = 0;
int Cofetarie::codCaen = 4724;
int Angajat::nrAngajati = 0;
int Prajitura::nrPrajituri = 0;

///////////////////////////////////////////////////////////


int main() {

	Cofetarie cofetarie1;
	Cofetarie cofetarie2("Adresa 1", new string[3]{ "Amandina", "Savarina", "Tort diplomat" }, 3);
	Cofetarie cofetarie3("Adresa 2", new string[2]{ "Tiramisu", "Dobos" }, 2, "Popescu Ion");

	Angajat angajat1;
	Angajat angajat2("Popescu", "Ion", 1234567890000, (char*)"Administrator");
	Angajat angajat3("Ionescu", "Maria", 2123456789000);

	Prajitura prajitura1;
	Prajitura prajitura2("Amandina", 15.5, 10);
	Prajitura prajitura3("Foret Noir", 18.2, 3, new string[3]{ "Visine", "Zahar", "Oua" }, 6);

	cout << "Hello world" << endl;
	cofetarie1.afisare();
	cofetarie2.afisare();
	cofetarie3.afisare();

	angajat1.afisare();
	angajat2.afisare();
	angajat3.afisare();

	prajitura1.afisare();
	prajitura2.afisare();
	prajitura3.afisare();

	prajitura1.setIngrediente("Frisca", "Biscuiti", 2);
	cout << prajitura1.getIngrediente() << endl;

	prajitura1.setNrBucati(10);
	cout << prajitura1.getNrBucati() << endl;

	prajitura1.setNrPrajituri(5);
	cout << prajitura1.getNrBucati() << endl;

	prajitura1.setNume("Cea mai buna prajitura");
	cout << prajitura1.getNume() << endl;

	prajitura1.setPret(23.5);
	cout << prajitura1.getPret() << endl;

	prajitura1.setNrIngrediente(2);
	cout << prajitura1.getNrIngrediente << endl;

	

		//TODO - test if program runs;
	
}


