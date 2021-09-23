#ifndef BANCO_H
#define BANCO_H

#include <objeto.h>

class Banco : public Objeto
{
public:
    Model3DS* model;
    Banco();
    Banco( Vetor3D nt, Vetor3D na, Vetor3D ns );
    void desenha();
};

#endif // BANCO_H
