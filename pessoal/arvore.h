#ifndef ARVORE_H
#define ARVORE_H

#include <objeto.h>

class Arvore : public Objeto
{
public:
    Model3DS* model;
    Arvore();
    Arvore( Vetor3D nt, Vetor3D na, Vetor3D ns );
    void desenha();
};

#endif // ARVORE_H
