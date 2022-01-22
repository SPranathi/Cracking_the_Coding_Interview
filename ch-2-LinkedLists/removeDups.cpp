/*
PROBLEM:
Write code to remove duplicates from an unsorted linked list.

Example:
1 1 2 3 4 4 -1
output
1 2 3 4

TIME COMPLEXITY:
O(n), because we iterate through the singly linked list only once, performing constant
work over each element.

SPACE COMPLEXITY:
O(n), because in the worst case we store each element in the set.
*/ 
#include<bits/stdc++.h>
using namespace std;
template <typename T>

class node{
    public:
    T data;
    node<T> *next;
    node(T data){
        this->data=data;
        this->next=NULL;
    }
};

void removeDuplicates(node<int> *head){
    // Hash to store seen values
    unordered_set<int> seen;

    /* Pick elements one by one */
    node<int> *prev=NULL;
    node<int> *cur=head;

    while(cur!=NULL){
        // If current value is seen before
        if(seen.find(cur->data)!=seen.end()){
            prev->next=cur->next;
            delete (cur);
        }
        else{
            seen.insert(cur->data);
            prev=cur;
        }
        cur=prev->next;
    }

}

node<int> *takeinput(){
    int data;
    cin>>data;
    node<int> *head=NULL,*tail=NULL;
    while(data!=-1){
        node<int> *newnode=new node<int>(data);
        if(head==NULL){
            head=newnode;
            tail=newnode;
        }
        else{
            tail->next=newnode;
            tail=newnode;
        }
        cin>>data;
    }
    return head;
}
void print(node<int> *head){
    node<int> *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main(){
    node<int> *head;
    head=takeinput();
    //print(head);
    removeDuplicates(head);
    print(head);
}


