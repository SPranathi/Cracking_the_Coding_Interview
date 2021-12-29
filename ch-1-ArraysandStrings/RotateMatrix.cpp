/*
Chapter 01 - Problem 07 - Rotate Matrix - CTCI 6th Edition page 91

Problem Statement:
Given an image represented by an NxN matrix, where each pixel in the image is 4 bytes,
write a method to rotate the image by 90 degrees. Can you do this in place?

Example:
[1,2,3,       [7,4,1,
4,5,6,   ->   8,5,2,
7,8,9]        9,6,3]

Time complexity: O(N^2). One operation per pixel in the image.

Space complexity: O(1). We only need to allocate enough space for one matrix cell.
*/ 
#include<iostream>
using namespace std;
void rotate(int **m,int n){
    if(n==0)
        return ;
    for(int l=0;l<n/2;l++){
        int first=l;
        int last=n-1-l;
        for(int i=first;i<last;i++){
            int offset=i-first;
            int top=m[first][i];

            //move left to top
            m[first][i]=m[last-offset][first];

            //move bottom to left
            m[last-offset][first]=m[last][last-offset];

            //move right to bottom
            m[last][last-offset]=m[i][last];

            //move top to right
            m[i][last]=top;
        }
    }
}

int main(){
    int n;
    cin>>n;
    int **arr=new int*[n];
    for(int i=0;i<n;i++){
        arr[i]=new int[n];
        for(int j=0;j<n;j++)
            cin>>arr[i][j];
    }
    rotate(arr,n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            cout<<arr[i][j]<<" ";
        cout<<endl;
    }

}