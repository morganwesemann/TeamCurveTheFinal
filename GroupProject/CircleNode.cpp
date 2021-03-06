/*
 * Authors: Adam Kim, Ean Evans, Alex Wallen, Morgan Wesemann
 * Project: VisualSplayTree
 * File: CircleNode.cpp
 */

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
            if (x > 0 && x < screen->getMaxPixelX() && y > 0 && y < screen->getHeight())
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

int CircleNode::getX() {
    return loc.x;
}

int CircleNode::getY() {
    return loc.y;
}

int CircleNode::getRadius()
{
    return radius;
}

void CircleNode::setRadius(int r)
{
    radius = r;
}

void CircleNode::setX(float xval)
{
    loc.x = xval;
}

void CircleNode::setY(float yval)
{
    loc.y = yval;
}

string CircleNode::getData()
{
    return data;
}
void CircleNode::setData(string str)
{
    data = str;
}


