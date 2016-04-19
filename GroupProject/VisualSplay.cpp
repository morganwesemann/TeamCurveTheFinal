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
}


void VisualSplay::insert(int val) {
    splay->insert(val);
}

void VisualSplay::remove(int val) {
    splay->remove(val);
}

void VisualSplay::clear() {
    delete splay;
}

void VisualSplay::draw() {
    if (splay != NULL) {
        int screenHeight, screenWidth;
        screenHeight = screen->getHeight();
        screenWidth = screen->getWidth();
        Location rootLoc;
        rootLoc.x = screenWidth/2;
        rootLoc.y = screenHeight - 100;
        CircleNode rootCircle(screen,alpha,"AI",rootLoc);
        ostringstream thestream;
        splay->printLevelOrderInt(thestream);
        string str = thestream.str();
        
        
        int size = str.length();
        int numNodes = splay->getNumNodes();
        CircleNode* circleTree = new CircleNode[numNodes];
        
        for (int i = 0; i < size; i++) {
            if (str[i] != ' ') {
                
            }
        }
        
        rootCircle.draw();

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

