#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* prev;
        Node* nxt;

        Node(int d){
            this->data=d;
            this->prev=NULL;
            this->nxt=NULL;
        }

};

void print(Node* &head){
    Node* temp=head;

    while(temp != NULL){
        cout<<temp->data<<" ";
        temp=temp->nxt;
    }
    cout<<endl;
}

int count(Node* &head){
    Node* temp=head;
    int count=0;
    while(temp!=NULL){
        count++;
        temp=temp->nxt;
    }
    return count;
}

void insertAtEnd(Node* &tail,Node* &head , int data){
    if(head==NULL){
        Node* temp = new Node(data);
        head=temp;
        tail=temp;
    }
   else{ Node* temp = new Node(data);
    tail->nxt=temp;
    temp->prev=tail;
    tail=temp;
    }
}

int main(){
   // Node* node1= new Node(10);
    Node*head=NULL;
    Node*tail=NULL;
    print(head);
    cout<<"Length of DLL: "<<count(head)<<endl;

    insertAtEnd(tail,head,15);
    insertAtEnd(tail,head,12);
    insertAtEnd(tail,head,16);
    insertAtEnd(tail,head,19);
    print(head);
     cout<<"Length of DLL: "<<count(head)<<endl;
     cout<<"Head Node Data:"<<head->data<<endl;
     cout<<"Tail Node Data:"<<tail->data<<endl;
    
}