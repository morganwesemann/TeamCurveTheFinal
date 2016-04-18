#include <iostream>
#include "Group0Splay.h"
#include "Group0SplayIMPL.h"
using namespace std;
void solve();

// TEST DATA:

// i 50 i 2 i 90 i 58 i 32 i 5900 i 99
// i 100 i 58 i 48 i 93 i 43 i 22 i 99 i 11 i 3 i 5 i 88 i 42 i 31 i 35
// r 35 r 48 r 43 r 3 r 100 r 88 r 42 r 88 f 93 f 11 r11

// i 10 i 5 i 15 i 7
// i 15 i 10 i 1 i 5
int main()
{
	solve();
	cout << "COMPLETE" << endl;
	return 0;
}

void solve()
{
	char operation;
	bool valid = true;
	int item;
	SplayTree<int> mySplayTree;

	cin >> operation;

	while(valid)
	{
		switch(operation)
		{
			case 'i':
			{
				cin >> item;
				mySplayTree.insert(item);
				break;
			}
			case 'f':
			{
				cin >> item;

				if(mySplayTree.find(item))
					cout << item << " found!" << endl;
				else
					cout << item << " not found..." << endl;

				break;
			}
			case 'p':
			{
				mySplayTree.printPreorder(cout);
				break;
			}
			case 'l':
			{
				mySplayTree.printLevelOrder(cout);
				break;
			}
			case 'r':
			{
				cin >> item;
				mySplayTree.remove(item);
				break;
			}
			case 'q':
			{
				valid = false;
				break;
			}
		}

		if(valid)
			cin >> operation;

	}//end while

}//end solve()
