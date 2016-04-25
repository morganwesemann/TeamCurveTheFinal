#include "Group0Splay.h"
#include <queue>

/*******************************************************************************/
template <class Base>
int SplayTree<Base>::getNumNodes() {
    return numNodes;
}

/*******************************************************************************/

template <class Base> const SplayNode<Base>* SplayNode<Base>::maxNode() const
{
	const SplayNode<Base> * ptr = this;
	while(ptr->right != NULL)	ptr = ptr->right;
	return ptr;
}

/*******************************************************************************/

template <class Base> const SplayNode<Base>* SplayNode<Base>::minNode() const
{
	const SplayNode<Base> * ptr = this;
	while(ptr->left != NULL)	ptr = ptr->left;
	return ptr;
}

/*******************************************************************************/

template <class Base> SplayNode<Base>* SplayNode<Base>::singleRotateRight()
{
	SplayNode<Base>* leftNode = this->left;

	this->left = leftNode -> right;    //update left child
	leftNode->right = this;            //update right child

	leftNode->right->parent=leftNode;  //update parent for right child
	if(this->left)
		this->left->parent=this;	   //update parent for LEFT child if !NULL

	return leftNode;
}

/*******************************************************************************/

template <class Base> SplayNode<Base>* SplayNode<Base>::singleRotateLeft()
{
	SplayNode<Base>* rightNode = this->right;

	this->right = rightNode->left; //update left child
	rightNode -> left = this; //update right child

	rightNode->left->parent=rightNode; 	//update parent for left child
	if(this->right)
		this->right->parent=this;	   //update parent for RIGHT child if !NULL

	return rightNode;
}

/*******************************************************************************/

