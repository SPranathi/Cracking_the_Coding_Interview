/*
Chapter 01 - Problem 08 - Set Zero - CTCI 6th Edition page 91

Problem Statement:
Write an algorithm such that if an element in an MxN matrix is 0, its entire
row and column are set to 0.

Example:
[1, 2, 0, 4,      [0, 0, 0, 0,
 1, 2, 3, 4,  ->   0, 2, 0, 4,
 0, 2, 3, 4]       0, 0, 0, 0]

Time complexity: O(MxN).

Space complexity: O(1).
*/ 
#include<iostream>
using namespace std;

void setZero(int **arr,int m,int n){
    //determine if first row and column contain zeros 
    bool firstZeroRow=false;
    bool firstZeroCol=false;
    
    for(int r=0;r<m;r++){
        if(arr[r][0]==0){
            firstZeroCol=true;
            break;
        }
    }
    for(int c=0;c<n;c++){
        if(arr[0][c]==0){
            firstZeroRow=true;
            break;
        }
    }
    //check the rest of the matrix for zeros and use frist row and col to
    //store this information
    for(int r=1;r<m;r++){
        for(int c=1;c<n;c++){
            if(arr[r][c]==0){
                arr[0][c]=0;
                arr[r][0]=0;
            }
        }
    } 
    
    //look at storage and apply zeros to appropriate rows and columns
    for(int r=1;r<m;r++){
        if(arr[r][0]==0){
            for(int c=1;c<n;c++)
                arr[r][c]=0;
        }
    }
    for(int c=1;c<n;c++){
        if(arr[0][c]==0){
            for(int r=1;r<m;r++)
                arr[r][c]=0;
        }
    }
    //look at first row and first col booleans to zero out first row and first col
    if(firstZeroCol){
        for(int r=0;r<m;r++)
                arr[r][0]=0;
    }
    if(firstZeroRow){
        for(int c=0;c<n;c++)
                arr[0][c]=0;
    }
}

int main(){
    int m,n;
    cin>>m>>n;
    int **arr=new int*[m];
    for(int i=0;i<m;i++){
        arr[i]=new int[n];
        for(int j=0;j<n;j++)
            cin>>arr[i][j];
    }
    setZero(arr,m,n);
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++)
            cout<<arr[i][j]<<" ";
        cout<<endl;
    }
}
