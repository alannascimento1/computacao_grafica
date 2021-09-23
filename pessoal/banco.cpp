#include "banco.h"

Banco::Banco(){
    model = new Model3DS("../3ds/banco.3DS");
    tipo=1;
}

Banco::Banco( Vetor3D nt, Vetor3D na, Vetor3D ns ){
    t = nt;
    a = na;
    s = ns;
    origem = false;
    tipo=1;
    model = new Model3DS("../3ds/banco.3DS");
}

void Banco::desenha(){
    glPushMatrix();
        Objeto::desenha();
        glPushMatrix();
            glTranslatef(0,0.5,0);
            glRotatef(-90,1,0,0);
            glScalef(0.0015,0.0015,0.0015);
            model->draw();
        glPopMatrix();

        glPushMatrix();
            if( selecionado ){
                GUI::setColor(1,0,0,0.5);
                GUI::drawBox(-1.2,-0.5,-0.5,
                              1.2, 1,0.5);
            }
         glPopMatrix();
    glPopMatrix();
}
