/*
Chapter 01 - Problem 02 - Check Permutation - CTCI 6th Edition page 90

Problem Statement:
Given two strings, write a method to decide if one is a permutation of the
other.

Example:
        ("alex", "lexa") -> True 

Time complexity: O(N) where N is the length of the linearly traversed strings.
Space complexity: O(1) because bit vector does not scale with string length.
*/
#include<iostream>
using namespace std;

bool is_permutation(string s,string t){
    int arr[26]={0};
    if(s.length()!=t.length())
        return false;
    for(int i=0;i<s.length();i++){
        arr[s[i]-'a']++;
    }
    for(int i=0;i<t.length();i++){
        arr[t[i]-'a']--;
        if(arr[t[i]-'a']<0)
            return false;
    }
    return true;
}

int main(){
    string s,t;
    cin>>s>>t;
    if(is_permutation(s,t))
        cout<<"true"<<endl;
    else
    {
            cout<<"false"<<endl;
    }
    
}