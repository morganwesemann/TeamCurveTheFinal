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
    deleteVisualSplay();
}
/******************************************************************************/
void VisualSplay::deleteVisualSplay() //DESTRUCTOR HELPER FUNCTION
{
    visualMap.clear();
}

/******************************************************************************/

void VisualSplay::checkBalance()
{
    if (splay->getNumNodes() != 0) // if tree is null, do not draw
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
        
        vector< pair<int,string> > vectorOfNodePairs = splay->parseToVector();
        
        //adam code here
        pair<int,string> readPair;
        for(int i = 0; i < vectorOfNodePairs.size(); i++)
        {
            readPair = vectorOfNodePairs[i];
            
            cout << "(Index = " << readPair.first << " , ";
            cout << "Data = " << readPair.second << ")";
            cout << endl;
        }
        cout << "**************************************" << endl;
        visualMap.clear();
        
        //note that pairs are accessed using pair.first and pair.second members
        
        //iterator for map, searching for a node
        map<int,CircleNode*>::iterator searchForNode;
        
        
        //split vector of indexes and data into map of indexes and CIRCLENODES
        
        Location locationToInsert;
        Location parentLocation;
        
        int parentIndex;
        int currentIndex;
        int possibleChild;
        int numTreeLevels;
        
        string currentData;
        string parentData;
        
        // backIndex is the index of the very last element in vector
        int backIndex = vectorOfNodePairs.back().first;
        
        
        if (backIndex == 1) // only root
        {
            numTreeLevels = 0;
            totalNodeSlots = 1;
        }
        else // more than just root
        {
            numTreeLevels = 1;
            
            while (backIndex != 1)
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
        
        //leave size as an iteger. Suck it Xcode
        int numNodes = vectorOfNodePairs.size();
        // get total number of nodes in tree
        
        // cover all nodes
        for (int i = 0; i < numNodes; i++)
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
                parentIndex = currentIndex / 2;
                
                parentLocation = visualMap[parentIndex]->getLocation();
                parentData = visualMap[parentIndex]->getData();
                
                possibleChild = parentIndex*2;
                searchForNode = visualMap.find(possibleChild);
                
                if (currentData < parentData)
                {
                    //left child
                    locationToInsert.x = parentLocation.x - 60;
                } else
                {
                    //right child
                    locationToInsert.x = parentLocation.x + 60;
                }
            }
            
            locationToInsert.y = parentLocation.y - 100;
            visualMap[currentIndex] = new CircleNode(screen,alpha,vectorOfNodePairs[i].second,locationToInsert);
            
            /*
             * ADAM CODE GO HERE
             *
             */
        }
        
    }// if tree is !NULL
    
}// checkBalance()


//TODO: refactor for visualMap, not visualSplay
void VisualSplay::draw()
{
    if (splay != NULL) // if tree is null, do not draw
    {
        checkBalance();
        // ONLY PART THAT DRAWS
        //draw tree (nodes and lines)
        
        map<int,CircleNode*>::iterator searchForNode;
        
        
        
        for (int i = 1; i < totalNodeSlots+1; i++)
        {
            searchForNode = visualMap.find(i);
            if (searchForNode != visualMap.end())
            {
                visualMap[i]->draw();
                Line lin(screen);
                int child1 = i*2;
                int child2 = i*2 + 1;
                //only draw left child if exists
                if (child1 < totalNodeSlots+1)
                {
                    searchForNode = visualMap.find(child1);
                    if (searchForNode != visualMap.end())
                    {
                        lin.draw(*visualMap[i], *visualMap[child1]);
                    }
                }
                //only draw right child if exists
                if (child2 < totalNodeSlots+1)
                {
                    searchForNode = visualMap.find(child2);
                    if (searchForNode != visualMap.end())
                    {
                        lin.draw(*visualMap[i], *visualMap[child2]);
                    }
                }
            }
        }
    }
}

void VisualSplay::moveTree(Location loc) {
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


vector<string> VisualSplay::splitStrIntoVector(string sentence, const char &d)
{
    vector<string> vec;
    //iterator to beginning of sentence
    string::iterator it = sentence.begin();
    string::iterator temp;
    //while the iterator is not at the end of the sentence
    while (it != sentence.end())
    {
        //find the next space
        temp = find(it, sentence.end(),d);
        /*
         if we aren't at the end, add the word in between the
         two iterators to the vector
         */
        if (it != sentence.end())
        {
            vec.push_back(string(it,temp));
        }
        //set iterator to end of word
        it = temp;
        //skip through extra spaces
        while ((it != sentence.end()) && (*it == d))
        {
            it++;
        }
    }
    return vec;
}