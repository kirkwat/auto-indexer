//
// Created by watso on 9/24/2020.
//

#ifndef INC_20F_AUTO_IDX_DSLIST_H
#define INC_20F_AUTO_IDX_DSLIST_H

using namespace std;

template <typename PlaceHolderType>
class Node{
public:
    Node* next;
    Node* previous;
    PlaceHolderType payload;
    //default constructor
    Node(){
        next=previous=nullptr;
    }
    //overloaded constructor
    Node(PlaceHolderType payload){
        this->payload=payload;
        next=previous=nullptr;
    }
};

template <typename PlaceHolderType>
class DSList{
private:
    Node<PlaceHolderType>* head;
    Node<PlaceHolderType>* tail;

public:
    //default constructor
    DSList(){
        head=tail=nullptr;
    }
    //copy constructor
    DSList(const DSList & copy) {
        head=tail=nullptr;
        Node<PlaceHolderType>* temp = copy.head;
        while(temp!=nullptr){
            push_back(temp->payload);
            temp = temp->next;
        }
    }
    //copy assignment operator
    DSList& operator=(const DSList& copy){
        if(this != &copy){
            Node<PlaceHolderType>* temp = head;
            while(temp != nullptr){
                Node<PlaceHolderType>* toDelete = temp;
                temp = temp->next;
                delete toDelete;
            }
            head=nullptr;
            Node<PlaceHolderType>* temp2 = copy.head;
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
        Node<PlaceHolderType>* temp = head->next;

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
            head=new Node<PlaceHolderType>(data);
            tail=head;
        }
        else{
            //put node at end of list
            tail->next=new Node<PlaceHolderType>(data);
            tail->next->previous=tail;
            tail=tail->next;
        }
    }
    //insert a node after a node with given index
    void InsertAfter(int index,PlaceHolderType data) {
        //placement node
        Node<PlaceHolderType> *curNode = nodeAt(index);
        //node to insert
        Node<PlaceHolderType> *nodeToInsert = new Node<PlaceHolderType>(data);
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
            Node<PlaceHolderType> * sucNode = curNode->next;
            nodeToInsert->next = sucNode;
            nodeToInsert->previous = curNode;
            curNode->next = nodeToInsert;
            sucNode->previous = nodeToInsert;
        }
    }
    //remove a node with given index
    void removeAt(int index) {
        Node<PlaceHolderType> *curNode = nodeAt(index);
        //pointer for next node
        Node<PlaceHolderType> *sucNode = curNode->next;
        //pointer for previous node
        Node<PlaceHolderType> *predNode = curNode->previous;
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
        Node<PlaceHolderType>* temp=head;
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
        Node<PlaceHolderType>* temp=head;
        //move temp pointer to index
        for(int i=0;i<index;i++){
            temp=temp->next;
        }
        return temp->payload;
    }
    //return node pointer for given index
    Node<PlaceHolderType>* nodeAt(int index){
        Node<PlaceHolderType>* temp=head;

        for(int i=0;i<index;i++){
            temp=temp->next;
        }
        return temp;
    }
    //return previous pointer for given index
    Node<PlaceHolderType>* getPrevious(int index){
        return nodeAt(index)->previous;
    }
    //return next pointer for given index
    Node<PlaceHolderType>* getNext(int index){
        return nodeAt(index)->next;
    }
};

#endif //INC_20F_AUTO_IDX_DSLIST_H
