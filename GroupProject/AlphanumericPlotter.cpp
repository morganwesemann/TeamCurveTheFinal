//
//  AlphanumericPlotter.cpp
//  3334groupproject
//
//  Created by Morgan Wesemann on 4/14/16.
//  Copyright © 2016 Morgan Wesemann. All rights reserved.
//

#include "AlphanumericPlotter.h"

AlphanumericPlotter::AlphanumericPlotter(GLUT_Plotter* g) {
    screen = g;
    numCharacters = 36;
    spaceAmount = 5;
    init();
    
}

AlphanumericPlotter::~AlphanumericPlotter() {
}

//it's ugly BUT IT WORKS
//to update and clean up
void AlphanumericPlotter::init() {
    string dummyText;
    char c;
    ifstream file;
    string fileName;
    char fileCharacter;
    
    string extension = ".txt";
    for (char i = 'A'; i <= 'Z'; i++) {
        fileName = "Characters/";
       
        fileName += i;
        fileName += extension;
        
        file.open(fileName.c_str());
        if (!file) {
            cout << "FATAL ERROR: Assets not found. Exiting program.";
            exit(1);
        }
        
        //skip ten lines
        for (int i = 0; i < 10; i++) {
            getline(file,dummyText);
        }
        
        file >> fileCharacter;
        
        map<char,character>::iterator it;
        
        it = characters.find(fileCharacter);
        
        if (it == characters.end()) {
            //this means the character is not already in, so add
            character tempChar;
            
            file >> tempChar.width >> tempChar.height;
            //store in vector
            for (int i = 0; i < tempChar.height; i++) {
                vector<char> temp;
                for (int j =0; j < tempChar.width; j++) {
                    file >> c;
                    temp.push_back(c);
                }
                tempChar.characterArray.push_back(temp);
            }

            characters[fileCharacter] = tempChar;
        }
        
        
        file.close();
        file.clear();
    }
    
    for (char i = '0'; i <= '9'; i++) {
        fileName = "Characters/";
        
        fileName += i;
        fileName += extension;
        
        file.open(fileName.c_str());
        if (!file) {
            cout << "FATAL ERROR: Assets not found. Exiting program.";
            exit(1);
        }
        
        //skip ten lines
        for (int i = 0; i < 10; i++) {
            getline(file,dummyText);
        }
        
        file >> fileCharacter;
        
        map<char,character>::iterator it;
        
        it = characters.find(fileCharacter);
        
        if (it == characters.end()) {
            //this means the character is not already in, so add
            character tempChar;
            
            file >> tempChar.width >> tempChar.height;
            //store in vector
            for (int i = 0; i < tempChar.height; i++) {
                vector<char> temp;
                for (int j =0; j < tempChar.width; j++) {
                    file >> c;
                    temp.push_back(c);
                }
                tempChar.characterArray.push_back(temp);
            }
            
            characters[fileCharacter] = tempChar;
        }
        
        
        file.close();
        file.clear();
    }
    
}

void AlphanumericPlotter::plotString(string str, int x, int y) {
    int size = str.length();
    character* charPtr;
    char c;
    for (int i = 0; i < size; i++) {
        c = str[i];
    
        map<char,character>::iterator it;
        
        it = characters.find(c);
        
        if (c != ' ' && it != characters.end()) {
            charPtr = &characters[c];
            //we loop through the vector and output the corresponding color
            int h = charPtr->height;
            for (int j = 0; j < h; j++) {
                for (int k = 0; k < charPtr->width; k++) {
                    c = charPtr->characterArray[j][k];
                    if (c == '1') {
                        screen->setColor(0xffffff);
                        screen->plot(x+k,y-j);

                    }
                }
                
                
            }
        } else {
            
        }
        
        x+= spaceAmount + charPtr->width;
    }
}

AlphanumericPlotter& AlphanumericPlotter::operator=(GLUT_Plotter* s) {
    screen = s;
    init();
    return *this;
}
