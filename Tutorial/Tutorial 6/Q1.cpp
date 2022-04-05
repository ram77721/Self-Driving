#include<iostream>
using namespace std;

#include <queue>
using std::queue;
queue<float> myQ;





typedef int Elem;
class SNode {					// circularly linked list node
    private:
        Elem elem;					// linked list element value
        SNode* next;				// next item in the list

    friend class SLinkedList;			// provide CircleList access
};

class SLinkedList {			// a singly linked list of Elems
    public:
        SLinkedList();			    // empty list constructor
        ~SLinkedList();			// destructor
        bool empty() const;				// is list empty?
        const Elem& front() const;		// get front element
        void addFront(const Elem& e);		// add to the front of list
        void removeFront();				// remove front item list
        int sizeRec();
        int sumRec();
        void printRec();
        void printReverseRec();
        bool containsRec(int n);
        void addTailRec(int n);


    private:
        SNode* head;				// pointer to the head of list
        int _sizeRec(SNode* node);
        int _sumRec(SNode* node);
        void _printRec(SNode* node);
        void _printReverseRec(SNode* node);
        bool _containsRec(SNode* node, int n);
        void _addTailRec(SNode* node, int n);

};

SLinkedList::SLinkedList()			// constructor
    : head(NULL) { }

SLinkedList::~SLinkedList()			// destructor
    { while (!empty()) removeFront(); }

bool SLinkedList::empty() const			// is list empty?
    { return head == NULL; }

const Elem& SLinkedList::front() const		// get front element
    { return head->elem; }

void SLinkedList::addFront(const Elem& e) {	// add to front of list
    SNode* v = new SNode;			// create new node
    v->elem = e;					// store data
    v->next = head;					// head now follows v
    head = v;						// v is now the head
}

void SLinkedList::removeFront() {		// remove front item
    SNode* old = head;				// save current head
    head = old->next;					// skip over old head
    delete old;						// delete the old head
}

//Size of List
int SLinkedList::_sizeRec(SNode* node){
    if(node == NULL){
        return 0;
    }
    else{
        return 1 + _sizeRec(node->next);
    }
}

int SLinkedList::sizeRec(){
    return _sizeRec(head);
}

//Sum of list
int SLinkedList::_sumRec(SNode* node){
    if(node == NULL){
        return 0;
    }
    else{
        return (node->elem) + _sumRec(node->next);
    }
}

int SLinkedList::sumRec(){
    return _sumRec(head);
}

//Print list
void SLinkedList::_printRec(SNode* node){
    if(node!= NULL){
        cout << node->elem << " " ;
        _printRec(node->next);
    }
   
}

void SLinkedList::printRec(){
     return _printRec(head);
}

//Reverse List print
void SLinkedList::_printReverseRec(SNode* node){
    if(node == NULL){
        return;
    }
    else{
        _printReverseRec(node->next);
        cout << node->elem << " " ;

    }
   
}

void SLinkedList::printReverseRec(){
     return _printReverseRec(head);
}

//contains
bool SLinkedList::_containsRec(SNode* node, int n){
    if(node == NULL){
        return false;
    }
    else{
        if(node->elem == n){
            return true;
        }
        else{
            return _containsRec(node->next,n);
        }
    }
   
}

bool SLinkedList::containsRec(int n){
     return _containsRec(head,n);
}

//addTail
void SLinkedList::_addTailRec(SNode* node,int n){
    if(node == NULL){
        return;
    }
    else{
        _addTailRec(node->next,n);
        cout << node->elem << " " ;

    }
   
}

void SLinkedList::addTailRec(int n){
     return _addTailRec(head,n);
}


int main( ) {
    SLinkedList a;				// list of integers
    a.addFront(1);
    a.addFront(2);
    a.addFront(3);
    a.addFront(4);
    cout << a.sumRec() << endl;
    a.printRec();
    cout << endl;
    a.printReverseRec();
    if(a.containsRec(1)){ cout << "contained";}

    return 0;
}