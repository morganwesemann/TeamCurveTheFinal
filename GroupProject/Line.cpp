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
    
    
    
    float slope;
    
    if (l.y == c.y || l.x == c.x) {
        slope = 0;
    } else {
        slope = (l.y - c.y) / (l.x - c.x);
    }
    
    
    int i, j;
    bool switchXY = false;
    if (l != c) {
        int theY = 0;
        cout << "not equal" << endl;
        if (l.x != c.x) {
            cout << "diff x" << endl;
            if (l.x < c.x)  {
                cout << "first less" << endl;
                i = l.x;
                j = c.x;
                theY = l.y;
            } else {
                cout << "second less" << endl;
                i = c.x;
                j = l.x;
                theY = c.y;
            }
        } else {
            cout << "diff y" << endl;
            switchXY = true;
            if (l.y < c.y) {
            
                cout << "first less" << endl;
                i = l.y;
                j = c.y;
                theY = l.x;
            } else {
                cout << "second less" << endl;
                i = c.y;
                j = l.y;
                theY = c.x;
            }
        }
        
        while (i <= j) {
            
            if (switchXY) {
                screen->plot(theY, i);
            } else {
                screen->plot(i, theY);
            }
            theY += slope;
            
            //screen->plot(i-1, theY-1);
            //screen->plot(i+1, theY+1);
            //cout << i << endl;
            
            i++;
        }
    }
    
    
    
}