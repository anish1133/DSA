#include<iostream>

using namespace std;

class Node {
    public:
        int data;
        Node* next;

        Node(int data){
            this->data = data;
            this->next = NULL;
        }

};

void insertAtEnd(Node* &tail, int d){
    Node* temp =new Node(d);
    tail->next=temp;
    tail=tail->next;

}

void print(Node* &head){
    Node*temp=head;
    while(temp != NULL){
        cout<< temp->data<< " ";
        temp=temp->next;
    }
    cout<<endl;
}

int main(){
    Node* Node1 = new Node(10);
    //cout<< Node1 -> data <<endl;
    //cout<< Node1 ->next <<endl;
    Node* head=Node1;
    Node* tail =Node1;
    print(head);
    insertAtEnd(tail,12);
    print(head);
    insertAtEnd(tail,15);
    insertAtEnd(tail,16);
    print(head);
}