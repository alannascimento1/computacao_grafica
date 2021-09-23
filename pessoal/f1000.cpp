#include "f1000.h"

F1000::F1000() {
    model = new Model3DS("../3ds/f1000.3DS");
    tipo=11;

}

F1000::F1000( Vetor3D nt, Vetor3D na, Vetor3D ns ){
    t = nt;
    a = na;
    s = ns;
    tipo=11;
    origem = false;
    model = new Model3DS("../3ds/f1000.3DS");
}

void F1000::desenha(){
    glPushMatrix();
        Objeto::desenha();
        glPushMatrix();
            glRotatef(-90,1,0,0);
            glScalef(0.020,0.020,0.020);
            model->draw();
        glPopMatrix();

        glPushMatrix();
            if( selecionado ){
                GUI::setColor(1,0,0,0.5);
                GUI::drawBox(-1.2,0,-2,
                             1.2 ,2, 2);
            }
         glPopMatrix();
    glPopMatrix();
}
