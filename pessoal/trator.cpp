#include "trator.h"

Trator::Trator() {
    model = new Model3DS("../3ds/trator.3DS");
    tipo=6;
}

Trator::Trator( Vetor3D nt, Vetor3D na, Vetor3D ns ) {
    t = nt;
    a = na;
    s = ns;
    origem = false;
    tipo=6;
    model = new Model3DS("../3ds/trator.3DS");
}

void Trator::desenha(){
    glPushMatrix();
        Objeto::desenha();
        glPushMatrix();
            glRotatef(-90,1,0,0);
            glScalef(0.021,0.021,0.021);
            model->draw();
        glPopMatrix();

        glPushMatrix();
            if( selecionado ){
                GUI::setColor(1,0,0,0.5);
                GUI::drawBox(-1.2,0,-2,1.5,1.5,2);
            }
         glPopMatrix();
    glPopMatrix();
}
