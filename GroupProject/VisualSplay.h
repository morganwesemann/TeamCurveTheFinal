//
//  VisualSplay.h
//  GroupProject
//
//  Created by Morgan Wesemann on 4/18/16.
//  Copyright © 2016 Morgan Wesemann. All rights reserved.
//

#ifndef VisualSplay_h
#define VisualSplay_h

#include <cstdlib>
#include <iostream>
#include "AlphaNumericPlotter.h"
#include "Line.h"
#include "CircleNode.h"
#include "Group0Splay.h"
#include <string>
#include "Group0SplayIMPL.h"
#include <sstream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

class VisualSplay {
private:
    vector<CircleNode* > visualSplay;
    SplayTree<int>* splay;
    GLUT_Plotter* screen;
    AlphanumericPlotter* alpha;
    vector<string> splitStrIntoVector(string str, const char &d = ' ');
    int totalNodeSlots;
    int treeHeight;
    int screenHeight;
    int screenWidth;
    
    Location rootLoc;
    
    void deleteVisualSplay();
    void updateTree();
public:
    
    void insert(int val);
    void remove(int val);
    void clear();
    void draw();
    
    void moveTree(Location loc);
    
    VisualSplay() {
        exit(1);
    }
    
    VisualSplay(GLUT_Plotter* g, AlphanumericPlotter* a);
};

#endif /* VisualSplay_h */
