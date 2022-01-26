/*
PROBLEM:
Implement an algorithm to find the kth to last element of a singly linked list.


EXAMPLE:
1 2 3 4 -1
output
1 2 3 4

TIME COMPLEXITY:
O(n), as we iterate through the list twice at max.

SPACE COMPLEXITY:
O(1), as we do not store any variables other than indices and iterators.

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

//recursive solution
node<int> *kthToLast(node<int> *head,int k,int &i){
    if(head==NULL)
        return NULL;
    node<int> *newnode=kthToLast(head->next,k,i);
    i=i+1;
    //if we have solved problem k times from last.
    if(i==k){
        return head;
    }
    return newnode;
}

node<int> *kthToLast(node<int> *head,int k){
    int i=0;
    return kthToLast(head,k,i); //starting at index 0
}

//iterative solution
node<int> *kthTolast(node<int> *head,int k){
    node<int> *slowptr=head;
    node<int> *fastptr=head;

    //Move fastptr k nodes into the list
    for(int i=0;i<k;i++){
        if(fastptr==NULL){
            return NULL; //out of bound
        }
        fastptr=fastptr->next;
    }

    /*Move them at same pace.When fastptr hits the end, slowptr will be at the right
    element*/
    while(fastptr!=NULL){
        fastptr=fastptr->next;
        slowptr=slowptr->next;
    }
    return slowptr;
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
    int k;
    cin>>k;
    node<int> *ans=kthToLast(head,k);
    print(ans);
    node<int> *res=kthTolast(head,k);
    print(res);
}



