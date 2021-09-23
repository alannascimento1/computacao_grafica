#ifndef ESCORREGADOR_H
#define ESCORREGADOR_H

#include <objeto.h>
#include <Vetor3D.h>

class Escorregador : public Objeto
{
public:
    Model3DS* model;
public:
    Escorregador();
    Escorregador( Vetor3D nt, Vetor3D na, Vetor3D ns );
    void desenha();
};

#endif
