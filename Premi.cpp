#include "Premi.h"
using namespace std;

Premi::Premi()
{
    //ctor
}

//

//
ostream & operator<<( ostream & output, const Premi & premi ){
    output << premi.a_nom;
    return output;
}

istream & operator>>( istream & input, Premi & premi ){
    getline(input, premi.a_nom);
    return input;
}
