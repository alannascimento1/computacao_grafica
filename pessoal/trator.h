#ifndef TRATOR_H
#define TRATOR_H

#include <objeto.h>

class Trator : public Objeto
{
public:
    Model3DS* model;
public:
    Trator();
    Trator( Vetor3D nt, Vetor3D na, Vetor3D ns );
    void desenha();
};

#endif
