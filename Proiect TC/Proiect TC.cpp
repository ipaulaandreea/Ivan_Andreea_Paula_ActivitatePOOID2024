﻿// Ivan Andreea-Paula: Prajitura, Cofetarie, Angajat;
// clasa Prajitura va reprezenta un anumit sortiment de prajitura

#include <string>
#include <iostream>
#include <stdexcept> 
#include <cstring>
#include <vector>
#include <sstream>
#include <fstream> 



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


		/////9. Supraincarcare operatori
			// - implementarea functiei operator>: in zona globala
		Cofetarie& operator=(const Cofetarie& c) {
			if (this != &c) {
				delete[] this->prajituri;

				this->nume = c.nume;
				this->adresa = c.adresa;
				this->administrator = c.administrator;
				this->nrPrajituri = c.nrPrajituri;

				if (c.nrPrajituri > 0) {
					this->prajituri = new string[c.nrPrajituri];
					for (int i = 0; i < c.nrPrajituri; i++) {
						this->prajituri[i] = c.prajituri[i];
					}
				}
				else {
					this->prajituri = nullptr;
				}
			}
			return *this;
		}

		friend void operator<<(std::ostream& out, const Cofetarie& c) {
			out << c.id << std::endl;
			out << c.nume << std::endl;
			out << c.adresa << std::endl;
			out << c.administrator << std::endl;

			out << c.nrPrajituri << std::endl;

			for (int i = 0; i < c.nrPrajituri; ++i) {
				out << c.prajituri[i] << std::endl;
			}
		}

		friend ifstream& operator>>(ifstream& file, Cofetarie& c) {
			int tempId;
			file >> tempId;
			if (file) {
				const_cast<int&>(c.id) = tempId;
			}

			file >> c.nume;
			file >> c.adresa;
			file >> c.administrator;
			file >> c.nrPrajituri;

			if (c.prajituri != nullptr) {
				delete[] c.prajituri;
				c.prajituri = nullptr;
			}


			c.prajituri = new string[c.nrPrajituri];
			for (int i = 0; i < c.nrPrajituri; ++i) {
				std::getline(file, c.prajituri[i]);
			}

			return file;

		}


		/*friend ostream& operator<<(
			ostream& oStream, 
			const Cofetarie& c) {
			oStream << "ID: " << c.id << ", "
				<< "Nume: " << c.nume << ", "
				<< "Adresa: " << c.adresa << ", "
				<< "Administrator " << c.administrator << ", "
				<< "Prajituri: " << endl;
			if (c.nrPrajituri > 0) {
				for (int i = 0; i < c.nrPrajituri; i++) {
					oStream << c.prajituri[i];
					if (i < c.nrPrajituri - 1) {
						oStream << ", ";
					}
				}
			}
			else {
				oStream << "Fara prajituri";
			}

			return oStream;

		}*/

		/*friend std::istream& operator>>(std::istream& in, Cofetarie& c) {
			std::cout << "Introduceti numele cofetariei: ";
			in.ignore();
			std::getline(in, c.nume);

			std::cout << "Introduceti adresa cofetariei: ";
			std::getline(in, c.adresa);

			std::cout << "Introduceti numele administratorului: ";
			std::getline(in, c.administrator);

			std::cout << "Introduceti numarul de prajituri: ";
			in >> c.nrPrajituri;

			delete[] c.prajituri;
			c.prajituri = new std::string[c.nrPrajituri];

			in.ignore();
			for (int i = 0; i < c.nrPrajituri; ++i) {
				std::cout << "Introduceti numele prajiturii " << i + 1 << ": ";
				std::getline(in, c.prajituri[i]);
			}

			return in;
		}*/

		
		friend bool operator>(const Cofetarie& c1, const Cofetarie& c2);

		friend bool operator!=(const Cofetarie& c1, const Cofetarie& c2) {
			return c1.nume != c2.nume;
		}




		//10. Functii pentru lucrul cu fisiere text:
		static void citesteDinFisier(string numeFisier) {
			Cofetarie cofetarieDinFisier;
			ifstream fis(numeFisier, ios::in);
			fis >> cofetarieDinFisier;
			fis.close();
			cout << cofetarieDinFisier;
		}

		static void scrieInFisier(const Cofetarie& c) {
			ofstream fis("cofetarie.txt", ios::out);
			fis << c;
			fis.close();
			};

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
			strcpy_s(this->functie, strlen(functie) + 1, newFunctie);
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

	/////9. Supraincarcare operatori
	Angajat& operator=(const Angajat& a) {
		if (this != &a) {
			delete[] this->functie;
			this->nume = a.nume;
			this->prenume = a.prenume;
			this->functie = new char[strlen(a.functie) + 1];
			strcpy_s(this->functie, strlen(a.functie), a.functie);
		};
	return *this;
	};

	friend bool operator== (const Angajat& a1, const Angajat& a2) {
		return a1.CNP == a2.CNP;
	};

	friend int operator% (const Angajat& a, int x);

	//friend ostream& operator<<(ostream& oStream, const Angajat& a) {
	//	oStream << a.id << "; "
	//		<< a.CNP << "; "
	//		<< a.nume << "; "
	//		<< a.prenume << "; ";
	//	if (a.functie != nullptr) {
	//		oStream << a.functie << "; ";
	//	}
	//	else {
	//		oStream << "Functie necunoscuta";
	//	}
	//	return oStream;
	//};

	//friend istream& operator>>(istream& in, Angajat& a) {
	//	
	//	cout << "Introduceti numele angajatului: ";
	//	in >> a.nume;

	//	cout << "Introduceti prenumele angajatului: ";
	//	in >> a.prenume;

	//	cout << "Introduceti functia angajtului: ";
	//	string tempFunctie;
	//	in >> tempFunctie;
	//	a.functie = new char[tempFunctie.length() + 1];
	//	strcpy_s(a.functie, tempFunctie.length() + 1, tempFunctie.c_str());


	//	return in;
	//}

	friend void operator<<(std::ostream& out, const Angajat& a) {
		out << a.id << std::endl;
		out << a.CNP << std::endl;
		out << a.nume << std::endl;
		out << a.prenume << std::endl;

		if (a.functie != nullptr) {
				out << a.functie << std::endl;
			}
			else {
				out << "Functie necunoscuta";
			}
		};


	friend ifstream& operator>>(ifstream& file, Angajat& a) {

		int tempId;
		file >> tempId;
		if (file) {
			const_cast<int&>(a.id) = tempId;
		}

		long long tempCNP;
		file >> tempCNP;
		if (file) {
			const_cast<long long&>(a.CNP) = tempCNP;
		}

		file >> a.nume;
		file >> a.prenume;

		char buffer[20];
		file >> buffer;
		a.functie = new char[strlen(buffer)+1];
		strcpy_s(a.functie, strlen(buffer) + 1, buffer);
		return file;

	}
	

	//10. Functii pentru lucrul cu fisiere text:
	static void citesteDinFisier(string numeFisier) {
		Angajat angajatDinFisier;
		ifstream fis(numeFisier, ios::in);
		fis >> angajatDinFisier;
		fis.close();
		cout << angajatDinFisier;
	}

	static void scrieInFisier(const Angajat& a) {
		ofstream fis("angajat.txt", ios::out);
		fis << a;
		fis.close();
	}



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

	/////9. Supraincarcare operatori
	Prajitura& operator=(const Prajitura& p) {
		if (this != &p) {
			delete[] this->ingrediente;

			this->nume = p.nume;
			this->pret = p.pret;
			this->nrIngrediente = p.nrIngrediente;
			this->ingrediente = new string[p.nrIngrediente];
			for (int i = 0; i < p.nrIngrediente; ++i) {
				this->ingrediente[i] = p.ingrediente[i];
			}
		}
		return *this;
	}

	operator float() const {
		return this->pret;
	}

	friend bool operator>(const Prajitura& p1, const Prajitura& p2);

	friend ostream& operator<<(ostream& oStream, const Prajitura& p) {
		oStream << "*Nume*" << p.nume << endl;
		oStream << "**Pret**" << p.pret << endl;
		oStream << "***Bucati***" << p.nrBucati << endl;
		oStream << "****Ingregiente****" << endl;
		if (p.ingrediente != nullptr) {
			for (int i = 0; i < p.nrIngrediente; i++) {
				oStream << p.ingrediente[i] << "; ";
			}
		}
		else {
			oStream << "Nothing to show:(";
		}
		return oStream;
	}

	friend istream& operator>>(istream& in, Prajitura& prajitura) {
		cout << "Introduceti numele prajiturii: ";
		in >> prajitura.nume;

		cout << "Introduceti pretul prajiturii: ";
		in >> prajitura.pret;

		cout << "Introduceti numarul ingredientelor prajiturii: ";
		in >> prajitura.nrIngrediente;

		prajitura.ingrediente = new string[prajitura.nrIngrediente];

		cout << "Introduceti ingredientele:" << endl;
		in.ignore();
		for (int i = 0; i < prajitura.nrIngrediente; i++) {
			cout << "Ingredient " << i + 1 << ": ";
			getline(in, prajitura.ingrediente[i]);
		}

		cout << "Introduceti numarul de bucati: ";
		in >> prajitura.nrBucati;

		return in;
	}

	//Citire/scriere in fisiere binare

	void scrieInFisierBinar(fstream& f) {
		int lungimeNume = this->nume.size();
		f.write((char*)&lungimeNume, sizeof(int));          
		f.write(this->nume.c_str(), lungimeNume);           
		f.write((char*)&this->pret, sizeof(float));         
		f.write((char*)&this->nrIngrediente, sizeof(int));  
		f.write((char*)&this->nrBucati, sizeof(int));       

		for (int i = 0; i < this->nrIngrediente; i++) {
			int lungimeIngredient = this->ingrediente[i].size();
			f.write((char*)&lungimeIngredient, sizeof(int));    
			f.write(this->ingrediente[i].c_str(), lungimeIngredient); 
		}
	}
	
	void citesteDinFisierBinar(fstream& f) {
		int lungimeNume;
		f.read((char*)&lungimeNume, sizeof(int));          
		char* bufferNume = new char[lungimeNume + 1];
		f.read(bufferNume, lungimeNume);                 
		bufferNume[lungimeNume] = '\0';                    
		this->nume = bufferNume;                        
		delete[] bufferNume;

		f.read((char*)&this->pret, sizeof(float));       

		f.read((char*)&this->nrIngrediente, sizeof(int)); 

		this->ingrediente = new string[this->nrIngrediente];
		for (int i = 0; i < this->nrIngrediente; i++) {
			int lungimeIngredient;
			f.read((char*)&lungimeIngredient, sizeof(int));   
			char* bufferIngredient = new char[lungimeIngredient + 1];
			f.read(bufferIngredient, lungimeIngredient);      
			bufferIngredient[lungimeIngredient] = '\0';       
			this->ingrediente[i] = bufferIngredient;          
			delete[] bufferIngredient;
		}

		f.read((char*)&this->nrBucati, sizeof(int));        
	}

	////functie virtuala
		virtual void metodaDeSuprascris() {
		cout << "prajiturile sunt bune!" << endl;
	};

};

