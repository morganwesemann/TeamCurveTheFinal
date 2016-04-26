//
//  menu.cpp
//  GroupProject
//
//  Created by Wallen, Alex on 4/25/16.
//  Copyright © 2016 Morgan Wesemann. All rights reserved.
//

#include "menu.h"

void menuButton::draw() {
    
    
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
    cout << "INIT" << endl;
    for(int i = 0; i < 7; i++) {
        cout << "INIT " << i << endl;
        Line line(screen);
        line.drawBetweenLocations(Location(0,0), Location(700, 700));
        alpha->plotString("TEST", 500, 500);
        Location tl, tr, bl, br;
        tl = buttons[i]->getLocation();
        tr = buttons[i]->getLocation();
        bl = buttons[i]->getLocation();
        br = buttons[i]->getLocation();
        
        tr.x += buttonWidth;
        
        bl.y -= buttonHeight;
        
        br.x += buttonWidth;
        br.y -= buttonHeight;
        
        //cout << "TL: " << tl.x << ", " << tl.y << endl;
        //cout << "TR: " << tr.x << ", " << tr.y << endl;
        //cout << "BL: " << bl.x << ", " << bl.y << endl;
        //cout << "BR: " << br.x << ", " << br.y << endl;
        
        line.drawBetweenLocations(tl, tr);
        line.drawBetweenLocations(tl, bl);
        line.drawBetweenLocations(tr, br);
        line.drawBetweenLocations(bl, br);
        
        alpha->plotString(buttons[i]->getData(), buttons[i]->getLocation().x, buttons[i]->getLocation().y-30);

    }
}

void UI::getClick(Location loc){
    for(int i = 0; i < 7; i++) {
        if(buttons[i]->isLocation(buttons[i]->getLocation())){
            //do stuff
        }
    }
}