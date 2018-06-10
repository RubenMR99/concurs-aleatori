#include "Participant.h"
#include <iomanip>
using namespace std;

Participant::Participant()
{
    a_identificador = "ID BUIT";
    a_premi = NULL;
}

//

bool Participant::ha_sigut_premiat() const{
    return a_premi;
}

string Participant::id() const{
    return a_identificador;
}

//

void Participant::premiar_amb(Premi *p){
    a_premi = p;
}

ostream & operator<<( ostream & output, const Participant & participant ){
    output << participant.a_identificador;
    if (participant.a_premi){
        output << " ha guanyat " << *participant.a_premi;
    }
    return output;
}

istream & operator>>( istream & input, Participant & participant ){
    getline(input, participant.a_identificador);
    return input;
}
