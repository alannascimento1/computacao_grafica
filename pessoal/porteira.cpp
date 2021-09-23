#include "porteira.h"

Porteira::Porteira() {
    model = new Model3DS("../3ds/porteira.3DS");
    tipo=4;

}

Porteira::Porteira( Vetor3D nt, Vetor3D na, Vetor3D ns ){
    t = nt;
    a = na;
    s = ns;
    origem = false;
    tipo=4;
    model = new Model3DS("../3ds/porteira.3DS");
}

void Porteira::desenha(){
    glPushMatrix();
        Objeto::desenha();
        glPushMatrix();

            glTranslatef(0,0.8,0);
            glRotatef(-90,1,0,0);
            glScalef(0.005,0.006,0.004);

            model->draw();
        glPopMatrix();

        glPushMatrix();
            if( selecionado ){
                GUI::setColor(1,0,0,0.5);
                GUI::drawBox(-0.2,0,-1.8,
                              0.2,2,1.8);
            }
         glPopMatrix();
    glPopMatrix();
}
