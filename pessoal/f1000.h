#ifndef F1000_H
#define F1000_H

#include <objeto.h>

class F1000 : public Objeto
{
public:
    Model3DS* model;
public:
    F1000();
    F1000( Vetor3D nt, Vetor3D na, Vetor3D ns );
    void desenha();
};

#endif
