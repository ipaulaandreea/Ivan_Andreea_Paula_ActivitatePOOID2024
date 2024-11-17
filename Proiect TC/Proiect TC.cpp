// Ivan Andreea-Paula: Prajitura, Cofetarie, Angajat;
// clasa Prajitura va reprezenta un anumit sortiment de prajitura

#include <string>
#include <iostream>
#include <stdexcept> 
#include <cstring>

using namespace std;


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
		}
		else {
			this->prajituri = nullptr;
		}
		this->nume = c.nume;
		this->administrator = c.administrator;
		this->adresa = c.adresa;
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

	void setPrajituri(string* prajituriNoi, int nrPrajituriNoi) {
		if (this->prajituri != nullptr) {
			delete[] this->prajituri;
		}
		if (prajituriNoi != nullptr) {
			this->prajituri = new string[nrPrajituriNoi];
			for (int i = 0; i < nrPrajituriNoi; i++) {
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
		static int getCodCaen() { return Cofetarie::codCaen; };

		static void setNrCofetarii(int nr) {
			if (nr > 0) {
				Cofetarie::nrCofetarii = nr;
			}
			else {
				cout<<"Numarul cofetariilor nu poate fi mai mic de 1"<<endl;
			}
		};

		static void setCodCaen(int cod) {
			if (cod >= 1000 && cod <= 9999) {
				Cofetarie::codCaen = cod;
			}
			else {
				cout<<"Codul CAEN trebuie sa fie format din 4 cifre."<<endl;
			}
		}

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

		static void afisareCodCaen() {
			cout << "Codul CAEN al cofetariei este: " <<
				Cofetarie::codCaen << endl;

		}

		/////8. Functii friend
		friend string getAdmin(Cofetarie c);
	};


///////////////////////////////////////////////////////////
	class Angajat {
	private:
		static int nrAngajati;
		const int id;
		const long long CNP;
		string nume;
		string prenume;
		char* functie;

	public:
		// 1. Destructor
		~Angajat() {
			if (this->functie != nullptr) {
				delete[] this->functie;
				this->functie = nullptr;
			}
		}

		// 2. Constructori
		Angajat(string nume = "Necunoscut", string prenume = "Necunoscut")
			: id(++nrAngajati), CNP(0000000000000) {
			this->nume = nume;
			this->prenume = prenume;
			this->functie = new char[strlen("Necunoscut") + 1];
			strcpy_s(this->functie, strlen("Necunoscut") + 1, "Necunoscut");
		}

		Angajat(string nume, string prenume, long long cnp, const char* functie)
			: id(++nrAngajati), CNP(cnp) {
			this->nume = nume;
			this->prenume = prenume;
			this->functie = new char[strlen(functie) + 1];
			strcpy_s(this->functie, strlen(functie) + 1, functie);
		}

		Angajat(string nume, string prenume, long long CNP)
			: id(++nrAngajati), CNP(CNP) {
			this->nume = nume;
			this->prenume = prenume;
			this->functie = nullptr;
		}

		//3. Constructor de copiere
		Angajat(const Angajat& a) : id(a.id), CNP(a.CNP) {
			if (a.functie != nullptr) {
				this->functie = new char[strlen(a.functie) + 1];
				strcpy_s(this->functie, strlen(a.functie) + 1, a.functie); 
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

	void setFunctie(const char* newFunctie) {
		if (this->functie != nullptr) {
			delete[] functie;
		}
		if (newFunctie != nullptr) {
			this->functie = new char[strlen(newFunctie) + 1];
			strcpy_s(this->functie, strlen(functie) + 1, functie);
		}
		else {
			this->functie = nullptr;
		}
	}

	//6. Functii statice - getteri si setteri
	static int getNrAngajati() { return Angajat::nrAngajati; };

	static void setNrAngajati(int nr) {
		if (nr > 0) {
			Angajat::nrAngajati = nr;
		}
		else {
			cout<<"Numarul angajatilor trebuie sa fie de cel putin 1"<<endl;
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
	friend void printFullName(Angajat a);
};

///////////////////////////////////////////////////////////


class Prajitura {
	// 1. Atribute
private:
	static int nrPrajituri;
	const int id;
	string nume;
	float pret;
	int nrIngrediente;
	string* ingrediente;
	int nrBucati;

public:
	// 2. Destructor
	~Prajitura() {
		if (ingrediente != nullptr) {
			delete[] ingrediente;
		}
		nrPrajituri--;
	};

	// 3. Constructori
	Prajitura()
		: id(++nrPrajituri), ingrediente(nullptr), nrIngrediente(0), nrBucati(0) {
		this->nume = "Necunoscut";
		this->pret = 0.0;
	};

	Prajitura(string nume, float pret, int nrIngrediente, 
		string* ingrediente, int nrBucati)
		: id(++nrPrajituri) {
		this->nrIngrediente = nrIngrediente;
		this->nume = nume;
		this->pret = pret;
		this->nrBucati = nrBucati;
		this->ingrediente = new string[nrIngrediente];
		for (int i = 0; i < nrIngrediente; i++) {
			this->ingrediente[i] = ingrediente[i];
		}
	};

	Prajitura(string nume, float pret, int nrBucati)
		: id(++nrPrajituri) {
		this->nrIngrediente = 0;
		this->nume = nume;
		this->pret = pret;
		this->nrBucati = nrBucati;
		this->ingrediente = nullptr;
	};

	// 3*. Constructor de copiere
	Prajitura(const Prajitura& p) : id(p.id) {
		this->nrIngrediente = p.nrIngrediente;
		if (p.nrIngrediente > 0) {
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

	// 4. Getteri
	const int getId() { return this->id; }
	string getNume() { return this->nume; }
	float getPret() { return this->pret; }
	int getNrIngrediente() { return this->nrIngrediente; }
	string* getIngrediente() { return this->ingrediente; }
	int getNrBucati() { return this->nrBucati; }

	// 5. Setteri
	void setNume(string newName) {
		if (newName.empty()) {
			this->nume = "Necunoscut";
		}
		else {
			this->nume = newName;
		}
	}

	void setPret(float newPrice) {
		if (newPrice <= 0) {
			cout<<"Pretul nu poate fi mai mic de 0"<<endl;
			return;
		}
		this->pret = newPrice;
	}

	void setIngrediente(string* newIngredients, int nrNewIngredients) {
		if (this->ingrediente != nullptr) {
			delete[] this->ingrediente;
		}
		if (newIngredients != nullptr) {
			this->ingrediente = new string[nrNewIngredients];
			for (int i = 0; i < nrNewIngredients; i++) {
				this->ingrediente[i] = newIngredients[i];
			}
		}
		else {
			this->ingrediente = nullptr;
		}
		this->nrIngrediente = nrNewIngredients;
	}

	void setNrIngrediente(int nrNewIngredients) {
		if (nrNewIngredients <= 0) {
			cout<<"Numarul ingredientelor trebuie sa fie mai mare de 0"<<endl;
		}
		this->nrIngrediente = nrNewIngredients;
	}

	void setNrBucati(int newNr) {
		if (newNr <= 0) {
			cout<<"Numarul de bucati trebuie sa fie un numar pozitiv."<<endl;
			return;
		}
		this->nrBucati = newNr;
	}

	// 6. Functii statice - getteri si setteri
	static int getNrPrajituri() { return Prajitura::nrPrajituri; }
	static void setNrPrajituri(int nr) {
		if (nr < 1) {
			cout<<"Numarul sortimentelor nu poate fi mai mic de 1"<<endl;
		}
		else {
			Prajitura::nrPrajituri = nr;
		}
	}

	// 7. Alte functii
	static void afisareNumarSortimente() {
		cout << "Numarul de sortimente al cofetariei este: " << Prajitura::nrPrajituri << endl;
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
// Functii globale
string getAdmin(Cofetarie c) { return c.administrator; };

void printFullName(Angajat a) {
	string fullName = a.nume + " " + a.prenume;
	cout << fullName << endl;
};
///////////////////////////////////////////////////////////
//Atribute statice

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
	Angajat angajat2("Popescu", "Ion", 1234567890000, "Administrator");
	Angajat angajat3("Ionescu", "Maria", 2123456789000);

	Prajitura prajitura1;
	Prajitura prajitura2("Amandina", 15.5, 10);
	Prajitura prajitura3("Foret Noir", 18.2, 3, new string[3]{ "Visine", "Zahar", "Oua" }, 6);

	cofetarie1.afisare();
	cofetarie2.afisare();
	cofetarie3.afisare();

	angajat1.afisare();
	angajat2.afisare();
	angajat3.afisare();

	prajitura1.afisare();
	prajitura2.afisare();
	prajitura3.afisare();

	 //Getters and Setters
	cofetarie1.setAdministrator("New Admin");
	cout << cofetarie1.getAdministrator() << endl;

	cofetarie1.setAdresa("New Address");
	cout << cofetarie1.getAdresa() << endl;

	cofetarie1.setPrajituri(new string[2]{ "Profiterol", "Amandina" }, 2);
	string* prajituri = cofetarie1.getPrajituri();
	for (int i = 0; i < cofetarie1.getNrPrajituri(); ++i) {
		cout << prajituri[i] << " ";
	}
	cout << endl;

	angajat1.setFunctie("Cofetar");
	cout << angajat1.getFunctie() << endl;

	angajat1.setNume("Matei");
	cout << angajat1.getNume() << endl;

	angajat1.setPrenume("Marius");
	cout << angajat1.getPrenume() << endl;

	prajitura1.setIngrediente(new string[2]{ "Frisca", "Biscuiti" }, 2);
	string* ingrediente = prajitura1.getIngrediente();
	for (int i = 0; i < prajitura1.getNrIngrediente(); ++i) {
		cout << ingrediente[i] << " ";
	}
	cout << endl;

	
	prajitura1.setNrBucati(10);
	cout << prajitura1.getNrBucati() << endl;
	
	prajitura1.setNume("Cea mai buna prajitura");
	cout << prajitura1.getNume() << endl;

	prajitura1.setPret(23.5);
	cout << prajitura1.getPret() << endl;

	prajitura1.setNrIngrediente(2);
	cout << prajitura1.getNrIngrediente() << endl;


	//// Static methods

	Cofetarie::setCodCaen(1234); 
	cout << "Cod CAEN: " << Cofetarie::getCodCaen() << endl;
	
	Cofetarie::setNrCofetarii(5);
	cout << Cofetarie::getNrCofetarii() << endl;

	Angajat::setNrAngajati(20);
	cout << Angajat::getNrAngajati() << endl;

	Prajitura::setNrPrajituri(10);
	cout << Prajitura::getNrPrajituri() << endl;


	//// Friend methods
	cout << getAdmin(cofetarie2) << endl;
	printFullName(angajat3);

	return 0;
}