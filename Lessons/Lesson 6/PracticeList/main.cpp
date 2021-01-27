#include <iostream>
#include "List.h"

using namespace std;

void main()
{
	List list;

	list.addToHead(100);
	list.addToHead(3);
	list.addToHead(56);
	/*list.addToHead(74);
	list.addToHead(23);
	list.addToHead(20);*/


	list.delFromTail();
	list.Print();

	list.delByIndex(0);
	list.Print();

}