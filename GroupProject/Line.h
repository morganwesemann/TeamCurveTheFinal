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
    void drawBetweenNodes(CircleNode a, CircleNode b);
    void drawBetweenLocations(Location locA, Location locB);
};

#endif 