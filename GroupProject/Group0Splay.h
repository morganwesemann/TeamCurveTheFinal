#ifndef SPLAYTREECONSTANT
#define SPLAYTREECONSTANT

// PREPROCESSOR DIRECTIVES
#include <iostream>
#include <string>
#include <cassert>
using namespace std;

template <class Base>
class SplayTree;

////////////////////////////////////////////////////////////////////////////////

template <class Base>
class SplayNode
{
public:
	friend class SplayTree<Base>;

	/*ID=0 DONE*/SplayNode (const Base &d = Base(),SplayNode*p=NULL,SplayNode*l=NULL,SplayNode*r=NULL)
	:data(d),parent(p),left(l),right(r){}
	/*ID=1 DONE*/~SplayNode(){delete left;delete right;}

	/*ID=2 DONE*/const SplayNode *minNode() const;
	/*ID=2 DONE*/const SplayNode *maxNode() const;
	/*ID=3 DONE*/SplayNode *singleRotateLeft();
	/*ID=4 DONE*/SplayNode *singleRotateRight();
	/*ID=5 DONE*/void printPreorder(ostream &os = cout, string indent = "") const;

	void verifySearchOrder() const;
	void verifyParentProperty() const;

protected:
	Base data;
	SplayNode *left, *right, *parent;
};

template <class Base>
void SplayNode<Base>::verifySearchOrder() const
{
    if (left)
    {
        assert(left->maxNode()->data < data);
        left->verifySearchOrder();
    }
    if (right)
    {
        assert(data < right->minNode()->data);
        right->verifySearchOrder();
    }
}

template <class Base>
void SplayNode<Base>::verifyParentProperty() const
{
    if (left!=NULL)
    {
        assert(this->left->parent == this);
        left->verifyParentProperty();
    }

    if (right!=NULL)
    {
    	assert(this->right->parent == this);
        right->verifyParentProperty();
    }
}

////////////////////////////////////////////////////////////////////////////////


// SPLAY TREE IMPLEMENTATION HERE
template <class Base>
class SplayTree
{
public:
	/*DONE HERE*/SplayTree(){root = NULL;}
	/*DONE HERE*/virtual ~SplayTree() { SplayNode<Base> *r = root; root = NULL; delete r; }
	/*DONE HERE*/void print(ostream &os = cout) {printPreorder(os);}
	/*DONE HERE*/void verifySearchOrder() const{ if (root) root->verifySearchOrder(); }
	/*DONE HERE*/void verifyParentProperty() const{ if (root) root->verifyParentProperty(); }
	/*DONE HERE*/void printPreorder(ostream &os = cout) const{if (root) root->printPreorder(os);}

	/*ID=0 DONE*/void insert(const Base &item);
	/*ID=1 */void remove(const Base &item);
	/*ID=2 DONE*/bool find(const Base &item);
	/*ID=3 DONE*/void splayToRoot(SplayNode<Base>* ptr);
	/*ID=4 DONE*/void printLevelOrder(ostream &os = cout) const;

protected:
	SplayNode<Base> *root;
};

#endif
