#include "catavento.h"

Catavento::Catavento() {
    tipo = 15;

}

Catavento::Catavento( Vetor3D nt, Vetor3D na, Vetor3D ns ){
    t = nt;
    a = na;
    s = ns;
    tipo = 15;
    origem = false;
}

void Catavento::desenha(){

glPushMatrix();
    Objeto::desenha();
    GUI::setColor(0.75,0.40, 0.10);
     //haste
    glPushMatrix();
        glTranslatef(0,0,0.15);
        glRotatef(180, 0, 1, 0);
        glRotatef(90, 0, 0, 1);
        glScalef(3, 0.2, 0.2);
        GUI::drawBox(0,0,0,1,1,1);
    glPopMatrix();
    //helices
    glPushMatrix();
        glTranslatef(0,3,0);
        glRotatef(90, 0, 0, 1);
        glRotatef(rot, 0, 1, 0);
        rot += 100;
        if(rot==100000) {
            rot=100;
        }

        glPushMatrix();
            glRotatef(270, 0, 1, 0);
            glScalef(1.5, 0.2, 0.2);
            GUI::drawBox(0,0,0,1,1,1);
        glPopMatrix();
        glPushMatrix();
            glRotatef(180, 0, 1, 0);
            glScalef(1.5, 0.2, 0.2);
            GUI::drawBox(0,0,0,1,1,1);
        glPopMatrix();
        glPushMatrix();
            glRotatef(90, 0, 1, 0);
            glScalef(1.5, 0.2, 0.2);
            GUI::drawBox(0,0,0,1,1,1);
        glPopMatrix();
        glPushMatrix();
        glScalef(1.5, 0.2, 0.2);
            GUI::drawBox(0,0,0,1,1,1);
        glPopMatrix();
    glPopMatrix();
    glPushMatrix();
        if( selecionado ){
            GUI::setColor(1,0,0,0.5);
            GUI::drawBox(-1,0,-1.5,
                         1,4.5,1.5);
        }
    glPopMatrix();
glPopMatrix();

}
