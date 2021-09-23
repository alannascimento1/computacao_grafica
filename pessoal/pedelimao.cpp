#include "pedelimao.h"

Pedelimao::Pedelimao(){
    model = new Model3DS("../3ds/pedelimao.3DS");
    tipo=10;

}

Pedelimao::Pedelimao( Vetor3D nt, Vetor3D na, Vetor3D ns ) {
    t = nt;
    a = na;
    s = ns;
    origem = false;
    tipo=10;
    model = new Model3DS("../3ds/pedelimao.3DS");
}

void Pedelimao::desenha(){
    glPushMatrix();
        Objeto::desenha();
        glPushMatrix();
            glRotatef(-90,1,0,0);
            glScalef(0.01,0.01,0.01);
            model->draw();
        glPopMatrix();

        glPushMatrix();
            if( selecionado ){
                GUI::setColor(1,0,0,0.5);
                GUI::drawBox(-1.2,0,0.5,
                              1.2,3,-0.5);
            }
         glPopMatrix();
    glPopMatrix();
}
