#include "jardim.h"

Jardim::Jardim() {
    model = new Model3DS("../3ds/jardim.3DS");
    tipo=9;

}

Jardim::Jardim( Vetor3D nt, Vetor3D na, Vetor3D ns ){
    t = nt;
    a = na;
    s = ns;
    origem = false;
    tipo=9;
    model = new Model3DS("../3ds/jardim.3DS");
}

void Jardim::desenha(){
    glPushMatrix();
        Objeto::desenha();
        glPushMatrix();
            glTranslatef(-5.5,0.9,0);
            glRotatef(-90,1,0,0);
            glScalef(0.1,0.05,0.07);

            model->draw();
        glPopMatrix();

        glPushMatrix();
            if( selecionado ){
                GUI::setColor(1,0,0,0.5);
                GUI::drawBox(0,0,0.5,
                             7,2,-0.5);
            }
         glPopMatrix();
    glPopMatrix();
}
