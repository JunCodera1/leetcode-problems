#include <iostream>
#include <vector>
#include <assert.h>

using std::cout, std::cin, std::endl, std::vector;

class Node {
public:
    int data;
    Node* next;
    Node(int new_data) {
        this->data = new_data;
        next = NULL;
    }
};

class ListOperation {
public:
    Node* head;
    ListOperation() { head = NULL; }
    void push(int data) {
        Node* new_node = new Node(data);
        new_node->next = head;
        head = new_node;
    }
    void append(int data){
        Node* new_node = new Node(data);

        Node* last = head;

        new_node->next = NULL;

        if(head == NULL){
            head = new_node;
            return;
        }

        while(last->next != NULL)
            last = last->next;

        last->next = new_node;
        return;
    }
    void print() {
        Node* tmp = head;
        while (tmp != NULL) {
            cout << tmp->data << " ";
            tmp = tmp->next;
        }
    }
    bool search(int x) {
        Node* tmp = head;
        while (tmp != NULL) {
            if (tmp->data == x) {
                return true;
            }
            tmp = tmp->next; // Move to the next node
        }
        return false;
    }
    void reverse() {
        Node *current = head;
        Node *prev = NULL;
        Node *next = NULL;
        while(current != NULL){
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
        head = prev;
    }
    void deleteN(int position) {
        if(head == NULL)
            return;
        Node *temp = head;
        if(position == 0){
            head = head -> next;
            delete temp;
            return;
        }
        for(int i = 0; i < position - 1 && temp != NULL; i++)
            temp = temp->next;
        if(temp == NULL && temp->next == NULL)
            return;
        Node * next = temp -> next -> next;
        delete temp->next;
        temp->next = next;
    }

    void deleteList(){
        /*deref head_ref to affect*/
        Node * current = head;
        Node * next = NULL;
        while(current != NULL){
            next = current -> next;
            delete current;
            current = next;
        }

        head = NULL;
    }

    int getNth(int index){
        Node * current = head;

        //The index of the node we're currently  looking at
        int count = 0;
        while(current != NULL){
            if(count == index)
                return (current->data);
            count++;
            current = current->next;
        }
        /*if we get to this line, the caller was asking for a non-existent element so we assert fail*/
        assert(0);

    }
    void printNthFromLast(int N){
        int len = 0, i;
        Node * temp = head;

        // Count the number of nodes of Linked List
        while(temp != NULL){
            temp = temp->next;
            len++;
        }
        // Check if value of N is not
        //more than length of the linked list
        if(len < N)
            return;
        temp = head;

        //Get the (len - N + 1)th node from the beginning
        for(i = 1; i < len - N + 1; i++)
            temp = temp -> next;

        cout << temp -> data;

        return;
    }
    int getLen(){
        int len = 0;
        Node * temp = head;
        //Traverse the entire linked list and increment len by 1 for each node
        while(temp != NULL){
            len++;
            temp = temp->next;
        }
        //Return the number of nodes in the linked list
        return len;
    }
    int getMiddle(){
        //find len
        int len = getLen();
        Node * temp = head;

        //traverse till we reached half of length
        int midIndex = len/2;
        while(midIndex--){
            temp = temp -> next;
        }
        // temp will be storing middle element
        return temp->data;
    }
    int countOccur(int num){
        int count = 0;
        Node * temp = head;
        while(temp != NULL){
            if(temp->data == num)
                count++;
            temp = temp ->next;
        }
        return count;
    }



    void printList() {
        while (head) {
            if (head->next == NULL)
                cout << "[" << head->data << "] "
                     << "[" << head << "]->"
                     << "(nil)" << endl;
            else
                cout << "[" << head->data << "] "
                     << "[" << head << "]->" << head->next
                     << endl;
            head = head->next;
        }
        cout << endl << endl;
    }
};

int main() {
    ListOperation lo;
    lo.push(22);
    lo.push(5003);
    lo.push(222);
    lo.push(5005);
    lo.push(224);
    lo.push(5001);
    lo.append(6001);
    lo.push(600);
    lo.push(2000);
    lo.append(22);
    lo.push(22);
    cout << "Given list: \n";
    lo.print();
    cout << "\nTime occur of 22: " << lo.countOccur(22) << "\n";
    cout << "\nMiddle of linked list : " << lo.getMiddle();
    cout << "\nReversed list: \n";
    lo.reverse();
    lo.print();

    cout << "\nElement of index 5 is " << lo.getNth(5);
    // Delete any position from list
    lo.deleteN(5);
    cout << "\nList after deleting position: \n";
    lo.printList();
    cout << "\nList after deleted:";
    lo.deleteList();
    lo.printList();
}
