//
// Created by watso on 9/24/2020.
//

#ifndef INC_20F_AUTO_IDX_DSLIST_H
#define INC_20F_AUTO_IDX_DSLIST_H

#include <iostream>

using namespace std;

template <class PlaceHolderType>
class DSList{
private:
    struct Node{
        Node* next;
        Node* previous;
        PlaceHolderType payload;
    };
    Node* head;
    Node* tail;

public:
    //default constructor
    DSList(){
        head=tail=nullptr;
    }
    //copy constructor
    DSList(const DSList & copy) {
        head=tail=nullptr;
        Node* temp = copy.head;
        while(temp!=nullptr){
            push_back(temp->payload);
            temp = temp->next;
        }
    }
    //copy assignment operator
    DSList& operator=(const DSList& copy){
        if(this != &copy){
            Node* temp = head;
            while(temp != nullptr){
                Node* toDelete = temp;
                temp = temp->next;
                delete toDelete;
            }
            head=nullptr;
            Node* temp2 = copy.head;
            while(temp2 !=nullptr){
                push_back(temp2->payload);
                temp2=temp->next;
            }
        }
        return *this;
    }
    //destructor
    ~DSList(){
        if(head==nullptr){
            return;
        }
        Node* temp = head->next;

        while (head != nullptr) {
            delete head;
            head=temp;

            if(head!=nullptr){
                temp=head->next;
            }
        }
    }
    //push back a new node into linked list
    void push_back(PlaceHolderType data){
        //if list is empty
        if(head==nullptr){
            head=new Node(data);
            tail=head;
        }
        else{
            //put node at end of list
            tail->next=new Node(data);
            tail->next->previous=tail;
            tail=tail->next;
        }
    }
    //insert a node after a node with given index
    void InsertAfter(int index,PlaceHolderType data) {
        //placement node
        Node *curNode = nodeAt(index);
        //node to insert
        Node *nodeToInsert = new Node(data);
        //if list is empty
        if (head == nullptr) {
            head = nodeToInsert;
            tail = nodeToInsert;
        }
            //insert at the end of list
        else if (curNode == tail) {
            tail->next = nodeToInsert;
            curNode->previous = tail;
            tail = nodeToInsert;
        }
            //insert in the middle of the list
        else {
            Node * sucNode = curNode->next;
            nodeToInsert->next = sucNode;
            nodeToInsert->previous = curNode;
            curNode->next = nodeToInsert;
            sucNode->previous = nodeToInsert;
        }
    }
    //remove a node with given index
    void removeAt(int index) {
        Node *curNode = nodeAt(index);
        //pointer for next node
        Node *sucNode = curNode->next;
        //pointer for previous node
        Node *predNode = curNode->previous;
        //if successor exists, point successor's previous to predecessor
        if (sucNode!=nullptr) {
            sucNode->previous = predNode;
        }
        //if predecessor exists, point predecessor's next to successor
        if (predNode!=nullptr) {
            predNode->next = sucNode;
        }
        // if curNode points to head,
        if (curNode == head) { // Removed head
            head = sucNode;
        }

        if (curNode == tail) { // Removed tail
            tail = predNode;
        }
    }
    //return the size of the list
    int getSize(){
        //if the list is empty
        if(head==nullptr)
            return 0;
        //if the list is 1
        if(head==tail)
            return 1;
        //if size is greater than 1
        Node* temp=head;
        int size=1;
        //increase size as it passes through each node
        while(temp!=tail){
            temp=temp->next;
            size++;
        }
        return size;
    }
    //return payload at given index
    PlaceHolderType& at(int index){
        Node* temp=head;
        //move temp pointer to index
        for(int i=0;i<index;i++){
            temp=temp->next;
        }
        return temp->payload;
    }
    //return node pointer for given index
    Node* nodeAt(int index){
        Node* temp=head;

        for(int i=0;i<index;i++){
            temp=temp->next;
        }
        return temp;
    }
    //return previous pointer for given index
    Node* getPrevious(int index){
        return nodeAt(index)->previous;
    }
    //return next pointer for given index
    Node* getNext(int index){
        return nodeAt(index)->next;
    }
};

#endif //INC_20F_AUTO_IDX_DSLIST_H
