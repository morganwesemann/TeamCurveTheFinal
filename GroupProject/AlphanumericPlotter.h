//
//  AlphanumericPlotter.h
//  3334groupproject
//
//  Created by Morgan Wesemann on 4/14/16.
//  Copyright © 2016 Morgan Wesemann. All rights reserved.
//

#ifndef AlphanumericPlotter_h
#define AlphanumericPlotter_h

#include "GLUT_Plotter.h"
#include <fstream>
#include <map>
#include <iostream>

struct character {
    vector<vector<char> > characterArray;
    int width, height;
    string fileName;
    character() {
        width = 0;
        height = 0;
        fileName = "";
    }
};

class AlphanumericPlotter {
private:
    map<char,character> characters;
    
    int numCharacters;
    int spaceAmount;
    
    unsigned int color;
    
    GLUT_Plotter* screen;
    
    void init();
public:
    
    AlphanumericPlotter(GLUT_Plotter* s);
    
    AlphanumericPlotter& operator=(GLUT_Plotter* s);
    
    ~AlphanumericPlotter();
    
    void plotString(string str, int x, int y);
    
};

#endif /* AlphanumericPlotter_h */
