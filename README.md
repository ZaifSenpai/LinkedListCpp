# LinkedListCpp
Linked List data structure implementation in C++

## Functions of LinkedList class:

### LinkedList()
Constructor

### add(int)
To add a new node in after the current node in linked list.

### edit(int)
Change the value of current node.

### int get()
Returns value at current node.

### bool next()
Navigate to node present next to current node.

### bool next(int n)
Navigate 'n' times after the current node.

### bool previous()
Navigate to that node which was the 'current node' before the current 'current node'. Only one navigation to previous node is alowed at one time. You can not go back multiple times at once because this class is not keeping track of all previous nodes.

### start()
Go to the first node in linked list.

### remove()
Remove current node from the linked list.

### emptyIt()
Deletes all nodes from Linkedlist

### Show()
Prints all values of the linkedlist from first node to last node.

### int length()
Returns total number of nodes in the Linkedlist

### bool operator == (LinkedList sample)
Compares current linkedlist and given linked list and returns true if both are same, else return false. Usage:
list1 == list2

### bool operator != (LinkedList sample)
Compares current linkedlist and given linked list and returns false if both are same, else return true. Usage:
list1 != list2
