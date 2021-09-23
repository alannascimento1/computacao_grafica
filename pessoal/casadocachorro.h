#ifndef CASADOCACHORRO_H
#define CASADOCACHORRO_H

#include <objeto.h>
#include <Vetor3D.h>

class Casadocachorro : public Objeto
{
public:
    Model3DS* model;
public:
    Casadocachorro();
    Casadocachorro( Vetor3D nt, Vetor3D na, Vetor3D ns );
    void desenha();
};

#endif
