#include "VisualSplay.h"
/******************************************************************************/
VisualSplay::VisualSplay(GLUT_Plotter* g,AlphanumericPlotter* a) // constructor
{
    screen = g;                            // screen
    
    alpha = a;                             // alphanumeric plotter
    
    screenHeight = screen->getHeight();    // screen width
    screenWidth = screen->getWidth();      // screen height
    
    rootLoc.x = screenWidth / 2;           // fixes root loc in x
    rootLoc.y = screenHeight - 100;        // fixes root loc in y
    

    splay = new SplayTree<int>;            // tree here
    
    totalNodeSlots = 0;                    // number of nodes
    treeHeight = 0;                        // # of levels in gree
}
/******************************************************************************/
void VisualSplay::insert(int val) //INSERTION FUNCTION
{
    splay->insert(val);
}
/******************************************************************************/
void VisualSplay::remove(int val) //REMOVE FUNCTION
{
    if(splay != NULL)
        splay->remove(val);
}
/******************************************************************************/
void VisualSplay::clear() //DESTRUCTOR
{
    delete splay;
    visualMap.clear();
}


/******************************************************************************/

void VisualSplay::buildVisualMap()
{
    /*retrieve our tree as a vector of indexes and data
     *note that index is index in the tree, not index in the vector
     * e.g.  1
     *     /   \
     *    2     3
     *   / \   / \
     *  4   5 6   7
     *
     * Above tree is INDEXES of those nodes, each level has 2^level nodes
     */
    
    if (splay->getNumNodes() != 0) // if tree is null, do not draw
    {
        
        vector< pair<int,string> > vectorOfNodePairs = splay->parseToVector();
        
        // CHECK VECTOR
        pair<int,string> readPair;
        for(int i = 0; i < vectorOfNodePairs.size(); i++)
        {
            readPair = vectorOfNodePairs[i];
            cout << "(Index = " << readPair.first << " , ";
            cout << "Data = " << readPair.second << ")";
            cout << endl;
        }
        //CHECK VECTOR
        
        
        map<int,CircleNode*>::iterator searchForNode;
        
        Location locationToInsert;
        Location parentLocation;
        int parentIndex;
        int currentIndex;
        int possibleChild;
        int numTreeLevels;
        string currentData;
        string parentData;
        
        int backIndex = vectorOfNodePairs.back().first;//index of last elem in vector
        
        cout<<"LAST INDEX = "<< backIndex << endl;
        cout << "**************************************" << endl<<endl;
        
        
        visualMap.clear();
        if (backIndex == 1) // 1 item (only root)
        {
            numTreeLevels = 0;
            totalNodeSlots = 1;
        }
        else // 2 or more items ( > root)
        {
            numTreeLevels = 1;
            
            while (backIndex != 1) // counts number of levels
            {
                backIndex /= 2;
                numTreeLevels++;
            }
            
            totalNodeSlots = 0;
            
            for (int i = 0; i < numTreeLevels; i++)
            {
                totalNodeSlots += pow(2, i);
            }
        }
        
        int numNodes = vectorOfNodePairs.size();
        
        for (int i = 0; i < numNodes; i++) // do this for all nodes
        {
            //get current index
            currentIndex = vectorOfNodePairs[i].first;
            
            //get current data
            
            currentData = vectorOfNodePairs[i].second;
            
            if (currentIndex == 1) // DRAW ROOT
            {
                locationToInsert.x = rootLoc.x;
                locationToInsert.y = rootLoc.y;
                parentLocation.y = rootLoc.y + 100;
                parentLocation.x = rootLoc.x;
                
            }
            else // DRAW !ROOT NODE
            {
                parentIndex = currentIndex/2;
                
                parentLocation = visualMap[parentIndex]->getLocation();
                parentData = visualMap[parentIndex]->getData();
                
                //possibleChild = parentIndex*2;
                //searchForNode = visualMap.find(possibleChild);
                
                if (currentData < parentData)
                    locationToInsert.x = parentLocation.x - 60; //pos x left child
                else
                    locationToInsert.x = parentLocation.x + 60; //pos x for right child
            }
            
            locationToInsert.y = parentLocation.y - 100;
            
            visualMap[currentIndex] = new CircleNode(screen,alpha,vectorOfNodePairs[i].second,locationToInsert);
        }
        
    }// if tree is !NULL
    
}// checkBalance()

/******************************************************************************/

void VisualSplay::draw()
{
    if (splay != NULL)
    {
        buildVisualMap();
        
        for (int i = 1; i < totalNodeSlots+1; i++)
        {
            if (visualMap.find(i) != visualMap.end())
            {
                visualMap[i]->draw();
                Line lin(screen);
                int leftchild = i*2;
                int rightChild = i*2 + 1;
                
                if (leftchild < totalNodeSlots+1)
                {
                    if (visualMap.find(leftchild) != visualMap.end())
                    {
                        lin.draw(*visualMap[i], *visualMap[leftchild]);
                    }
                }
                
                if (rightChild < totalNodeSlots+1)
                {
                    if (visualMap.find(rightChild) != visualMap.end())
                    {
                        lin.draw(*visualMap[i], *visualMap[rightChild]);
                    }
                }
            }
        }
    }
}

void VisualSplay::moveTreeBy(Location loc) {
    screen->setColor(0x000000);
    draw();
    if (splay != NULL) {
    
        rootLoc.x += loc.x;
        rootLoc.y += loc.y;
        //cout << "x: " << rootLoc.x << " y: " << rootLoc.y << endl;
    }
    screen->setColor(0xffffff);
    draw();
}
/******************************************************************************/

void VisualSplay::moveTreeTo(Location loc) {
    screen->setColor(0x000000);
    draw();
    rootLoc.x = loc.x;
    rootLoc.y = loc.y;
    screen->setColor(0xffffff);
    draw();
}