class PlatouPrajituri {
private:
	static int nrPlatouri;
	int id;
	string nume;
	Prajitura* prajituri;
	int nrPrajituri;

public:
	~PlatouPrajituri() {
		if (this->prajituri != nullptr) {
			delete[] this->prajituri;
		}
		nrPlatouri--;
	}
	PlatouPrajituri()
		: id(++nrPlatouri), nume("Platou Necunoscut"), prajituri(nullptr), nrPrajituri(0) {
	}

	PlatouPrajituri(string nume, int nrSortimentePrajituri, Prajitura* prajituriPtPlatou) {
		this->id = ++nrPlatouri;
		this->nume = nume;
		this->nrPrajituri = nrSortimentePrajituri;
		if (this->nrPrajituri > 0 && this->prajituri != nullptr) {
			this->prajituri = new Prajitura[nrSortimentePrajituri];
			for (int i = 0; i < nrSortimentePrajituri; i++) {
				this->prajituri[i] = prajituriPtPlatou[i];
			}
		}
		else {
			this->prajituri = nullptr;
		}

	};

	int getId() {
		return this->id;
	}
	string getNume() {
		return this->nume;
	}

	int getNrPrajituri() {
		return this->nrPrajituri;
	}

	Prajitura* getPrajituri() {
		return this->prajituri;
	}

