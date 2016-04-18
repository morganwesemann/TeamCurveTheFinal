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
    Location l;
    l.x = 200;
    l.y = 200;
    AlphanumericPlotter alpha(g);
    CircleNode circle(g,&alpha,"II",l,32);
    circle.draw();
    
    l.x = 300;
    l.y = 200;
    AlphanumericPlotter alpha1(g);
    CircleNode circle1(g,&alpha1,"AA",l,32);
    circle1.draw();
    
    l.x = 425;
    l.y = 200;
    AlphanumericPlotter alpha2(g);
    CircleNode circle2(g,&alpha2,"AI",l,32);
    circle2.draw();
    
    l.x = 200;
    l.y = 300;
    AlphanumericPlotter alpha3(g);
    CircleNode circle3(g,&alpha3,"MI",l,32);
    circle3.draw();
    
    l.x = 200;
    l.y = 425;
    AlphanumericPlotter alpha4(g);
    CircleNode circle4(g,&alpha4,"12",l,32);
    circle4.draw();
    
    l.x = 100;
    l.y = 200;
    AlphanumericPlotter alpha5(g);
    CircleNode circle5(g,&alpha5,"14",l,32);
    circle5.draw();
    
    Line lin(g);
    
    lin.draw(circle, circle3);
    
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

