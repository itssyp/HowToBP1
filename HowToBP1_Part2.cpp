#include <iostream>
#include <math.h>
#include <vector>
#include <fstream>

using namespace std;

/*
    Nezzuk akkor hogyan is epitunk fel egy fuggvenyt. Eloszor az ugynevezett szignarturajat irjuk meg.
    A szignature a vaza. Az elso dolog amit el kell dontenunk, hogy a fuggvenyunk milyen tipusu legyen, azaz mi lesz a visszateresi, azaz milyen "valaszt" varunk a reszprogramtol.
    Ebben az esetben mivel az a kerdes amit meg akar valaszolni a reszprogram, hogy egy adott szam paros-e, igy ez termeszetesen igaz vagy hamis, avagy bool.
    Utana megadjuk a fuggveny nevek, ezzel a nevvel fogjuk majd meghivni a mainben, barmi lehet.
    Utana jonnek a parameterek, szepen egymes utan vesszovel elvalaszta. Minden parameternek van egy tipusa, es egy neve.
    A parameterek erteke hivaskor dol el, a mainben.
    Tehat pl ha ezt a fuggvenyt meghivjuk a mainben ugy hogy:
    ... paros(5);
    akkor a fuggveny ugy fog lefutni, hogy az o altala a-nak hivott valtozo kezdoerteke 5 lesz.
    Igy tud a main adatokat adni a reszprogramnak.
    Termeszetesen valtozoval is meg lehet hivni egy fuggvenyt.
    int x = 5;
    ... paros(x);
    ekkor ugyan az tortenik, a fuggvenyunk altal a-nak nevezett parameter kezdoerteke x, azaz 5 lesz. Figyeljuk meg hogy teljesen mindegy milyen nevu a mainben szereplo valtozo, 
    es mi a neve a fuggveny paramterenek.
    Ha a szignatura kesz van, megirjuk a fuggveny pocakjat, hogy mit csinaljon. Ebben az esetben dontse el hogy a maintol parameterkent kapott szam paros-e.
    Ezt az valaszt fogja adni az alprogram, ez lesz a visszateresi ertek. A visszateresi erteket fogja vissza kapni a main, behelyettesitve a hivas helyere.
    Tekerj vissza a mainbe.
*/
bool paros(int a){
    return a % 2 == 0;
}

/*
    Itt van meg par pelda fuggveny, a megertes kedveert.
*/

int faktorialis(int n){
    if (n == 0){
        return 1; // Tobb return statement is lehet egy fuggvenyben, igy ki tudunk ugrani ideje koran, meg tudunk adni perem eseteket.
    }
    int fakt = 1;
    for (int i = 1; i <= n; i++){
        fakt *= i; 
    }
    return fakt;
}

bool prim(int a){
    if (a < 2) return false;
    if (a == 2) return true;
    for (int i = 2; i < sqrt(a); i++){
        if (a % i == 0){
            return false;
        }
    }
    return true;
}

string hosszabb(string s1, string s2){
    if (s1.length() > s2.length()) {
        return s1;
    } else {
        return s2;
    }
}

string visszafele(string s){
    string vissza;
    for (int i = s.length() - 1; i >= 0; i--){
        vissza += s[i];
    }
    return vissza;
}

/*
    Ahogy mondtam, nem kell fetetlenul lennie visszateresi erteknek, ekkor a fuggveny tipusa void. Klasszikusan void fuggvenyeket pl egybol kiirjak az eredmenyuket, vagy valami mas 
    formaban rogzitik azt, lasd kesobb referencia szerinti atadas.
    pl a paros fuggvenyunk nezhetne ki igyis...
*/
void paros2(int a){
    bool b = a % 2 == 0;
    cout << b << endl;
}
/*
    A void fuggvenyeket amikor meghivjuk a mainben, "nem all elottuk semmi."
*/

/*
    A fuggveny visszateresi erteke barmi lehet, igy termeszetesen vector is.
    Ezt eloszeretettel hasznaljuk pl ha be akarunk olvasni egy adatsort a fuggvennyel.
    Eloszor nezzunk egy fuggvenyt ami siman random szamokkal feltotott vektort ad vissza.
*/
vector<int> randomfeltolt(int n, int r){ // n db (0..r( szammal tolti fel
    vector<int> v;
    for (int i = 0; i < n; i++){
        v.push_back(rand() % r);
    }
    return v;
}

/*
    Nezzunk egy olyan esetet, amikor egy faljbol akarjuk feltolteni a vectorunkat szamokkal, tendaljunk a vizsga feladatok iranyaba.
    Tobb strategiank is van.
*/

