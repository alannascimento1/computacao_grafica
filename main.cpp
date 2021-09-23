#include <iostream>
#include <fstream>
#include <sstream>
#include <gui.h>
#include "extra.h"
#include "CameraDistante.h"
#include "CameraJogo.h"

#include <vector>
#include <casarao.h>
#include <cerca.h>
#include <porteira.h>
#include <carroca.h>
#include <trator.h>
#include <arvore.h>
#include <jardim.h>
#include <pedelimao.h>
#include <f1000.h>
#include <garagem.h>
#include <casadocachorro.h>
#include <cachorro.h>
#include <catavento.h>
#include <banco.h>
#include <escorregador.h>


using namespace std;


vector<Objeto*> objetos;
Camera* cam;
int posSelecionado = -1;
bool incluirObjeto = false;

void desenha() {
    GUI::displayInit();
    GUI::setLight(0,1,12,1,true,false);
    GUI::drawOrigin(2.5);
    GUI::setColor(0.96,0.76,0.01);
    GUI::drawFloor(20,20);

        for (int i = 0; i < objetos.size(); ++i) {
            glPushMatrix();
                objetos[i]->desenha();
            glPopMatrix();
        }

        if (posSelecionado >= 0 and posSelecionado < objetos.size()) {
            objetos[posSelecionado]->t.x += glutGUI::dtx;
            objetos[posSelecionado]->t.y += glutGUI::dty;
            objetos[posSelecionado]->t.z += glutGUI::dtz;

            objetos[posSelecionado]->a.x += glutGUI::dax;
            objetos[posSelecionado]->a.y += glutGUI::day;
            objetos[posSelecionado]->a.z += glutGUI::daz;

            objetos[posSelecionado]->s.x += glutGUI::dsx;
            objetos[posSelecionado]->s.y += glutGUI::dsy;
            objetos[posSelecionado]->s.z += glutGUI::dsz;
        }
    GUI::displayEnd();
}




void save(){
    ofstream arq("cenario.txt");
    arq.clear();
    arq << objetos.size() << "\n";
    for (int i = 0; i < objetos.size();i++) {
        arq << objetos[i]->tipo << "\n";
        arq << objetos[i]->t.x << "\n";
        arq << objetos[i]->t.y << "\n";
        arq << objetos[i]->t.z << "\n";
        arq << objetos[i]->a.x << "\n";
        arq << objetos[i]->a.y << "\n";
        arq << objetos[i]->a.z << "\n";
        arq << objetos[i]->s.x << "\n";
        arq << objetos[i]->s.y << "\n";
        arq << objetos[i]->s.z << "\n";
    }
}




void iniciaCenarioPadrao() {
    cout << "INICIANDO CENÁRIO" << endl;
    ifstream arq("cenario.txt");
    string linha;
    getline(arq,linha);
    int n_obj = std::stoi (linha);
    int tipo;
    double tx, ty, tz, ax, ay, az, sx, sy, sz;
    for( int i = 0; i < n_obj; i++ ){
      getline(arq,linha);
      tipo = std::stoi (linha);
      getline(arq,linha);
      tx = std::stof(linha);
      getline(arq,linha);
      ty = std::stof(linha);
      getline(arq,linha);
      tz = std::stof(linha);
      getline(arq,linha);
      ax = std::stof(linha);
      getline(arq,linha);
      ay = std::stof(linha);
      getline(arq,linha);
      az = std::stof(linha);
      getline(arq,linha);
      sx = std::stof(linha);
      getline(arq,linha);
      sy = std::stof(linha);
      getline(arq,linha);
      sz = std::stof(linha);
      Vetor3D tn = Vetor3D(tx,ty,tz);
      Vetor3D an = Vetor3D(ax,ay,az);
      Vetor3D sn = Vetor3D(sx,sy,sz);
      switch(tipo) {
        case 1:
          objetos.push_back(new Banco(tn, an, sn));
          break;
        case 2:
          objetos.push_back(new Casarao(tn, an, sn));
          break;
        case 3:
          objetos.push_back(new Cerca(tn, an, sn));
          break;
        case 4:
          objetos.push_back(new Porteira(tn, an, sn));
          break;
        case 5:
          objetos.push_back(new Carroca(tn, an, sn));
          break;
        case 6:
          objetos.push_back(new Trator(tn, an, sn));
          break;
        case 7:
          objetos.push_back(new Arvore(tn, an, sn));
          break;
        case 8:
          objetos.push_back(new Escorregador(tn, an, sn));
          break;
        case 9:
          objetos.push_back(new Jardim(tn, an, sn));
          break;
        case 10:
          objetos.push_back(new Pedelimao(tn, an, sn));
          break;
        case 11:
          objetos.push_back(new F1000(tn, an, sn));
          break;
        case 12:
          objetos.push_back(new Garagem(tn, an, sn));
          break;
        case 13:
          objetos.push_back(new Casadocachorro(tn, an, sn));
          break;
        case 14:
          objetos.push_back(new Cachorro(tn, an, sn));
          break;
        case 15:
          objetos.push_back(new Catavento(tn, an, sn));
          break;
      }
    }
}



void reload(){
    objetos.clear();
    iniciaCenarioPadrao();
    glutGUI::trans_obj = false;
}