	void setId(int newId) {
		this->id = newId;
	}
	void setNume(string newName) {
		this->nume = newName;
	}

	void setNrPrajituri(int newNr) {
		this->nrPrajituri = newNr;
	}

	void setPrajituri(Prajitura* newPrajituri, int newNr) {
		if (this->nrPrajituri > 0 && this->prajituri != nullptr) {
			this->prajituri = new Prajitura[newNr];
			for (int i = 0; i < newNr; i++) {
				this->prajituri[i] = newPrajituri[i];
			}
		}
	}

	friend std::ostream& operator<<(ostream& out, const PlatouPrajituri& pp) { 
		out << pp.id << endl;
		out << pp.nume << endl;
		if (pp.nrPrajituri > 0 && pp.prajituri != nullptr) {

			for (int i = 0; i < pp.nrPrajituri; i++) {
				out << pp.prajituri[i] << endl;

			}
		}
		else {
			out << "Platou gol" << endl;
		}
		return out;

};
	friend int operator>(const PlatouPrajituri& p1, const PlatouPrajituri& p2) {
		return p1.nrPrajituri > p2.nrPrajituri;
	}

	friend std::istream& operator>>(std::istream& in, PlatouPrajituri& pp);

	//Citire/scriere in fisiere binare

	void scrieInFisierBinar(fstream& f) {
		int lungimeNume = this->nume.size();
		f.write((char*)&lungimeNume, sizeof(int)); 
		f.write(this->nume.c_str(), lungimeNume); 

		f.write((char*)&this->nrPrajituri, sizeof(int));

		for (int i = 0; i < this->nrPrajituri; i++) {
			string numePrajitura = this->prajituri[i].getNume();
			int lungimeNumePrajitura = numePrajitura.size();
			//int lungimeNumePrajitura = this->prajituri[i].getNume().size();
			f.write((char*)&lungimeNumePrajitura, sizeof(int));
			f.write(this->prajituri[i].getNume().c_str(), lungimeNumePrajitura);
		}
	}


void citesteDinFisierBinar(fstream& f) {
    int lungimeNume;
    f.read((char*)&lungimeNume, sizeof(int));

    char* bufferNume = new char[lungimeNume + 1];
    f.read(bufferNume, lungimeNume);
    bufferNume[lungimeNume] = '\0';

    this->nume = bufferNume;
    delete[] bufferNume; 

    f.read((char*)&this->nrPrajituri, sizeof(int));


    this->prajituri = new Prajitura[this->nrPrajituri];

    for (int i = 0; i < this->nrPrajituri; i++) {
        int lungimeNumePrajitura;
        f.read((char*)&lungimeNumePrajitura, sizeof(int));
		//momentan ma intereseaza doar numele prajiturilor

        char* bufferNumePrajitura = new char[lungimeNumePrajitura + 1];
        f.read(bufferNumePrajitura, lungimeNumePrajitura);
        bufferNumePrajitura[lungimeNumePrajitura] = '\0'; 
        this->prajituri[i] = Prajitura(bufferNumePrajitura, 0, 0);

        delete[] bufferNumePrajitura;
    }
}


};



