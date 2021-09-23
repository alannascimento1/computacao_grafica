#include "escorregador.h"

Escorregador::Escorregador(){
    model = new Model3DS("../3ds/escorregador.3DS");
    tipo=8;

}

Escorregador::Escorregador( Vetor3D nt, Vetor3D na, Vetor3D ns ){
    t = nt;
    a = na;
    s = ns;
    tipo=8;
    origem = false;
    model = new Model3DS("../3ds/escorregador.3DS");
}

void Escorregador::desenha(){
    glPushMatrix();
        Objeto::desenha();
        glPushMatrix();
            glTranslatef(0,1.6,0);
            glRotatef(-90,1,0,0);
            glScalef(0.0018,0.0018,0.0018);
            model->draw();
        glPopMatrix();

        glPushMatrix();
            if( selecionado ){
                GUI::setColor(1,0,0,0.5);
                GUI::drawBox(-1.3,0,-1,
                              1.3, 3.5,1);
            }
         glPopMatrix();
    glPopMatrix();
}
