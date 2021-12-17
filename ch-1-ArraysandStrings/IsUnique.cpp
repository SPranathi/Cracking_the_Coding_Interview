/*
*Chapter 01 - Problem 01 - Is Unique - CTCI 6th Edition page 90
*
*Problem Statement:
*Implement an algorithm to determine if a string has all unique characters.
*What if you cannot use additional data structures?
*
*Example:
*"aalex" -> False
*
*Time complexity: O(N) where N is the length of the of the linearly traversed string.
*Space complexity: O(1) because bit vector size does not scale with input string length.
*
* 
*If we cannot use additional structures, we can do O(N^2) character comparisons
*to check for uniqueness. If we are allowed to modify the original string, we
*could sort it in place in N*log(N) time and test consecutive characters for equality.
*/
#include<iostream>
using namespace std;

bool isunique(string s){
    int arr[26]={0};
    for(int i=0;i<s.length();i++){
        if(arr[s[i]-'a']!=0)
            return false;
        arr[s[i]-'a']++;
    }
    return true;
}

int main(){
    string s;
    cin>>s;
    if(isunique(s))
        cout<<"true"<<endl;
    else
    {
        cout<<"false"<<endl;
    }
    
}