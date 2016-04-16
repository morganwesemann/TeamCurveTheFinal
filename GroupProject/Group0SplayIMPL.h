#include "Group0Splay.h"
#include <queue>

//verifySearchOrder()
//verfiyParentProperty()

////////////////////////////////////////////////////////////////////////////////

template <class Base>
/*ID=2 DONE*/const SplayNode<Base>* SplayNode<Base>::maxNode() const
{
	const SplayNode<Base> * ptr = this;

	while (ptr->right != NULL)
		ptr = ptr->right;

	return ptr;
}

////////////////////////////////////////////////////////////////////////////////

template <class Base>
/*ID=2 DONE*/const SplayNode<Base>* SplayNode<Base>::minNode() const
{
	const SplayNode<Base> * ptr = this;

	while (ptr->left != NULL)
		ptr = ptr->left;

	return ptr;
}

////////////////////////////////////////////////////////////////////////////////

/*
* rotate ptr
*
* node* temp = ptr->parent;
* ptr=ptr->singleRotateRight();
* temp->left = ptr;
* ptr->parent=temp;
*
*/

template <class Base>
/*ID=3 DONE*/SplayNode<Base>* SplayNode<Base>::singleRotateRight()
{
	SplayNode<Base>* leftNode = this->left;

	//update children
	this->left = leftNode->right;
	leftNode->right = this;

	//update parent
	leftNode->right->parent = leftNode;

	return leftNode;
}

////////////////////////////////////////////////////////////////////////////////

/*
* rotate around ptr
*
* Node* temp = ptr -> parent;
* ptr = ptr -> singleRotateLeft();
* temp->left = ptr;
* ptr->parent = temp;
*
*/
template <class Base>
/*ID=4 DONE*/SplayNode<Base>* SplayNode<Base>::singleRotateLeft()
{
	SplayNode<Base>* rightNode = this->right;

	//update children
	this->right = rightNode->left;
	rightNode->left = this;

	//update parent
	rightNode->left->parent = rightNode;

	return rightNode;
}



////////////////////////////////////////////////////////////////////////////////
template<class Base>

void SplayTree<Base>::splayToRoot(SplayNode<Base>* ptr)
{

	//IN ALL DOUBLE ROTATE CASES, ROTATE TWICE AROUND GRANDPARENT

	Base rootData;
	Base myData;
	Base parentData;
	Base grandParentData;
	bool flagSingleRotate = false;
	bool flagDoubleRotate = false;


	while (ptr != root)
	{
		cout << "working..." << endl;

		if (ptr == root->left || ptr == root->right) // 1 node above
			flagSingleRotate = true;
		else
			flagDoubleRotate = true;


		if (flagSingleRotate)
		{
			// single rotate here
			myData = ptr->data;
			rootData = root->data;

			if (rootData > myData)//L access
			{
				//R rotate here
				root = root->singleRotateRight();
			}
			else
			{
				//L rotate here
				root = root->singleRotateLeft();
			}

		}//if singlerotate



		if (flagDoubleRotate)
		{
			// double rotate here

			// set up data here
			myData = ptr->data;
			parentData = ptr->parent->data;
			grandParentData = ptr->parent->parent->data;

			if (grandParentData < parentData && parentData < myData) //RR access
			{
				//LL rotate to correct

				SplayNode<Base>* grandPtr = ptr->parent->parent;
				SplayNode<Base>* parentPtr = ptr->parent;

				//L rotation here
				parentPtr = parentPtr->singleRotateLeft();
				grandPtr->right = parentPtr;
				parentPtr->left->parent = parentPtr;

				if (grandPtr == root)
				{
					root = root->singleRotateLeft(); //single left rotate to root
				}
				else
				{
					SplayNode<Base>* temp = grandPtr->parent;
					grandPtr = grandPtr->singleRotateLeft(); //single left rotate
					temp->right = grandPtr;
					grandPtr->parent = temp;// second rotate down
					ptr = grandPtr;// update ptr
				}

			}
			else if (grandParentData < parentData && parentData > myData)//RL access
			{
				SplayNode<Base>* grandPtr = ptr->parent->parent;
				SplayNode<Base>* parentPtr = ptr->parent;

				parentPtr = parentPtr->singleRotateRight();	//update parentPtr
				parentPtr->right->parent = parentPtr;		//ensure child parent is true
				grandPtr->right = parentPtr;				//ensure parent parent is true
				// first right rotate done

				if (grandPtr == root)
				{
					root = root->singleRotateLeft(); //single left rotate to root
				}
				else
				{
					SplayNode<Base>* temp = grandPtr->parent;
					grandPtr = grandPtr->singleRotateLeft(); //single left rotate
					temp->right = grandPtr;
					grandPtr->parent = temp;// second rotate down
					ptr = grandPtr;// update ptr
				}
			}
			else if (grandParentData > parentData && parentData > myData)//LL access
			{
				//RR rotate to correct

				SplayNode<Base>* grandPtr = ptr->parent->parent;
				SplayNode<Base>* parentPtr = ptr->parent;

				//R rotation here
				parentPtr = parentPtr->singleRotateRight();
				grandPtr->left = parentPtr;
				parentPtr->right->parent = parentPtr;

				if (grandPtr == root)
				{
					root = root->singleRotateRight(); //single left rotate to root
				}
				else
				{
					SplayNode<Base>* temp = grandPtr->parent;
					grandPtr = grandPtr->singleRotateRight(); //single left rotate
					temp->left = grandPtr;
					grandPtr->parent = temp;// second rotate down
					ptr = grandPtr;// update ptr
				}

			}
			else if (grandParentData > parentData && parentData < myData)//LR access
			{
				//RL rotate
				SplayNode<Base>* grandPtr = ptr->parent->parent;
				SplayNode<Base>* parentPtr = ptr->parent;

				parentPtr = parentPtr->singleRotateLeft();	//update parentPtr
				parentPtr->left->parent = parentPtr;		//ensure child parent is true
				grandPtr->left  = parentPtr;				//ensure parent parent is true
															// first right rotate done

				if (grandPtr == root)
				{
					root = root->singleRotateRight(); //single left rotate to root
				}
				else
				{
					SplayNode<Base>* temp = grandPtr->parent;
					grandPtr = grandPtr->singleRotateRight(); //single left rotate
					temp->left = grandPtr;
					grandPtr->parent = temp;// second rotate down
					ptr = grandPtr;// update ptr
				}
			}

		}//if doublerotate

		 // reset flags here
		flagSingleRotate = false;
		flagDoubleRotate = false;

	}//while

}//splayToRoot()

 ////////////////////////////////////////////////////////////////////////////////

