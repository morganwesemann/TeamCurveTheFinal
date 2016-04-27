/*
 * Authors: Adam Kim, Ean Evans, Alex Wallen, Morgan Wesemann
 * Project: VisualSplayTree
 * File: GroupProject.h
 */
#ifndef GroupProject_H_
#define GroupProject_H_
#include "GLUT_Plotter.h"
#include "AlphanumericPlotter.h"
#include "CircleNode.h"
#include "Line.h"
#include <fstream>
#include <cmath>
#include <iostream>
#include "VisualSplay.h"
#include "menu.h"


class GroupProject
{
private:
    GLUT_Plotter *g;
    VisualSplay *v;
    AlphanumericPlotter *alpha;
    UI *gui;
    int screenHeight;
    int screenWidth;
    int maxPixelX;
    bool doInsert = false;
    bool doDelete = false;
    bool doFind = false;
    string ourNumber;
    Location changedLoc;
    Location oldLoc;
    enum mode {TEXT, INSERT, REMOVE, FIND, CENTER, CLEAR, QUIT, NONE};
    
public:
    GroupProject(GLUT_Plotter* g);
    ~GroupProject();
    void Play(void);
    };

#endif /* GroupProject_H_ */