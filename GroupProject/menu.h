//
//  menu.h
//  GroupProject
//
//  Created by Wallen, Alex on 4/25/16.
//  Copyright © 2016 Morgan Wesemann. All rights reserved.
//

#ifndef menu_h
#define menu_h

#include "AlphanumericPlotter.h"
#include "GLUT_Plotter.h"
#include "Location.h"
#include "Line.h"



class menuButton {
    
private:
    Location loc;
    int width = 170, height = 109;
    AlphanumericPlotter* alpha;
    GLUT_Plotter* screen;
    string data;
    string buffer;
    enum type {MODE, STATIC, CONFIRM};
    type typeMode;
    
public:
    menuButton() {
        screen = NULL;
        data = "";
        alpha = NULL;
    }
    
    menuButton(GLUT_Plotter* g, AlphanumericPlotter* a, string d, Location l, int t) {
        screen = g;
        alpha = a;
        data = d;
        loc = l;
        typeMode = (type)t;
    }
    
    void draw();
    
    void setLocation(Location l);
    void setData(string str);
    
    Location getLocation();
    int getX();
    int getY();
    string getData();
    
    bool isLocation(Location);
    
    void action();

};

class UI {
private:
    menuButton buttons[7];
    
public:
    void init();
    void getClick(Location loc);
    
};

#endif /* menu_h */