template<class Base> void SplayTree<Base>::splayToRoot(SplayNode<Base>* ptr)
{
	Base myData,parentData,grandParentData;
	bool singleRotateFlag=false, doubleRotateFlag=false;

	while(ptr != root)
	{
		if(ptr == root->left || ptr == root->right) // 1 LEVEL FROM ROOT
			singleRotateFlag=true;
		else
			doubleRotateFlag=true;

/*******************************************************************************/

		if(singleRotateFlag)
		{
			if(root->data > ptr->data)
			{
				root = root->singleRotateRight();
				if(root->left)	root->left->parent = root;
				//cout << "single R rotation" << endl;
			}
			else
			{
				root = root->singleRotateLeft();
				if(root->right)	root->right->parent=root;
				//cout << "single L rotation" << endl;
			}
			ptr=root;
		}

/*******************************************************************************/

		if(doubleRotateFlag)
		{
			myData = ptr->data;
			parentData = ptr->parent->data;
			grandParentData = ptr->parent->parent->data;
			SplayNode<Base>* rotateNode = ptr->parent->parent;

			//cout << endl;
			//cout << "current     data = " << myData<<endl;
			//cout << "parent      data = " << parentData<<endl;
			//cout << "grandparent data = " << grandParentData<<endl;

/*******************************************************************************/
			if(grandParentData < parentData && parentData < myData) //RR access
			{
				//cout << endl << "LL correction" << endl;//temporary

				if(rotateNode == root) //LL correction
				{
					root = root->singleRotateLeft();
					root->left->parent = root;
					root = root->singleRotateLeft();
					root->left->parent = root;

					root->parent = NULL;
					ptr=root;
				}
				else
				{
					SplayNode<Base>* anchorNode = rotateNode->parent;

					if(anchorNode->data > rotateNode->data)
					{
						anchorNode->left = anchorNode->left->singleRotateLeft();
						anchorNode->left->parent = anchorNode;
						anchorNode->left = anchorNode->left->singleRotateLeft();
						anchorNode->left->parent = anchorNode;
					}
					else
					{
						anchorNode->right = anchorNode->right->singleRotateLeft();
						anchorNode->right->parent = anchorNode;
						anchorNode->right = anchorNode->right->singleRotateLeft();
						anchorNode->right->parent = anchorNode;
					}

					//cout << "LL correction done" << endl;//temp
				}
			}
/*******************************************************************************/
			else if(grandParentData > parentData && parentData > myData)//LL access
			{
				//cout << endl << "RR correction" << endl;//temporary

				if(rotateNode == root)//RR correction
				{
					root = root->singleRotateRight();
					root->right->parent = root;

					root = root->singleRotateRight();
					root->right->parent = root;

					root->parent = NULL;
					ptr=root;
				}
				else
				{
					SplayNode<Base>* anchorNode = rotateNode->parent;

					if(anchorNode->data > rotateNode->data)
					{
						anchorNode->left = anchorNode->left->singleRotateRight();
						anchorNode->left->parent = anchorNode;
						anchorNode->left = anchorNode->left->singleRotateRight();
						anchorNode->left->parent = anchorNode;
					}
					else
					{
						anchorNode->right = anchorNode->right->singleRotateRight();
						anchorNode->right->parent = anchorNode;
						anchorNode->right = anchorNode->right->singleRotateRight();
						anchorNode->right->parent = anchorNode;
					}
				}
			}
/*******************************************************************************/
			else if(grandParentData < parentData && parentData > myData)//RL access
			{
				//cout << endl << "LR correction" << endl;//temporary

				if(rotateNode == root)//LR correction
				{
					root->right = root->right->singleRotateRight();

					root -> right->parent = root;//update parent
					root->right->right->parent=root->right;//update parent

					root = root -> singleRotateLeft();
					ptr=root;
				}
				else
				{
					//correction
					SplayNode<Base>* anchorNode = rotateNode->parent;

					rotateNode->right = rotateNode->right->singleRotateRight();//rotate
					rotateNode->right->right->parent = rotateNode->right;//parent
					rotateNode->right->parent = rotateNode;//parent

					if(anchorNode->data > rotateNode->data)
					{
						anchorNode->left = anchorNode->left->singleRotateLeft();//rotate
						anchorNode->left->left->parent = anchorNode->left;
						anchorNode->left->parent = anchorNode;
					}
					else
					{
						anchorNode->right = anchorNode->right->singleRotateLeft();//rotate
						anchorNode->right->right->parent = anchorNode->right;
						anchorNode->right->parent = anchorNode;
					}
				}
			}
/*******************************************************************************/
			else if(grandParentData > parentData && parentData < myData)//LR access
			{
				//cout << endl << "RL correction" << endl;//temporary

				if(rotateNode == root) //RL correction
				{
					root->left = root->left->singleRotateLeft();

					root -> left->parent = root;//update parent
					root->left->left->parent=root->left;//update parent

					root = root -> singleRotateRight();
					ptr=root;
				}
				else
				{
					SplayNode<Base>* anchorNode = rotateNode->parent;

					rotateNode->left = rotateNode->left->singleRotateLeft();//rotate
					rotateNode->left->left->parent = rotateNode->left;//parent
					rotateNode->left->parent = rotateNode;//parent

					if(anchorNode->data > rotateNode->data)
					{
						anchorNode->left = anchorNode->left->singleRotateRight();//rotate
						anchorNode->left->right->parent = anchorNode->left;
						anchorNode->left->parent = anchorNode;
					}
					else
					{
						anchorNode->right = anchorNode->right->singleRotateRight();//rotate
						anchorNode->right->right->parent = anchorNode->right;
						anchorNode->right->parent = anchorNode;
					}

				}//else

			}//else if

/*******************************************************************************/

		}// if(doubleRotateFlag)

		singleRotateFlag = false;
		doubleRotateFlag = false;

		root->verifySearchOrder();
		root->verifyParentProperty();

		//cout << endl << "Tree integrity verified" << endl;
		//print(cout);
		//cout << endl;

	}//while

}//splayToRoot()

//no longer used, but kept in for legacy support
/*******************************************************************************/

template <class Base> void SplayTree<Base>::printLevelOrderInt(ostream &os) const
{

    SplayNode<Base>* temp = new SplayNode<int>(-1);
	if(root == NULL) // TREE IS EMPTY HERE, 0 ITEMS
	{
		os << "-1" << endl;
		return;
	}

	queue <SplayNode<Base>*> qParent,qChildren;
	int levelNum = 0;
    int count = 0;

	qParent.push(root);

	while(!qParent.empty())
	{
		os << "l" << " ";

		while(!qParent.empty() )
		{
			SplayNode<Base>* current = qParent.front();
			os << current->data << " ";
            if (current->data != -1) {
                count++;
                if (count == numNodes)
                return;
            }
			qParent.pop();
            
            
                if(current->left!=NULL) {
                    qChildren.push(current->left);
                    
                } else {
                    qChildren.push(temp);
                }
                if(current->right!=NULL) {
                    qChildren.push(current->right);
                    
                } else {
                   qChildren.push(temp);
                }
            
		}
		
		levelNum++;
		qParent = qChildren;
		while(!qChildren.empty()) qChildren.pop();
	}//while
    delete temp;
     
     
}//printLevelOrder()

