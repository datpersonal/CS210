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


    void sortList()
    {

    }

    void removeMultiplies()
    {

    }

    int countMultiples(T value)
    {
        int num;


        return num;
    }

    void evenOddSplit()
    {

    }

    void reverseList()
    {

    }

};

// Main Program

int main() {
 //initialize variables
    int choice = 0;
    int value;
    string name;
    int index;
    Data *temp;
    bool isQuit = false;
   // Calling operations on Linked List
    DoubleLinkedList<Data> *ll;
    DoubleLinkedList<Data> *ll1; //hold odd value
    DoubleLinkedList<Data> *ll2; // hold even value

    do {

        //Display Menu
        cout <<"\n=========================================\n";
        cout << "\nWelcome to Dat's Doubly linked list menu!" << endl;
        cout << "Please read the option: " << endl;
        cout << "1. Create a list" << endl;
        cout << "2. Delete a list" << endl;
        cout << "3. Insert at Head" << endl;
        cout << "4. Insert at Tail" << endl;
        cout << "5. Insert at Index" << endl;
        cout << "6. Delete at Head" << endl;
        cout << "7. Delete at Tail" << endl;
        cout << "8. Delete at Index" << endl;
        cout << "9. Reverse List" << endl;
        cout << "10. Sort List" << endl;
        cout << "11. Count Multiples" << endl;
        cout << "12. Delete Multiples" << endl;
        cout << "13. Split List Even Odd" << endl;
        cout << "14. Exit" << endl;
        cout << "Please choose the option above:\n";
        //Take the choice using switch case
        cin >> choice;
        cout <<"=========================================\n";
        switch (choice) {
            case 1:
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

            case 2:

                isQuit = false;
                 break;
            case 3:
                cout << "Please enter the string value of the node: \n";
                cin >> name;
                cout << "Please enter the integer value of the node: \n";
                cin >> value;
                temp = new Data(value, name);
                ll->prepend(temp);
                ll->printList();
                isQuit = false;
                break;
            case 4:
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
            case 5:
                cout << "Please enter the string value of the node: \n";
                cin >> name;
                cout << "Please enter the integer value of the node: \n";
                cin >> value;
                cout << "Please enter the index you want to insert at: \n";
                cin >> index;
                while(index > ll->getLength())
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
            case 6:
                ll->deleteAtHead();
                cout <<"Your new linked list after delete is: \n";
                ll->printList();
                isQuit = false;
                break;
                break;
            case 7:
                ll->deleteAtTail();
                cout <<"Your new linked list after delete is: \n";
                ll->printList();
                isQuit = false;
                break;
            case 8:
                cout <<"Please enter the the index you want to delete at:\n";
                cin >> index;
                while(index > ll->getLength())
                {
                    cout << "Please enter correct index you want to insert at: \n";
                    cin >> index;
                }
                ll->deleteAtIndex(index);
                cout <<"Your new linked list after delete is: \n";
                ll->printList();
                isQuit = false;

                break;
            case 9:
                break;
            case 10:
                break;
            case 11:
                break;
            case 12:
                break;
            case 13:
                break;
            case 14:
                isQuit = true;
                break;
            default:
                cout << "It is an invalid choice." << endl;
                isQuit = false;
        }
    }while(!isQuit);


    return 0;
}
