#include "Line.h"
using namespace std;

Line::Line(GLUT_Plotter* g)
{
    screen = g;
}

void Line::drawBetweenNodes(CircleNode a, CircleNode b) //this line connects 2 circlesnodes
{
    // requires 2 circle nodes
    CircleNode node1 = a;
    CircleNode node2 = b;
    Location locA, locB;
    float slope;
    
    locA = node1.getLocation();
    locB = node2.getLocation();
    
    //cout << node1.getData() << node2.getData(); //logging
    
    //if (locA.y == locB.y || locB.x == locA.x)
    if(locA == locB)
        slope = 0;
    else
        slope = float((locA.y - locB.y)) / (locA.x - locB.x);
    
    //cout << "SLOPE: " << slope; //logging
    
    
    int i, j; // position variables
    
    bool switchXY = false; //
    
    CircleNode* lessNode = NULL;
    CircleNode* moreNode = NULL;
    
    if (locA != locB) // if same, do not plot
    {
        float addedBySlope = 0;
        
        if (locA.x != locB.x) // only for nonvertical lines
        {
            if (locA.x < locB.x)
            {
                lessNode = &node1;
                moreNode = &node2;
                
                i = locA.x;
                j = locB.x;
                
                addedBySlope = locA.y;
            }
            else
            {
                lessNode = &node2;
                moreNode = &node1;
                
                i = locB.x;
                j = locA.x;
                
                addedBySlope = locB.y;
            }
        }
        else // only for vertical lines
        {
            switchXY = true;
            
            if (locA.y < locB.y)
            {
                lessNode = &node1;
                moreNode = &node2;
                
                i = locA.y;
                j = locB.y;
                addedBySlope = locA.x;
            }
            else
            {
                lessNode = &node2;
                moreNode = &node1;
                
                i = locB.y;
                j = locA.y;
                
                addedBySlope = locB.x;
            }
        }
        
        // here does actual drawing
        while (i <= j)
        {
            if (switchXY == true) // VERTICAL HERE
            {
                if (addedBySlope>0 && addedBySlope < screen->getWidth() && i>0 && i < screen->getHeight())
                {
                    // GETTING LOCATIONS
                    Location temp = lessNode->getLocation();
                    Location temp2 = moreNode->getLocation();
                    
                    // CHECKS LEFTMOST NODE IF POINT IS WITHIN CIRCLE
                    float checkLeft = pow((i - temp.y),2) + pow((addedBySlope - temp.x),2);
                    
                    // CHECKS RIGHTMOST NODE IF POINT IS WITHIN CIRCLE
                    float checkRight = pow((i - temp2.y),2) + pow((addedBySlope - temp2.x),2);
                    
                    // CONNECTS CIRCLE WITH LINE THAT DOES CROSS BORDER
                    if (checkLeft > pow(lessNode->getRadius(),2) && checkRight > pow(moreNode->getRadius(),2))
                    {
                        /*screen->plot(addedBySlope, i);
                        screen->plot(addedBySlope+1, i);
                        screen->plot(addedBySlope, i+1);
                        screen->plot(addedBySlope-1, i);
                        screen->plot(addedBySlope, i-1);*/
                        
                        if (addedBySlope - 1 >0 && addedBySlope - 1 < screen->getWidth()) {
                            screen->plot(addedBySlope-1, i);
                        }
                        
                        if (addedBySlope + 1 >0 && addedBySlope + 1 < screen->getWidth()) {
                            screen->plot(addedBySlope+1, i);
                        }
                        
                        if (i - 1 >0 && i - 1 < screen->getHeight()) {
                            screen->plot(addedBySlope, i-1);
                            
                        }
                    }
                }
            }
            else // NONVERTICAL LINES
            {
                if (i>0 && i < screen->getWidth() && addedBySlope>0 && addedBySlope < screen->getHeight())
                {
                    Location temp = lessNode->getLocation();
                    Location temp2 = moreNode->getLocation();
                    
                    float chckLeft = pow((i - temp.x),2) + pow((addedBySlope - temp.y),2);
                    float chckRight = pow((i - temp2.x),2) + pow((addedBySlope - temp2.y),2);
                    
                    if (chckLeft > pow(lessNode->getRadius(),2) && chckRight > pow(moreNode->getRadius(),2))
                    {
                        screen->plot(i, addedBySlope);
                        if (i - 1 >0 && i - 1 < screen->getWidth()) {
                            screen->plot(i-1, addedBySlope);
                        }
                        
                        if (i + 1 >0 && i + 1 < screen->getWidth()) {
                            screen->plot(i+1, addedBySlope);
                        }
                        
                        if (addedBySlope - 1 >0 && addedBySlope - 1 < screen->getHeight()) {
                            screen->plot(i, addedBySlope-1);

                        }
                        
                        if (addedBySlope + 1 >0 && addedBySlope + 1 < screen->getHeight()) {
                            screen->plot(i, addedBySlope+1);
                        }
                        
                        
                    }
                }
            }
            addedBySlope += slope;
            i++;
        }
    }
}