// Visszateresi ertek vector, a fuggveny letrehozza az ures vector, letrehozza fajlvaltozot, megnyitja, feltolti a vectort, es returnoli.
vector<int> beolvas(){
    vector<int> v;
    ifstream f("szamok.txt");
    while(f.good()){
        int a;
        f >> a;
        v.push_back(a);
    }
    return v;
}


// Itt annyi a kulonbseg, hogy a fajlt amibol beolvasni akarunk a fuggveny parameterkent kapja meg. Figyeljunk arra hogy itt mindig referencia szerint adjuk at a fajlt (&).
// Ez azert szebb, mert igy a main donti el hogy melyik fajlbol akar olvasni, igy ha tobb vectort akarunk tobb fajlbol feltolteni pl, akkor igy meg tudjuk csinalni ezzel az egy fuggvennyel.
vector<int> beolvas2(ifstream &f){
    vector<int> v;
    while(f.good()){
        int a;
        f >> a;
        v.push_back(a);
    }
    return v;
}
/*
    Ha mar van egy vectorunk ami fel van toltve adatokkal, akkor tudunk vele minden fele feladatokat csinalni, azokra fuggvenyt irni. 
    Itt vannak az alap teteleink pelda felhasznalasa.
*/
// maximumkereses, a fuggveny parameterkent kap egy vectort, abban keresi a legnagyobb erteku elemet.
int maximum(vector<int> v){
    int mx = v[0];
    for (size_t i = 0; i < v.size(); i++){
        if (mx < v[i]) {
            mx = v[i];
        }
    }
    return mx;
}

int minimum(vector<int> v){
    int mn = v[0];
    for (size_t i = 0; i < v.size(); i++){
        if (mn > v[i]) {
            mn = v[i];
        }
    }
    return mn;
}

// osszegzes tetele, a gyakorlas kedveert itt egy range based for ciklust lathattok, termeszetesen nem muszaj hasznalni. 
int osszeg(vector<int> v){
    int sm = 0;
    for (int szam: v){
        sm += szam;
    }
    return sm;
}

// linearis kereses, figyeljuk meg, hogy fuggvenyek egymast is meg tudjak hivni, (a main is csak egy nagy fuggveny ami meghiv mas fuggvenyeket)
int elsoParosHelye(vector<int> v){
    for (size_t i = 0; i < v.size(); i++){
        if (paros(v[i])) return i;
    }
}

int main(){
    /*
        Nezzunk fuggvenyeket. Mar mindenki almabol felkeltve fujja hogy a fuggvenyeket azert szeretjuk nagyon, mert egyreszt olvashatobba teszik a kodot azzal, hogy bizonyos reszfeladatokat
        kiemelunk, es kulon reszprogramba rakjuk. Masreszt pedig igy ezek a reszprogramok ujrahasznosithatova valnak.
    */
    {
        // Vegyunk egy egyszeru peldat. 
        // Meg szeretnenk tudni, hogy az x szamunk paros-e.
        int x = 5;
        bool p = x % 2 == 0;
        cout << p << endl;
        // meg mondjuk utana meg szeretnenk tudni ugyan ezt y-rol is.
        int y = 4;
        p = y % 2 == 0;
        cout << p << endl;
        // De ennel egy picit egyszerubb es olvashatobb lenne, ha fuggvenyt hasznalnak.
        /*
            Ugorj kerlek az ///TODO sorba a folytatashoz.
        */
       /*
        A fenti kodban a ... eddig szandekos volt, most beszeljunk errol egy kicsit.
        Lesz olyan lehetosegunk is hogy egy fuggvenynek nincs visszateresi erteke (void), olyat is nezunk majd.
        Viszont ha van, akkor azzal valamit kell kezdeni a mainben, " a hivas elott mindenkepp kell alljon valami ".
       */
        // Tehat peldaul a fuggveny eredmenyet taroluk el egy valtozoban.
        p = paros(x);
        // Vagy irassuk ki egybol a valaszt a konzolra.
        cout << paros(x) << endl;
        cout << faktorialis(x) << endl;
        cout << prim(x) << endl;
        cout << hosszabb("almafa", "cica") << endl;
        cout << visszafele("kutya") << endl;
        paros2(x);
    }
    {
        // Fuggvenyek folytatasa
        vector<int> randomszamok = randomfeltolt(5, 10);
        for (int i: randomszamok){
            cout << i << " ";
        }
        cout << endl;

    }
    return 0;
}

    
    
    