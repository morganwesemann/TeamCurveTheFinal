//
//  menu.cpp
//  GroupProject
//
//  Created by Wallen, Alex on 4/25/16.
//  Copyright © 2016 Morgan Wesemann. All rights reserved.
//

#include "menu.h"

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
    return (l.x >= loc.x && l.x <= loc.x + width && l.y >= loc.y && l.y <= loc.y - height + 1);
}

void UI::init(){
    cout << "INIT" << endl;
    screen->setColor(0xffffff);
    for(int i = 0; i < 6; i++) {
        cout << "INIT " << i << endl;
        Line line(screen);
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
        
        alpha->plotString(buttons[i]->getData(), buttons[i]->getLocation().x + 10, buttons[i]->getLocation().y-50);

    }
}

void UI::getClick(Location loc){
    for(int i = 0; i < 6; i++) {
        if(buttons[i]->isLocation(buttons[i]->getLocation())){
            m = (mode)i;
            cout << "MODE IS NOW " << m;
            return;
        }
    }
}