void Line::drawBetweenLocations(Location locA, Location locB) {
    float slope;
    
    //cout << node1.getData() << node2.getData(); //logging
    
    //if (locA.y == locB.y || locB.x == locA.x)
    if(locA == locB)
        slope = 0;
    else
        slope = float((locA.y - locB.y)) / (locA.x - locB.x);
    
    //cout << "SLOPE: " << slope; //logging
    
    
    int i, j; // position variables
    
    bool switchXY = false; //
    
    CircleNode* lessNode = NULL;
    CircleNode* moreNode = NULL;
    
    if (locA != locB) // if same, do not plot
    {
        float addedBySlope = 0;
        
        if (locA.x != locB.x) // only for nonvertical lines
        {
            if (locA.x < locB.x)
            {
                
                
                i = locA.x;
                j = locB.x;
                
                addedBySlope = locA.y;
            }
            else
            {
               
                
                i = locB.x;
                j = locA.x;
                
                addedBySlope = locB.y;
            }
        }
        else // only for vertical lines
        {
            switchXY = true;
            
            if (locA.y < locB.y)
            {
                
                
                i = locA.y;
                j = locB.y;
                addedBySlope = locA.x;
            }
            else
            {
                
                
                i = locB.y;
                j = locA.y;
                
                addedBySlope = locB.x;
            }
        }
        
        // here does actual drawing
        while (i <= j)
        {
            if (switchXY == true) // VERTICAL HERE
            {
                for (int j = -1; j < 1; j++) {
                    int x = addedBySlope+j;
                    int y = i;
                    if (x>0 && x < screen->getWidth() && y>0 && y < screen->getHeight())
                    {
                        screen->plot(x, y);
                    }
                }
                
                for (int j = -1; j < 1; j++) {
                    int x = addedBySlope;
                    int y = i+j;
                    if (x>0 && x < screen->getWidth() && y>0 && y < screen->getHeight())
                    {
                        screen->plot(x, y);
                    }
                }
                
                       /* screen->plot(addedBySlope+1, i);
                        screen->plot(addedBySlope, i+1);
                        screen->plot(addedBySlope-1, i);
                        screen->plot(addedBySlope, i-1);*/
                    
                
            }
            else // NONVERTICAL LINES
            {
                
                for (int j = -1; j < 1; j++) {
                    int y = addedBySlope+j;
                    int x = i;
                    if (x>0 && x < screen->getWidth() && y>0 && y < screen->getHeight())
                    {
                        screen->plot(x, y);
                    }
                }
                
                for (int j = -1; j < 1; j++) {
                    int y = addedBySlope;
                    int x = i+j;
                    if (x>0 && x < screen->getWidth() && y>0 && y < screen->getHeight())
                    {
                        screen->plot(x, y);
                    }
                }
                
                /*if (i>0 && i < screen->getWidth() && addedBySlope>0 && addedBySlope < screen->getHeight())
                {
                    Location temp = lessNode->getLocation();
                    Location temp2 = moreNode->getLocation();
                    
                    float chckLeft = pow((i - temp.x),2) + pow((addedBySlope - temp.y),2);
                    float chckRight = pow((i - temp2.x),2) + pow((addedBySlope - temp2.y),2);
                    
                    if (chckLeft > pow(lessNode->getRadius(),2) && chckRight > pow(moreNode->getRadius(),2))
                    {
                        screen->plot(i, addedBySlope);
                        if (i - 1 >0 && i - 1 < screen->getWidth()) {
                            screen->plot(i-1, addedBySlope);
                        }
                        
                        if (i + 1 >0 && i + 1 < screen->getWidth()) {
                            screen->plot(i-1, addedBySlope);
                        }
                        
                        if (addedBySlope - 1 >0 && addedBySlope - 1 < screen->getHeight()) {
                            screen->plot(i, addedBySlope-1);
                            
                        }
                        
                        if (addedBySlope + 1 >0 && addedBySlope + 1 < screen->getHeight()) {
                            screen->plot(i, addedBySlope+1);
                        }
                        
                        
                    }
                }*/
            }
            addedBySlope += slope;
            i++;
        }
    }

}