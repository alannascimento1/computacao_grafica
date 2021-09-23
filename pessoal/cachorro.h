#ifndef CACHORRO_H
#define CACHORRO_H

#include <objeto.h>
#include <Vetor3D.h>

class Cachorro : public Objeto
{
public:
    Model3DS* model;
public:
    Cachorro();
    Cachorro( Vetor3D nt, Vetor3D na, Vetor3D ns );
    void desenha();
};

#endif
