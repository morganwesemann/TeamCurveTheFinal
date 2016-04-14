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

// SPLAY NODE IMPLEMENTATION HERE
template <class Base>
class SplayNode
{
public:
	friend class SplayTree<Base>;

	// CONSTRUCTOR, DESTRUCTOR
	SplayNode											//DONE
	(
		const Base &d = Base(),
		SplayNode*l=NULL,
		SplayNode*r=NULL
	) :data(d),left(l),right(r){}
	~SplayNode();										//DONE

	// FIND MIN, FIND MAX
	const SplayNode *minNode() const;					//DONE
	const SplayNode *maxNode() const;					//DONE

	// ROTATIONS HERE
	SplayNode *singleRotateLeft(); 						//DONE
	SplayNode *singleRotateRight(); 					//DONE
	SplayNode *doubleRotateLeftRight(); 				//DONE
	SplayNode *doubleRotateRightLeft(); 				//DONE

	// GETTERS HERE
	const SplayNode* getLeft() const 	{return left;}	//DONE
	const SplayNode* getRight() const	{return right;}	//DONE
	const Base& getData() const			{return data;}	//DONE

	// SPLAY HERE
	const SplayNode* splay(SplayNode* root, Base& item);

protected:
	Base data;
	SplayNode *left, *right;
};


////////////////////////////////////////////////////////////////////////////////


// SPLAY TREE IMPLEMENTATION HERE
template <class Base>
class SplayTree
{
public:

	// CONSTRUCTOR, DESTRUCTOR
	SplayTree() {root = NULL;}
	virtual ~SplayTree(){SplayNode<Base> *r = root;root = NULL;delete r;}

	// INSERT, REMOVE, FIND, DISPLAY
	void insert(const Base &item);
	void remove(const Base &item);
	bool find(const Base &item);
	void display(ostream &os = cout) const {if (root) root->display(os);}

protected:
	SplayNode<Base> *root;
};







#endif
