#ifndef CONCURS_H
#define CONCURS_H
#include <iostream>
#include <fstream>
#include <iomanip>

#include "Premi.h"
#include "Participant.h"

using namespace std;

class Concurs
{
    public:
        Concurs();
        Concurs(ifstream &fitxer);
        void realitza_concurs();
        int generar_numero(int minim, int maxim);

    protected:

    private:
        //METO. PRIV.
        bool ha_sortit(int numero) ;
        bool i_ha_sortit(unsigned n, int numero, int esq, int dre);
        void afegir_numero(int numero);
        //ATRIBUTS
        struct Vector_participants{
            Participant taula[1000];
            int n;
        };
        struct Vector_premis{
            Premi taula[1000];
            int n;
        };
        struct Vector_naturals{
            int taula[1000];
            int n;
        };
        Vector_participants a_participants;
        Vector_premis a_premis;
        Vector_naturals numeros_anteriors;
        unsigned a_x0;
};

#endif // CONCURS_H
