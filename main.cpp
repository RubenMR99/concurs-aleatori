/***** ESPECIFICACIÓ
AUTOR: RUBEN MORENO ROMERO
PROBLEMA: Entrant dades de persones i de premis per teclat fer un concurs.
ENTRADA: Dades personals (Nom/NºDorsal) i Dades dels premis (Nom del premi - Numero del premi)
SORTIDA: Surt per pantalla qui ha guanyat que.
VERSIÓ: 0.1 10/06/18
*****/
#include <fstream>
#include <iomanip>
#include <iostream>

#include "Concurs.h"

#ifdef _WIN32
    #include<windows.h>
#endif // _WIN32
using namespace std;

void fer_minuscula(char &caracter){
    //PRE: --; POST: Retorna el caracter en forma de majuscula
    if (caracter <= 'Z' and caracter >= 'A'){
        caracter -= ('A' - 'a');
    }
}

int main() {
    #ifdef _WIN32
    SetConsoleOutputCP(1252);
    SetConsoleCP(1252);
    #endif

    cout << "BENVINGUT AL PCR (Programa Concurs Rapid)" << endl
    << "SI US PLAU, INTRODUIU 's' SI VOLEU INTRODUIR DADES MANUALMENT" << endl
    << "INTRODUIU 'f' SI VOLEU OBRIR LES DADES DESDE UN FITXER" << endl;
    char opcio;
    do{
        cin >> opcio;
        fer_minuscula(opcio);
        if (opcio != 's' and opcio != 'f'){
            cout << "ERROR, no pots introduir '" << opcio << "', només pots introduir 'f' o 's'" << endl;
        }
    }while(opcio != 's' and opcio != 'f');
    if (opcio == 'f'){
        cout << "HAS ESCOLLIT ENTRAR DESDE FITXER" << endl
        << "SI US PLAU, INTRODUIU EL NOM DEL FITXER ON S'UBIQUEN LES DADES DELS PARTICIPANTS" << endl
        << "(Arxiu tipus .txt , amb dades separades per linees amb l'identificador a cada linea)" << endl;
        string nom_fitxer;
        ifstream fitxer_participants;
        do{
            cin >> nom_fitxer;
            fitxer_participants.open(nom_fitxer.c_str());
            if (! fitxer_participants.is_open()){
                cout << "NOM INCORRECTE" << endl
                << "COMPROVA QUE L'ARXIU ES TROBA AL MATEIX DIRECTORI" << endl;
            }
        }while(not fitxer_participants.is_open());
        Concurs concurs(fitxer_participants);
        concurs.realitza_concurs();
    }
    /*else{
        ;
    }*/
    return 0;
}
