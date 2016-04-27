/*
 * Authors: Adam Kim, Ean Evans, Alex Wallen, Morgan Wesemann
 * Project: VisualSplayTree
 * File: AlphanumericPlotter.h
 */
#ifndef AlphanumericPlotter_h
#define AlphanumericPlotter_h

#include "GLUT_Plotter.h"
#include <fstream>
#include <map>
#include <iostream>


struct character
{
    // 2 dimensional vector of characters
    vector<vector<char> > characterArray;
    
    int width, height;
    
    string fileName;
    
    character()
    {
        width = 0;
        height = 0;
        fileName = "";
    }
};

class AlphanumericPlotter
{
private:
    map<char,character> characters;
    
    int numCharacters, spaceAmount;
    
    unsigned int color;
    
    GLUT_Plotter* screen;
    
    bool isMenu;
    
    void init();
public:
    
    AlphanumericPlotter(GLUT_Plotter* s);
    
    AlphanumericPlotter& operator=(AlphanumericPlotter& a);
    
    ~AlphanumericPlotter();
    
    void plotString(string str, int x, int y);

    int getPixelWidth(string str);
    
    void isButton(bool b);
    
};

#endif
