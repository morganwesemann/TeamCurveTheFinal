//
//  menu.cpp
//  GroupProject
//
//  Created by Wallen, Alex on 4/25/16.
//  Copyright © 2016 Morgan Wesemann. All rights reserved.
//

#include "menu.h"

void menuButton::draw() {
    Location tl , tr, bl, br;
    tl = getLocation();
    tr = getLocation();
    bl = getLocation();
    br = getLocation();
    
    tr.x += width;
    
    bl.y += height;
    
    br.x += width;
    br.y += height;
    
    //drawLine(tl, tr);
    //drawLine(tl, bl);
    //drawLine(tr, br);
    //drawLine(bl, br);
    
    //alpha->plotString(data, loc.x + 20, loc.y + 40);
    
}

void menuButton::setLocation(Location l) {
    loc = l;
}

void menuButton::setData(string str){
    data = str;
}

Location menuButton::getLocation(){
    return loc;
}

int menuButton::getX(){
    return loc.x;
}

int menuButton::getY(){
    return loc.y;
}

string menuButton::getData(){
    return data;
}