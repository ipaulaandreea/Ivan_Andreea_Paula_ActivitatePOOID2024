#include <iostream> 
#include<string> 
using namespace std;

class Masina {
private: const int id;
	   static int nrMasini;
	   string marca;
	   int nrComponente;
	   float* preturi;
	   ////static field can be accessed only through static method //
	   static int getNrMasini() {
		   return nrMasini;
	   }

	   static void setNrMasini(int _nrMasini) {
		   nrMasini = _nrMasini;
	   }

public:
	~Masina() {
		if (this->preturi != nullptr) delete[] this->preturi;
	}

	Masina() : id(++nrMasini) {
		this->marca = "Necunoscuta";
		this->nrComponente = 0;
		this->preturi = nullptr;
	};

	Masina(string marca, int nrComponente, float* preturi) :id(++nrMasini) {
		this->marca = marca;
		this->nrComponente = nrComponente;
		this->preturi = new float[nrComponente];

		for (int i = 0; i < nrComponente; i++) {
			this->preturi[i] = preturi[i];
		}

		delete[] preturi;
	}

	int getNrComponente() {
		return this->nrComponente;
	}

	void setNrComponente(int nrComponente) {
		if (nrComponente > 0) {
			this->nrComponente = nrComponente;
		}
		else {
			throw exception();
			throw 400;
			//you can throw exceptions, status codes, primmitives, strings
			// int type; 
			// throw "valoare negativa"; 
		}
	}

	void afisareMasina() {
		std::cout << this->id <<
			". Masina cu marca " << this->marca <<
			" are " << this->nrComponente << " componente cu urmatoarele preturi: ";
		if (this->preturi != nullptr) {
			for (int i = 0; i < nrComponente; i++) {
				cout << " " << this->preturi[i];
			};
		};
	};
	//get si set pt vectorul de preturi 

	float* getPreturi() {
		float* vectorPreturi = new float[this->nrComponente];
		for (int i = 0; i < this->nrComponente; i++) {
			vectorPreturi[i] = this->preturi[i];
		}
		return vectorPreturi;
	};

	void setPreturi(float* vectorNou, int nouaDimensiune) {
		setNrComponente(nouaDimensiune);
		if (this->preturi != nullptr) {
			delete[] this->preturi;
		}

		this->preturi = new float[nouaDimensiune];
		for (int i = 0; i < nouaDimensiune; i++) {
			this->preturi[i] = vectorNou[i];
		}
		delete[] vectorNou;
	}

	const int getId() {
		return this->id;
	}
};

int Masina::nrMasini = 0;


int main() {
	Masina masina1;
	Masina masina2("Renault", 4, new float[4] {5.3, 40.4, 500, 10});
	Masina masina3;
	try {
		masina1.setNrComponente(6);
	}
	catch (const char* mesaj) { cout << endl << mesaj; }
	catch (int cod) { cout << cod; }
	catch (...) {
		cout << endl << "Valoarea din set este mai mica sau egala cu 0!";
	} masina2.afisareMasina();
	cout << endl << masina1.getNrComponente();
	masina3.afisareMasina();
	float* masina2Preturi = masina2.getPreturi();
	for (int i = 0; i < masina2.getNrComponente(); i++) {
		cout << endl << "" << masina2Preturi[i];
	}
	masina3.setPreturi(new float[3] {4.4, 6, 50}, 3);
	masina3.afisareMasina();
	//pointeri la obiecte 
	Masina* pMasina = new Masina();
	pMasina->afisareMasina();
	Masina* pMasina2 = new Masina("Ford", 3, new float[3] {4, 5, 6});
	/*cout << pMasina2.getId();*/

	//apelarea destructorului nu se face automat, ca in cazul celorlalte obiect, pentru ca pointerii stau pe heap, iar destructorul se triggeruieste doar pentru entitatile de pe stack; 
	delete pMasina;
	delete pMasina2;
	/*Masina::getNrMasini();*/ //de facut getteri si setteri pt pointeri la obiecte 
};
