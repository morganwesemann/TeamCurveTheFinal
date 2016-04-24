//
//  VisualSplay.cpp
//  GroupProject
//
//  Created by Morgan Wesemann on 4/18/16.
//  Copyright © 2016 Morgan Wesemann. All rights reserved.
//

#include "VisualSplay.h"


VisualSplay::VisualSplay(GLUT_Plotter* g,AlphanumericPlotter* a) {
    screen = g;
    alpha = a;
    splay = new SplayTree<int>;
    totalNodeSlots = 0;
    screenHeight = screen->getHeight();
    screenWidth = screen->getWidth();
    totalNodeSlots = 0;
    treeHeight = 0;
    rootLoc.x = screenWidth / 2;
    rootLoc.y = screenHeight - 100;
    
    
}


void VisualSplay::insert(int val) {
    splay->insert(val);
}

void VisualSplay::remove(int val) {
    splay->remove(val);
}

void VisualSplay::clear()
{
    delete splay;
    deleteVisualSplay();
}

void VisualSplay::deleteVisualSplay()
{
    visualSplay.clear();
}

void VisualSplay::draw() {
    
    if (splay != NULL) {
        
        vector<vector<string> > tempDoubleVec;
        vector<string> tempVec;
        
        ostringstream levelOrderStream;
        splay->printLevelOrderInt(levelOrderStream);
        string levelOrder = levelOrderStream.str();
        
        size_t treeHeight = count(levelOrder.begin(),levelOrder.end(),'l');
        
        //if first draw call, make vector
        if (visualSplay.empty())
        {
            for (int i = 0; i < treeHeight; i++)
            {
                totalNodeSlots+= pow(2.0, i);
            }
            for (int i = 0; i < totalNodeSlots+1;i++)
            {
                visualSplay.push_back(NULL);
            }
        }
        else
        {
            int tempNodeSlots = 0;
            for (int i = 0; i < treeHeight; i++) {
                tempNodeSlots+= pow(2.0, i);
            }
            
            //increase capacity of visual splay if needed
            if (tempNodeSlots > totalNodeSlots) {
                tempNodeSlots -= totalNodeSlots;
                for (int i = 0; i < tempNodeSlots; i++) {
                    visualSplay.push_back(NULL);
                }
            }
            
        }
        
        
        
        levelOrder.erase(0,1);
        cout << levelOrder;
        
        tempVec = splitStrIntoVector(levelOrder,'l');
        if (tempVec.empty()) {
            exit(1);
        }
        for (int i = 0; i < treeHeight; i++) {
            tempVec[i].erase(0,1);
            tempDoubleVec.push_back(splitStrIntoVector(tempVec[i]));
        }
        
        size_t tempSize = 0;
        int visualLocation = 1;
        Location l;
        l.x = -1;
        l.y = -1;
        for (int i = 0; i < treeHeight; i++) {
            tempSize = tempDoubleVec[i].size();
            //prepare vector for nodes
            for (int j = 0; j < tempSize; j++) {
                if (tempDoubleVec[i][j] == "-1") {
                    if (visualSplay[visualLocation] != NULL) {
                        delete visualSplay[i];
                        visualSplay[visualLocation] = NULL;
                    }
                } else {
                    
                    
                    if (visualSplay[visualLocation] != NULL) {
                        delete visualSplay[visualLocation];
                    }
                    if (visualLocation == 1) {
                        l.x = rootLoc.x;
                    } else if (visualLocation == 2 || visualLocation == 3) {
                    
                        int parent = visualLocation / 2;
                        cout << "parent" << parent << endl;
                        Location parentLoc;
                        parentLoc = visualSplay[parent]->getLocation();
                        
                        //calc possible parents
                        int child1 = parent*2;
                        
                        if (child1 == visualLocation) {
                            //left ptr
                            l.x = parentLoc.x - 60;
                            
                        } else {
                            //right ptr
                            l.x = parentLoc.x + 60;
                            
                        }

                    } else {
                            
                        
                        int parent = visualLocation / 2;
                        int grandparent = parent / 2;
                        cout << "parent" << parent << endl;
                        Location parentLoc;
                        Location grandparentLoc;
                        parentLoc = visualSplay[parent]->getLocation();
                        grandparentLoc = visualSplay[grandparent]->getLocation();
                        
                        
                        

                        
                        //calc possible parents
                        
                        int child1 = parent*2;
                        
                        if (child1 == visualLocation) {
                            //left ptr
                            l.x = parentLoc.x - 60;
                            //check collisions
                            
                            if (parentLoc.x > grandparentLoc.x) {
                                if (l.x <= grandparentLoc.x) {
                                    parentLoc.x += 60;
                                    l.x = parentLoc.x - 60;
                                    visualSplay[parent]->setLocation(parentLoc);
                                }
                            }
                            
                        } else {
                           //right ptr
                            l.x = parentLoc.x + 60;
                            
                            //check
                            if (parentLoc.x < grandparentLoc.x) {
                                if (l.x <= grandparentLoc.x) {
                                    parentLoc.x -= 60;
                                    l.x = parentLoc.x + 60;
                                    visualSplay[parent]->setLocation(parentLoc);
                                }
                            }
                        }
                        
                        //int currentLocation = visualLocation;
                        
                        //check every node for going past parents
                        /*do {
                            if (visualSplay[currentLocation] != NULL) {
                                l = visualSplay[currentLocation]->getLocation();
                                cout << "there is a node here and it is not null";

                                //calc possible parents
                                
                                 child1 = parent*2;
                                
                                if (child1 == visualLocation) {
                                    //left ptr
                                    cout << " and it is a left child" << endl;
                                    if (parentLoc.x > grandparentLoc.x) {
                                        if (l.x <= grandparentLoc.x) {
                                            parentLoc.x += 60;
                                            l.x = parentLoc.x - 60;
                                            visualSplay[parent]->setLocation(parentLoc);
                                        }
                                    }
                                    
                                } else {
                                    //right ptr
                                    cout << " and it is a right child" << endl;
                                    if (parentLoc.x < grandparentLoc.x) {
                                        if (l.x <= grandparentLoc.x) {
                                            parentLoc.x -= 60;
                                            l.x = parentLoc.x + 60;
                                            visualSplay[parent]->setLocation(parentLoc);
                                        }
                                    }
                                    
                                }
                         
                                if (child1 == visualLocation) {
                                    //left ptr
                                    l.x = parentLoc.x - 60;
                                    //check collisions
                                    
                                    if (parentLoc.x > grandparentLoc.x) {
                                        if (l.x <= grandparentLoc.x) {
                                            parentLoc.x += 60;
                                            l.x = parentLoc.x - 60;
                                            visualSplay[parent]->setLocation(parentLoc);
                                        }
                                    }
                                    
                                } else {
                                    //right ptr
                                    l.x = parentLoc.x + 60;
                                    
                                    //check
                                    if (parentLoc.x < grandparentLoc.x) {
                                        if (l.x <= grandparentLoc.x) {
                                            parentLoc.x -= 60;
                                            l.x = parentLoc.x + 60;
                                            visualSplay[parent]->setLocation(parentLoc);
                                        }
                                    }
                                }*
                                
                                
                                
                            }
                            currentLocation--;
                            parent = currentLocation / 2;
                            grandparent = parent / 2;
                            cout << "p: " << parent << " " << grandparent << endl;
                        } while (currentLocation > 4);*/
                    }
                    l.y = rootLoc.y - (i * 100);
                    
                    visualSplay[visualLocation] = new CircleNode(screen,alpha,tempDoubleVec[i][j],l);
                }
                visualLocation++;
            }
        }
        
        //resolve collisions
        
    
        //draw tree (nodes and lines)
        for (int i = 1; i < totalNodeSlots+1; i++) {
            if (visualSplay[i] != NULL) {
                visualSplay[i]->draw();
                Line lin(screen);
                int child1 = i*2;
                int child2 = i*2 + 1;
                
                //only draw left child if exists
                if (child1 < totalNodeSlots+1) {
                    if (visualSplay[child1] != NULL) {
                        lin.draw(*visualSplay[i], *visualSplay[child1]);
                    }
                }
                
                //only draw right child if exists
                if (child2 < totalNodeSlots+1) {
                    if (visualSplay[child2] != NULL) {
                        lin.draw(*visualSplay[i], *visualSplay[child2]);
                    }
                }
            }
        }
    }
}

vector<string> VisualSplay::splitStrIntoVector(string sentence, const char &d) {
    vector<string> vec;
    //iterator to beginning of sentence
    string::iterator it = sentence.begin();
    string::iterator temp;
    
    //while the iterator is not at the end of the sentence
    while (it != sentence.end()) {
        //find the next space
        temp = find(it, sentence.end(),d);
        /*
         if we aren't at the end, add the word in between the
         two iterators to the vector
         */
        if (it != sentence.end()) {
            vec.push_back(string(it,temp));
        }
        //set iterator to end of word
        it = temp;
        
        //skip through extra spaces
        while ((it != sentence.end()) && (*it == d)) {
            it++;
        }
    }
    return vec;
}