void proximo(){
    if (posSelecionado >= 0 and posSelecionado < objetos.size()) {
        objetos[posSelecionado]->selecionado = false;
    }
    posSelecionado++;
    posSelecionado = posSelecionado % objetos.size();
    if (posSelecionado >= 0 and posSelecionado < objetos.size()) {
        objetos[posSelecionado]->selecionado = true;
    }
}




void anterior(){
    if (posSelecionado >= 0 and posSelecionado < objetos.size()) {
        objetos[posSelecionado]->selecionado = false;
    }
    posSelecionado--;
    if (posSelecionado < 0) {
        posSelecionado = objetos.size()-1;
    }
    if (posSelecionado >= 0 and posSelecionado < objetos.size()) {
        objetos[posSelecionado]->selecionado = true;
    }
}




void apagarSelecionado(){
    if (posSelecionado >= 0 and posSelecionado < objetos.size()) {
        objetos.erase(objetos.begin()+posSelecionado);
    }
}

void delFinal(){
    if(objetos.size() > 0 ){
        objetos.pop_back();
    }
}

void limpaSelect(){
    if (posSelecionado >= 0 and posSelecionado < objetos.size()) {
        objetos[posSelecionado]->selecionado = false;
    }
    glutGUI::trans_obj = false;
}

void showOrig(){

    if (posSelecionado >= 0 and posSelecionado < objetos.size()) {
        objetos[posSelecionado]->origem = !objetos[posSelecionado]->origem;
    }

}

void teclado(unsigned char key, int x, int y) {

    GUI::keyInit(key,x,y);

    switch (key) {
    case 'O':
        incluirObjeto = !incluirObjeto;
        break;

    case 'w':
        if (incluirObjeto) {
            objetos.push_back( new Pedelimao() );
        }
        break;

    case 'Q':
        if (incluirObjeto) {
            objetos.push_back( new Casarao() );
        }
        break;

    case 'J':
        if (incluirObjeto) {
            objetos.push_back( new Jardim() );
        }
        break;

    case 'I':
        if (incluirObjeto) {
            objetos.push_back( new Carroca() );
        }
        break;
    case 'V':
        if (incluirObjeto) {
            objetos.push_back( new Trator() );
        }
        break;

    case '$':
        if (incluirObjeto) {
            objetos.push_back( new F1000() );
        }
        break;

    case 'R':
        if (incluirObjeto) {
            objetos.push_back( new Arvore() );
        }
        break;

    case 'a':
        if (incluirObjeto) {
            objetos.push_back( new Cerca() );
        }
        break;

    case 'T':
        if (incluirObjeto) {
            objetos.push_back( new Garagem() );
        }
        break;
    case 'N':
        if (incluirObjeto) {
            objetos.push_back( new Catavento() );
        }
        break;
    case 'A':
        if (incluirObjeto) {
            objetos.push_back( new Porteira() );
        }
        break;
    case 'K':
        if (incluirObjeto) {
            objetos.push_back( new Casadocachorro() );
        }
        break;
    case 'k':
        if (incluirObjeto) {
            objetos.push_back( new Cachorro() );
        }
        break;
    case 'L':
        if (incluirObjeto) {
            objetos.push_back( new Banco() );
        }
        break;

    case 'n':
        if (incluirObjeto) {
            objetos.push_back( new Escorregador() );
        }
        break;

    case 't':
        glutGUI::trans_obj = !glutGUI::trans_obj;
        break;

    case 'l':
        glutGUI::trans_luz = !glutGUI::trans_luz;
        break;

    case ']':
        proximo();
        break;

    case '[':
        anterior();
        break;

    case '-':
        limpaSelect();
        break;

    case '*':
        showOrig();
        break;

    case 'p':
        apagarSelecionado();
        break;

    case 'P':
        delFinal();
        break;

    case 'S':
        save();
        break;

    case 'v':
        reload();
        break;

    case '1'://CAMERA JOGO ENTRANDO NA FAZENDA (PORTEIRA)
        glutGUI::cam = new CameraJogo(-5.1,2,4,    -3,2,4,    0,1,0);
        break;

    case '2': //CAMERA JOGO NO PATIO (escorregador)
        glutGUI::cam = new CameraJogo(-8.7,2,-10,    -7.7,2,-3,     0,1,0);//-7.7
        break;

    case '3': //CAMERA JOGO CACHORRO
        glutGUI::cam = new CameraJogo(4.5, 0.5, -3.5,    6.5, 0.5, -3.5,     0,1,0);//-7.7
        break;

    case '4': //CAMERA DISTANTE PATIO (escorregador)
        glutGUI::cam = new CameraDistante(-12,8,-12, -7.7,2,-3, 0,1,0);
        break;
    case '5': //CAMERA DISTANTE CASARAO
        glutGUI::cam = new CameraDistante(7,8,6, 6,0,-7, 0,1,0);
        break;
    case '6': //CAMERA DISTANTE CATAVENTO
        glutGUI::cam = new CameraDistante(1.5,16,20, 1.5,0,7, 0,1,0);
        break;


    default:
        break;
    }
}

int main()
{
    iniciaCenarioPadrao();
    GUI gui = GUI(800,600,desenha,teclado);
}
