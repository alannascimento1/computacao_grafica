#include "casadocachorro.h"

Casadocachorro::Casadocachorro() {
    tipo=13;
}

Casadocachorro::Casadocachorro( Vetor3D nt, Vetor3D na, Vetor3D ns ){
    t = nt;
    a = na;
    s = ns;
    tipo=13;
    origem = false;
}

void Casadocachorro::desenha(){

    GUI::setColor(1,0,0);
glPushMatrix();

    Objeto::desenha();
    glPushMatrix();
        GUI::setColor(1,0.3,0.3);
        GUI::drawBox(0,0,0,1,1,1);

        float dif =  0.001;
        float dif2 = 0.001;
        GUI::setColor(0.81,0.71, 0.23);
        //OS PROXIMOS DOIS SAO TELHADO DIREITO
        glEnable(GL_CULL_FACE);
        glBegin(GL_QUADS);
            glNormal3f(1,1,0);
            glVertex3f(1.1,0.9,1.1);
            glVertex3f(1.1,0.9,-0.1);
            glVertex3f(0.5,1.5,-0.1);
            glVertex3f(0.5,1.5,1.1);
        glEnd();
        glBegin(GL_QUADS);
            glNormal3f(-1,-1-dif,0);
            glVertex3f(0.5,1.5-dif,1.1);
            glVertex3f(0.5,1.5-dif,-0.1);
            glVertex3f(1.1,0.9-dif,-0.1);
            glVertex3f(1.1,0.9-dif,1.1);
        glEnd();
        //OS PROXIMOS DOIS SAO TELHADO ESQUERDO
        glBegin(GL_QUADS);
            glNormal3f(-1,1,0);
            glVertex3f(0.5,1.5,1.1);
            glVertex3f(0.5,1.5,-0.1);
            glVertex3f(-0.1,0.9,-0.1);
            glVertex3f(-0.1,0.9,1.1);
        glEnd();
        glBegin(GL_QUADS);
            glNormal3f(1,-1-dif2,0+dif2);
            glVertex3f(-0.1,0.9-dif2,1.1+dif2);
            glVertex3f(-0.1,0.9-dif2,-0.1+dif2);
            glVertex3f(0.5,1.5-dif2,-0.1+dif2);
            glVertex3f(0.5,1.5-dif2,1.1+dif2);
        glEnd();
//        GUI::setColor(0.81,0.71, 0.23);
        //FRENTE TRIANGULO
        GUI::setColor(1,0.3,0.3);
        glBegin(GL_TRIANGLES);
            glNormal3f(0,0,1);
            glVertex3f(1,1,1);
            glVertex3f(0.5,1.5,1);
            glVertex3f(0,1,1);
        glEnd();
        //TRAS TRIANGULO
         GUI::setColor(1,0.3,0.3);
        glBegin(GL_TRIANGLES);
            glNormal3f(0,0,-1);
            glVertex3f(0.5,1.5,0);
            glVertex3f(1,1,0);
            glVertex3f(0,1,0);
        glEnd();
        //PORTA
        GUI::setColor(0,0,0);
        glBegin(GL_QUADS);
            glNormal3f(0,0,1.003);
            glVertex3f(0.7,0,1.003);
            glVertex3f(0.7,0.7,1.003);
            glVertex3f(0.3,0.7,1.003);
            glVertex3f(0.3,0,1.003);
        glEnd();
    glPopMatrix();

    glPushMatrix();
        if( selecionado ){
            GUI::setColor(1,0,0,0.5);
            GUI::drawBox(0,0,-0.5,1.5,1.5,1.5);
        }
    glPopMatrix();
    glPopMatrix();

}
