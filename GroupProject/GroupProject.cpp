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
    alpha = new AlphanumericPlotter(g);
    v = new VisualSplay(g,alpha);
}

void GroupProject::drawT() {
    //v->draw();
    
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

bool doInsert = false;
bool first = true;
string ourNumber;
Location changedLoc;
Location oldLoc;

//GroupProject Main Game Loop
void GroupProject::Play(void){
    
    //Check for Keyboard Hit
    while(g->kbhit()){
        int k = g->getKey();
        //cout << "key entered: " << k << endl;
        switch (k){
            case 'I':
            case 'i':
                doInsert = true;
                ourNumber.clear();
                //cout << endl << "insert" << endl;
                break;
            case 13:
                if (doInsert) {
                    doInsert = false;
                   // cout << "our number: " << ourNumber;
                    int temp = atoi(ourNumber.c_str());
                    //cout << "int: " << temp;
                    g->setColor(0xffffff);
                    v->insert(temp);
                    g->Clear();
                    v->draw();
                    ourNumber.clear();

                }
                
                break;
            case 0x30:
            case 0x31:
            case 0x32:
            case 0x33:
            case 0x34:
            case 0x35:
            case 0x36:
            case 0x37:
            case 0x38:
            case 0x39:
                
                if (doInsert) {
                    //k -= 0x30;
                    //cout << char(k) << endl;
                    ourNumber += char(k);
                    //cout << ourNumber.length();
                    if (ourNumber.length() == 3) {
                        doInsert = false;
                        //cout << "our number: " << ourNumber;
                        int temp = atoi(ourNumber.c_str());
                        //cout << "int: " << temp;
                        g->setColor(0xffffff);
                        v->insert(temp);
                        g->Clear();
                        v->draw();
                        ourNumber.clear();
                        
                        
                    }
                }
                
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
            if (c.state == 1) {
                oldLoc.x = c.x;
                oldLoc
                .y = c.y;
                cout << "x: " << c.x << " y: " << c.y << endl;
            }
            if (c.state == 2) {
                
                
                cout << "old loc y: " << oldLoc.y << " click y: " << c.y << endl;
                cout << "old loc x: " << oldLoc.x << " click x: " << c.x << endl;
                
                changedLoc.y = (c.y - oldLoc.y)* -1;
                //cout << "y diff" << changedLoc.y << endl;
                oldLoc.y = c.y;
                
                changedLoc.x = c.x - oldLoc.x;
                oldLoc.x = c.x;
                
                
         
                
                //cout << "x: " << changedLoc.x << " y: " << changedLoc.y << endl;
                
                g->setColor(0xffffff);
                v->moveTree(changedLoc);
                //g->Clear();
                //v->draw();
                
                //changedLoc.x = c.x;
                //changedLoc.y = c.y;
                
                
            }
            /*g->setColor(0xffffff);
            alpha->plotString("ABCDEFGHIJKLMNOPQRSTUVWXYZ", 0, 100);
            alpha->plotString("0123456789", 300, 300);
            //char* buffer = g->getBuffer();
            g->plot(c.x, g->getHeight() - c.y);
            */
        }
    }
    
    // Update screen - draw game
    g->Draw();
    
}

