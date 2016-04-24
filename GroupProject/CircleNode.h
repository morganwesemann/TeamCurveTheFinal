//
//  CircleNode.h
//  3334groupproject
//
//  Created by Morgan Wesemann on 4/15/16.
//  Copyright © 2016 Morgan Wesemann. All rights reserved.
//

#ifndef CircleNode_h
#define CircleNode_h

#include "Location.h"
#include "GLUT_Plotter.h"
#include "AlphanumericPlotter.h"
#include <cmath>

class CircleNode
{
private:
    GLUT_Plotter* screen;
    string data;
    AlphanumericPlotter* alpha;
    Location loc;
    int radius;
    
public:
    CircleNode()
    {
        screen = NULL;
        data = "";
        alpha = NULL;
        radius = 0;
    }
    CircleNode(GLUT_Plotter* g, AlphanumericPlotter* a, string d, Location l, int r = 40);
    
    void draw();
    
    void setLocation(Location l);
    void setRadius(int r);
    void setData(string str);
    
    Location getLocation();
    int getRadius();
    string getData();
};


#endif
