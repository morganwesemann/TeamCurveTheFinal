/*
 * Authors: Adam Kim, Ean Evans, Alex Wallen, Morgan Wesemann
 * Project: VisualSplayTree
 * File: main.cpp
 */
#include <iostream>
#include "GroupProject.h"
using namespace std;

void Player(void);
GroupProject* app;

int main() {
    GLUT_Plotter* g = new GLUT_Plotter(); //Create plotter
    app = new GroupProject(g);                 //Create Game (Tetris)
    g->RegisterIdleFunc(Player);          //Register Callback
    g->MainLoop();                        //Enter main loop
    return 0;
}

void Player(void){
    app->Play();
}
