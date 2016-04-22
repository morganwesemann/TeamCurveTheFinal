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
    
    
    cout << node1.getData();
    cout << node2.getData();
    float slope;
    
    if (l.y == c.y || l.x == c.x) {
        slope = 0;
    } else {
        slope = float((l.y - c.y)) / (l.x - c.x);
    }
    
    cout << "SLOPE: " << slope;
    
    
    int i, j;
    bool switchXY = false;
    CircleNode* lessNode = NULL;
    CircleNode* moreNode = NULL;
    if (l != c) {
        float theY = 0;
        //cout << "not equal" << endl;
        if (l.x != c.x) {
            //cout << "diff x" << endl;
            if (l.x < c.x)  {
                //cout << "first less" << endl;
                lessNode = &node1;
                moreNode = &node2;
                i = l.x;
                j = c.x;
                theY = l.y;
            } else {
                //cout << "second less" << endl;
                lessNode = &node2;
                moreNode = &node1;
                i = c.x;
                j = l.x;
                theY = c.y;
            }
        } else {
            //cout << "diff y" << endl;
            switchXY = true;
            if (l.y < c.y) {
                lessNode = &node1;
                moreNode = &node2;
                //cout << "first less" << endl;
                i = l.y;
                j = c.y;
                theY = l.x;
            } else {
                lessNode = &node2;
                moreNode = &node1;
                //cout << "second less" << endl;
                i = c.y;
                j = l.y;
                theY = c.x;
            }
        }
        
        while (i <= j) {
            
            if (switchXY) {
                if (theY > 0 && theY < screen->getWidth() && i > 0 && i < screen->getHeight()) {
                    Location temp = lessNode->getLocation();
                    Location temp2 = moreNode->getLocation();
                    float checkPoint = pow((i - temp.y),2) + pow((theY - temp.x),2);
                    float checkPoint2 = pow((i - temp2.y),2) + pow((theY - temp2.x),2);
                    if (checkPoint > pow(lessNode->getRadius(),2) && checkPoint2 > pow(moreNode->getRadius(),2)) {
                        screen->plot(theY, i);
                        screen->plot(theY+1, i);
                        screen->plot(theY, i+1);
                        screen->plot(theY-1, i);
                        screen->plot(theY, i-1);
                    }
                }
            } else {
                if (i > 0 && i < screen->getWidth() && theY > 0 && theY < screen->getHeight()) {
                    Location temp = lessNode->getLocation();
                    Location temp2 = moreNode->getLocation();
                    float checkPoint = pow((i - temp.x),2) + pow((theY - temp.y),2);
                    float checkPoint2 = pow((i - temp2.x),2) + pow((theY - temp2.y),2);
                    if (checkPoint > pow(lessNode->getRadius(),2) && checkPoint2 > pow(moreNode->getRadius(),2)) {
                        screen->plot(i, theY);
                        screen->plot(i-1, theY);
                        screen->plot(i+1, theY);
                        screen->plot(i, theY+1);
                        screen->plot(i, theY-1);
                    }
                }
            }
            theY += slope;
            
            i++;
        }
    }
    
    
    
}