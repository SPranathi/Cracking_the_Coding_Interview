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
O(n), because in the worst case we store each element in the hashmap.
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

void removeDups(node<int> *head){
    set<int> count;
    node<int> *prev=head;
    node<int> *cur=prev->next;
    count.insert(head->data);
    while(cur!=NULL){
        if(count.find(cur->data)!=count.end()){
            cout<<cur->data<<"if"<<endl;
            node<int> *temp=cur;
            if(cur->next!=NULL){
                cur=cur->next;
                prev->next=cur;
            }
            else
                prev->next=NULL;
            delete temp;
        }
        else{
            count.insert(cur->data);
                    cout<<cur->data<<"else"<<endl;
    }
        prev=cur;
        cur=cur->next;
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
    print(head);
    removeDups(head);
    print(head);
}


