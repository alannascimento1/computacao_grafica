#ifndef CATAVENTO_H
#define CATAVENTO_H

#include <objeto.h>
#include <Vetor3D.h>

class Catavento : public Objeto
{
public:
    int rot=1;
    Model3DS* model;
public:
    Catavento();
    Catavento( Vetor3D nt, Vetor3D na, Vetor3D ns );
    void desenha();
};

#endif