template <class Base>
void SplayTree<Base>::printLevelOrder(ostream &os) const
{
	if (root == NULL)
	{
		os << "NULL" << endl;
		return;
	}

	SplayNode<Base>* current;
	queue <SplayNode<Base>*> qParent;
	queue <SplayNode<Base>*> qChildren;
	int levelNum = 0;

	qParent.push(root);

	while (!qParent.empty())
	{
		os << "Level " << levelNum << ":\t";
		while (!qParent.empty())
		{

			current = qParent.front();
			os << current->data << " ";

			qParent.pop();

			if (current->left != NULL)
				qChildren.push(current->left);
			if (current->right != NULL)
				qChildren.push(current->right);
		}

		os << endl;

		levelNum++;

		qParent = qChildren;
		while (!qChildren.empty()) qChildren.pop();

	}//while


}//printLevelOrder()

 ////////////////////////////////////////////////////////////////////////////////

template <class Base>
void SplayNode<Base>::printPreorder(ostream &os, string indent) const
{
	if (this != NULL)
	{
		os << indent << this->data << endl;
		this->left->printPreorder(os, indent += "  ");
		this->right->printPreorder(os, indent);
	}
	else
		os << indent << "NULL" << endl;
}

////////////////////////////////////////////////////////////////////////////////


template <class Base>
/*ID=2 */void SplayTree<Base>::insert(const Base &item)
{
	if (root == NULL)
	{
		root = new SplayNode<Base>(item, root, NULL, NULL);
		printPreorder(cout);
		return;
	}

	SplayNode<Base>* ptr = root;
	SplayNode<Base>* parent = root;
	bool right = false;

	while (ptr != NULL)
	{
		if (ptr->data == item) return;

		if (ptr->data < item) {
			parent = ptr;
			ptr = ptr->right;
			right = true;
		}
		else
			if (ptr->data > item) {
				parent = ptr;
				ptr = ptr->left;
				right = false;
			}
	}

	SplayNode<Base>* newNode;

	if (right)
	{
		parent->right = new SplayNode<Base>(item, parent, NULL, NULL);
		newNode = parent->right;
	}
	else
	{
		parent->left = new SplayNode<Base>(item, parent, NULL, NULL);
		newNode = parent->left;
	}


	//printLevelOrder(cout);
	//printPreorder(cout);

	splayToRoot(newNode);

	this->verifySearchOrder();
	this->verifyParentProperty();

	printPreorder(cout);
}



////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
