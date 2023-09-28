#include <iostream>

using namespace std;

// Data Class : Holds all the data that goes inside the Node
class Data {
public:
    int value;
    string name;
    Data(int value, string name) {
        this->value = value;
        this->name = name;
    }

    //encapsulation to get the value and name of the node
    string getName()
    {
        return name;
    }
    int getValue()
    {
        return value;
    }
    void print() {
        cout << "["<< value << ", " << name << "] ";
    }

};

// Node Class : Node for the LinkedList
template <typename T> class Node {
public:
    T *value;
    Node<T> *next;
    Node<T> *prev;
    Node(T *value) {
        this->value = value;
        next = nullptr;
        prev = nullptr;
    }
    void print() { value->print(); }
};

// LinkedList Class : Container for Nodes
template <typename T> class DoubleLinkedList {
private:
    Node<T> *head;
    Node<T> *tail;
    int length;

public:
    // Constructor
    DoubleLinkedList(T *value) {
        Node<T> *newNode = new Node<T>(value);
        head = newNode;
        tail = newNode;
        length = 1;
    }

    // Destructor
    ~DoubleLinkedList() {
        Node<T> *temp = head;
        while (head) {
            head = head->next;
            delete temp;
            temp = head;
        }
    }

    void printList() {
        Node<T> *temp = head;
        while (temp != nullptr) {
            temp->print();
            temp = temp->next;
        }
    }

    // get and set
    Node<T> *getHead() {
        if (head == nullptr) {
            cout << "Head: nullptr" << endl;
        } else {
            cout << "Head: " << head->value << endl;
        }
        return head;
    }

    Node<T> *getTail() {
        if (tail == nullptr) {
            cout << "Tail: nullptr" << endl;
        } else {
            cout << "Tail: " << tail->value << endl;
        }
        return tail;
    }

    int getLength() {
        cout << "Length: " << length << endl;
        return length;
    }

    Node<T> *get(int index) {
        if (index < 0 || index >= length)
            return nullptr;
        Node<T> *temp = head;
        for (int i = 0; i < index; ++i) {
            temp = temp->next;
        }
        return temp;
    }

    bool set(int index, T *value) {
        Node<T> *temp = get(index);
        if (temp) {
            temp->value = value;
            return true;
        }
        return false;
    }

    // All insert methods
    // Insert at end
    void append(T *value) {
        Node<T> *newNode = new Node<T>(value);
        if (length == 0) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        length++;
    }

    // Insert at beginning

    void prepend(T *value) {
        Node<T> *newNode = new Node<T>(value);
        if (length == 0) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
        length++;
    }

    // Insert at Index

    bool insert(int index, T *value) {
        if (index < 0 || index > length)
            return false;
        if (index == 0) {
            prepend(value);
            return true;
        }
        if (index == length) {
            append(value);
            return true;
        }
        Node<T> *newNode = new Node<T>(value);
        Node<T> *prev1 = get(index - 1);
        Node<T> *next1 = prev1->next;
        newNode->prev = prev1;
        newNode->next = next1;
        prev1->next = newNode;
        next1->prev = newNode;
        length++;
        return true;
    }

    // All delete Methods
    // Write DeleteHead, DeleteTail & DeleteAtIndex here
    void deleteAtHead()
    {
        if(length == 0)
        {
            return;
        }

        Node<T> *temp = head;
        if(length ==1)
        {
            head = nullptr;
            tail = nullptr;
        }
        else
        {
            head=head->next;
            head->prev = nullptr;
        }
        delete temp;
        length --;

    }

    //Delete Tail
    void deleteAtTail()
    {
        if(length ==0)
            return;
        Node<T> *temp = head;
        if(length == 1)
        {
            head= nullptr;
            tail = nullptr;
        }else
        {
            Node<T> *pre = head;
            while(temp->next)
            {
                pre = temp;
                temp = temp->next;
            }
            tail = pre;
            tail->next = nullptr;
        }
        delete temp;
        length--;
    }

    void deleteAtIndex(int index)
    {
        if (index < 0 || index >= length)
            return;
        if (index == 0)
            return deleteAtHead();
        if (index == length - 1)
            return deleteAtTail();

        Node<T> *prev = get(index - 1);
        Node<T> *temp = prev->next;

        prev->next = temp->next;
        delete temp;
        length--;
    }

// Using Bubble sort (redo)
    void sortList()
    {
        Node<T> *currentNode= head;
        Node<T> *temp;
        int intValueA, intValueB;

        while(currentNode->next != nullptr)
        {
            intValueA = currentNode->value->getValue();
            intValueB = currentNode->next->value->getValue();
            //if next Node is greater than current Node
            if(intValueA > intValueB)
            {
                temp = currentNode;
                temp->next = currentNode->next->next;
                temp->prev = currentNode->next;
                //swap

                currentNode->next = currentNode;
            }
            else
            {
                currentNode = currentNode -> next;
            }

        }

    }

    void removeMultiplies()
    {
          Node<T> *currentNode = head;
          Node<T> *found;
          int intValA, intValB;
          string strValA, strValB;

        //iterate the node until end
        while(currentNode->next != nullptr)
        {
            //get value at current node
            intValA = currentNode->value->getValue();
            strValA = currentNode->value->getName();
            //get value of the next node
            intValB = currentNode->next->value->getValue();
            strValB = currentNode->next->value->getName();
            //duplicates found
            if (intValA == intValB && strValA == strValB)
            {
                //store the dup in found node
                found = currentNode->next;
                //update the link of the node
                currentNode->next = currentNode->next->next;
                currentNode->next->prev = currentNode;
                //delete the found node
                free(found);
                //go to the next node
                currentNode = currentNode->next;
            }
            else
            {
                currentNode = currentNode->next;
            }
        }




    }

    int countMultiples(T *value) {
        int num = 0;
        int intValA, intValB;
        string strValA, strValB;
        Node<T> *checkNode = new Node<T> (value);// node hold value to check
        if (head == nullptr)
        {
            cout << "\nEmpty List\n";
        }
        else
        {
            Node<T> *tempNode = head;

                while (tempNode->next != nullptr)
                {
                    //get values in check Node
                    intValA = checkNode->value->getValue();
                    strValA = checkNode ->value ->getName();
                    //get value in temp Node to compare
                    intValB = tempNode->value->getValue();
                    strValB = tempNode -> value -> getName();

                    if((intValA == intValB) && (strValA == strValB))
                    {
                        num +=1;
                    }
                    tempNode = tempNode->next; // go to next value
                }
        }
        return num;
    }


    void evenOddSplit()
    {
        Node <T> *evenHead = head; // start at index 0
        Node<T> *oddHead = head-> next; // start at index 1

        DoubleLinkedList<Data> *evenList = new DoubleLinkedList<Data> (evenHead->value);
        DoubleLinkedList<Data> *oddList = new DoubleLinkedList<Data> (oddHead->value);
        while(evenHead->next != nullptr || oddHead ->next != nullptr)
        {
            // evenHead start at node 0  and this will go to node 2 by skipping 1
            evenHead->next = evenHead->next->next;
            evenHead = evenHead->next;
            //when the list hit the node near end
            if(evenHead->next == nullptr)
            {
                //add the last node then break
                evenList->append(evenHead->value);
                break;
            }
            else
            {
                evenList->append(evenHead->value);

            }

            //this start from node [1] and go to node [3]
            oddHead->next = oddHead->next->next;
            oddHead = oddHead ->next;
            if(oddHead -> next == nullptr)
            {
                oddList->append(oddHead->value);
                break;
            }
            else
            {
                oddList->append(oddHead->value);
            }
        }


        cout << "Odd List: \n";
        oddList->printList();
        cout << endl;
        cout << "Even List:\n";
        evenList->printList();
        destroyList();
    }


    void destroyList()
    {
        head = nullptr;
        tail = nullptr;
    }


    void reverseList()
    {
        Node<T> *temp = nullptr;
        Node<T> *current = head;
        while(current != nullptr)
        {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current= current->prev;
        }

        if(temp != nullptr)
        {
            head = temp->prev;
        }
    }
};


