/* 
 * File:   Group0Splay.h

 * Created on April 11, 2016, 3:03 AM
 */

#ifndef GROUP0SPLAY_H
#define GROUP0SPLAY_H
#include <iostream>
#include <string>
#include <cassert>
#include <algorithm>
#include <cstdlib>
#include <sstream>
using namespace std;
//template <class type_t>
class splay{
public:
     splay(splay *l = NULL, splay *r = NULL, int h = 0) : left(l), right(r){}//DONE
    ~splay();//DONE
    //Perform a left-left rotation
    splay *leftLeftRotation(splay* ll);
    //Perform a left-left rotation
    splay *rightRightRotation(splay* rr);
    //Perform an insert
    splay *insert(splay *root);
    //Perform a remove
    splay *remove(splay *root);
    //Perform a splay
    splay *splayIt(splay* root);
protected:
    splay *left, *right; //left and right nodes
    int height;
};


#endif /* GROUP0SPLAY_H */



