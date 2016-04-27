/*
 * Authors: Adam Kim, Ean Evans, Alex Wallen, Morgan Wesemann
 * Project: VisualSplayTree
 * File: menu.cpp
 */
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
    
    menuButton(string d, Location l, int t);
    
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
    UI(GLUT_Plotter* g, AlphanumericPlotter* a);
    
    ~UI() {
        for(int i = 0; i < 7; i++) {
            delete buttons[i];
        }
    }
    
    void init();
    bool getClick(Location loc);
    
    int getButtonWidth();
    
    int getMode();
    
    void buttonSelect(int but);
    
    void deselectButton();
    
    void redrawButton(int but, string data);
    
};

#endif /* menu_h */