#ifndef CARROCA_H
#define CARROCA_H

#include <objeto.h>

class Carroca : public Objeto
{
public:
    Model3DS* model;
public:
    Carroca();
    Carroca( Vetor3D nt, Vetor3D na, Vetor3D ns );
    void desenha();
};

#endif // CARROCA_H
