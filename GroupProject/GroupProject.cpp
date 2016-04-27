#include "GroupProject.h"


/******************************************************************************/
GroupProject::GroupProject(GLUT_Plotter* g)
{
    this->g = g;
    g->setColor(0xffffff);
    alpha = new AlphanumericPlotter(g);
    gui = new UI(g, alpha);
    screenWidth = g->getWidth();
    screenHeight = g->getHeight();
    
    maxPixelX = screenWidth - gui->getButtonWidth();
    g->setMaxPixelX(maxPixelX);
    v = new VisualSplay(g,alpha);
    
   
}

/******************************************************************************/

GroupProject::~GroupProject() {
    delete gui;
    v->clearTree();
}


void GroupProject::Play(void) //GroupProject Main Game Loop
{
    
    while(g->kbhit()) //Check for Keyboard Hit
    {
        
        int k = g->getKey();
        

        switch (k){
            case 'L':
                g->setColor(0x000000);
                v->draw();
                v->clearTree();
                gui->redrawButton(TEXT, "");
                gui->deselectButton();
                break;
            case 8:
            case 0x7f:
                if (doInsert || doFind || doDelete) {
                    int length = ourNumber.length();
                    if (length > 0) {
                        ourNumber.erase(length-1,1);
                        gui->redrawButton(TEXT, ourNumber);
                        cout << ourNumber;
                    }
                }
                break;
            case 'I':
            case 'i':
                doInsert = true;
                gui->buttonSelect(INSERT);
                gui->redrawButton(TEXT, "");
                doDelete = false;
                doFind = false;
                ourNumber.clear();
                break;
            case 13:
                
                if (doInsert || doFind || doDelete) {
                    size_t length = ourNumber.length();
                    
                    if (length > 0) {
                        int temp = atoi(ourNumber.c_str());
                        g->setColor(0x000000);
                        v->draw();
                        if (doInsert) {
                            v->insert(temp);
                        } else if (doFind) {
                            v->find(temp);
                        } else if (doDelete) {
                            v->remove(temp);
                        }
                        gui->deselectButton();
                        doDelete = false;
                        doInsert = false;
                        doFind = false;
                        g->setColor(0xffffff);
                        v->draw();
                        ourNumber.clear();
                        gui->redrawButton(TEXT, "");
                    }
                    
                }
                
                break;
            //numbers 0-9
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
                
                if (doInsert || doFind || doDelete) {
                    ourNumber += char(k);
                    gui->redrawButton(TEXT, ourNumber);

                }
                
                break;
            case 'Q': exit(1); //ESC key
		              break;
            case 'R':
            case 'r':
                gui->buttonSelect(REMOVE);
                gui->redrawButton(TEXT, "");
                doDelete = true;
                doInsert = false;
                ourNumber.clear();
                break;
            case 'F':
            case 'f':
                gui->buttonSelect(FIND);
                gui->redrawButton(TEXT, "");
                doFind = true;
                doInsert = false;
                doDelete = false;
                ourNumber.clear();
                break;
            case 'c':
            case 'C':
                Location newRootLoc(maxPixelX/2, screenHeight - 100);
                g->setColor(0xffffff);
                gui->redrawButton(TEXT, "");
                gui->deselectButton();
                v->moveTreeTo(newRootLoc);
                
                break;
        }
    }
    
    
    //Check for mouse click
    while(g->click()){
        
        Click c;
        c = g->getClick();
        
        
        //if location is IN BOUNDS, plot
        if (c.x > 0 && c.x < g->getWidth() && c.y > 0 && c.y < screenHeight) {
            if (c.state == 0) {
                if(gui->getClick(Location(c.x, c.y))){
                    switch (gui->getMode())
                    {
                        case INSERT:
                            
                            if (doInsert == true) {
                                size_t length = ourNumber.length();
                                
                                if (length > 0) {
                                    int temp = atoi(ourNumber.c_str());
                                    g->setColor(0x000000);
                                    v->draw();
                                    if (doInsert) {
                                        v->insert(temp);
                                    }
                                    gui->deselectButton();
                                    doDelete = false;
                                    doInsert = false;
                                    doFind = false;
                                    g->setColor(0xffffff);
                                    v->draw();
                                    ourNumber.clear();
                                    gui->redrawButton(TEXT, "");
                                }
                            } else {
                                doInsert = true;
                                gui->buttonSelect(INSERT);
                                gui->redrawButton(TEXT, "");
                                doDelete = false;
                                doFind = false;
                                ourNumber.clear();
                            }

                            break;
                        case REMOVE:
                            if (doDelete == true) {
                                size_t length = ourNumber.length();
                                if (length > 0) {
                                    int temp = atoi(ourNumber.c_str());
                                    g->setColor(0x000000);
                                    v->draw();
                                    if (doDelete) {
                                        v->remove(temp);
                                    }
                                    gui->deselectButton();
                                    doDelete = false;
                                    doInsert = false;
                                    doFind = false;
                                    g->setColor(0xffffff);
                                    v->draw();
                                    ourNumber.clear();
                                    gui->redrawButton(TEXT, "");
                                }
                            } else {
                                gui->redrawButton(TEXT, "");
                                doDelete = true;
                                doInsert = false;
                                doFind = false;
                                ourNumber.clear();
                            }
                            break;
                        case FIND:
                            if (doFind == true) {
                                size_t length = ourNumber.length();
                                
                                if (length > 0) {
                                    int temp = atoi(ourNumber.c_str());
                                    g->setColor(0x000000);
                                    v->draw();
                                    if (doFind) {
                                        v->find(temp);
                                    }
                                    gui->deselectButton();
                                    doDelete = false;
                                    doInsert = false;
                                    doFind = false;
                                    g->setColor(0xffffff);
                                    v->draw();
                                    ourNumber.clear();
                                    gui->redrawButton(TEXT, "");
                                }
                            } else {
                                gui->redrawButton(TEXT, "");
                                doFind = true;
                                doDelete = false;
                                doInsert = false;
                                ourNumber.clear();
                            }
                            break;
                        case CENTER:
                        {
                            gui->redrawButton(TEXT, "");
                            Location newRootLoc(maxPixelX/2, screenHeight - 100);
                            g->setColor(0xffffff);
                            v->moveTreeTo(newRootLoc);
                            gui->deselectButton();
                        }
                            break;
                        case CLEAR:
                            g->setColor(0x000000);
                            v->draw();
                            v->clearTree();
                            gui->redrawButton(TEXT, "");
                            gui->deselectButton();
                            
                            break;
                        
                        case QUIT:
                            exit(1);
                            
                    }
                }
            }
            if (c.state == 1) {
                oldLoc.x = c.x;
                oldLoc.y = c.y;
            }
            if (c.state == 2) {
                
                changedLoc.y = (c.y - oldLoc.y)* -1;
                oldLoc.y = c.y;
                
                changedLoc.x = c.x - oldLoc.x;
                oldLoc.x = c.x;
                
                g->setColor(0xffffff);
                v->moveTreeBy(changedLoc);
                
            }
        }
    }
    
    // Update screen - draw game
    g->Draw();
    
}
/******************************************************************************/
