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
    spaceAmount = 10;
    init();
    
}

AlphanumericPlotter::~AlphanumericPlotter() {
}

//it's ugly BUT IT WORKS
//to update and clean up
void AlphanumericPlotter::init() {
    string dummyText;
    char c;
    
    file.open("Characters/A.txt");
    if (!file) {
        //cout << "FATAL ERROR: Assets not found. Exiting program.";
        exit(1);
    }
    
    //skip ten lines
    for (int i = 0; i < 10; i++) {
        getline(file,dummyText);
    }
    
    file >> charA.width >> charA.height;
    //store in vector
    for (int i = 0; i < charA.height; i++) {
        vector<char> temp;
        for (int j =0; j < charA.width; j++) {
            file >> c;
            temp.push_back(c);
        }
        charA.characterArray.push_back(temp);
    }
    
    file.close();
    file.clear();
    
    file.open("Characters/B.txt");
    if (!file) {
        //cout << "FATAL ERROR: Assets not found. Exiting program.";
        exit(1);
    }
    
    //skip ten lines
    for (int i = 0; i < 10; i++) {
        getline(file,dummyText);
    }
    
    file >> charB.width >> charB.height;
    //store in vector
    for (int i = 0; i < charB.height; i++) {
        vector<char> temp;
        for (int j =0; j < charB.width; j++) {
            file >> c;
            temp.push_back(c);
        }
        charB.characterArray.push_back(temp);
    }
    
    file.close();
    file.clear();
    
    file.open("Characters/C.txt");
    if (!file) {
        //cout << "FATAL ERROR: Assets not found. Exiting program.";
        exit(1);
    }
    
    //skip ten lines
    for (int i = 0; i < 10; i++) {
        getline(file,dummyText);
    }
    
    file >> charC.width >> charC.height;
    //store in vector
    for (int i = 0; i < charC.height; i++) {
        vector<char> temp;
        for (int j =0; j < charC.width; j++) {
            file >> c;
            temp.push_back(c);
        }
        charC.characterArray.push_back(temp);
    }
    
    file.close();
    file.clear();
    
    file.open("Characters/D.txt");
    if (!file) {
        //cout << "FATAL ERROR: Assets not found. Exiting program.";
        exit(1);
    }
    
    //skip ten lines
    for (int i = 0; i < 10; i++) {
        getline(file,dummyText);
    }
    
    file >> charD.width >> charD.height;
    //store in vector
    for (int i = 0; i < charD.height; i++) {
        vector<char> temp;
        for (int j =0; j < charD.width; j++) {
            file >> c;
            temp.push_back(c);
        }
        charD.characterArray.push_back(temp);
    }
    
    file.close();
    file.clear();
    
    file.open("Characters/E.txt");
    if (!file) {
        //cout << "FATAL ERROR: Assets not found. Exiting program.";
        exit(1);
    }
    
    //skip ten lines
    for (int i = 0; i < 10; i++) {
        getline(file,dummyText);
    }
    
    file >> charE.width >> charE.height;
    //store in vector
    for (int i = 0; i < charE.height; i++) {
        vector<char> temp;
        for (int j =0; j < charE.width; j++) {
            file >> c;
            temp.push_back(c);
        }
        charE.characterArray.push_back(temp);
    }
    
    file.close();
    file.clear();
    
    file.open("Characters/F.txt");
    if (!file) {
        //cout << "FATAL ERROR: Assets not found. Exiting program.";
        exit(1);
    }
    
    //skip ten lines
    for (int i = 0; i < 10; i++) {
        getline(file,dummyText);
    }
    
    file >> charF.width >> charF.height;
    //store in vector
    for (int i = 0; i < charF.height; i++) {
        vector<char> temp;
        for (int j =0; j < charF.width; j++) {
            file >> c;
            temp.push_back(c);
        }
        charF.characterArray.push_back(temp);
    }
    
    file.close();
    file.clear();
    
    file.open("Characters/G.txt");
    if (!file) {
        //cout << "FATAL ERROR: Assets not found. Exiting program.";
        exit(1);
    }
    
    //skip ten lines
    for (int i = 0; i < 10; i++) {
        getline(file,dummyText);
    }
    
    file >> charG.width >> charG.height;
    //store in vector
    for (int i = 0; i < charG.height; i++) {
        vector<char> temp;
        for (int j =0; j < charG.width; j++) {
            file >> c;
            temp.push_back(c);
        }
        charG.characterArray.push_back(temp);
    }
    
    file.close();
    file.clear();
    
    file.open("Characters/H.txt");
    if (!file) {
        //cout << "FATAL ERROR: Assets not found. Exiting program.";
        exit(1);
    }
    
    //skip ten lines
    for (int i = 0; i < 10; i++) {
        getline(file,dummyText);
    }
    
    file >> charH.width >> charH.height;
    //store in vector
    for (int i = 0; i < charH.height; i++) {
        vector<char> temp;
        for (int j =0; j < charH.width; j++) {
            file >> c;
            temp.push_back(c);
        }
        charH.characterArray.push_back(temp);
    }
    
    file.close();
    file.clear();
    
    file.open("Characters/I.txt");
    if (!file) {
        //cout << "FATAL ERROR: Assets not found. Exiting program.";
        exit(1);
    }
    
    //skip ten lines
    for (int i = 0; i < 10; i++) {
        getline(file,dummyText);
    }
    
    file >> charI.width >> charI.height;
    //store in vector
    for (int i = 0; i < charI.height; i++) {
        vector<char> temp;
        for (int j =0; j < charI.width; j++) {
            file >> c;
            temp.push_back(c);
        }
        charI.characterArray.push_back(temp);
    }
    
    file.close();
    file.clear();
    
    file.open("Characters/J.txt");
    if (!file) {
        //cout << "FATAL ERROR: Assets not found. Exiting program.";
        exit(1);
    }
    
    //skip ten lines
    for (int i = 0; i < 10; i++) {
        getline(file,dummyText);
    }
    
    file >> charJ.width >> charJ.height;
    //store in vector
    for (int i = 0; i < charJ.height; i++) {
        vector<char> temp;
        for (int j =0; j < charJ.width; j++) {
            file >> c;
            temp.push_back(c);
        }
        charJ.characterArray.push_back(temp);
    }
    
    file.close();
    file.clear();
    
    file.open("Characters/K.txt");
    if (!file) {
        //cout << "FATAL ERROR: Assets not found. Exiting program.";
        exit(1);
    }
    
    //skip ten lines
    for (int i = 0; i < 10; i++) {
        getline(file,dummyText);
    }
    
    file >> charK.width >> charK.height;
    //store in vector
    for (int i = 0; i < charK.height; i++) {
        vector<char> temp;
        for (int j =0; j < charK.width; j++) {
            file >> c;
            temp.push_back(c);
        }
        charK.characterArray.push_back(temp);
    }
    
    file.close();
    file.clear();
    
    file.open("Characters/L.txt");
    if (!file) {
        //cout << "FATAL ERROR: Assets not found. Exiting program.";
        exit(1);
    }
    
    //skip ten lines
    for (int i = 0; i < 10; i++) {
        getline(file,dummyText);
    }
    
    file >> charL.width >> charL.height;
    //store in vector
    for (int i = 0; i < charL.height; i++) {
        vector<char> temp;
        for (int j =0; j < charL.width; j++) {
            file >> c;
            temp.push_back(c);
        }
        charL.characterArray.push_back(temp);
    }
    
    file.close();
    file.clear();
    
    file.open("Characters/M.txt");
    if (!file) {
        //cout << "FATAL ERROR: Assets not found. Exiting program.";
        exit(1);
    }
    
    //skip ten lines
    for (int i = 0; i < 10; i++) {
        getline(file,dummyText);
    }
    
    file >> charM.width >> charM.height;
    //store in vector
    for (int i = 0; i < charM.height; i++) {
        vector<char> temp;
        for (int j =0; j < charM.width; j++) {
            file >> c;
            temp.push_back(c);
        }
        charM.characterArray.push_back(temp);
    }
    
    file.close();
    file.clear();
    
    file.open("Characters/N.txt");
    if (!file) {
        //cout << "FATAL ERROR: Assets not found. Exiting program.";
        exit(1);
    }
    
    //skip ten lines
    for (int i = 0; i < 10; i++) {
        getline(file,dummyText);
    }
    
    file >> charN.width >> charN.height;
    //store in vector
    for (int i = 0; i < charN.height; i++) {
        vector<char> temp;
        for (int j =0; j < charN.width; j++) {
            file >> c;
            temp.push_back(c);
        }
        charN.characterArray.push_back(temp);
    }
    
    file.close();
    file.clear();
    
    file.open("Characters/O.txt");
    if (!file) {
        //cout << "FATAL ERROR: Assets not found. Exiting program.";
        exit(1);
    }
    
    //skip ten lines
    for (int i = 0; i < 10; i++) {
        getline(file,dummyText);
    }
    
    file >> charO.width >> charO.height;
    //store in vector
    for (int i = 0; i < charO.height; i++) {
        vector<char> temp;
        for (int j =0; j < charO.width; j++) {
            file >> c;
            temp.push_back(c);
        }
        charO.characterArray.push_back(temp);
    }
    
    file.close();
    file.clear();
    
    file.open("Characters/P.txt");
    if (!file) {
        //cout << "FATAL ERROR: Assets not found. Exiting program.";
        exit(1);
    }
    
    //skip ten lines
    for (int i = 0; i < 10; i++) {
        getline(file,dummyText);
    }
    
    file >> charP.width >> charP.height;
    //store in vector
    for (int i = 0; i < charP.height; i++) {
        vector<char> temp;
        for (int j =0; j < charP.width; j++) {
            file >> c;
            temp.push_back(c);
        }
        charP.characterArray.push_back(temp);
    }
    
    file.close();
    file.clear();
    
    file.open("Characters/Q.txt");
    if (!file) {
        //cout << "FATAL ERROR: Assets not found. Exiting program.";
        exit(1);
    }
    
    //skip ten lines
    for (int i = 0; i < 10; i++) {
        getline(file,dummyText);
    }
    
    file >> charQ.width >> charQ.height;
    //store in vector
    for (int i = 0; i < charQ.height; i++) {
        vector<char> temp;
        for (int j =0; j < charQ.width; j++) {
            file >> c;
            temp.push_back(c);
        }
        charQ.characterArray.push_back(temp);
    }
    
    file.close();
    file.clear();
    
    file.open("Characters/R.txt");
    if (!file) {
        //cout << "FATAL ERROR: Assets not found. Exiting program.";
        exit(1);
    }
    
    //skip ten lines
    for (int i = 0; i < 10; i++) {
        getline(file,dummyText);
    }
    
    file >> charR.width >> charR.height;
    //store in vector
    for (int i = 0; i < charR.height; i++) {
        vector<char> temp;
        for (int j =0; j < charR.width; j++) {
            file >> c;
            temp.push_back(c);
        }
        charR.characterArray.push_back(temp);
    }
    
    file.close();
    file.clear();
    
    file.open("Characters/S.txt");
    if (!file) {
        //cout << "FATAL ERROR: Assets not found. Exiting program.";
        exit(1);
    }
    
    //skip ten lines
    for (int i = 0; i < 10; i++) {
        getline(file,dummyText);
    }
    
    file >> charS.width >> charS.height;
    //store in vector
    for (int i = 0; i < charS.height; i++) {
        vector<char> temp;
        for (int j =0; j < charS.width; j++) {
            file >> c;
            temp.push_back(c);
        }
        charS.characterArray.push_back(temp);
    }
    
    file.close();
    file.clear();
    
    file.open("Characters/T.txt");
    if (!file) {
        //cout << "FATAL ERROR: Assets not found. Exiting program.";
        exit(1);
    }
    
    //skip ten lines
    for (int i = 0; i < 10; i++) {
        getline(file,dummyText);
    }
    
    file >> charT.width >> charT.height;
    //store in vector
    for (int i = 0; i < charT.height; i++) {
        vector<char> temp;
        for (int j =0; j < charT.width; j++) {
            file >> c;
            temp.push_back(c);
        }
        charT.characterArray.push_back(temp);
    }
    
    file.close();
    file.clear();
    
    file.open("Characters/U.txt");
    if (!file) {
        //cout << "FATAL ERROR: Assets not found. Exiting program.";
        exit(1);
    }
    
    //skip ten lines
    for (int i = 0; i < 10; i++) {
        getline(file,dummyText);
    }
    
    file >> charU.width >> charU.height;
    //store in vector
    for (int i = 0; i < charU.height; i++) {
        vector<char> temp;
        for (int j =0; j < charU.width; j++) {
            file >> c;
            temp.push_back(c);
        }
        charU.characterArray.push_back(temp);
    }
    
    file.close();
    file.clear();
    
    file.open("Characters/V.txt");
    if (!file) {
        //cout << "FATAL ERROR: Assets not found. Exiting program.";
        exit(1);
    }
    
    //skip ten lines
    for (int i = 0; i < 10; i++) {
        getline(file,dummyText);
    }
    
    file >> charV.width >> charV.height;
    //store in vector
    for (int i = 0; i < charV.height; i++) {
        vector<char> temp;
        for (int j =0; j < charV.width; j++) {
            file >> c;
            temp.push_back(c);
        }
        charV.characterArray.push_back(temp);
    }
    
    file.close();
    file.clear();
    
    file.open("Characters/W.txt");
    if (!file) {
        //cout << "FATAL ERROR: Assets not found. Exiting program.";
        exit(1);
    }
    
    //skip ten lines
    for (int i = 0; i < 10; i++) {
        getline(file,dummyText);
    }
    
    file >> charW.width >> charW.height;
    //store in vector
    for (int i = 0; i < charW.height; i++) {
        vector<char> temp;
        for (int j =0; j < charW.width; j++) {
            file >> c;
            temp.push_back(c);
        }
        charW.characterArray.push_back(temp);
    }
    
    file.close();
    file.clear();
    
    file.open("Characters/X.txt");
    if (!file) {
        //cout << "FATAL ERROR: Assets not found. Exiting program.";
        exit(1);
    }
    
    //skip ten lines
    for (int i = 0; i < 10; i++) {
        getline(file,dummyText);
    }
    
    file >> charX.width >> charX.height;
    //store in vector
    for (int i = 0; i < charX.height; i++) {
        vector<char> temp;
        for (int j =0; j < charX.width; j++) {
            file >> c;
            temp.push_back(c);
        }
        charX.characterArray.push_back(temp);
    }
    
    file.close();
    file.clear();
    
    file.open("Characters/Y.txt");
    if (!file) {
        //cout << "FATAL ERROR: Assets not found. Exiting program.";
        exit(1);
    }
    
    //skip ten lines
    for (int i = 0; i < 10; i++) {
        getline(file,dummyText);
    }
    
    file >> charY.width >> charY.height;
    //store in vector
    for (int i = 0; i < charY.height; i++) {
        vector<char> temp;
        for (int j =0; j < charY.width; j++) {
            file >> c;
            temp.push_back(c);
        }
        charY.characterArray.push_back(temp);
    }
    
    file.close();
    file.clear();
    
    file.open("Characters/Z.txt");
    if (!file) {
        //cout << "FATAL ERROR: Assets not found. Exiting program.";
        exit(1);
    }
    
    //skip ten lines
    for (int i = 0; i < 10; i++) {
        getline(file,dummyText);
    }
    
    file >> charZ.width >> charZ.height;
    //store in vector
    for (int i = 0; i < charZ.height; i++) {
        vector<char> temp;
        for (int j =0; j < charZ.width; j++) {
            file >> c;
            temp.push_back(c);
        }
        charZ.characterArray.push_back(temp);
    }
    
    file.close();
    file.clear();
    
    file.open("Characters/0.txt");
    if (!file) {
        //cout << "FATAL ERROR: Assets not found. Exiting program.";
        exit(1);
    }
    
    //skip ten lines
    for (int i = 0; i < 10; i++) {
        getline(file,dummyText);
    }
    
    file >> char0.width >> char0.height;
    //store in vector
    for (int i = 0; i < char0.height; i++) {
        vector<char> temp;
        for (int j =0; j < char0.width; j++) {
            file >> c;
            temp.push_back(c);
        }
        char0.characterArray.push_back(temp);
    }
    
    file.close();
    file.clear();
    
    file.open("Characters/1.txt");
    if (!file) {
        //cout << "FATAL ERROR: Assets not found. Exiting program.";
        exit(1);
    }
    
    //skip ten lines
    for (int i = 0; i < 10; i++) {
        getline(file,dummyText);
    }
    
    file >> char1.width >> char1.height;
    //store in vector
    for (int i = 0; i < char1.height; i++) {
        vector<char> temp;
        for (int j =0; j < char1.width; j++) {
            file >> c;
            temp.push_back(c);
        }
        char1.characterArray.push_back(temp);
    }
    
    file.close();
    file.clear();
    
    file.open("Characters/2.txt");
    if (!file) {
        //cout << "FATAL ERROR: Assets not found. Exiting program.";
        exit(1);
    }
    
    //skip ten lines
    for (int i = 0; i < 10; i++) {
        getline(file,dummyText);
    }
    
    file >> char2.width >> char2.height;
    //store in vector
    for (int i = 0; i < char2.height; i++) {
        vector<char> temp;
        for (int j =0; j < char2.width; j++) {
            file >> c;
            temp.push_back(c);
        }
        char2.characterArray.push_back(temp);
    }
    
    file.close();
    file.clear();
    
    file.open("Characters/3.txt");
    if (!file) {
        //cout << "FATAL ERROR: Assets not found. Exiting program.";
        exit(1);
    }
    
    //skip ten lines
    for (int i = 0; i < 10; i++) {
        getline(file,dummyText);
    }
    
    file >> char3.width >> char3.height;
    //store in vector
    for (int i = 0; i < char3.height; i++) {
        vector<char> temp;
        for (int j =0; j < char3.width; j++) {
            file >> c;
            temp.push_back(c);
        }
        char3.characterArray.push_back(temp);
    }
    
    file.close();
    file.clear();
    
    file.open("Characters/4.txt");
    if (!file) {
        //cout << "FATAL ERROR: Assets not found. Exiting program.";
        exit(1);
    }
    
    //skip ten lines
    for (int i = 0; i < 10; i++) {
        getline(file,dummyText);
    }
    
    file >> char4.width >> char4.height;
    //store in vector
    for (int i = 0; i < char4.height; i++) {
        vector<char> temp;
        for (int j =0; j < char4.width; j++) {
            file >> c;
            temp.push_back(c);
        }
        char4.characterArray.push_back(temp);
    }
    
    file.close();
    file.clear();
    
    file.open("Characters/5.txt");
    if (!file) {
        //cout << "FATAL ERROR: Assets not found. Exiting program.";
        exit(1);
    }
    
    //skip ten lines
    for (int i = 0; i < 10; i++) {
        getline(file,dummyText);
    }
    
    file >> char5.width >> char5.height;
    //store in vector
    for (int i = 0; i < char5.height; i++) {
        vector<char> temp;
        for (int j =0; j < char5.width; j++) {
            file >> c;
            temp.push_back(c);
        }
        char5.characterArray.push_back(temp);
    }
    
    file.close();
    file.clear();
    
    file.open("Characters/6.txt");
    if (!file) {
        //cout << "FATAL ERROR: Assets not found. Exiting program.";
        exit(1);
    }
    
    //skip ten lines
    for (int i = 0; i < 10; i++) {
        getline(file,dummyText);
    }
    
    file >> char6.width >> char6.height;
    //store in vector
    for (int i = 0; i < char6.height; i++) {
        vector<char> temp;
        for (int j =0; j < char6.width; j++) {
            file >> c;
            temp.push_back(c);
        }
        char6.characterArray.push_back(temp);
    }
    
    file.close();
    file.clear();
    
    file.open("Characters/7.txt");
    if (!file) {
        //cout << "FATAL ERROR: Assets not found. Exiting program.";
        exit(1);
    }
    
    //skip ten lines
    for (int i = 0; i < 10; i++) {
        getline(file,dummyText);
    }
    
    file >> char7.width >> char7.height;
    //store in vector
    for (int i = 0; i < char7.height; i++) {
        vector<char> temp;
        for (int j =0; j < char7.width; j++) {
            file >> c;
            temp.push_back(c);
        }
        char7.characterArray.push_back(temp);
    }
    
    file.close();
    file.clear();
    
    file.open("Characters/8.txt");
    if (!file) {
        //cout << "FATAL ERROR: Assets not found. Exiting program.";
        exit(1);
    }
    
    //skip ten lines
    for (int i = 0; i < 10; i++) {
        getline(file,dummyText);
    }
    
    file >> char8.width >> char8.height;
    //store in vector
    for (int i = 0; i < char8.height; i++) {
        vector<char> temp;
        for (int j =0; j < char8.width; j++) {
            file >> c;
            temp.push_back(c);
        }
        char8.characterArray.push_back(temp);
    }
    
    file.close();
    file.clear();
    
    file.open("Characters/9.txt");
    if (!file) {
        //cout << "FATAL ERROR: Assets not found. Exiting program.";
        exit(1);
    }
    
    //skip ten lines
    for (int i = 0; i < 10; i++) {
        getline(file,dummyText);
    }
    
    file >> char9.width >> char9.height;
    //store in vector
    for (int i = 0; i < char9.height; i++) {
        vector<char> temp;
        for (int j =0; j < char9.width; j++) {
            file >> c;
            temp.push_back(c);
        }
        char9.characterArray.push_back(temp);
    }
    
    file.close();
    file.clear();
    
    
}

