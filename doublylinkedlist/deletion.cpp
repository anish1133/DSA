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
        ~Node(){
            int val=this->data;
            if(nxt != NULL){
                delete nxt;
                nxt=NULL;
            }
            cout<<"\n\ndeleted val: "<<val<<endl;
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
void insertAtEnd(Node* &tail, int data){
    Node* temp = new Node(data);
    tail->nxt=temp;
    temp->prev=tail;
    tail=temp;
}

void insertAtPosition( Node* &head , Node* &tail,int pos, int data){
    Node* temp = head;
    Node* newnode = new Node(data);
    int cnt=1;  
    if(pos==1){
        newnode->nxt=head;
        head->prev=newnode;
        head=newnode;
        return;
    }
    
    while(cnt<pos-1){
        temp=temp->nxt;
        cnt++;
    }
    if(temp->nxt==NULL){
        newnode->prev=temp;
        temp->nxt=newnode;
        tail=newnode;
        return;
    }
    newnode->nxt=temp->nxt;
    temp->nxt->prev=newnode;  
    temp->nxt=newnode;
    newnode->prev=temp;      
}

void deletion(Node* &head, Node* &tail, int pos){
    if(pos==1){
        Node* temp = head;
        /*head=head->nxt;
        head->prev->nxt=NULL;
        head->prev=NULL; 
        */
       temp->nxt->prev=NULL;
       head=temp->nxt;
       temp->nxt=NULL;
       delete temp;
    }
    Node* temp =head;
    Node*cur =head;
    Node* prevv = NULL;
    int cnt=1;
    while(cnt<pos){
        prevv=cur;
        cur=cur->nxt;
        cnt++;
    }
    if(cur->nxt==NULL){
        tail=prevv;
    }

    cur->prev=NULL;
    prevv->nxt=cur->nxt;
    cur->nxt=NULL;
   // prevv->nxt->prev=NULL;
    delete cur;

}

int main(){
    Node* node1= new Node(10);
    Node*head=node1;
    Node*tail=node1;
    print(head);
    cout<<"Length of DLL: "<<count(head)<<endl;

    insertAtEnd(tail,15);
    insertAtEnd(tail,12);
    insertAtEnd(tail,16);
    insertAtEnd(tail,19);
    insertAtPosition(head,tail,3,20);
    insertAtPosition(head,tail,1,30 );
    insertAtPosition(head,tail,8,300 );
    print(head);
    cout<<"Length of DLL: "<<count(head)<<endl;
    cout<<"Head Node Data:"<<head->data<<endl;
    cout<<"Tail Node Data:"<<tail->data<<endl;

    deletion(head,tail,8);
    print(head);
    cout<<"Length of DLL: "<<count(head)<<endl;
    cout<<"Head Node Data:"<<head->data<<endl;
    cout<<"Tail Node Data:"<<tail->data<<endl;
    

    
}