#ifndef CASARAO_H
#define CASARAO_H

#include <objeto.h>

class Casarao : public Objeto
{
public:
    Model3DS* model;
public:
    Casarao();
    Casarao( Vetor3D nt, Vetor3D na, Vetor3D ns );
    void desenha();
};

#endif // CASARAO_H
