#include <iostream>

using namespace std;

struct node{
    int data;
    node* prev;
    node* next;

    node(int val):data (val),prev(nullptr),next(nullptr){}
};

node* insertafter(node*head, node*targetnode, int value){
    if(targetnode==nullptr){
        cout <<"target node cant be null";
        return head;
    }
    node* newnode= new node(value);

    newnode->next=targetnode->next;
    newnode->prev=targetnode;

    if (targetnode->next !=nullptr){
        targetnode->next->prev=newnode;
    }
    targetnode->next=newnode;
    cout <<"insterted"<<value<<"AFTER node with value"<<targetnode->data<<endl;
    return head;
}

node* deletenode(node* head, node* nodetodelete){
    if(head==nullptr|| nodetodelete==nullptr){
        cout<< "cannot delete";
        return head;

    }

    if (nodetodelete==head){
        head=head->next;
        if (head!=nullptr){
            head->prev=nullptr;
        }
    }else{
        if(nodetodelete->prev!=nullptr){
            nodetodelete->prev->next=nodetodelete->next;
        }
        if (nodetodelete->next !=nullptr){
            nodetodelete->next->prev=nodetodelete->prev;
        }
    }
    cout << "deleted node val"<< nodetodelete->data<<endl;
    delete nodetodelete;
    return head;
}
node* searchnode(node* head, int val){
    node* curr =head;
    while (curr!=nullptr){
        if (curr->data==val){
            return curr;
        }
        curr=curr->next;
    }
    return nullptr;
}

void displaylist(node* head){
    if(head==nullptr){
        cout<< "empty list";
        return;
    }
    node* curr=head;
    while(curr!=nullptr){
        cout<<curr->data<<" ";
        curr=curr->next;
    }
    cout<<endl;
}

node* createlist(){
    node* head=new node(10);
    node* second=new node(20);
    node* third =new node(30);

    head->next=second;
    second->prev=head;
    second->next=third;
    third->prev=second;
    return head;

}


int main(){
    node* head =createlist();
    displaylist(head);

    node* target=searchnode(head,20);
    head =insertafter(head,target,23);
    displaylist(head);

    target=searchnode(head,30);
    head=deletenode(head,target);
    displaylist(head);

    return 0;


}