TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

INCLUDEPATH += bib
INCLUDEPATH += gui_glut
INCLUDEPATH += pessoal

LIBS += -lGL -lGLU -lglut -l3ds -lSDL_image

SOURCES += main.cpp \
    bib/Camera.cpp \
    bib/CameraDistante.cpp \
    bib/CameraJogo.cpp \
    bib/Desenha.cpp \
    bib/model3ds.cpp \
    bib/Vetor3D.cpp \
    gui_glut/extra.cpp \
    gui_glut/gui.cpp \
    pessoal/objeto.cpp \
    pessoal/casarao.cpp \
    pessoal/cerca.cpp \
    pessoal/porteira.cpp \
    pessoal/carroca.cpp \
    pessoal/trator.cpp \
    pessoal/arvore.cpp \
    pessoal/jardim.cpp \
    pessoal/pedelimao.cpp \
    pessoal/f1000.cpp \
    pessoal/garagem.cpp \
    pessoal/casadocachorro.cpp \
    pessoal/cachorro.cpp \
    pessoal/catavento.cpp \
    pessoal/banco.cpp \
    pessoal/escorregador.cpp

HEADERS += \
    bib/Camera.h \
    bib/CameraDistante.h \
    bib/CameraJogo.h \
    bib/Desenha.h \
    bib/model3ds.h \
    bib/Vetor3D.h \
    gui_glut/extra.h \
    gui_glut/gui.h \
    pessoal/objeto.h \
    pessoal/casarao.h \
    pessoal/cerca.h \
    pessoal/porteira.h \
    pessoal/carroca.h \
    pessoal/trator.h \
    pessoal/arvore.h \
    pessoal/jardim.h \
    pessoal/pedelimao.h \
    pessoal/f1000.h \
    pessoal/garagem.h \
    pessoal/casadocachorro.h \
    pessoal/cachorro.h \
    pessoal/catavento.h \
    pessoal/banco.h \
    pessoal/escorregador.h
