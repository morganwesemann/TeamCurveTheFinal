/*
 * Authors: Adam Kim, Ean Evans, Alex Wallen, Morgan Wesemann
 * Project: VisualSplayTree
 * File: VisualSplay.h
 */

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
    
    SplayTree<int>* splay;              // pointer to splay tree
    GLUT_Plotter* screen;               // plotter for screen
    AlphanumericPlotter* alpha;         // alphanumeric plotter
        
    int totalNodeSlots;
    int totalNodes;
    int treeHeight;
    int screenHeight;
    int screenWidth;
    
    Location rootLoc;
    
    map<int,CircleNode*> visualMap;     // map <index, circleNodes>
    void buildVisualMap();                // converts vector<index, data>
                                        // to map<index, circleNodes>
    void updateLocations(Location loc);
public:
    
    VisualSplay(GLUT_Plotter* g, AlphanumericPlotter* a);
    void insert(int val);
    void remove(int val);
    void find(int val);
    void clearVisualMap();
    void clearTree();
    void draw();
    void moveTreeBy(Location loc);
    void moveTreeTo(Location loc);
    void setRoot(Location loc);
    
    VisualSplay()
    {
        cerr << "DEFAULT CONSTRUCTOR FOR VISUAL SPLAY CALLED, QUITTING..."<<endl;
        exit(-1);
    }
    
};

#endif /* VisualSplay_h */
