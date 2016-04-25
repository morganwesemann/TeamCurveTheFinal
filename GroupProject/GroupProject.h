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


class GroupProject
{
private:
    GLUT_Plotter *g;
    VisualSplay *v;
    AlphanumericPlotter *alpha;
    int screenHeight;
    int screenWidth;
    int maxPixelX;
    
public:
    GroupProject(GLUT_Plotter* g);
    void Play(void);
};

#endif /* GroupProject_H_ */