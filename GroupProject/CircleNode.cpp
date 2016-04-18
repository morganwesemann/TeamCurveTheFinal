//
//  CircleNodeIMPL.h
//  3334groupproject
//
//  Created by Morgan Wesemann on 4/15/16.
//  Copyright © 2016 Morgan Wesemann. All rights reserved.
//


#include "CircleNode.h"

CircleNode::CircleNode(GLUT_Plotter* g, AlphanumericPlotter* a, string d, Location l, int r) {
 screen = g;
 data = d;
 loc = l;
 radius = r;
 alpha = a;
 }

void CircleNode::draw() {
    
    //radius
    
    float twoPi = 2.0 * M_PI;
    
    for(int i = 0; i <= 360;i++) {
        screen->plot(
                     loc.x + (radius * cos(i *  twoPi / 360)),
                     loc.y + (radius * sin(i * twoPi / 360))
                    );
        screen->plot(
                     loc.x + ((radius-1) * cos(i *  twoPi / 360)),
                     loc.y + ((radius-1) * sin(i * twoPi / 360))
                     );
        screen->plot(
                     loc.x + ((radius+1) * cos(i *  twoPi / 360)),
                     loc.y + ((radius+1) * sin(i * twoPi / 360))
                     );
    }
    alpha->plotString(data, loc.x-23, loc.y+11);
}

void CircleNode::setLocation(Location l) {
    loc = l;
}

Location CircleNode::getLocation() {
    return loc;
}

int CircleNode::getRadius() {
    return radius;
}


void CircleNode::setRadius(int r) {
    radius = r;
}


