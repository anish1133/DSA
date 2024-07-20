#include<iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* nxt;

    Node(int val){
        this->data=val;
        this->nxt=NULL;
    }
    ~Node(){
        int data=this->data;
        if(this->nxt!= NULL){
            delete nxt;
            nxt=NULL;
        }
    }
};

void insertNode( Node* &tail , int element , int val ){

    //empty
    if(tail == NULL){
        Node *newNode = new Node(val);
        tail=newNode;
        newNode->nxt=newNode; 
    }
    
    else{
        Node *curr=tail;

        while( curr->data != element){
            curr=curr->nxt;
        }
        Node *temp = new Node(val);
        temp->nxt=curr->nxt;
        curr->nxt=temp;
    }
}

void print(Node* tail){
    Node *temp=tail;
        if(tail==NULL){
            cout<<"empty";
        }
    do{
        cout<< tail->data << "-->";
        tail=tail->nxt;
    }while(tail != temp);
    cout<<"NULL"<<endl;
}

void deletion(Node* &tail, int element){

    if(tail == NULL){
        cout<<"Empty Circuler Linked LIst"; 
    }
    else{
        
        Node *prev=tail;
        Node *curr=prev->nxt;
        while(curr->data != element){
            prev=curr;
            curr=curr->nxt;
        }
        if(curr==prev)
        {
            tail=NULL;
        }
        prev->nxt=curr->nxt;
        if(tail==curr){
            tail=curr->nxt;
        }
        curr->nxt=NULL;
        delete curr;
    }
}

int main(){
    Node *tail=NULL;
    insertNode(tail,5,3);
    print(tail);
    insertNode(tail,3,5);
    print(tail);
    insertNode(tail,5,19);
    print(tail);
    insertNode(tail,19,91);
    print(tail);
    insertNode(tail,5,11);
    print(tail);
    insertNode(tail,3,21);
    print(tail);
    deletion(tail , 19);
    print(tail);
    deletion(tail , 91);
    print(tail);
    deletion(tail , 21);
    print(tail);

    deletion(tail , 3);
    print(tail);
     deletion(tail , 5);
    print(tail);
     deletion(tail , 11);
    print(tail);

}