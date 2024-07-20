#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* nxt;

    Node(int data){
        this->data=data;
        this->nxt=NULL;
    }
};

void insertAtEnd(Node* &tail, int d){
    Node* temp = new Node(d);
    tail->nxt=temp;
    tail=temp;
}
void insertAtPosition(Node* &head, Node* &tail, int pos , int d){
   
    Node* temp = head;
    int count=1;
    if(pos==1){
        Node* NewNode =  new Node(d);
        NewNode->nxt=head;
        head=NewNode;
        return;
    }

    while(count < pos-1){
        temp=temp->nxt;
        count++;
    }
    if(temp->nxt==NULL){
        Node* NewNode =  new Node(d);
        temp->nxt=NewNode;
        tail=NewNode;
        return;
    }

    Node* NewNode =new Node(d);
    NewNode->nxt=temp->nxt;
    temp->nxt=NewNode;
}
void print(Node* &head){
    Node*temp =head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp=temp->nxt;
    }
    cout<<endl;
}
int main(){
    Node* Node1= new Node(10);
    Node* head =Node1;
    Node* tail =Node1;
    insertAtEnd(tail,12);
    insertAtEnd(tail,15);
    insertAtEnd(tail,16);
    print(head);
    insertAtPosition(head,tail,1,17);
    print(head);

    cout<<head->data<<endl;
    cout<<tail->data<<endl;

}