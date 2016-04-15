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
	/*ID=3 DONE*/SplayNode *singleRotateLeft();
	/*ID=4 DONE*/SplayNode *singleRotateRight();
	/*ID=5 DONE*/void printPreorder(ostream &os = cout, string indent = "") const;


protected:
	Base data;
	SplayNode *left, *right, *parent;
};


////////////////////////////////////////////////////////////////////////////////


// SPLAY TREE IMPLEMENTATION HERE
template <class Base>
class SplayTree
{
public:
	/*ID=0 DONE*/SplayTree()
	{root = NULL;}
	/*ID=1 DONE*/virtual ~SplayTree() { SplayNode<Base> *r = root; root = NULL; delete r; }

	/*ID=2 */void insert(const Base &item);
	/*ID=3 */void remove(const Base &item);
	/*ID=4 */bool find(const Base &item);
	/*ID=5 */void splayToRoot(SplayNode<Base>* ptr);
	/*ID=6 DONE*/void printLevelOrder(ostream &os = cout) const;
	/*ID=7 DONE*/void printPreorder(ostream &os = cout) const
	{if (root) root->printPreorder(os);}

protected:
	SplayNode<Base> *root;
};






#endif
