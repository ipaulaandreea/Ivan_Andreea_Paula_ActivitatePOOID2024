//Ivan Andreea-Paula: Prajitura, Cofetarie, Angajat;

#include <string>
using namespace std;

class Cofetarie {

private:
	string nume;
	const int id;
	static int nrCofetarii = 0;
	static int codCaen = 4724;
	string adresa;
	Angajat* administrator;
	Prajitura* prajituri;
	static int nrPrajituri = 0;

public:

	~Cofetarie() {
		if (this.prajituri != nullptr) {
			delete[] this->prajituri;
		}
	};

	Cofetarie() : id(++nrCofetarii) {
		this->administrator = nullptr;
		this->nume = "Necunoscut";
		this->adresa = "Necunoscuta";
		this->nrAngajati = 0;
		this->prajituri = nullptr;
	};

	Coferatarie(
		string adresa,
		int nrPrajituri,
		Prajitura* prajituri)
		:id(++nrCofetarii) {
		this->adresa = adresa;
		this->nrPrajituri = nrPrajituri;
		this->prajituri = new Prajitura[nrPrajituri];
		for (int i = 0; i < nrPrajituri; i++) {
			this->prajituri[i] = prajituri[i];
		}
		delete[] prajituri;
	}
};

class Anjagat {
	private:
		const int id;
		static int nrAngajati = 0;
		string nume;
		string prenume;
		const long long [13] CNP;
		char* functie;

	public:
		~Angajat() {
			if (this->functie = NULL) {
				delete[]this->functie;
			}
			nrAngajati--;
		};

		Anjagat() : id(++nrAngajati){
			this->nume = "Necunoscut";
			this->prenume = "Necunoscut";
			this->CNP = 0000000000000;
			this->functie = new char[strlen("Necunoscut") + 1];
			strcpy_s(this->functie, strlen("Necunoscut") + 1, "Necunoscut");
		}

		Anjagat(
			string nume, 
			string prenume, 
			long long CNP, 
			char* functie) 
			: id(++nrAngajati) {
			this->nume = nume;
			this->prenume = prenume;
			this->CNP = CNP;
			this->functie = new char[strlen(functie) + 1];
			strcpy_s(this->functie, strlen(functie) + 1, functie);
		}
};

		class Prajitura:
			private: 
				const int id;
				static int nrPrajituri = 0;
				string nume;
				float pret;
				string* listaIngrediente;
				int nrBucati;


	////Todos: 
	// check access modifiers
	// //make sure each class has a pointer field
	// make sure each class has 3 constructors
	// add getters and setters
	// add static methods to each class
	// add objects in main;
	//make sure code runs;
			