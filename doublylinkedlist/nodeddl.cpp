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
int main(){
    Node* node1= new Node(10);
    Node*head=node1;
    print(head);
    cout<<"Length of DLL: "<<count(head)<<endl;
    
}