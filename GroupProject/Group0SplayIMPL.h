#include "Group0Splay.h"
#include <queue>

//verifySearchOrder()
//verfiyParentProperty()

////////////////////////////////////////////////////////////////////////////////

template <class Base>
/*ID=2 DONE*/const SplayNode<Base>* SplayNode<Base>::maxNode() const
{
	const SplayNode<Base> * ptr = this;

	while(ptr->right != NULL)
		ptr = ptr->right;

	return ptr;
}

////////////////////////////////////////////////////////////////////////////////

template <class Base>
/*ID=2 DONE*/const SplayNode<Base>* SplayNode<Base>::minNode() const
{
	const SplayNode<Base> * ptr = this;

	while(ptr->left != NULL)
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
	this->left = leftNode -> right;
	leftNode->right = this;

	//update parent
	leftNode->right->parent=leftNode;

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
	this->right = rightNode -> left;
	rightNode -> left = this;

	//update parent
	rightNode->left->parent=rightNode;

	return rightNode;
}



////////////////////////////////////////////////////////////////////////////////
template<class Base>

void SplayTree<Base>::splayToRoot(SplayNode<Base>* ptr)
{
	Base myData,parentData,grandParentData;
	bool singleRotateFlag=false;
	bool doubleRotateFlag=false;
	bool isDone = false;

	while(isDone == false)
	{
		if(ptr == root->left || ptr == root->right) // 1 LEVEL FROM ROOT
		{
			if(root->data > ptr->data)
				root = root -> singleRotateRight();
			else
				root = root -> singleRotateLeft();
			root->parent = NULL;
			isDone = true;
		}

		else // 2 OR MORE LEVELS FROM ROOT
		{
			myData = ptr->data;
			parentData = ptr->parent->data;
			grandParentData = ptr->parent->parent->data;
			SplayNode<Base>* rotateNode = ptr->parent->parent;

			if(grandParentData < parentData && parentData < myData) //RR access
			{
				//LL correction
				if(rotateNode == root)
				{
					root = root->singleRotateLeft();
					root->left->parent = root;
					root = root->singleRotateLeft();
					root->left->parent = root;

					root->parent = NULL;
					isDone=true;
				}
				else
				{
					rotateNode = rotateNode->parent;
					rotateNode->right = rotateNode->right->singleRotateLeft();
					rotateNode->right->left->parent=rotateNode->right;

					rotateNode->right = rotateNode->right->singleRotateLeft();
					rotateNode->right->left->parent=rotateNode->right;

					rotateNode->right->parent = rotateNode;
					ptr = rotateNode->right;
				}
			}
			else if(grandParentData > parentData && parentData > myData)//LL access
			{
				//RR correction START
				if(rotateNode == root)
				{
					root = root->singleRotateRight();
					root->right->parent = root;

					root = root->singleRotateRight();
					root->right->parent = root;

					root->parent = NULL;
					isDone=true;
				}
				else
				{
					rotateNode = rotateNode->parent;

					rotateNode->left = rotateNode->left->singleRotateRight();
					rotateNode->left->right->parent=rotateNode->left;

					rotateNode->left = rotateNode->left->singleRotateRight();
					rotateNode->left->right->parent=rotateNode->left;

					rotateNode->left->parent = rotateNode;
					ptr = rotateNode->left;
				}
				//RR correction END
			}
			else if(grandParentData < parentData && parentData > myData)//RL access
			{
				//LR correction
				if(rotateNode == root)
				{
					root->right = root->right->singleRotateRight();

					root -> right->parent = root;//update parent
					root->right->right->parent=root->right;//update parent

					root = root -> singleRotateLeft();
					isDone = true;
				}
				else
				{
					SplayNode<Base>* temp = rotateNode->parent;

					rotateNode->right = rotateNode->right->singleRotateRight();

					rotateNode->right->right->parent=rotateNode->right;//update parent
					rotateNode->right->parent = rotateNode;//update parent

					temp->right = temp->right->singleRotateLeft();
					temp->right->left->parent = temp->right;//update parent
					temp->right->parent = temp;//update parent
				}
			}
			else if(grandParentData > parentData && parentData < myData)//LR access
			{
				//RL correction , adjusted
				if(rotateNode == root)
				{
					root->left = root->left->singleRotateLeft();

					root -> left->parent = root;//update parent
					root->left->left->parent=root->left;//update parent

					root = root -> singleRotateRight();
					isDone = true;
				}
				else
				{
					SplayNode<Base>* temp = rotateNode->parent;

					rotateNode->left = rotateNode->left->singleRotateLeft();

					rotateNode->left->left->parent=rotateNode->left;//update parent
					rotateNode->left->parent = rotateNode;//update parent

					temp->left = temp->left->singleRotateRight();
					temp->left->right->parent = temp->left;//update parent
					temp->left->parent = temp;//update parent
				}
			}
		}

		//cout << "working..." << endl;

	}//while

}//splayToRoot()

////////////////////////////////////////////////////////////////////////////////

template <class Base>
void SplayTree<Base>::printLevelOrder(ostream &os) const
{
	if(root == NULL)
	{
		os << "NULL" << endl;
		return;
	}

	SplayNode<Base>* current;
	queue <SplayNode<Base>*> qParent;
	queue <SplayNode<Base>*> qChildren;
	int levelNum = 0;

	qParent.push(root);

	while(!qParent.empty())
	{
		os << "Level "<< levelNum << ":\t";
		while(!qParent.empty())
		{

			current = qParent.front();
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

////////////////////////////////////////////////////////////////////////////////

template <class Base>
void SplayNode<Base>::printPreorder(ostream &os, string indent) const
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

////////////////////////////////////////////////////////////////////////////////


template <class Base>
/*ID=2 */void SplayTree<Base>::insert(const Base &item)
{
	if(root == NULL)
	{
		root = new SplayNode<Base>(item,NULL,NULL,NULL);
		printPreorder(cout);
		return;
	}

	SplayNode<Base>* ptr = root;
	SplayNode<Base>* parent = root;
	bool right = false;

	while(ptr != NULL)
	{
		if(ptr->data == item) return;

		if(ptr->data < item){
			parent = ptr;
			ptr = ptr->right;
			right = true;
		}
		else
			if(ptr->data > item){
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

	splayToRoot(newNode);

	this->verifySearchOrder();
	this->verifyParentProperty();

	printPreorder(cout);
}

////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////
