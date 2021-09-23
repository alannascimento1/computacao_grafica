#include "carroca.h"

Carroca::Carroca() {
    model = new Model3DS("../3ds/carroca.3DS");
    tipo=5;

}

Carroca::Carroca( Vetor3D nt, Vetor3D na, Vetor3D ns ){
    t = nt;
    a = na;
    s = ns;
    origem = false;
    tipo=5;
    model = new Model3DS("../3ds/carroca.3DS");
}

void Carroca::desenha(){
    glPushMatrix();
        Objeto::desenha();
        glPushMatrix();
            glRotatef(-90,1,0,0);
            glScalef(0.2,0.2,0.2);
            model->draw();
        glPopMatrix();

        glPushMatrix();
            if( selecionado ){
                GUI::setColor(1,0,0,0.5);
                GUI::drawBox(-1.2,0,0.5,1.2,1,-0.5);
            }
         glPopMatrix();
    glPopMatrix();
}