/*******************************************************************************/
template<class Base>
vector<pair<int,string> > SplayTree<Base>::parseToVector()
{
    vector<pair<int,string> > dataVector;
    pair<int, string> dataPair;
    
    queue<pair<int, SplayNode<Base>*> > nodeQueueParent, nodeQueueChildren;
    pair<int, SplayNode<Base>*> nodePair;
    pair<int, SplayNode<Base>*> tempNodePair;
    
    
    if(root == NULL)
    {
        return dataVector;
    }
    
    
    // here 1 element is guaranteed, so add to vector and queue
    nodePair.first = 1;
    nodePair.second = root;
    nodeQueueParent.push(nodePair);
    
    //while(!nodeQueueParent.empty())
    //{
        while(!nodeQueueParent.empty())
        {
            nodePair = nodeQueueParent.front();
            nodeQueueParent.pop();
            
            dataPair.first = nodePair.first;
            //dataPair.second = nodePair.second->data;
            
            stringstream dataReader;
            dataReader << nodePair.second->data;
            string data = dataReader.str();
            dataPair.second = data;
            dataVector.push_back(dataPair);
            
            
            if(nodePair.second->left != NULL)
            {
                tempNodePair.first = (2 * nodePair.first);
                
                tempNodePair.second = nodePair.second->left;
                
                nodeQueueParent.push(tempNodePair);
            }
            if(nodePair.second->right!=NULL)
            {
                tempNodePair.first = (2 * nodePair.first)+1;
                
                tempNodePair.second = nodePair.second->right;
                
                nodeQueueParent.push(tempNodePair);
            }
        }
        
       // nodeQueueParent = nodeQueueChildren;
        //while(!nodeQueueChildren.empty()) nodeQueueChildren.pop();
    //}
    
    return dataVector;
    
    
    /*
    vector<pair<int,string> > nodes;
    
    pair<int,string> indexDataPair;
    pair<int,SplayNode<Base>*> currentPair;
    SplayNode<Base>* node;
    if(root == NULL) //empty tree
    {
        return nodes;
    }
    
    queue <pair<int,SplayNode<Base>*> > qParent,qChildren;
    int levelNum = 0;
    
    currentPair.first = 1;
    currentPair.second = root;
    
    qParent.push(currentPair);
    
    while(!qParent.empty())
    {
        
        while(!qParent.empty() )
        {
            currentPair = qParent.front();
            
            indexDataPair.first = currentPair.first;
            node = currentPair.second;
            stringstream intAsString;
            intAsString << node->data;
            string data = intAsString.str();
            
            indexDataPair.second = data;
            
            nodes.push_back(indexDataPair);
            
            qParent.pop();
            
            
            if(node->left!=NULL)
            {
                currentPair.first = currentPair.first*2;
                currentPair.second = node->left;
                qChildren.push(currentPair);
                
            }
            
            
            if(node->right!=NULL)
            {
                currentPair.first = currentPair.first*2+1;
                currentPair.second = node->right;
                qChildren.push(currentPair);
                
            }
            
            
        }
        
        levelNum++;
        qParent = qChildren;
        while(!qChildren.empty()) qChildren.pop();
    }//while
    
    return nodes;
     */
     
}

/*******************************************************************************/

template<class Base>void SplayNode<Base>::printPreorder(ostream&os, string indent) const
{
	if(this!=NULL)
	{
		os << indent << this->data << endl;
		this->left->printPreorder(os,indent+="  ");
		this->right->printPreorder(os,indent);
	}
	else
		os << indent << "NULL" << endl;
}

/*******************************************************************************/

template <class Base> void SplayTree<Base>::insert(const Base &item)
{
	if(root == NULL) // TREE IS EMPTY HERE, 0 ITEMS
	{
		root = new SplayNode<Base>(item,NULL,NULL,NULL);
        numNodes++;
		return;
	}

	SplayNode<Base>* ptr = root;
	SplayNode<Base>* parent = root;
	bool right = false;

	while(ptr != NULL)
	{
		if(ptr->data == item) return;

		else if(ptr->data < item){
			parent = ptr;
			ptr = ptr->right;
			right = true;
		}
		else if(ptr->data > item){
			parent = ptr;
			ptr = ptr->left;
			right = false;
		}
	}

	SplayNode<Base>* newNode;

	if(right)
	{
		parent->right = new SplayNode<Base>(item,parent,NULL,NULL);
        
		newNode = parent->right;
	}
	else
	{
		parent->left = new SplayNode<Base>(item,parent,NULL,NULL);
		newNode = parent->left;
	}
    
    numNodes++; // update # of nodes

	//cout << endl << "SPLAYING NODE -> "<< newNode->data<<endl; //temporary

	splayToRoot(newNode);
}

