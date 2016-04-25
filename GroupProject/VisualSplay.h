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
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

class VisualSplay {
private:
    map<int,CircleNode*> visualMap;     // nodes
    
    SplayTree<int>* splay;              // pointer to splay tree
    
    GLUT_Plotter* screen;               // plotter
    
    AlphanumericPlotter* alpha;         // alphanumeric plotter
        
    int totalNodeSlots;
    int treeHeight;
    
    int screenHeight;
    int screenWidth;
    
    Location rootLoc;
    
    void deleteVisualSplay();
    
    void updateTree();
    
    void checkBalance();
    
public:
    
    void insert(int val);
    void remove(int val);
    void clear();
    void draw();
    
    void moveTree(Location loc);
    
    VisualSplay(){exit(-10);}
    
    VisualSplay(GLUT_Plotter* g, AlphanumericPlotter* a);
};

#endif /* VisualSplay_h */
