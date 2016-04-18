//
//  Line.cpp
//  3334groupproject
//
//  Created by Morgan Wesemann on 4/15/16.
//  Copyright © 2016 Morgan Wesemann. All rights reserved.
//


#include "Line.h"

using namespace std;

Line::Line(GLUT_Plotter* g) {
    screen = g;
}

void Line::draw(CircleNode a, CircleNode b) {
    CircleNode node1 = a;
    CircleNode node2 = b;
    Location l;
    Location c;
    l = node1.getLocation();
    c = node2.getLocation();
    float slope = (l.y - c.y) / (l.x - c.x);
    
    int i, j;
    
    if (l != c) {
        if (l.x != c.x) {
            if (l.x < c.x) {
                i = l.x;
                j = c.x;
            } else {
                i = c.x;
                j = l.x;
            }
        } else {

            if (l.y < c.y) {
                i = l.y;
                j = c.y;
            } else {
                i = c.y;
                j = l.y;
            }
        }
        while (i <= j) {
            screen->plot(i, (slope*i));
            i++;
        }
    }
    
    
    
}