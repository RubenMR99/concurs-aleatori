#ifndef PARTICIPANT_H
#define PARTICIPANT_H
#include <iostream>
#include "Premi.h"

using namespace std;

class Participant
{
    public:
        //CONST.
        Participant(); //Pre: --; Post: Inicialitza el identificador a "ID BUIT" i el punter a premi a NULL
        //CONSU.
        bool ha_sigut_premiat() const; //Pre --; Post: Retorna si el participant actual ha sigut premiat
        string id() const; //Pre: --; Post: Retorna l'identificador
        //MODI.
        void premiar_amb(Premi *p); //Pre --; Premia a participant amb p
        friend ostream & operator<<( ostream & output, const Participant & participant ); //Pre: --; Post: Flux de dades de sortida
        friend istream & operator>>( istream & input, Participant & participant ); //Pre: --; Post Flux de dads d¡entrada

    private:
        //Atributs
        string a_identificador;
        Premi *a_premi;
};

#endif // PARTICIPANT_H
