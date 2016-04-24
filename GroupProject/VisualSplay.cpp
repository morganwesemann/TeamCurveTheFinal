#include "VisualSplay.h"
VisualSplay::VisualSplay(GLUT_Plotter* g,AlphanumericPlotter* a)
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

void VisualSplay::insert(int val)
{
    splay->insert(val);
}

/******************************************************************************/

void VisualSplay::remove(int val)
{
    if(splay != NULL)
    {
        splay->remove(val);
    }
}

/******************************************************************************/

void VisualSplay::clear()
{
    delete splay;
    deleteVisualSplay();
}

/******************************************************************************/


void VisualSplay::deleteVisualSplay()
{
    visualSplay.clear();
}

/******************************************************************************/

void VisualSplay::checkBalance()
{
    if (splay != NULL) // if tree is null, do not draw
    {
        
        vector<vector<string> > nodeMatrix;
        vector<string> nodesInLevelVector;
        
        // These 3 lines
        ostringstream levelOrderStream;
        splay->printLevelOrderInt(levelOrderStream);
        string convertedTreeString = levelOrderStream.str();
        
        // treeHeight counts number of levelså
        long treeHeight = count(convertedTreeString.begin(),convertedTreeString.end(),'l');
        
////////////////////////////////////////////////////////////////////////////////

        if (visualSplay.empty())  // Build vector here on first call
        {
            for (int i = 0; i < treeHeight; i++)
            {
                totalNodeSlots+= pow(2.0, i);
            }
            for (int i = 0; i < totalNodeSlots+1;i++)
            {
                visualSplay.push_back(NULL);
            }
        }
        
        else // Here vector previously exists & needs updating
        {
            int tempNodeSlots = 0;
            for (int i = 0; i < treeHeight; i++)
            {
                tempNodeSlots+= pow(2.0, i);
            }
            
            //increase capacity of visual splay if needed
            if (tempNodeSlots > totalNodeSlots)
            {
                tempNodeSlots -= totalNodeSlots;
                for (int i = 0; i < tempNodeSlots; i++)
                {
                    visualSplay.push_back(NULL);
                }
            }
        }// end building vector
        
////////////////////////////////////////////////////////////////////////////////
        
        convertedTreeString.erase(0,1);
        cout << convertedTreeString;
        nodesInLevelVector = splitStrIntoVector(convertedTreeString,'l');
        
        
        //if (nodesInLevel.empty()){exit(1);}
        
        
        for (int i = 0; i < treeHeight; i++)
        {
            nodesInLevelVector[i].erase(0,1);
            nodeMatrix.push_back(splitStrIntoVector(nodesInLevelVector[i]));
        }
        
////////////////////////////////////////////////////////////////////////////////
        
        size_t numNodesInLevel = 0; //nodes in each level
        int index = 1;              // index in visualSplay[] circleNode array
        
        Location l;
        
        // visualsplay is a vector containing circlenodes ordered as a splay tree
        // parent at n, right child is at 2n, left child is at 2n+1
        // root is at index 1
        
        for (int i = 0; i < treeHeight; i++) // loops level by level
        {
            numNodesInLevel = nodeMatrix[i].size(); // # of nodes in each level
            
            for (int j = 0; j < numNodesInLevel; j++) // this handles each node
            {
                if (nodeMatrix[i][j] == "-1") // node in matrix is NULL
                {
                    if (visualSplay[index] != NULL)
                    {
                        delete visualSplay[index];
                        visualSplay[index] = NULL;
                    }
                }
                
                else // node in matrix exists
                    
                {
                    //COMPARISON HAPPENS HERE
                    
                    if (visualSplay[index] != NULL)
                        delete visualSplay[index];
                    
                    if (index == 1) // ROOT CASE
                        l.x = rootLoc.x;
                    
                    else
                    if (index == 2 || index == 3) // ROOT CHILDREN CASE
                    {
                        //here root's children
                        int parent = index / 2;
                        Location parentLoc;
                        parentLoc = visualSplay[parent]->getLocation();
                        
                        int child1 = parent*2;
                        
                        if (child1 == index)
                        {
                            l.x = parentLoc.x - 60; //left child of root
                        }
                        else
                        {
                            l.x = parentLoc.x + 60; //right child of root
                        }
                    }
                    else {
                        // not root
                        // not root's children
                        // getting grandparent & parent
                        int parent = index / 2;
                        int grandparent = parent / 2;
                        Location parentLoc, ancestorLocation;
                        parentLoc = visualSplay[parent]->getLocation();
                        ancestorLocation = visualSplay[grandparent]->getLocation();
                        // left child check
                        int child1 = parent*2;

                        // redo work here
                        if (child1 == index)
                        {
                            l.x = parentLoc.x - 60; // l = leftchild
                            int ancestor;
                            int ancestorChild;
                            int currentLocation = index;
                            do
                            {
                                ancestorChild = currentLocation/2;
                                ancestor = ancestorChild/2;
                                if (parentLoc.x > ancestorLocation.x)
                                {
                                    if (l.x >= ancestorLocation.x)
                                    {
                                        // here corrects LR problem
                                        // by shifting parent & child left
                                        parentLoc.x += 60;
                                        l.x = parentLoc.x - 60;
                                        visualSplay[parent]->setLocation(parentLoc);
                                    }
                                }
                                currentLocation /= 2;
                                //break; // temporary
                            }while(ancestor > 1); // root is 1
                        }
                        else //right side check
                        {
                            l.x = parentLoc.x + 60; // l = rightchild
                            int ancestor;
                            int ancestorChild;
                            int currentLocation = index;
                            do
                            {
                                ancestorChild = currentLocation/2;
                                ancestor = ancestorChild/2;
                                if (parentLoc.x < ancestorLocation.x)
                                {
                                    if (l.x <= ancestorLocation.x)
                                    {
                                        // here corrects LR problem
                                        // by shifting parent & child left
                                        parentLoc.x -= 60;
                                        l.x = parentLoc.x + 60;
                                        visualSplay[parent]->setLocation(parentLoc);
                                    }
                                }
                                currentLocation /= 2;
                                //break; //temporary
                            }while(ancestor > 1); // root is 1
                        }
                    }
                    // Resolve conflict here
                    l.y = rootLoc.y - (i * 100);
                    visualSplay[index] = new CircleNode(screen,alpha,nodeMatrix[i][j],l);
                    
                }
                index++;
            
            }
        
        }// for i<treeHeight
    
    }// if tree is !NULL
    
}// checkBalance()

/******************************************************************************/


void VisualSplay::draw()
{
    if (splay != NULL) // if tree is null, do not draw
    {
        checkBalance();
        // ONLY PART THAT DRAWS
        //draw tree (nodes and lines)
        for (int i = 1; i < totalNodeSlots+1; i++)
        {
            if (visualSplay[i] != NULL)
            {
                visualSplay[i]->draw();
                Line lin(screen);
                int child1 = i*2;
                int child2 = i*2 + 1;
                //only draw left child if exists
                if (child1 < totalNodeSlots+1)
                {
                    if (visualSplay[child1] != NULL)
                    {
                        lin.draw(*visualSplay[i], *visualSplay[child1]);
                    }
                }
                //only draw right child if exists
                if (child2 < totalNodeSlots+1)
                {
                    if (visualSplay[child2] != NULL)
                    {
                        lin.draw(*visualSplay[i], *visualSplay[child2]);
                    }
                }
            }
        }
    }
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