#include <iostream>

using namespace std;

struct node{
    int data;
    node* next;
    node(int val): data(val), next(nullptr){}
};

void recursiveReverse(node* head){
    if (head==nullptr) return;
    recursiveReverse(head->next);
    cout << head->data<<" ";
}

node* createlist(int arr[], int n){
    if (n==0 )return nullptr;

    node* head =new node(arr[0]);
    node* curr=head;

    for (int i=1;i<n;i++){
        curr->next=new node(arr[i]);
        curr=curr->next;
    }
    return head;
}

void printForward(node* head){
    node* curr=head;
    while(curr!=nullptr){
        cout<< curr->data<<' ';
        curr=curr->next;

    }
}

void deletelist(node* head){
    node* temp=head;
    head=head->next;
    delete temp;
}


int main(){
    int data[]={10,20,30,40};
    int n =sizeof(data)/sizeof(data[0]);

    node* list=createlist(data,n);
    cout<< "regularlist:";
    printForward(list);
    cout<<"\nreverse traversed list:";
    recursiveReverse(list);


    return 0;



}