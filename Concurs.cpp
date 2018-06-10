#include "Concurs.h"
#include <cstdlib>

int const A = 1103515245, C = 12345, M = 32767 ;
using namespace std;

Concurs::Concurs(){
    a_participants.n = a_premis.n = numeros_anteriors.n = a_x0 = 0;
}

Concurs::Concurs(ifstream &fitxer){
    //cout << "llegint fixer";
    a_participants.n = a_premis.n = numeros_anteriors.n = a_x0 = 0;
    do{
        fitxer >> a_participants.taula[a_participants.n];
        //cout << a_participants.taula[a_participants.n] << endl;
        if (not fitxer.eof()) a_participants.n ++;
    } while (not fitxer.eof());
    //cout << "FITXER LLEGIT!" << endl;
    fitxer.close();

    string nom_fitxer_premis;
    ifstream fitxer_premis;
    cout << "INTRODUEIX EL NOM DEL FITXER ON ES TROBEN ELS PREMIS" <<
    "(Arxiu .txt amb els premis separats per salts de linies)" << endl;

    do{
            cin >> nom_fitxer_premis;
            fitxer_premis.open(nom_fitxer_premis.c_str());
            if (! fitxer_premis.is_open()){
                cout << "NOM INCORRECTE" << endl
                << "COMPROVA QUE L'ARXIU ES TROBA AL MATEIX DIRECTORI I/O INTRODUEIXES BÉ EL NOM" << endl;
            }
        }while(not fitxer_premis.is_open());
   // cout << "FITXER OBERT!" << endl;
    do{
        fitxer_premis >> a_premis.taula[a_premis.n];
        //cout << a_premis.taula[a_premis.n] << endl;
        if (not fitxer_premis.eof()) a_premis.n ++;
    } while (not fitxer_premis.eof());

    //cout << endl << "HA ACABAT LA GESTIO D'ARXIUS" << endl << endl;
}

void Concurs::realitza_concurs(){
    cout << "ESCULL UNA LLAVOR PER L'ALEATORIETAT" << endl
    << "(Pot ser un numero qualsevol)" << endl;
    cin >> a_x0;
    cout << "Llavor guardada!" << endl;
    for (int i = 0; i < a_premis.n; i ++){
        int numero_pr = generar_numero(0,a_participants.n);
        cout << i << " NUMERO PREMIAT : " << numero_pr << endl;
        a_participants.taula[numero_pr].premiar_amb(&a_premis.taula[i]);
    }
    ofstream fitxer_sortida("resultat.txt");
    for (int i = 0; i < a_participants.n; i ++){
       if (a_participants.taula[i].ha_sigut_premiat()) fitxer_sortida << i << " - " << a_participants.taula[i] << endl;
    }
}

int Concurs::generar_numero(int minim, int maxim){
    int xn = (A * a_x0 + C) % M;
    a_x0 = xn;
    xn = xn % maxim + minim;
    if (ha_sortit(xn)){
        xn = generar_numero(minim, maxim);
    }
    else afegir_numero(xn);
    return xn;
}

bool Concurs::ha_sortit(int numero) {
    return i_ha_sortit(numeros_anteriors.n, numero, 0, numeros_anteriors.n);
}

bool Concurs::i_ha_sortit(unsigned n, int numero, int esq, int dre){
    bool trobat = false;
    int mig;
    if (esq>dre) trobat = false;
    else {
        mig = (esq+dre)/2;
        if (numeros_anteriors.taula[mig] == numero) trobat = true;
        else if (numero < numeros_anteriors.taula[mig]) trobat = i_ha_sortit(n,numero,esq,mig-1);
        else trobat = i_ha_sortit(n,numero,mig+1,dre);
    }
    return trobat;
}

void Concurs::afegir_numero(int numero){
    int posicio = 0;
    bool trobat = false;
    while (posicio < numeros_anteriors.n and not trobat){
        if (numeros_anteriors.taula[posicio + 1] > numero) trobat = true;
        else posicio ++;
    }
    int i = numeros_anteriors.n;
    while(i > 0 and numero < numeros_anteriors.taula[i-1]) {
        numeros_anteriors.taula[i] = numeros_anteriors.taula[i-1];
        i--;
    }
    numeros_anteriors.taula[i] = numero;
    numeros_anteriors.n ++;
}
