#include <iostream>
#include "Node.cpp"

using namespace std;

class LinkedList {
    private:
        int size;
        bool prevCounter; // To prevent consecutive previous functions()
        Node *headNode;
        Node *currentNode, *lastCurrentNode;

    public:
        // Constructor
        LinkedList() {
            headNode = new Node();
            headNode->setNext(NULL);
            currentNode = NULL;
            size = 0;
            prevCounter = 0;
        }

        void add(int addObject) {
            Node* newNode = new Node();
            newNode->set(addObject);
        
            if (currentNode != NULL) {
                newNode->setNext(currentNode->getNext());
                currentNode->setNext(newNode);
                lastCurrentNode = currentNode;
                currentNode = newNode;
            }
           else {
                newNode->setNext(NULL);
                headNode->setNext(newNode);
                lastCurrentNode = headNode->getNext();
                currentNode =  newNode;
            }
            size++;
            prevCounter = 0;
        }

        void edit(int editObject) {
            if(currentNode != headNode->getNext())
                currentNode->set(editObject);
        }

        int get() {
            if (currentNode != headNode->getNext())
                return currentNode->get();
        }
        
        bool next() {
            if (currentNode == NULL) return false;

            lastCurrentNode = currentNode;
            currentNode = currentNode->getNext();
            prevCounter = 0;
            if (currentNode == NULL || size == 0) 
                return false;
            else
                return true;
        }

        bool next(int n) {
            bool b;
			for (int i = 0; i < n; i++)
            	b = next();
            return b;
        }
        
        bool previous() {
        	if (currentNode != headNode->getNext() && prevCounter != 1) {
        		currentNode = lastCurrentNode;
        		prevCounter = 1;
			}
			return 0;
		}

        void start() {
            lastCurrentNode = headNode->getNext();
            currentNode = headNode->getNext();
            prevCounter = 0;
        }

        void remove() {
            if(currentNode != NULL && currentNode != headNode->getNext()) {
                lastCurrentNode->setNext(currentNode->getNext());
                delete currentNode;
                currentNode = lastCurrentNode->getNext();
                size--;
                prevCounter = 1;
            }
            else if(currentNode != headNode->getNext()) {
                delete currentNode;
                currentNode = lastCurrentNode;
                currentNode->setNext(NULL);
                lastCurrentNode->setNext(NULL);
                size--;
                prevCounter = 1;
            }
        }

        void emptyIt() {
            this->start();
            if(this->size > 0) {
				do 
					this->remove();
				while (this->next());
			}
            size = 0;
            currentNode = NULL;
            headNode->setNext(NULL);
        }

        void Show() {
            this->start();
            if(this->size > 0) {
                do {
                    cout << this->get() << ", ";
                } while(this->next());
                cout << "\b\b \b\n";
            }
        }

        int length() { 
            return size; 
        }

        bool operator == (LinkedList sample) {
            bool flag = true;
            sample.start();
            this->start();
            if(sample.length() == this->length()) {
                do {
                    if (this->get() != sample.get()) {
                        flag = false;
                    }
                } while(sample.next() && this->next());
            }
            else flag = false;
            return flag;
        }

        bool operator != (LinkedList sample) {
            bool flag = this->operator == (sample);
            return !flag;
        }
};
