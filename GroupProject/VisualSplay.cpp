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
}


void VisualSplay::insert(int val) {
    splay->insert(val);
}

void VisualSplay::remove(int val) {
    splay->remove(val);
}

void VisualSplay::clear() {
    delete splay;
    deleteVisualSplay();
}

void VisualSplay::deleteVisualSplay() {
    visualSplay.clear();
}

void VisualSplay::draw() {
    
    if (splay != NULL) {
        
        int numNodes = splay->getNumNodes();
        
        ostringstream levelOrderStream;
        splay->printLevelOrderInt(levelOrderStream);
        string levelOrder = levelOrderStream.str();
        
        int size = levelOrder.length();
        int countLevels = count(levelOrder.begin(),levelOrder.end(),'l');
        
        
        
        if (visualSplay.empty()) {
            for (int i = 0; i < countLevels; i++) {
                totalNodeSlots+= pow(2.0, i);
            }
            for (int i = 0; i < totalNodeSlots+1;i++) {
                visualSplay.push_back(NULL);
                
            }
            
        } else {
            //calc node slots of current splay tree
            int tempNodeSlots = 0;
            for (int i = 0; i < countLevels; i++) {
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
        vector<vector<string> > tempDoubleVec;
        vector<string> tempVec;
        
        
        levelOrder.erase(0,1);
        cout << levelOrder;
        
        tempVec = splitStrIntoVector(levelOrder,'l');
        if (tempVec.empty()) {
            exit(1);
        }
        for (int i = 0; i < countLevels; i++) {
            tempVec[i].erase(0,1);
            tempDoubleVec.push_back(splitStrIntoVector(tempVec[i]));
        }
        
        int tempSize = 0;
        int visualLocation = 1;
        Location l;
                for (int i = 0; i < countLevels; i++) {
            tempSize = tempDoubleVec[i].size();
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
                        l.x = screenWidth/2;
                    } else if (visualLocation == 2) {
                        l.x = screenWidth/2 - 50;
                    } else {
                        int temp = ((i+1) / 2) - 1;
                        int temp2 = ((i+2) / 2) - 1;
                        if (visualSplay[temp2] == visualSplay[temp]) {
                            //left ptr
                            //int depth = splay->getHeight(splay->getRoot());
                            //
                            //cout << depth;
                            //int width = splay->getWidth(depth-1 - i);
                            l.x = screenWidth/2 + (50);
                        } else {
                            l.x = screenWidth/2 - (50);
                            //right ptr
                        }
                    }
                    l.y = screenHeight - 100 - (i * 70);
                    
                    

                    
                    
                    visualSplay[visualLocation] = new CircleNode(screen,alpha,tempDoubleVec[i][j],l);
                }
                visualLocation++;
            }
        }
        
    
        
        for (int i = 1; i < totalNodeSlots+1;i++) {
            if (visualSplay[i] != NULL) {
                visualSplay[i]->draw();
                cout << visualSplay[i]->getData() << endl;
            } else {
                cout << "NULL" << endl;
            }
        }
        
        for (int i = totalNodeSlots; i > 1;i--) {
            if (visualSplay[i] != NULL) {
                int temp;
                if (i == 2) {
                    temp = 1;
                } else {
                    temp = ((i+1) / 2) - 1;
                }
                Line lin(screen);
                cout << "first: " << i << " second: " << temp << endl;
                lin.draw(*visualSplay[i], *visualSplay[temp]);
                
            } else {
            }
        }
        
        
        /*Location rootLoc;
        rootLoc.x = screenWidth/2;
        rootLoc.y = screenHeight - 100;
        CircleNode rootCircle(screen,alpha,"19",rootLoc);
        rootCircle.draw();*/
        
       
        
        
        
        
        
        CircleNode* circleTree = new CircleNode[numNodes+1];
        
        /*for (int i = 0; i < size; i++) {
            if (str[i] != ' ') {
                if (str)
            }
        }
        
        //rootCircle.draw();

        /*int numNodes = splay->getNumNodes();
        for (int i = 0; i < numNodes; i++) {
            
        }*/
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

