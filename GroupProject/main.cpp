#include <iostream>
#include "Group0Splay.h"
#include "Group0SplayIMPL.h"
using namespace std;
void solve();

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
			case 'p':
			{
				mySplayTree.printLevelOrder(cout);
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
