#include "cachorro.h"

Cachorro::Cachorro(){
    model = new Model3DS("../3ds/cachorro.3ds");
    tipo=14;
}

Cachorro::Cachorro( Vetor3D nt, Vetor3D na, Vetor3D ns ){
    t = nt;
    a = na;
    s = ns;
    origem = false;
    tipo=14;
    model = new Model3DS("../3ds/cachorro.3ds");
}

void Cachorro::desenha(){
    glPushMatrix();
        Objeto::desenha();
        glPushMatrix();
            glTranslatef(0,0,0);
            glRotatef(-90,1,0,0);
            glScalef(0.00016,0.00016,0.00016);
            model->draw();
        glPopMatrix();

        glPushMatrix();
            if( selecionado ){
                GUI::setColor(1,0,0,0.5);
                GUI::drawBox(-0.7,-0.5,-0.5,
                              0.7, 1,0.5);
            }
         glPopMatrix();
    glPopMatrix();
}