void menuDisplay()
{
    //Display Menu
    cout <<"\n=========================================\n";
    cout << "\nWelcome to Dat's Doubly linked list menu!" << endl;
    cout << "Please read the option: " << endl;
    cout << "a. Create a list" << endl;
    cout << "b. Delete a list" << endl;
    cout << "c. Insert at Head" << endl;
    cout << "d. Insert at Tail" << endl;
    cout << "e. Insert at Index" << endl;
    cout << "f. Delete at Head" << endl;
    cout << "g. Delete at Tail" << endl;
    cout << "h. Delete at Index" << endl;
    cout << "j. Reverse List" << endl;
    cout << "k. Sort List" << endl;
    cout << "l. Count Multiples" << endl;
    cout << "m. Delete Multiples" << endl;
    cout << "n. Split List Even Odd" << endl;
    cout << "q. Exit" << endl;
    cout << "Please choose the option above:\n";
};



// Main Program

int main() {
 //initialize variables
    char choice;
    int value;
    string name;
    int index;
    int count =0;
    Data *temp;
    bool isQuit = false;
   // Calling operations on Linked List
    DoubleLinkedList<Data> *ll;


    do {
        menuDisplay();
        cin >> choice;
        while((choice > 'z' ) || (choice < 'a' ))
        {
            cout <<"That is invalid input.\nPlease enter your choice:\n";
            cin >> choice;
        }
        cout <<"=========================================\n";
        switch (toupper(choice)) {
            case 'A':
                cout << "Please enter the string value of the node: \n";
                cin >> name;
                cout << "Please enter the integer value of the node: \n";
                cin >> value;
                temp = new Data(value, name);
                // Creating Linked List
                ll = new DoubleLinkedList(temp);
                cout <<"Your new linked list is: \n";
                ll->printList();
                isQuit = false;
                break;

            case 'B':
                ll->destroyList();
                //test case to see if list is still appear:
                ll->printList();
                cout << "\nThe list is destroyed!\n";
                isQuit = true;
                break;
            case 'C':


                cout << "Please enter the string value of the node: \n";
                cin >> name;
                cout << "Please enter the integer value of the node: \n";
                cin >> value;
                temp = new Data(value, name);
                ll->prepend(temp);
                ll->printList();
                isQuit = false;
                break;
            case 'D':

                cout << "Please enter the string value of the node: \n";
                cin >> name;
                cout << "Please enter the integer value of the node: \n";
                cin >> value;
                temp = new Data(value, name);
                ll->append(temp);
                cout <<"Your new linked list is: \n";
                ll->printList();
                isQuit = false;
                break;
            case 'E':

                cout << "Please enter the string value of the node: \n";
                cin >> name;
                cout << "Please enter the integer value of the node: \n";
                cin >> value;
                cout << "Please enter the index you want to insert at: \n";
                cin >> index;
                cout <<"This is the list before add new node: \n";
                ll->printList();
                while(index > ll->getLength()|| index < 0)
                {
                    cout << "Please enter correct index you want to insert at: \n";
                    cin >> index;
                }
                temp = new Data(value, name);
                ll->insert(index,temp);
                cout <<"Your new linked list after adding new node is: \n";
                ll->printList();
                isQuit = false;
                break;
            case 'F':

                ll->deleteAtHead();
                cout <<"Your new linked list after delete is: \n";
                ll->printList();
                isQuit = false;
                break;
                break;
            case 'G':

                ll->deleteAtTail();
                cout <<"Your new linked list after delete is: \n";
                ll->printList();
                isQuit = false;
                break;
            case 'H':
                cout <<"Please enter the the index you want to delete at:\n";
                cin >> index;
                while(index > ll->getLength()||index < 0)
                {
                    cout << "Please enter correct index you want to insert at: \n";
                    cin >> index;
                }
                ll->deleteAtIndex(index);
                cout <<"Your new linked list after delete is: \n";
                ll->printList();
                isQuit = false;
                break;
            case 'J':
                ll->reverseList();
                cout <<"Your new linked list after reverse is: \n";
                ll->printList();
                isQuit = false;
                break;
            case 'K':
                ll->sortList();
                cout <<"Your new linked list after sort is: \n";
                ll->printList();
                isQuit = false;
                break;
            case 'L':

                cout <<"Enter the integer value: \n";
                cin >> value;
                cout <<"Enter the string value:\n";
                cin >> name;
                temp = new Data(value,name);
                count = ll->countMultiples(temp);
                ll->printList();
                cout << "\nThe value of [" << value << "," << name << "] appeared " << count  << " times.\n";
                isQuit = false;
                break;

            case 'M':
                ll->removeMultiplies();
                ll->printList();
                cout << endl;
                break;
            case 'N':
                ll->evenOddSplit();
                //test case to see if the list is destroy
                ll->printList();
                cout << "\nlist is destroyed after new two list are created" << endl;
                isQuit = true;
                break;
            case 'Q':
                isQuit = true;
                break;
        }
    }while(!isQuit);


    return 0;
}
