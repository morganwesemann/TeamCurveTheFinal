//
//  CircleNodeIMPL.h
//  3334groupproject
//
//  Created by Morgan Wesemann on 4/15/16.
//  Copyright © 2016 Morgan Wesemann. All rights reserved.
//


#include "CircleNode.h"

CircleNode::CircleNode(GLUT_Plotter* g, AlphanumericPlotter* a, string d, Location l, int r)
{
     screen = g;
     data = d;
     loc = l;
     radius = r;
     alpha = a;
}

void CircleNode::draw()
{
    // Geometry variables
    float twoPi = 2.0 * M_PI;
    float x, y;
    
    for(int i = 0; i <= 360;i++)
    {
        for(int padding = -1; padding <= 1; padding++)
        {
            x = loc.x + ((radius+padding) * cos(i *  twoPi / 360));
            y = loc.y + ((radius+padding) * sin(i * twoPi / 360));
            if (x > 0 && x < screen->getWidth() && y > 0 && y < screen->getHeight())
            {
                screen->plot(x,y);
            }
        }
    }
    
    int pixelWidth = (alpha->getPixelWidth(data) / 2) - 2;
    
    alpha->plotString(data, loc.x-pixelWidth, loc.y+11);
    
}

void CircleNode::setLocation(Location l)
{
    loc = l;
}

Location CircleNode::getLocation()
{
    return loc;
}

int CircleNode::getRadius()
{
    return radius;
}

void CircleNode::setRadius(int r)
{
    radius = r;
}

string CircleNode::getData()
{
    return data;
}
void CircleNode::setData(string str)
{
    data = str;
}