/*******************************************************************************/

template <class Base> bool SplayTree<Base>::find(const Base &item)
{
	if(root == NULL) // TREE IS EMPTY
		return false;

	SplayNode<Base>* lastNode = root;
	SplayNode<Base>* ptr = root;
	bool isFound = false;

	while(!isFound && ptr!=NULL)
	{
		if(ptr->data==item) isFound = true;

		else if(ptr->data < item)
		{
			lastNode = ptr;
			ptr = ptr->right;
		}
		else if(ptr->data > item)
		{
			lastNode = ptr;
			ptr = ptr->left;
		}
	}

	if(isFound == true)
		splayToRoot(ptr);
	else
		splayToRoot(lastNode);


	return isFound;
}


/*******************************************************************************/
/*
 * CASE 0: not found -> splay from last accessed node DONE
 *
 * CASE 1: delete root with 0 children -> do not splay
 * CASE 2: delete root with 1 children -> do not splay
 * CASe 3: delete root with 2 children -> splay removed node's parent
 *
 * CASE 4: delete node with 0 children -> splay removed node's parent
 * CASE 5: delete node with 1 children -> splay removed node's parent
 * CASE 6: delete node with 2 children -> splay removed node's parent
 *
 */


template <class Base>
void SplayTree<Base>::remove(const Base &item)
{
	if(root == NULL) // TREE IS EMPTY, 0 ITEMS
		return;

	SplayNode<Base>* ptr=root;
	SplayNode<Base>* parent=root;
	bool isFound = false, right = true;

	while(ptr != NULL && !isFound)
	{
		if(ptr->data == item)
			isFound = true;

		else if(ptr->data < item){
			parent = ptr;
			ptr = ptr->right;
			right = true;
		}
		else if(ptr->data > item){
			parent = ptr;
			ptr = ptr->left;
			right = false;
		}
	}

/*******************************************************************************/

	if(isFound == false)// item not found
	{
		splayToRoot(parent); //DONE
		return;
	}

/*******************************************************************************/

	if(ptr->right==NULL && ptr->left==NULL)// delete 0 children
	{
		if(ptr == root) // delete ROOT with 0 children, DO NOT SPLAY
		{
			delete root;
			root = NULL;
		}
		else // delete NODE with 0 children
		{
			right? parent->right = NULL : parent->left = NULL;
			delete ptr;

			splayToRoot(parent); //DONE
		}
	}//delete 0 children

/*******************************************************************************/

	else if(ptr->right != NULL && ptr->left != NULL)// delete 2 children
	{
		SplayNode<Base>* min = ptr->right;
		SplayNode<Base>* minParent = ptr->right;

		while(min->left!=NULL)
		{
			minParent = min;
			min = min->left;
		}

		ptr->data = min->data;

		if(min==ptr->right) // smallest larger val HAS IS right child
		{
			ptr->right = min->right;
			if(min->right)
				min->right->parent = ptr;
		}
		else
		if(min->right != NULL) //node to delete -> HAS right node
		{
			minParent->left = min->right;
			minParent->left->parent = minParent;
		}
		else // node to delete -> has NO right node
			minParent->left = NULL;

		min->parent = NULL;
		min->right=NULL;
		delete min;

		root->verifySearchOrder();
		root->verifyParentProperty();

		splayToRoot(parent);
        
        

	}// delete 2 children

/*******************************************************************************/

	else // delete 1 child
	{
		SplayNode<Base>* temp = root;

		if(ptr->right != NULL)// RIGHT child only
		{
			if(ptr==root)// delete ROOT with RIGHT child only, DO NOT SPLAY
			{
				root = root->right;
				temp->right = NULL;
				delete temp;
			}
			else // delete NODE with RIGHT child only
			{
				(right)? parent->right = ptr->right : parent->left = ptr->right;
				ptr->right = NULL;
				delete ptr;
				splayToRoot(parent);
			}
		}
		else // LEFT child only
		{
			if(ptr==root) // delete ROOT with LEFT child only, DO NOT SPLAY
			{
				root = root->left;
				temp->right = temp->left = NULL;
				delete temp;
			}
			else // delete NODE with LEFT child only
			{
				(right)? parent->right = ptr->left : parent->left = ptr->left;
				ptr->left = ptr->right = NULL;
				delete ptr;
				splayToRoot(parent);
			}
		}

	}// delete 1 child

/*******************************************************************************/

    numNodes--;
    
}// remove()

/*******************************************************************************/


