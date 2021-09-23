#include "arvore.h"

Arvore::Arvore(){
    model = new Model3DS("../3ds/arvore.3DS");
    tipo=7;
}

Arvore::Arvore( Vetor3D nt, Vetor3D na, Vetor3D ns ){
    t = nt;
    a = na;
    s = ns;
    tipo=7;
    origem = false;
    model = new Model3DS("../3ds/arvore.3DS");
}

void Arvore::desenha(){
    glPushMatrix();
        Objeto::desenha();
        glPushMatrix();
            glTranslatef(0,1.6,0);
            glRotatef(-90,1,0,0);
            glScalef(0.012,0.012,0.012);
            model->draw();
        glPopMatrix();

        glPushMatrix();
            if( selecionado ){
                GUI::setColor(1,0,0,0.5);
                GUI::drawBox(-2,-0.5,-2,
                              2, 3.5,2);
            }
         glPopMatrix();
    glPopMatrix();
}
