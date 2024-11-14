// Ivan Andreea-Paula: Prajitura, Cofetarie, Angajat;
// clasa Prajitura va reprezenta un anumit sortiment de prajitura

#include <string>
#include <iostream>


using namespace std;

class Cofetarie {

private:
	string nume;
	const int id;
	static int nrCofetarii;
	static int codCaen;
	string adresa;
	string administrator;
	string* prajituri;
	int nrPrajituri;

public:
	~Cofetarie() {
		if (this->prajituri != nullptr) {
			delete[] this->prajituri;
		};
	}

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

};

class Angajat {

private:
	const int id;
	const long long CNP;
	static int nrAngajati;
	string nume;
	string prenume;
	char* functie;

public:
	~Angajat() {
		if (this->functie != nullptr) {
			delete[] this->functie;
			this->functie = nullptr;
		}
	}

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

};

class Prajitura {
private:
	const int id;
	static int nrPrajituri;
	string nume;
	float pret;
	int nrIngrediente;
	string* ingrediente;
	int nrBucati;

public:

	~Prajitura() {
		if (ingrediente != nullptr) {
			delete[] ingrediente;
		}
		nrPrajituri--;
	};

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

int Cofetarie::nrCofetarii = 0;
int Cofetarie::codCaen = 4724;
int Angajat::nrAngajati = 0;
int Prajitura::nrPrajituri = 0;

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
}


