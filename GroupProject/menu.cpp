//
//  menu.cpp
//  GroupProject
//
//  Created by Wallen, Alex on 4/25/16.
//  Copyright © 2016 Morgan Wesemann. All rights reserved.
//

#include "menu.h"

menuButton::menuButton(string d, Location l, int t) {
    data = d;
    loc = l;
    typeMode = (type)t;
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
    if( l.x < loc.x ) {
        //cout << "Loc is too far left" << endl;
        return false;
    }
    if( l.y > loc.y ) {
        //cout << "Loc is too far up" << endl;
        return false;
    }
    if( l.y < loc.y - 109 ) {
        //cout << "Loc is too far down" << endl;
        return false;
    }
    return true;
}

UI::UI(GLUT_Plotter* g, AlphanumericPlotter* a) {
    screen = g;
    alpha = a;
    buttons[0] = new menuButton("", Location(854, 768), 0);
    buttons[1] = new menuButton("INSERT", Location(854, 768 - (buttonHeight)), 0);
    buttons[2] = new menuButton("REMOVE", Location(854, 768 - (buttonHeight*2)), 0);
    buttons[3] = new menuButton("FIND", Location(854, 768 - (buttonHeight*3)), 1);
    buttons[4] = new menuButton("CENTER", Location(854, 768 - (buttonHeight*4)), 2);
    buttons[5] = new menuButton("CLEAR", Location(854, 768 - (buttonHeight*5)), 1);
    buttons[6] = new menuButton("QUIT", Location(854, 768 - (buttonHeight*6)), 1);
    selectedButton = NONE;
    init();
    
}

void UI::init(){
    //cout << "INIT" << endl;
    screen->setColor(0xffffff);
    for(int i = 0; i < 7; i++) {
        //cout << "INIT " << i << endl;
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
        
        alpha->plotString(buttons[i]->getData(), buttons[i]->getLocation().x + 10, buttons[i]->getLocation().y-80);

    }
}

bool UI::getClick(Location loc){
    for(int i = 0; i < 7; i++) {
        if(buttons[i]->isLocation(loc)){
            m = mode(6 - i);
            if ((6-i) == INSERT || (6-i) == REMOVE || (6-i) == FIND) {
                buttonSelect(6 - i);
            }
            //cout << "MODE = " << m << endl;
            return true;
        }
    }
    return false;
}

int UI::getButtonWidth() {
    return buttonWidth + 1;
}

int UI::getMode() {
    return m;
}

void UI::buttonSelect(int but) {
    if (selectedButton != NONE) {
        deselectButton();
    }
    screen->setColor(0x33cc33);
    alpha->isButton(true);
    alpha->plotString(buttons[but]->getData(), buttons[but]->getLocation().x + 10, buttons[but]->getLocation().y-80);
    alpha->isButton(false);
    screen->setColor(0xffffff);
    selectedButton = mode(but);
}

void UI::deselectButton() {
    if (selectedButton != NONE) {
        screen->setColor(0xffffff);
        alpha->isButton(true);
        alpha->plotString(buttons[selectedButton]->getData(), buttons[selectedButton]->getLocation().x + 10, buttons[selectedButton]->getLocation().y-80);
        alpha->isButton(false);
    }
}

void UI::redrawButton(int but, string data) {
    screen->setColor(0x000000);
    alpha->isButton(true);
    alpha->plotString(buttons[but]->getData(), buttons[but]->getLocation().x + 10, buttons[but]->getLocation().y-80);
    buttons[but]->setData(data);
    screen->setColor(0xffffff);
    alpha->plotString(buttons[but]->getData(), buttons[but]->getLocation().x + 10, buttons[but]->getLocation().y-80);
    alpha->isButton(false);
    
}
