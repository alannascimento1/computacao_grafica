#ifndef PORTEIRA_H
#define PORTEIRA_H

#include <objeto.h>

class Porteira : public Objeto
{
public:
    Model3DS* model;
public:
    Porteira();
    Porteira( Vetor3D nt, Vetor3D na, Vetor3D ns );
    void desenha();
};

#endif // PORTEIRA_H
