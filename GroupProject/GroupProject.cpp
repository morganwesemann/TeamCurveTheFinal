#include "GroupProject.h"


/******************************************************************************/
GroupProject::GroupProject(GLUT_Plotter* g)
{
    this->g = g;
    alpha = new AlphanumericPlotter(g);
    v = new VisualSplay(g,alpha);
}

/******************************************************************************/

bool doInsert = false;
bool doDelete = false;
bool first = true;
string ourNumber;
Location changedLoc;
Location oldLoc;

void GroupProject::Play(void) //GroupProject Main Game Loop
{
    while(g->kbhit()) //Check for Keyboard Hit
    {
        int k = g->getKey();

        switch (k){
                
            case 'I':
            case 'i':
                doInsert = true;
                doDelete = false;
                ourNumber.clear();
                break;
            case 13:
                if (doInsert)
                {
                    doInsert = false;
                    doDelete = false;
                   // cout << "our number: " << ourNumber;
                    int temp = atoi(ourNumber.c_str());
                    g->setColor(0x000000);
                    v->draw();
                    v->insert(temp);
                    g->setColor(0xffffff);
                    v->draw();
                    ourNumber.clear();

                }
                
                if (doDelete) {
                    doInsert = false;
                    // cout << "our number: " << ourNumber;
                    int temp = atoi(ourNumber.c_str());
                    //cout << "int: " << temp;
                    
                    g->setColor(0x000000);
                    v->draw();
                    v->remove(temp);
                    g->setColor(0xffffff);
                    v->draw();
                    ourNumber.clear();
                    
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
                        
                        g->setColor(0x000000);
                        v->draw();
                        v->insert(temp);
                        g->setColor(0xffffff);
                        v->draw();
                        ourNumber.clear();
                    }
                }
                
                if (doDelete) {
                    //k -= 0x30;
                    //cout << char(k) << endl;
                    ourNumber += char(k);
                    //cout << ourNumber.length();
                    if (ourNumber.length() == 3) {
                        doDelete = false;
                        //cout << "our number: " << ourNumber;
                        int temp = atoi(ourNumber.c_str());
                        //cout << "int: " << temp;
                        
                        g->setColor(0x000000);
                        v->draw();
                        v->remove(temp);
                        g->setColor(0xffffff);
                        v->draw();
                        ourNumber.clear();
                        
                        
                    }
                }

                
                break;
                
                
            case 27: exit(1); //ESC key
		              break;
            case 'R':
            case 'r':
                doDelete = true;
                doInsert = false;
                ourNumber.clear();
                break;
            case 'c':
            case 'C':
                float screenWidth = g->getWidth();
                
                float screenHeight = g->getHeight();
                Location newRootLoc(screenWidth/2, screenHeight - 100);
                g->setColor(0xffffff);
                
                v->moveTreeTo(newRootLoc);
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
                oldLoc.y = c.y;
                cout << "x: " << c.x << " y: " << c.y << endl;
            }
            if (c.state == 2) {
                
                
                cout << "old loc y: " << oldLoc.y << " click y: " << c.y << endl;
                //cout << "old loc x: " << oldLoc.x << " click x: " << c.x << endl;
                
                changedLoc.y = (c.y - oldLoc.y)* -1;
                //cout << "y diff" << changedLoc.y << endl;
                oldLoc.y = c.y;
                
                changedLoc.x = c.x - oldLoc.x;
                oldLoc.x = c.x;
                
                
         
                
                //cout << "x: " << changedLoc.x << " y: " << changedLoc.y << endl;
                
                g->setColor(0xffffff);
                v->moveTreeBy(changedLoc);
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
/******************************************************************************/
