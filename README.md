# Homework Repository for the Object-Oriented Programming (C++) Course

## Proiect - Faza 1  ✅
1. Alegeți trei obiecte din realitate. Cele trei obiecte trebuie să fie din același domeniu. Domeniul îl alegeți astfel încât să conțină inițialele voastre.  
   - **Exemplu:** Alin Zamfiroiu - Magazin, Ziar, etc.

2. Pentru cele trei obiecte realizați trei clase care să conțină atribute specifice fiecărui obiect în parte.  

3. În cele trei clase trebuie să aveți:  
   - Atribute normale.  
   - Atribute statice.  
   - Atribute constante.  
   - Cel puțin un pointer pentru care veți aloca spațiu în HEAP.  

4. Realizați pentru fiecare clasă cel puțin 3 constructori cu număr diferit de parametri (în total vor fi 9 constructori).  
   - În cadrul constructorilor inițializați toate atributele claselor.  
   - Aveți grijă la inițializarea atributelor constante și a atributelor statice.  

5. În fiecare clasă realizați câte o funcție statică pentru orice tip de procesare sau calcul.  

6. În funcția `main`:
   - Creați, inițializați și afișați câte trei obiecte de tipul fiecărei clase, astfel încât să apelați toți constructorii.  

7. Realizați toate clasele în același fișier `.cpp`, una sub cealaltă.  
   - În partea finală a fișierului implementați funcția `main` în cadrul căreia testați toți constructorii implementați.  

---

## Proiect - Faza 2  
1. Pentru clasele de la tema precedentă treceți atributele din zona publică a clasei în zona **privată**.  

2. În cele trei clase trebuie să implementați destructorii astfel încât să ștergeți memoria alocată în HEAP.  

3. Implementați constructorul de copiere pentru toate clasele.  ✅

4. Pentru toate atributele trecute acum în zona privată a clasei realizați metode de acces la acestea:  
   - **Getteri** și **setteri**. ✅

5. Pentru atributele statice realizați funcții statice pentru a oferi acces la acestea.  ✅

6. Realizați două funcții globale care să realizeze anumite prelucrări/procesări (la alegere) și să folosească obiecte de tipul claselor implementate.  
   - Cele două funcții vor fi prietene cu clasele ale căror obiecte sunt folosite, astfel încât să aibă acces la atributele private.  ✅

7. În funcția `main`: ✅
   - Apelați toate metodele și funcțiile implementate pentru a le testa.  
   - Cu ajutorul get-erilor să afișați valorile atributelor.  

---

## Proiect - Faza 3  
1. Pentru clasele de la tema precedentă:  
   - Supraincarcați operatorul `=` (de atribuire).  
   - Supraincarcați cel puțin alți **3 operatori** (câte 4 operatori pentru fiecare clasă).  

2. Creați cel puțin **o funcție prietenă** în proiect.  

3. În funcția `main`:  
   - Apelați atât funcția prietenă, cât și cei **12 operatori** implementați.  
   - **Recomandare:** Folosiți operatori diferiți pentru a obține experiență variată.  

---

## Proiect - Faza 4  
1. Pentru clasele din proiect creați în funcția `main` **3 vectori**:  
   - Un vector cu obiecte de tipul primei clase.  
   - Un vector cu obiecte de al doilea tip.  
   - Un vector cu obiecte de tipul ultimei clase.  

2. Citiți obiectele pentru acești vectori de la tastatură și afișați-le la consolă.  

3. Parcurgeți acești vectori separat.  

4. Dacă observați că aveți nevoie de anumiți operatori pe care nu i-ați supraincarcat, îi puteți supraincarca acum.  

5. Creați o matrice de obiecte de tipul uneia dintre clasele alese.  
   - Citiți obiectele din acea matrice și le afișați la consolă.  

---

## Proiect - Faza 5  
1. Realizați o nouă clasă în proiect care să aibă cel puțin un atribut de tipul uneia dintre clasele deja implementate (relație de **has-a**):  
   - Atributul poate fi un simplu obiect, un pointer, un vector de obiecte sau un vector de pointeri.  

2. Pentru această clasă adăugați și alte atribute pe lângă acesta.  
   - Puteți avea relație de **has-a** și cu celelalte clase, dacă doriți.  

3. Implementați pentru această clasă metodele specifice claselor:  
   - **Getteri** și **setteri** pentru toate atributele.  
   - **3 operatori** la alegere.  


---

## Proiect - Faza 6  
1. Pentru clasele implementate adăugați metode sau operatori care să lucreze cu:  
   - **Fișiere text**.  
   - **Fișiere binare**.  

2. Aveți 4 clase în acest moment în proiect.  
   - Pentru cel puțin **două dintre ele**, adăugați metode sau operatori de lucru cu **fișiere text**.  
   - Pentru cel puțin **două dintre ele**, adăugați metode sau operatori de lucru cu **fișiere binare**.  

---

## Proiect - Faza 7  
1. În cadrul proiectului adăugați alte **două clase** care să moștenească una sau două dintre clasele existente deja în proiect (**relație de is-a**).  

2. Pentru noile clase adăugați:  
   - Atribute specifice.  
   - Metode specifice (constructori, get-eri, set-eri, etc.).  

3. În funcția `main`:  
   - Creați obiecte de tipul noilor clase, astfel încât să testați tot ce ați implementat.  
   - Realizați **upcasting** și utilizați-l.  
