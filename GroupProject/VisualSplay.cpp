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
    buildVisualMap();

}
/******************************************************************************/
void VisualSplay::remove(int val) //REMOVE FUNCTION
{
    if(splay != NULL) {
        splay->remove(val);
        buildVisualMap();
    }

}
/******************************************************************************/
void VisualSplay::clear() //DESTRUCTOR
{
    delete splay;
    map<int,CircleNode*>::iterator it;
    for (it = visualMap.begin(); it != visualMap.end(); it++) {
        delete it->second;
    }
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
        int possibleChildIndex;
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
        
        totalNodes = vectorOfNodePairs.size();
        
        // root index is 1
        // root left is 2
        // root right is 3
        // start checking at level 2, where index is >3
        
        
        
        
        
        for (int i = 0; i < totalNodes; i++) // do this for all nodes
        {
            //get current index
            currentIndex = vectorOfNodePairs[i].first;
            
            //get current data
            
            currentData = vectorOfNodePairs[i].second;
            
            int temp = stoi(currentData);
            
            if (temp == 0) {
                temp;
            }
            
            
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
                
                possibleChildIndex = parentIndex*2;
                
                if (possibleChildIndex == currentIndex) {
                    locationToInsert.x = parentLocation.x - 60; //neg x left child
                } else {
                    locationToInsert.x = parentLocation.x + 60; //pos x for right child
                }
            }
            
            locationToInsert.y = parentLocation.y - 100;
            
            visualMap[currentIndex] = new CircleNode(screen,alpha,vectorOfNodePairs[i].second,locationToInsert);
            
            cout << "In map, key -> " << currentIndex << " added " << endl;
            
            /*
             Location locationToInsert;
             Location parentLocation;
             int parentIndex;
             int currentIndex;
             int possibleChildIndex;
             int numTreeLevels;
             string currentData;
             string parentData;
             */
            
            // root index is 1
            // root left is 2
            // root right is 3
            // start checking at level 2, where index is >3
            
            /******************************************************************************/
            if(currentIndex > 3)
            {
                
                
                int newCurrentIndex;
                queue<int> collisionCheckQueue;//ADDING MOVED NODE INDEXES HERE
                collisionCheckQueue.push(currentIndex);//ADDING MOVED NODE INDEXES HERE
                //any node that is moved
                // the moved node's index will be pushed here
                
                while(!collisionCheckQueue.empty())//ADDING MOVED NODE INDEXES HERE
                {
                    newCurrentIndex = collisionCheckQueue.front();
                    collisionCheckQueue.pop();//ADDING MOVED NODE INDEXES HERE
                    
                    cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
                    cout << "HELLO"<<endl;
                    cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
                    
                    int tempIndex = newCurrentIndex/2; // search from grandparent
                    // this is only guaranteed the first time
                    
                    //bool collisionFound = false;
                    CircleNode* checkXposNode;
                    
                    CircleNode* addedNode = visualMap[newCurrentIndex];
                    
                    // stop searching up when tempIndex = 1
                    // tempIndex = 1 is the root node
                    
                    while(tempIndex >= 1)
                    {
                        //bool collisionFound = false;
                        
                        if(visualMap.find(tempIndex) != visualMap.end()) // parent index found
                        {
                            checkXposNode = visualMap[tempIndex];
                            
                            cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
                            cout << "Ancestor index found, checking for collisions"<<endl;
                            cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
                            
                            if(checkXposNode->getX() == addedNode->getX())// collision found bc x pos is same
                            {
                                
                                cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
                                cout << "Collision found, correcting"<<endl;
                                cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
                                
                                int ancestorData = stoi(checkXposNode->getData());
                                int currentData = stoi(addedNode->getData());
                                
                                int movedIndex;
                                int offset;
                                
                                if(currentData < ancestorData) // data < anc data
                                {
                                    // for ancestor, move LEFT child LEFT
                                    movedIndex = 2*tempIndex;
                                    offset = - 60;
                                }
                                else // data > anc data
                                {
                                    // for ancestor, move RIGHT child RIGHT
                                    movedIndex = 2*tempIndex + 1;
                                    offset = 60;
                                }
                                
                                cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
                                cout << "queue START"<<endl;
                                cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
                                queue<int> updatePosQueue;
                                int current;
                                
                                updatePosQueue.push(movedIndex);
                                
                                
                                while(!updatePosQueue.empty())
                                {
                                    current = updatePosQueue.front();
                                    visualMap[current]->setX((visualMap[current]->getX()+offset));
                                    updatePosQueue.pop();
                                    
                                    collisionCheckQueue.push(current);//ADDING MOVED NODE INDEXES HERE
                                    
                                    int left = current*2;
                                    int right = current*2 + 1;
                                    
                                    if(visualMap.find(left) != visualMap.end())
                                    {
                                        updatePosQueue.push(left);
                                    }
                                    
                                    if(visualMap.find(right) != visualMap.end())
                                    {
                                        updatePosQueue.push(right);
                                    }
                                    
                                } // bfs queue
                                
                                cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
                                cout << "queue END"<<endl;
                                cout << endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
                                
                            }//if(checkXposNode->getX() == addedNode->getX())
                            
                        }//if(visualMap.find(tempIndex) != visualMap.end()) lookup parent
                        
                        tempIndex = tempIndex / 2; // UPDATE tempIndex, which checks x positions of parents
                        
                    }//while(tempIndex >= 1) : repeat this work until root is reached
                    
                }
                
                //DO WHILE
                
            }// if(totalNodes > 3): only start checking once level 2 reached, guaranteed grandparent
            
            /******************************************************************************/
            
        }// for: loop until all nodes are accounted for
        
    }// if: tree exists (tree is not NULL)
    
}// function: checkBalance()

