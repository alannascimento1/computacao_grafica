#include "casarao.h"

Casarao::Casarao() {
    model = new Model3DS("../3ds/casarao.3DS");
    tipo=2;

}

Casarao::Casarao( Vetor3D nt, Vetor3D na, Vetor3D ns ){
    t = nt;
    a = na;
    s = ns;
    origem = false;
    tipo=2;
    model = new Model3DS("../3ds/casarao.3DS");
}

void Casarao::desenha(){
    glPushMatrix();
        Objeto::desenha();
        glPushMatrix();
            glRotatef(-90,1,0,0);
            glScalef(0.004,
                     0.004,
                     0.004);
            model->draw();
        glPopMatrix();

        glPushMatrix();
            if( selecionado ){
                GUI::setColor(1,0,0,0.5);
                GUI::drawBox(-3,0,-3,
                             3,4,2);
            }
         glPopMatrix();
    glPopMatrix();
}
