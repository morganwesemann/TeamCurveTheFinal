/*
 * GroupProject.h
 *
 *  Created on: Mar 28, 2014
 *  Created on: Mar 28, 2014
 *      Author: Dr. Booth
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


class GroupProject{
private:
    GLUT_Plotter *g;
    
public:
    //constructor
    GroupProject(GLUT_Plotter* g);
    
    //Main GAIM FUNCTION
    void Play(void);
    
    void drawT();
};

#endif /* GroupProject_H_ */