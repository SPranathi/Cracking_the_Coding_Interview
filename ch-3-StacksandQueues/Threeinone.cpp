/*
PROBLEM:
Describe how you could use a single array to implement three stacks.

IMPLEMENTATION:
Divide a fixed-length array into thirds, filling up each third with
a different stack.

TIME/SPACE COMPLEXITY:
Not relevant as this is a conceptual question, though this implementation
has O(1) push, pop, and peek.

*/
#include<bits/stdc++.h>
using namespace std;
class FixedMultiStack{
    public:
    FixedMultiStack(int stackCapacity);
    virtual ~FixedMultiStack();

    //push
    void push(int stackNum,int value);

    //pop
    void pop(int stackNum);

    //top
    int top(int stackNum) const;

    bool isEmpty(int stackNum) const;
    bool isFull(int stackNum) const;

    private:
    int numofStack=3;
    int stackCapacity;
    int *stackArray;
    int *stackCapacityUsed;


    int indexOfTop(int stackNum) const;
};

FixedMultiStack::FixedMultiStack(int stackCapacity){
    this->stackCapacity=stackCapacity;
    stackArray=new int [numofStack * stackCapacity]();
    stackCapacityUsed=new int [numofStack]();
}

FixedMultiStack::~FixedMultiStack()
{
  delete [] stackArray;
  delete [] stackCapacityUsed;
}


void FixedMultiStack::push(int stackNum,int value){
    if(isFull(stackNum))
        cout<<"Stack "<<stackNum<<" is full.\n";
    else{
        stackCapacityUsed[stackNum]++;
        stackArray[indexOfTop(stackNum)]=value;
    }
}
void FixedMultiStack::pop(int stackNum){
    if(isFull(stackNum))
        cout<<"Stack "<<stackNum<<" is empty.\n";
    else{
        int topIndex=indexOfTop(stackNum);
        stackArray[topIndex]=0;
        stackCapacityUsed[stackNum]--;
    }
}

int FixedMultiStack::top(int stackNum) const{
    if(isEmpty(stackNum)){
        cout<<"Stack "<<stackNum<<" is empty.\n";
        exit(1);
    }
    else{
        return stackArray[indexOfTop(stackNum)];
    }
}

bool FixedMultiStack::isEmpty(int stackNum) const{
    return (stackCapacityUsed[stackNum]==0);
}

bool FixedMultiStack::isFull(int stackNum) const{
    return (stackCapacityUsed[stackNum]==stackCapacity);
}

int FixedMultiStack::indexOfTop(int stackNum) const{
    int startIndex=stackNum*stackCapacity;
    int capacity=stackCapacityUsed[stackNum];
    return (startIndex+capacity -1);
}