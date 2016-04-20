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

/*void GroupProject::drawT() {
    int screenHeight, screenWidth;
    screenHeight = screen->getHeight();
    screenWidth = screen->getWidth();
    AlphanumericPlotter alpha(g)
    Location rootLoc;
    rootLoc.x = screenWidth/2;
    rootLoc.y = screenHeight - 100;
    CircleNode rootCircle(g,&alpha,"19",rootLoc);
    

    
}*/

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
        
        //if location is IN BOUNDS, plot
        if (c.x > 0 && c.x < g->getWidth() && c.y > 0 && c.y < g->getHeight()) {
        
            if (c.state == 0) {
                
            }
            AlphanumericPlotter alpha(g);
            g->setColor(0xffffff);
            alpha.plotString("ABCDEFGHIJKLMNOPQRSTUVWXYZ", 0, 100);
            alpha.plotString("0123456789", 300, 300);
            drawT();
            char* buffer = g->getBuffer();
            g->plot(c.x, g->getHeight() - c.y);
            
        }
    }
    
    // Update screen - draw game
    g->Draw();
    
}