/******************************************************************************/

void VisualSplay::draw()

{
    if (splay->getNumNodes() != 0) // if tree is null, do not draw
    {
        
        map<int,CircleNode*>::iterator searchForNode;
        queue<int> indexQueue;
        
        int currentIndex = 1;
        
        indexQueue.push(1);
        
        while (!indexQueue.empty()) {
            searchForNode = visualMap.find(currentIndex);
            if (searchForNode != visualMap.end())
            {
                currentIndex = indexQueue.front();
                visualMap[currentIndex]->draw();
                indexQueue.pop();
                
                Line lin(screen);
                int leftChild = currentIndex*2;
                int rightChild = currentIndex*2 + 1;
                //only draw left child if exists
                
                    searchForNode = visualMap.find(leftChild);
                    if (searchForNode != visualMap.end())
                    {
                        lin.drawBetweenNodes(*visualMap[currentIndex], *visualMap[leftChild]);
                        indexQueue.push(leftChild);
                    }
                
                //only draw right child if exists
                
                    searchForNode = visualMap.find(rightChild);
                    if (searchForNode != visualMap.end())
                    {
                        lin.drawBetweenNodes(*visualMap[currentIndex], *visualMap[rightChild]);
                        indexQueue.push(rightChild);
                    }
                
            }
        }
        
        
        //OLD CODE
        
        /*for (int i = 1; i < totalNodeSlots+1; i++)
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
         }*/
    }
}

/******************************************************************************/

void VisualSplay::moveTreeBy(Location loc) {
    
    if (splay->getNumNodes() != 0) {
        screen->setColor(0x000000);
        draw();
        rootLoc.x += loc.x;
        rootLoc.y += loc.y;
        updateLocations(loc);
        screen->setColor(0xffffff);
        draw();
    }
    
}
/******************************************************************************/

void VisualSplay::moveTreeTo(Location loc) {
    if (splay->getNumNodes() != 0) {
        screen->setColor(0x000000);
        draw();
        rootLoc.x = loc.x;
        rootLoc.y = loc.y;
        buildVisualMap();
        screen->setColor(0xffffff);
        draw();
    }
}

void VisualSplay::updateLocations(Location loc) {
    if (splay->getNumNodes() != 0) {
        
        map<int, CircleNode*>::iterator it;
        Location currentLocation;
        CircleNode* current;
        for (it = visualMap.begin(); it != visualMap.end(); it++) {
            current = it->second;
            currentLocation = current->getLocation();
            currentLocation.x += loc.x;
            currentLocation.y += loc.y;
            current->setLocation(currentLocation);
        }
    }
}

