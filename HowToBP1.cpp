#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <math.h>
#include <time.h>

using namespace std;

int main(){
    /*
                        !Itt kezd az olvasást!
        Ez itt a "mi az amit tudnom kell vizsgára?" című C++ gyorstalpaló
    */
    /// Alap változók
    int a;    // Egész szám
    float f;  // Tört szám
    double d; // Mégtörtebb szám (2x pontosságú a floathoz képest)
    bool b;   // Logikai (true vagy false (1 v. 0))
    char c;   // Karakter
    string s; // Szöveg
    /*
        Ezeket már plangban is ismertük.
    */
    /// Alap változók használata
    // Értékadás
    a = 5;
    f = 2.7182818;
    d = 3.141592653589793; // valos pontossagok
    b = true;
    c = 'k';    // Karaktert mindig a ' ' jelöli!
    s = "cica"; // Szöveget mindig a " " jelöli!
    {
    // Műveletek
    int x = 5;
    int y = 3;
    cout << x + y << " " << x - y << " " << x * y << endl; // 8, 2, 15. Eddig nem esünk hasra azért.
    cout << x / y << endl;                                 // 1! Itt már figyeljünk! 2 egész számot /-el osztva levágja a tört részt
    /*
        Jó Szilva de mivan ha én mindenképp tört eredményt akarok kapni két egész szám osztásánál?
        Vagy átmásolod az egy változódat egy float/double tÍpusú változóba,
        vagy az alábbi módon forceolod:
    */
    cout << float(x) / y << endl; // 1.66667, természetesen mindegy melyik számot konvertálod floattá.
    /*
        Ha két számot, nem változót, vagy egy változót és egy számot akarsz hasonló módon osztani, vagy ugyan így a változód konvertálod, vagy:
    */
    cout << x / 3.0 << endl;
    // Mi van még?
    cout << x % y << endl; // 2, avagy a MOD, avagy az osztási maradékot adja meg.
    // Figyeljunk, hatvanyozas nem ^ hanem:
    cout << pow(x, 2) << endl; // mit, mire emelunk.
    cout << sqrt(x) << endl; // van gyokvonasunk is, de persze pow(x, 0.5) ugyan ugy jo
    // floatok, doubleok intuitívan működnek, ott nincs természetesen egész vagy maradékos osztás.
    // boolokkal nem végzünk műveleteket, bool természetesen logikai kifejezés eredménye lehet.
    b = 5 > 1 && (x == 3 || c == 'k'); // Igaz, && jelöli az ÉS-t, || jelöli a VAGY-ot
    }
    // karakterekkel sem nagyon...
    /*
        Legalábbis semmi olyat nem csinál mint amire intuitívan gondolnátok, már amennyire bármiféle karakter összeadás kivonás osztás szorzás intuitív lehet...
        Nem fogtok hibát kapni, mert létezik a művelet.
        https://www.asciitable.com/
        Minden karakternek van egy ASCII kódja, tehát megfeleltethető egy számnak. Bármiféle karakterek közötti aritmetikai művelet ezeknek az eredménye.
        Ez nem mindig rossz, vagy félrevezető...
    */
    // Vizsgáljuk meg hogy egy adott karakterről hogy, hogy nagybetű vagy kisbetű.
    { // SIDENOTE: Ha ilyet láttok ebben a demo kódban ne foglalkozzatok vele, nekem kell, így a változók csak a bajuszon belül léteznek, és nem fogyok ki a változónevekből
        char kis = 'a';
        bool tmp;
        tmp = (96 < kis && kis < 123); // Kisvizsgalat
        cout << tmp << endl;           // Igaz
        tmp = (64 < kis && kis < 91);  // Nagyvizsgalat
        cout << tmp << endl;           // Termeszetesen hamis
        // Termeszetesen erre leteznek a fuggvenyek is.
        cout << islower(kis) << endl;
        cout << isupper(kis) << endl;
        // Kis nagy konverziot is lehet csinalni az ASCII kodok segitsegevel, de termeszetesen arra is van fuggveny.
        char nagy;
        nagy = kis - 32;
        cout << nagy << endl;
        nagy = toupper(kis);
        cout << nagy << endl; // Es vica versa
        // Figyeljetek oda arra, hogy ezeknek a muveleteknek SZAM az eredmenye.
        cout << kis - 32 << " " << toupper(kis) << endl; // 65 lesz mindket esetben. Vagy taroljatok el karakter valtozoban eloszor az eredmenyt, vagy forceoljatok konverziot.
        cout << char(kis - 32) << " " << char(toupper(kis)) << endl;
        /*
             Minden egyeb mokat az ASCII-val az olvasora bizok.
        */
    }
    {
        /*
            Nezzunk stringeket, ugyerzem veluk sokszor van bajotok <3
        */
        string szoveg;
        char karakter;
        // Itt mar nem asciizunk. Lehet osszeadni szoveget szoveggel vagy karakterrel, avagy konkatenacio
        szoveg = "alma";
        cout << szoveg + "fa" << endl; // Almafa
        karakter = 'f';
        cout << szoveg + karakter + 'a' << endl;
        // A stringek egyes karaktereit [] -el tudjuk elerni.
        cout << szoveg[0] << endl; // a
        // Termeszetesen 0-tol indexelunk.
        // a stringeknek van hossza.
        cout << szoveg.length() << endl; // 4
        // Igy pl az utolso karakter
        cout << szoveg[szoveg.length() - 1] << endl; //Ebben az esetben ez is a...
        // Nagyon fontos muvelet meg a substr, szövegrészletet tudunk lekérni a stringből
        cout << szoveg.substr(1, 2) << endl; // lm, figyeljunk oda, hogy ez mashogy mukodik mint plangban! 1 a kezdo index, 2 a szoveg reszlet HOSSZA!
        // Fontos meg a find, stringben tudjuk egy adott karakter vagy szoveg elso elofordulasat megadni. Szoveg keresese esetben a szoveg kezdo indexet kapjuk.
        cout << szoveg.find('m') << ", " << szoveg.find("lma"); // 2, 1
        // Mi van ha nincs meg a stringben a keresett karakter / szoveg?
        cout << szoveg.find('c') << endl; // valami undi nagy szam.
        // Ezt ki tudjuk hasznalni.
        bool vane = szoveg.find('c') < szoveg.length();
        cout << vane << endl; // termeszetesen 0 avagy false
        // Ennel picit elegansabb az string::npos, de el lehet engedni.
        vane = szoveg.find('c') != string::npos; 
        cout << vane << endl; // Ugyan ugy false
    }
    /*
        Na eddig semmi izgi nem volt.
        Nezzuk az elagazasokat es ciklusokat.
    */

    // Azt mondjuk hogy
    {
    int x = 5;
    if (x == 5) {
        cout << "x egyenlo 5-el!" << endl;
    } 
    // Termeszetesen barmilyen feltetel felirhato, vagy 
    bool feltetel = x==5;
    if (feltetel) {
        cout << "x egyenlo 5-el!" << endl;
    }
    // tehat bool ertekehez kozvetlenul is kothetjuk a futast, nem kell feltetel == true.
    // Ezt a dragat kiegeszithetjuk egy else aggal is ami termeszetesen akkor fut le, ha a feltetel NEM teljesult.
    if (feltetel) {
        cout << "x egyenlo 5-el!" << endl;
    } else {
        cout << "x nem egyenlo 5-el" << endl;
    }
    // Kb ennyi is volt.
    }
    // ciklusok! 3 fele van.
    srand(time(NULL)); // biztositjuk hogy tenyleg random legyen a random szamunk.
    int kocka = -1;
    while (kocka != 6) {
        kocka = rand() % 6 + 1; // ugye a rand alapbol 0tol 5ig valasztana igy egy szamot, a + 1 el eltoljuk 1tol 6igra
        cout << kocka << " ";
    } // Addig dobunk a kockaval amig nem sikerul hatost dobni. Tehat addig fut a ciklus amig teljesul a feltetel
    cout << endl;
    // Ugyan ez a while ciklus lehet hatultesztelus is, amivel biztositani tudjuk, hogy legalabb egyszer fusson le a ciklus, akkor is mar alapbol hamis a feltetelunk.
    kocka = 6;
    do {
        kocka = rand() % 6 + 1;
        cout << kocka << " ";
    } while (kocka != 6);
    cout << endl;
    /*
        Figyeljuk meg hogy biztosan 6 volt alapbol a kocka, de megis dobtunk 1-et fixen, meg amennyit meg kellett hogy megint 6os legyen.
        Nem gyakran hasznalunk hatultesztelo ciklust, de neha hasznos lehet (ritkan)
    */
    // Annal tobbet hasznalunk for ciklust. Szeretjuk mert adott szamu alkalommal fog lefutni, es van ciklusvaltozonk.
    for (int i = 0; i < 4; i++){
        cout << "Az i erteke: " << i << endl;
    } 
    // Ha egymasba szeretnenk rakni 2 for ciklust, figyeljunk a ciklus valtozokra!
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            cout << "Az i, j erteke: " << i << ", " << j << endl;
        }
    }
    // Es nagyabol ennyik voltak a ciklusok is.
    /*
        Meg mindig nem mondtam semmi izgalmasat, de olvasmanynak mar kezd jo lenni :D
        Nezzuk meg a primitiv (statikus) tomboket
    */
    // Leteznek. Elore megmondjuk hany elemuk lesz, es ez innentol fix. Nem szeretjuk oket igazan
    int t[3];
    t[0] = 1;
    t[1] = 2;
    t[2] = 3;
    for (int i = 0; i < 3; i++){
        cout << t[i] << ", ";
    }
    cout << endl;
    // Es nagyjabol ennyi. Lepjunk a sokkal izgibb vectorokra 
    /*
                                    vector<type> v;
            A vectornak van egy "altipusa" tehat a <> belul megmondjuk milyen elemeket fog, kell tarolnia. 
            A vector mindig homogen, tehat csak egy tipusu elemei lehetnek.
    */
    {
    // Nezzunk egy egyszeru intes peldat.
    vector<int> v; // Letrehozzuk uresen. 
    // Van neki egy merete amit le tudunk kerni, sokat fogjuk hasznalni.
    cout << "A vector merete: " << v.size() << endl; // termeszetesen 0
    //  Tudunk vectort meg 3 masik modon is inicilalizalni, ugy hogy ne legyen ures.
    {
        vector<int> tmp(10); // Ekkor 10 ures elemmel jon letre. 
        cout << "A vector merete: " << tmp.size() << endl; // 10. De figyeljunk ra hogy ezek ures elemek, ne nagyon keregessuk le oket..
    } 
    {
        vector<int> tmp(10,2); // Ekkor 10 eleme lesz, mindegyik erteket 2
        //Nem iratom ki, higyjetek el
    }
    {
        vector<int> tmp = {2, 3, 5 ,7}; // Ekkor pontosan ezekkel az elemekkel jon letre.
    }
    // A vectorba tudunk rakni elemeket a push_back tagfuggvennyel.
    v.push_back(1);
    // Ilyenkor az elemeg mindig a vector vegere kerulnek, hozzacsapjuk a vegere.
    // Mostmar van 0. eleme, tombhoz hasonloan el is tudjuk erni.
    cout << v[0] << endl; // 1
    // figyeljunk oda, ha veletlen olyan elemet szeretnetek lekerni a vectorbol ami nem letezek, az error.
    /*
        Ez az ugynevezett tulindexeles.
        cout << v[1] << endl; 
        Meghalna a kod, aki nem hiszi vegye ki kommentbol
    */
    // Elsokorben nagyjabol ennyi a vectornak is a hasznalata.
    // Meg van egy ket tagfuggveny ami hasznos lehet, ugyhogy megmutatom, de nem feltetlen kell.
    // Rakunk bele par elemet..
    v.push_back(2);
    v.push_back(3);
    // Tudunk torolni elemet a vector vegerol.
    cout << v[v.size() - 1] << endl; // Utolso elem, termeszetesen 3
    v.pop_back(); 
    cout << v[v.size() - 1] << endl; // Utolso elem igy mar a 2-es lesz.
    // Van egy erase fuggvenyunk is, OVATOSAN
    // Ezzel index alapjan tudunk torolni
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);
    cout << v[2] << endl; // A kettes indexu elem a 4
    v.erase(v.begin() + 2); // Ilyen elsore furcsa megadasi modja van, mindig v.begin() + valamennyi, valamennyi, hogy melyik indexu elemet szeretnetek torolni, tehat nem azt hogy hanyadikat
    cout << v[2] << endl; // A torolt elem utan visszatolodnak egyet az elemek, tehat termeszetesen lyuk nem marad. 5
    /*
        Nagyon gyakori eset, hogy a vector elemein vegig akarunk menni, vagy valami szamitas, feladatmegoldas miatt, vagy szimplan mert ki akarjuk irtani az elemeit, 
        ezt egy egyszeru for ciklussal tesszuk meg.
    */
    for (int i = 0; i < v.size(); i++){ // az i bejar minden erteket 0-tol a vector mereteig. Az i mindig a vector elemeinek indexe lesz.
        cout << v[i] << " ";
    }
    // Ha egy icipicit elegansabbak akarunk lenni, akkor int helyett hasznalhatunk size_t-t. 
    // A size_t tulajdonkeppen egy elojel nelkuli integer, unsigned int, tehát nem lehet negatív. Ez azért szép, mert a vector indexei sem lehetnek negatívak.
    for (size_t i = 0; i < v.size(); i++){ 
        //...
    }
    /*
        Letezek meg a vectorok bejarasara egy masik modszer is, az ugynevezett range based for ciklus. Ez sokkal kevesebb gepelessel jar, de kicsit mas az eredmeny.
    */
    for (int elem: v){ // int az elem, "a ciklus valtozo", nem a vector indexeit fogja jelenti, hanem konkretan minden iteracioban a vector egy elemenek erteket veszi fel.
        cout << elem << " "; 
    }
    /*
        Tehat pl ha az lenne a feladat hogy mondjuk meg hanyadik elem a vectorban az 5, akkor ez a fajta ciklus annyira nem lenne jo megkozelites, hiszen 
        hiaba talaljuk meg az 5os erteku elemet, nem tudjuk melyik index tartozik hozza.
        Tovabba az elem csak egy masolata a vector valodi elemenek, tehat ha pl itt azt mondjuk elem++; utana az eredeti vector eredeti ertekei nem valtoznak.
        Ha azt akarjuk hogy a vector tenylegesen elemeinek valtozzon az erteke akkor vagy hasznaljunk sima forcikulst, vagy
    */
    for (int &elem: v){ // rakjunk az elem ele egy &-t, igy referencia szerint atadva. (referencia vs ertek szerinti atadast lasd a masodik reszben)
        elem++;
    }
    }
    /*
        Ezzel mar meg is tanultatok vectorokat hasznalni, sot kicsit jobban is kelletenel. Majd persze a structnal kicsit meg cifrazzuk, de az mar semmi.
        Eddig minden adatot manualisan irtunk bele a kodba, most adjon nekunk a felhasznalo bemenetet.
        Erre igazabol 2 modunk van. 
        cin es ifstream
    */
    // Nezzunk egy cin-t. O ugye a konzol, eddig mindent oda irattunk ki, szoval remelem mindenki megtalalta mar.
    // Onnan be is kerhetunk adatot
    {
        int x;
        // cin >> x;
        cout << "A beolvasott x erteke: " << x << endl; // Itt nem tudom megjosolni a kimenetet :c
        // Termeszetesn barmilyen mas alap tipusu valtozot ugyan igy be lehet olvasni
        // A stringre egy pillantast viszont megeri vetni.
        string szoveg;
        // cin >> szoveg; // Ezzel a fajta beolvasassal az elso whitespace-ig olvas! (space, tabulator, enter)
        cout << "A beolvasott szoveg: " << szoveg << endl; // Teszteljetek nyugodtan
        // Ha teljes sort akarunk olvasni akkor
        // getline(cin, szoveg); // Honnan hova, honnan hova
        cout << "A beolvasott szoveg: " << szoveg << endl; //
    }
    /*
        Kb ennyi volt a cin.
    */
    // vectort ha cinrol szeretnenk feltolteni, akkor ciklussal, elemenkent, valahogy igy pl
    {
        vector<int> v;
        for (int i = 0; i < 5; i++){
            int x;
            // cin >> x;
            v.push_back(x);
        }
        // Igy 5 elemet olvasunk be konzolrol, es belepakoljuk oket a vectorba.
        // Vagy esetleg valami ilyet lehet meg..
        while (v.size() < 10) {
            int x; 
            // cin >> x;
            v.push_back(x);
        }
        // Itt ugye fugg a vector alap elemszamatol, hogy hanyszor fog lefutni, mindig fix 10ig tolti a vectort.
    }
    /*
        Lehet meg igy ugy trukkozni ezzel, de nem jellemzo ezek hasznalata..
        Nezzunk ifstreamet, a valosagban kb minden ott fog tortetnni.
    */
    {
        ifstream f; // Letrehozzuk a fajlvaltozot.
        f.open("adatok.txt"); // megnyitjuk a fizikai fajlunkat
    }
    {
        ifstream f("adatok.txt"); // Vagy megcsinaljuk a kettot egyben es sporolunk a billentyuleutesekkel
        // Innentol fogva ez egy ugyan olyan bemenet, mint a konzol, ugyan ugy tudunk belole olvasni, ugyan azokkal a szabalyokkal.
        int x;
        f >> x;
        string sz;
        f >> sz;
        // vagy
        getline(f,sz);
        // stb...
        // Nagyon fontos ez szeretjuk a fajlokban, hogy tudjak magukrol meddig tartananak, lehet e meg olvasni beloluk. ez az f.good() fuggveny. Eredmenye true vagy false, attol fuggoen hogy 
        // "jo e meg", tart e meg a fajl. 
        // Klasszikusan while ciklus feltetele kent szoktuk hasznalni, addig olvasunk a fajbol amig csak lehet.
        while(f.good()){
            f >> x; // a fileban space elvalasztva vannak szamok, ahogy eddig is tapasztaltuk, amikor szamot olvasunk azt a program automatikusan spacetol spaceig olvassa.
            //adat feldolgozasa
        }
    }
    {
        /*
            Az ifstream parja az ofstream, vagyis a kimeneti fajl. Hasznalata pont mint a konzolrairatas.
        */
       ofstream f("kimenet.txt");
       f << "Hello World!";
    }
    /*
        Es nagyjabol ennyi is volt ez a szakasz is.
    */

    
    return 0;
}