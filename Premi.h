#ifndef PREMI_H
#define PREMI_H
#include <iostream>
using namespace std;

class Premi
{
    public:
        //CONST.
        Premi(); //Pre: -- Post: Constructor per defecte
        //MODI.
        friend ostream & operator<<( ostream & output, const Premi & premi ); //Pre: --; Post: Flux de dades de sortida
        friend istream & operator>>( istream & input, Premi & premi ); //Pre: --; Post Flux de dads d¡entrada

    private:
        string a_nom;
};

#endif // PREMI_H
