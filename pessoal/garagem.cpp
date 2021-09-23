#include "garagem.h"

Garagem::Garagem() {
    tipo=12;

}

Garagem::Garagem( Vetor3D nt, Vetor3D na, Vetor3D ns ){
    t = nt;
    a = na;
    s = ns;
    tipo=12;
    origem = false;
}

void Garagem::desenha(){
    glPushMatrix();

        Objeto::desenha();
        glPushMatrix();
            glPushMatrix();

            GUI::setColor(0.75,0.40, 0.31);


            GUI::drawBox(3,0,-1,3.2,3,-1+0.2);
            GUI::drawBox(3,0,5,3.2,3,5+0.2);

            GUI::drawBox(0,0,5,0.2,2,5+0.2);

                GUI::drawBox(0,0,-1,0.2,2,-1+0.2);


                glEnable(GL_CULL_FACE);

                glBegin(GL_QUADS);

                    glNormal3f(-1,1,0);
                    glVertex3f(0,2,5.2);//INF ESQ
                    glVertex3f(3.18,3,5.2);// INF DIR
                    glVertex3f(3.18,3,-1);//FREN ESQ
                    glVertex3f(0,2,-1); // FRENT DIR
                glEnd();

                glBegin(GL_QUADS);

                    glNormal3f(1,-1,0);
                    glVertex3f(0,2,-1); // FRENT DIR
                    glVertex3f(3.18,3,-1);//FREN ESQ
                    glVertex3f(3.18,3,5.2);// INF DIR
                    glVertex3f(0,2,5.2);//INF ESQ





                glEnd();

            glPopMatrix();
        glPopMatrix();

        glPushMatrix();
            if( selecionado ){
                GUI::setColor(1,0,0,0.5);
                GUI::drawBox(0,  0,-1,
                             3.3,3.4,5.3);
            }
        glPopMatrix();
    glPopMatrix();

}
