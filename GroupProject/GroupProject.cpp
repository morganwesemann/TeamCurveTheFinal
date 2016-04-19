/*
 * GroupProject.cpp
 *
 *  Created on: Mar 31, 2014
 *  Modified on: Mar 31, 2014
 *  Author: D. Booth
 */


#include "GroupProject.h"

//GroupProject Constructor

GroupProject::GroupProject(GLUT_Plotter* g){
    this->g = g;
}

void GroupProject::drawT() {
    AlphanumericPlotter alpha(g);
    VisualSplay v(g,&alpha);
    v.insert(5);
    v.insert(400);
    v.insert(45);
    v.insert(69);
    v.insert(61);
    v.insert(67);
    v.insert(65);
    v.insert(63);
    v.draw();
    

}
//GroupProject Main Game Loop
void GroupProject::Play(void){
    
    //Check for Keyboard Hit
    while(g->kbhit()){
        int k = g->getKey();
        switch (k){
            case 65:
                break;
            case 27: exit(1); //ESC key
		              break;
        }
    }
    
    
    //Check for mouse click
    while(g->click()){
        
        Click c;
        c = g->getClick();
        AlphanumericPlotter alpha(g);
        g->setColor(0xffffff);
        alpha.plotString("ABCDEFGHIJKLMNOPQRSTUVWXYZ", 0, 100);
        alpha.plotString("0123456789", 300, 300);
        drawT();
        g->plot(c.x, g->getHeight() - c.y);
    }
    
    // Update screen - draw game
    g->Draw();
    
}