std::istream& operator>>(std::istream& in, PlatouPrajituri& pp) {
	in >> pp.nume;
	in >> pp.nrPrajituri;

	if (pp.prajituri != nullptr) {
		delete[] pp.prajituri;
		pp.prajituri = nullptr;
	}

	if (pp.nrPrajituri > 0) {
		pp.prajituri = new Prajitura[pp.nrPrajituri];

		for (int i = 0; i < pp.nrPrajituri; i++) {
			in >> pp.prajituri[i];
		}
	}
	return in;

};

///////////////////////Clase-copil///////////////////////////
class PrajituraDiabetici:public Prajitura {
private:
	string tipIndulcitor;
	float concentratieIndulcitor;

public:
	PrajituraDiabetici()
		: Prajitura(), tipIndulcitor("Necunoscut"), concentratieIndulcitor(0.0) {};

	PrajituraDiabetici(const std::string& nume, float pret, int nrBucati, 
	const std::string& tipIndulcitor, double concentratieIndulcitor){
			Prajitura(nume, pret, nrBucati);
          	this->tipIndulcitor = tipIndulcitor; 
          	this->concentratieIndulcitor = concentratieIndulcitor;
	};

	string getTipIndulcitor() {
		return this->tipIndulcitor;
	};

	float getConcentratieIndulcitor() {
		return this->concentratieIndulcitor;
	};

	// string getNume(){
	// 	return Prajitura::getNume();
	// }

	void setTipIndulcitor(const string& tipIndulcitor) {
		this->tipIndulcitor = tipIndulcitor;
	};

	// void setNume(const string& nume){
	// 	Prajitura::setNume(nume);
	// };

	void setConcentratieIndulcitor(float concentratieIndulcitor) {
		this->concentratieIndulcitor = concentratieIndulcitor;
	};
        
