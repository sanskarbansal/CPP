#include<iostream>
#include "mapNode.h"
using namespace std;

int main()
{
	ourmap<int> s;
	s.insert("abc", 1);
	s.insert("abc", 10);
	s.insert("bcd", 2);
	cout << s.getValue("abc") << endl;
	cout << s.deleteMap("bcd") << endl;
	cout << s.getValue("abc") ;
	return 0;
}
