#include <iostream>
#include "LinkedList.cpp"

using namespace std;



int main() {
	LinkedList list;
	
	list.add(5); list.add(13); list.add(4);
	list.add(8); list.add(24); list.add(48); list.add(12);
	list.start();
	
	list.next(3);
	cout << list.get() << endl;
	list.remove();
	cout << list.get();
	
	return 0;
}
