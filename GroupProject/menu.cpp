//
//  menu.cpp
//  GroupProject
//
//  Created by Wallen, Alex on 4/25/16.
//  Copyright © 2016 Morgan Wesemann. All rights reserved.
//

#include "menu.h"

void menuButton::draw() {
    Line line(screen);
    Location tl, tr, bl, br;
    tl = getLocation();
    tr = getLocation();
    bl = getLocation();
    br = getLocation();
    
    tr.x += width;
    
    bl.y -= height;
    
    br.x += width;
    br.y -= height;
    
    //cout << "TL: " << tl.x << ", " << tl.y << endl;
    //cout << "TR: " << tr.x << ", " << tr.y << endl;
    //cout << "BL: " << bl.x << ", " << bl.y << endl;
    //cout << "BR: " << br.x << ", " << br.y << endl;
    
    line.drawBetweenLocations(tl, tr);
    line.drawBetweenLocations(tl, bl);
    line.drawBetweenLocations(tr, br);
    line.drawBetweenLocations(bl, br);
    
    alpha->plotString(data, loc.x, loc.y-30);
    
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

bool menuButton::isLocation(Location l){
    return (l.x >= loc.x && l.x <= loc.x + width && l.y >= loc.y && l.y <= loc.y + height);
}

void action(){
    
}

void UI::init(){
    Location insertBut(1024-170, 768);
    Location removeBut(1024-170, 768-109);
    Location clearBut(1024-170, 768-109-109);
    Location centerBut(1024-170, 768-109-109-109);
    menuButton buttons[4];
    buttons[0] = menuButton(g, alpha, "INSERT", insertBut, 0);
    buttons[1] = menuButton(g, alpha, "REMOVE", removeBut, 0);
    buttons[2] = menuButton(g, alpha, "CLEAR", clearBut, 0);
    buttons[3] = menuButton(g, alpha, "CENTER", centerBut, 0);
    initMenu(buttons, 4);
}

void UI::getClick(Location loc){
    for(int i = 0; i < 7; i++) {
        if(buttons[i].isLocation(buttons[i].getLocation())){
            //do stuff
        }
    }
}