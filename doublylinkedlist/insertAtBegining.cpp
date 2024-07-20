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
void insertAtBegining(Node* &head, int data){
    if(head==NULL){
        Node* temp = new Node(data);
        head=temp;
    }
    else{
    Node* temp = new Node(data);
    temp->nxt=head;
    head->prev=temp;
    head=temp;
    }
}

int main(){
    
    Node*head=NULL;
    print(head);
    cout<<"Length of DLL: "<<count(head)<<endl;

    insertAtBegining(head,15);
    print(head);
    insertAtBegining(head,12);
    insertAtBegining(head,16);
    insertAtBegining(head,19);
    print(head);
     cout<<"Length of DLL: "<<count(head)<<endl;
    
}