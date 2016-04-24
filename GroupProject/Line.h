//
//  Line.h
//  3334groupproject
//
//  Created by Morgan Wesemann on 4/15/16.
//  Copyright © 2016 Morgan Wesemann. All rights reserved.
//

#ifndef Line_h
#define Line_h

#include "Location.h"
#include "GLUT_Plotter.h"
#include "AlphanumericPlotter.h"
#include "CircleNode.h"
#include <cmath>
#include <iostream>

class Line
{
private:
    GLUT_Plotter* screen;
    
public:
    Line(GLUT_Plotter* g);
    
    void draw(CircleNode a, CircleNode b);
};

#endif /* Line_h */
