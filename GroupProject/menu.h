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
    string data;
    string buffer;
    enum type {MODE, STATIC, CONFIRM};
    type typeMode;
    
public:
    
    menuButton(string d, Location l, int t) {
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
    GLUT_Plotter* screen;
    AlphanumericPlotter* alpha;
    menuButton* buttons[7];
    int buttonWidth = 170, buttonHeight = 109;
    enum mode {TEXT, INSERT, REMOVE, FIND, CENTER, CLEAR, QUIT, NONE};
    mode m;
    
    mode selectedButton;
    
public:
    UI(GLUT_Plotter* g, AlphanumericPlotter* a) {
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
    
    ~UI() {
        for(int i = 0; i < 7; i++) {
            delete buttons[i];
        }
    }
    
    void init();
    bool getClick(Location loc);
    
    int getButtonWidth() {
        return buttonWidth + 1;
    }
    
    int getMode() {
        return m;
    }
    
    void buttonSelect(int but) {
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
    
    void deselectButton() {
        if (selectedButton != NONE) {
            screen->setColor(0xffffff);
            alpha->isButton(true);
            alpha->plotString(buttons[selectedButton]->getData(), buttons[selectedButton]->getLocation().x + 10, buttons[selectedButton]->getLocation().y-80);
            alpha->isButton(false);
        }
    }
    
    void redrawButton(int but, string data) {
        screen->setColor(0x000000);
        alpha->isButton(true);
        alpha->plotString(buttons[but]->getData(), buttons[but]->getLocation().x + 10, buttons[but]->getLocation().y-80);
        buttons[but]->setData(data);
        screen->setColor(0xffffff);
        alpha->plotString(buttons[but]->getData(), buttons[but]->getLocation().x + 10, buttons[but]->getLocation().y-80);
        alpha->isButton(false);

    }
    
};

#endif /* menu_h */