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
#include "dirent.h"

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
    
    character charA;
    character charB;
    character charC;
    character charD;
    character charE;
    character charF;
    character charG;
    character charH;
    character charI;
    character charJ;
    character charK;
    character charL;
    character charM;
    character charN;
    character charO;
    character charP;
    character charQ;
    character charR;
    character charS;
    character charT;
    character charU;
    character charV;
    character charW;
    character charX;
    character charY;
    character charZ;
    character char0;
    character char1;
    character char2;
    character char3;
    character char4;
    character char5;
    character char6;
    character char7;
    character char8;
    character char9;
    
    int numCharacters;
    int spaceAmount;
    ifstream file;
    
    DIR * dirp;
    
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
