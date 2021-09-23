#ifndef CERCA_H
#define CERCA_H

#include <objeto.h>

class Cerca : public Objeto
{
public:
    Model3DS* model;
public:
    Cerca();
    Cerca( Vetor3D nt, Vetor3D na, Vetor3D ns );
    void desenha();
};

#endif // CERCA_H
