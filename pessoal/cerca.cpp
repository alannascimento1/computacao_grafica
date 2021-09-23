#include "cerca.h"

Cerca::Cerca() {
    model = new Model3DS("../3ds/cerca.3DS");
    tipo=3;

}

Cerca::Cerca( Vetor3D nt, Vetor3D na, Vetor3D ns ){
    t = nt;
    a = na;
    s = ns;
    origem = false;
    tipo=3;
    model = new Model3DS("../3ds/cerca.3DS");
}

void Cerca::desenha(){
    glPushMatrix();
        Objeto::desenha();
        glPushMatrix();
            glTranslatef(0,0.30,0);
            glRotatef(-90,1,0,0);
            glScalef(0.0054     ,
                     0.0009   ,
                     0.001 );

            model->draw();
        glPopMatrix();

        glPushMatrix();
            if( selecionado ){
                GUI::setColor(1,0,0,0.5);
                GUI::drawBox(-7.5,0,-0.5,
                              7.5,1.5,0.5);
            }
         glPopMatrix();
    glPopMatrix();
}