 bool operator > (const PrajituraDiabetici& p2) const {
    return this->concentratieIndulcitor > p2.concentratieIndulcitor;
};
	void metodaDeSuprascris() override {
		cout << "prajiturile fara zahar sunt si mai bune!" << endl;
	};
};


class PrajituraPaleo :public Prajitura {
private:
	string tipInlocuitorGluten;
	int grameCarbohidrati;

public:
	PrajituraPaleo()
		: Prajitura(), tipInlocuitorGluten("Necunoscut"), grameCarbohidrati(0) {};

	PrajituraPaleo(const std::string& nume, float pret, int nrBucati,
		const std::string& tipInlocuitorGluten, int grameCarbohidrati) {
		Prajitura(nume, pret, nrBucati);
		this->tipInlocuitorGluten = tipInlocuitorGluten;
		this->grameCarbohidrati = grameCarbohidrati;
	};

	string getTipInlocuitorGluten() {
		return this->tipInlocuitorGluten;
	};

	float getGrameCarbohidrati() {
		return this->grameCarbohidrati;
	};


	void setTipInlocuitorGluten(const string& tipInlocuitorGluten) {
		this->tipInlocuitorGluten = tipInlocuitorGluten;
	};


	void setGrameCarbohidrati(int grameCarbohidrati) {
		this->grameCarbohidrati = grameCarbohidrati;
	};

	void metodaDeSuprascris() override {
		cout << "prajiturile paleo sunt si mai bune!" << endl;
	};
};


///////////////////////////////////////////////////////////
// Functii globale
string getAdmin(Cofetarie c) { return c.administrator; };

bool operator>(Cofetarie& c1, Cofetarie& c2) { 
	return c1.getAdministrator().length() > c2.getAdministrator().length();
}

int operator%(Angajat& a, int x) {
	return a.getNume().length() % x;
}

void printFullName(Angajat a) {
	string fullName = a.nume + " " + a.prenume;
	cout << fullName << endl;
};



bool operator>(Prajitura& p1, Prajitura& p2) {
	return p1.getPret() > p2.getPret();
};





///////////////////////////////////////////////////////////
//Atribute statice

int Cofetarie::nrCofetarii = 0;
int Cofetarie::codCaen = 4724;
int Angajat::nrAngajati = 0;
int Prajitura::nrPrajituri = 0;
int PlatouPrajituri::nrPlatouri = 0;


///////////////////////////////////////////////////////////


