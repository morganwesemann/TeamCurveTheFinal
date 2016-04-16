#include "Group0Splay.h"
#include <queue>

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
				if(root->left)
					root->left->parent = root;
				cout << "single R rotation" << endl;
			}
			else
			{
				root = root->singleRotateLeft();
				if(root->right)
					root->right->parent=root;
				cout << "single L rotation" << endl;
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

			cout << endl;
			cout << "current     data = " << myData<<endl;
			cout << "parent      data = " << parentData<<endl;
			cout << "grandparent data = " << grandParentData<<endl;

/*******************************************************************************/
			if(grandParentData < parentData && parentData < myData) //RR access
			{
				cout << endl << "LL correction" << endl;//temporary

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

					cout << "LL correction done" << endl;//temp
				}
			}
/*******************************************************************************/
			else if(grandParentData > parentData && parentData > myData)//LL access
			{
				cout << endl << "RR correction" << endl;//temporary

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
				cout << endl << "LR correction" << endl;//temporary

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
				cout << endl << "RL correction" << endl;//temporary

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

/*******************************************************************************/

template <class Base> void SplayTree<Base>::printLevelOrder(ostream &os) const
{
	if(root == NULL) {os << "NULL" << endl;return;}

	queue <SplayNode<Base>*> qParent,qChildren;
	int levelNum = 0;

	qParent.push(root);

	while(!qParent.empty())
	{
		os << "Level "<< levelNum << ":\t";

		while(!qParent.empty())
		{
			SplayNode<Base>* current = qParent.front();
			os << current->data << " ";
			qParent.pop();
			if(current->left!=NULL)
				qChildren.push(current->left);
			if(current->right!=NULL)
				qChildren.push(current->right);
		}
		os << endl;
		levelNum++;
		qParent = qChildren;
		while(!qChildren.empty()) qChildren.pop();
	}//while

}//printLevelOrder()

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
	if(root == NULL) {root = new SplayNode<Base>(item,NULL,NULL,NULL);return;}

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

	//cout << endl << "SPLAYING NODE -> "<< newNode->data<<endl; //temporary

	splayToRoot(newNode);
}

/*******************************************************************************/

template <class Base> bool SplayTree<Base>::find(const Base &item)
{
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

// i 50 i 2 i 90 i 58 i 32 i 5956 i 32 i 99
// i 100

/*******************************************************************************/
