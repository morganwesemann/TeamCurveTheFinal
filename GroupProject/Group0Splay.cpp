//test
/* 
 * File:   Group0Splay.cpp
 *
 * Created on April 11, 2016, 3:24 AM
 */
#include "Group0Splay.h"
using namespace std;

/*
 * TODO: Develop and Test splay, insert, remove, and deconstructor
 */
splay::~splay(){
    delete left;
    delete right;
    left = right = NULL;
}

splay *splay ::insert(splay* it){
    
}
splay *splay :: remove(splay* it){
    
}
splay *splay :: leftLeftRotation(splay* element){
    splay* temp = element->left;
	element->left = temp->right;
	temp->right = element;
	return temp;
}
splay *splay :: rightRightRotation(splay* element){
    splay* temp = element->right;
	element->right = temp->left;
	temp->left = element;
	return temp;
}
