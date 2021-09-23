#ifndef PEDELIMAO_H
#define PEDELIMAO_H

#include <objeto.h>

class Pedelimao : public Objeto
{
public:
    Model3DS* model;
public:
    Pedelimao();
    Pedelimao( Vetor3D nt, Vetor3D na, Vetor3D ns );
    void desenha();
};

#endif