void AlphanumericPlotter::plotString(string str, int x, int y) {
    int size = str.length();
    character* charPtr;
    char c;
    for (int i = 0; i < size; i++) {
        c = str[i];
        switch (c) {
            case 'A':
                charPtr = &charA;
                break;
            case 'B':
                charPtr = &charB;
                break;
            case 'C':
                charPtr = &charC;
                break;
            case 'D':
                charPtr = &charD;
                break;
            case 'E':
                charPtr = &charE;
                break;
            case 'F':
                charPtr = &charF;
                break;
            case 'G':
                charPtr = &charG;
                break;
            case 'H':
                charPtr = &charH;
                break;
            case 'I':
                charPtr = &charI;
                break;
            case 'J':
                charPtr = &charJ;
                break;
            case 'K':
                charPtr = &charK;
                break;
            case 'L':
                charPtr = &charL;
                break;
            case 'M':
                charPtr = &charM;
                break;
            case 'N':
                charPtr = &charN;
                break;
            case 'O':
                charPtr = &charO;
                break;
            case 'P':
                charPtr = &charP;
                break;
            case 'Q':
                charPtr = &charQ;
                break;
            case 'R':
                charPtr = &charR;
                break;
            case 'S':
                charPtr = &charS;
                break;
            case 'T':
                charPtr = &charT;
                break;
            case 'U':
                charPtr = &charU;
                break;
            case 'V':
                charPtr = &charV;
                break;
            case 'W':
                charPtr = &charW;
                break;
            case 'X':
                charPtr = &charX;
                break;
            case 'Y':
                charPtr = &charY;
                break;
            case 'Z':
                charPtr = &charZ;
                break;
            case '0':
                charPtr = &char0;
                break;
            case '1':
                charPtr = &char1;
                break;
            case '2':
                charPtr = &char2;
                break;
            case '3':
                charPtr = &char3;
                break;
            case '4':
                charPtr = &char4;
                break;
            case '5':
                charPtr = &char5;
                break;
            case '6':
                charPtr = &char6;
                break;
            case '7':
                charPtr = &char7;
                break;
            case '8':
                charPtr = &char8;
                break;
            case '9':
                charPtr = &char9;
                break;
            case ' ':
                break;
            default:
                charPtr = &charA;
                break;
        }
        
        if (c != ' ') {
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
