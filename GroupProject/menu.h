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
    
    void draw();
    
    void setLocation(Location l);
    void setData(string str);
    
    Location getLocation();
    int getX();
    int getY();
    string getData();

};

#endif /* menu_h */