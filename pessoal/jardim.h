#ifndef JARDIM_H
#define JARDIM_H

#include <objeto.h>

class Jardim : public Objeto
{
public:
    Model3DS* model;
    Jardim();
    Jardim( Vetor3D nt, Vetor3D na, Vetor3D ns );
    void desenha();
};

#endif