int main() {

	Cofetarie cofetarie1;
	Cofetarie cofetarie2("Adresa 1", new string[3]{ "Amandina", "Savarina", "Tort diplomat" }, 3);
	Cofetarie cofetarie3("Adresa 2", new string[2]{ "Tiramisu", "Dobos" }, 2, "Popescu Ion");

	//Cofetarie::scrieInFisier(cofetarie3);
	//Cofetarie::citesteDinFisier("cofetarie.txt");


	 Angajat angajat1;
	 Angajat angajat2("Popescu", "Ion", 1234567890000, "Administrator");
	 Angajat angajat3("Ionescu", "Maria", 2123456789000);

	 //Angajat::scrieInFisier(angajat2);
	 //Angajat::citesteDinFisier("angajat.txt");

	 Prajitura prajitura1;
	 Prajitura prajitura2("Amandina", 15.5, 10);
	 Prajitura prajitura3("Foret Noir", 18.2, 3, new string[3]{ "Visine", "Zahar", "Oua" }, 6);

	 
	// fstream fisier("prajitura.dat", ios::out | ios::binary);
	// if (!fisier.is_open()) {
	//	 cout << "Eroare la crearea fisierului!" << endl;
	//	 return 1;
	// }

	// prajitura2.scrieInFisierBinar(fisier);
	//
	//fisier.close();

	//fisier.open("prajitura.dat", ios::in | ios::binary);
 //   if (!fisier.is_open()) {
 //       cout << "Eroare la deschiderea fisierului!" << endl;
 //       return 1; 
 //   }

 //   fisier.seekg(0, ios::beg);

	// Prajitura prajitura;
	// prajitura.citesteDinFisierBinar(fisier);
	// fisier.close();
	// cout << prajitura << endl;

	//PlatouPrajituri platou1("Platou 1", 3, new Prajitura[3]{ prajitura1, prajitura2, prajitura3 });

	// fstream fisier2("platou.dat", ios::out | ios::binary);
	// if (!fisier2.is_open()) {
	//	 cout << "Eroare la crearea fisierului!" << endl;
	//	 return 1;

	// }
	//fisier.open("prajitura.dat", ios::in | ios::binary);
 //   if (!fisier.is_open()) {
 //       cout << "Eroare la deschiderea fisierului!" << endl;
 //       return 1; 
 //   }
	// platou1.scrieInFisierBinar(fisier2);

	// fisier2.close();

	//fisier2.open("platou.dat", ios::in | ios::binary);
 //   if (!fisier2.is_open()) {
 //       cout << "Eroare la deschiderea fiierului!" << endl;
 //       return 1; 
 //   }

 //   fisier2.seekg(0, ios::beg);

	// PlatouPrajituri platou;
	// platou.citesteDinFisierBinar(fisier2);
	// fisier2.close();
	// cout << platou;  

	PrajituraDiabetici pd1("Prajitura Stevia", 15.5f, 10, "Stevia", 0.4f);
    PrajituraDiabetici pd2("Prajitura Erythritol", 12.0f, 5, "Erythritol", 0.6f);

    	cout << "Prajitura 1: " << pd1.getNume() << ", tip indulcitor: " << pd1.getTipIndulcitor() 
         << ", concentratie indulcitor: " << pd1.getConcentratieIndulcitor() << endl;

    	cout << "Prajitura 2: " << pd2.getNume() << ", tip indulcitor: " << pd2.getTipIndulcitor() 
         << ", concentratie indulcitor: " << pd2.getConcentratieIndulcitor() << endl;


    // Upcasting
	pd1.metodaDeSuprascris();
    Prajitura* prajituraUp1 = &pd1;  

   prajituraUp1->metodaDeSuprascris();

   PrajituraPaleo pal1("Prajitura Hrisca", 15.5f, 10, "Faina Hrisca",20);
   PrajituraPaleo pal2("Prajitura Linte", 12.0f, 5, "Faina linte", 25);

   cout << "Prajitura 1: " << pal1.getNume() << ", tip inlocuitor: " << pal1.getTipInlocuitorGluten()
	   << ", grame carbohidrati: " << pal1.getGrameCarbohidrati() << endl;

   cout << "Prajitura 2: " << pal2.getNume() << ", tip inlocuitor: " << pal2.getTipInlocuitorGluten()
	   << ", grame carbohidrati: " << pal2.getGrameCarbohidrati() << endl;

   pal1.setGrameCarbohidrati(14);
   pal2.setTipInlocuitorGluten("Pudra de Roscove");


   // Upcasting
   pal2.metodaDeSuprascris();
   Prajitura* prajituraUp2 = &pal2;

   prajituraUp2->metodaDeSuprascris();

	return 0; 

	//  //Getteri si setteri
	// cofetarie1.setAdministrator("New Admin");
	// cout << cofetarie1.getAdministrator() << endl;

	// cofetarie1.setAdresa("New Address");
	// cout << cofetarie1.getAdresa() << endl;

	// cofetarie1.setPrajituri(new string[2]{ "Profiterol", "Amandina" }, 2);
	// string* prajituri = cofetarie1.getPrajituri();
	// for (int i = 0; i < cofetarie1.getNrPrajituri(); ++i) {
	// 	cout << prajituri[i] << " ";
	// }
	// cout << endl;

	// angajat1.setFunctie("Cofetar");
	// cout << angajat1.getFunctie() << endl;

	// angajat1.setNume("Matei");
	// cout << angajat1.getNume() << endl;

	// angajat1.setPrenume("Marius");
	// cout << angajat1.getPrenume() << endl;

	// prajitura1.setIngrediente(new string[2]{ "Frisca", "Biscuiti" }, 2);
	// string* ingrediente = prajitura1.getIngrediente();
	// for (int i = 0; i < prajitura1.getNrIngrediente(); ++i) {
	// 	cout << ingrediente[i] << " ";
	// }
	// cout << endl;

	
	// prajitura1.setNrBucati(10);
	// cout << prajitura1.getNrBucati() << endl;
	
	// prajitura1.setNume("Cea mai buna prajitura");
	// cout << prajitura1.getNume() << endl;

	// prajitura1.setPret(23.5);
	// cout << prajitura1.getPret() << endl;

	// prajitura1.setNrIngrediente(2);
	// cout << prajitura1.getNrIngrediente() << endl;


	// //// Metode statice

	// Cofetarie::setCodCaen(1234); 
	// cout << "Cod CAEN: " << Cofetarie::getCodCaen() << endl;
	
	// Cofetarie::setNrCofetarii(5);
	// cout << Cofetarie::getNrCofetarii() << endl;

	// Angajat::setNrAngajati(20);
	// cout << Angajat::getNrAngajati() << endl;

	// Prajitura::setNrPrajituri(10);
	// cout << Prajitura::getNrPrajituri() << endl;


	// //// Methode friend
	// cout << getAdmin(cofetarie2) << endl;
	// printFullName(angajat3);

	// ///Operatori
	// //Cofetarie:
	// //1. operatorul = 
	// Cofetarie cofetarie4 = cofetarie3;

	// //2. operatorul <<
	// cout << cofetarie4 << endl;

	// //3. operatorul >
	// bool rez1 = cofetarie4 > cofetarie1;
	// cout << rez1 << endl;

	// //4. operatorul !=
	// bool rez2 = cofetarie4 != cofetarie3;
	// cout << rez2 << endl;
	// bool rez3 = cofetarie4 != cofetarie2;
	// cout << rez3 << endl;

	// ////////////

	// //Angajat:
	// 	//1. operatorul = 
	// Angajat angajat4 = angajat3;

	// 	//2. operatorul <<
	// cout << angajat4 << endl;

	// 	//3. operatorul %
	// bool rez4 = angajat4%2;
	// cout << rez4 << endl;

	// 	//4. operatorul ==
	// bool rez5 = angajat4 == angajat3;
	// cout << rez5 << endl;
	// bool rez6 = angajat4 == angajat1;
	// cout << rez6 << endl;
	

	// //Prajitura:
	// 	//1. operatorul =
	// Prajitura prajitura4 = prajitura3;

	// 	//2. operatorul <<
	// cout << prajitura4 << endl;

	// 	//3. operatorul >
	// int rez7 = prajitura4 > prajitura1; 
	// cout << rez7 << endl;

	// 	//4. operatorul float()
	// cout << (float)prajitura4 << endl;


	// vector<Cofetarie> vectorCofetarii;
	// vector<Angajat> vectorAngajati;
	// vector<Prajitura> vectorPrajituri;

	// int n;
	// cout << "Introduceti numarul de cofetarii pe care le veti introduce: ";
	// cin >> n;
	// cin.ignore();
	// vectorCofetarii.resize(n);
	// for (int i = 0; i < n; ++i) {
	// 	cout << "Introduceti detaliile cofetariei " << i + 1 << ":\n";
	// 	cin >> vectorCofetarii[i];
	// }

	// int m;
	// cout << "Introduceti numarul de angajati pe care ii veti introduce: ";
	// cin >> m;
	// cin.ignore();
	// vectorAngajati.resize(m);
	// for (int i = 0; i < m; ++i) {
	// 	cout << "Introduceti detaliile angajatului " << i + 1 << ":\n";
	// 	cin >> vectorAngajati[i];
	// }

	// int p;
	// cout << "Introduceti numarul de prajituri pe care le veti introduce: ";
	// cin >> p;
	// cin.ignore();
	// vectorPrajituri.resize(p);
	// for (int i = 0; i < p; ++i) {
	// 	cout << "Introduceti detaliile prajiturii " << i + 1 << ":\n";
	// 	cin >> vectorPrajituri[i];
	// }

	// for (int i = 0; i < m; i++) {
	// 	cout << vectorCofetarii[i];
	// }

	// for (int i = 0; i < n; i++) {
	// 	cout << vectorAngajati[i];
	// }

	// for (int i = 0; i < p; i++) {
	// 	cout << vectorPrajituri[i];
	// }

	// int rows = 2;
	// int cols = 2;

	// vector<vector<Prajitura>> matricePrajituri(rows, vector<Prajitura>(cols));

	// for (int i = 0; i < rows; i++) {
	// 	for (int j = 0; j < cols; j++) {
	// 		cout << "\nIntroduceti detalii pentru prajitura de pe randul " << i + 1 << " si coloana " << j + 1 << ":\n";
	// 			cin >> matricePrajituri[i][j];
	// 	}
	// }

	// for (int i = 0; i < rows; i++) {
	// 	for (int j = 0; j < cols; j++) {
	// 		cout << "\nPrajitura rand " << i + 1 << " coloana " << j + 1 << ":\n";
	// 		cout << matricePrajituri[i][j] << endl;
	// 	}
	// }


	return 0;

}