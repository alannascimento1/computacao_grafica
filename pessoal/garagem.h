#ifndef GARAGEM_H
#define GARAGEM_H

#include <objeto.h>
#include <Vetor3D.h>

class Garagem : public Objeto
{
public:
    Model3DS* model;
public:
    Garagem();
    Garagem( Vetor3D nt, Vetor3D na, Vetor3D ns );
    void desenha();
};

#endif
