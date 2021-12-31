/*
Chapter 01 - Problem 09 - String Rotation - CTCI 6th Edition page 91

Problem Statement:
Assume you have a method isSubstring() which checks if one word is a substring of
another. Given two strings, s1 and s2, write code to check if s2 is a rotation of s1 using
only one call to isSubstring().

Example:
stringRotation("waterbottle", "erbottlewat")

Time complexity: O(N) where N is the length of the concatenated string. Substring checking can be done in linear time.

Space complexity: O(N) because we have to allocate enough space to double the length of s1.
*/

#include<iostream>
#include<string>
using namespace std;

bool rotation(string s1,string s2){
    //check that s1 and s2 are of equal length and not empty
    if(s1.length()!=s2.length() || s1.length()==0)
        return false;
    string s3=s1+s1;
    //If the substring is found, find() function returns the position.
    //But if it is not found, it will return string::npos
    return (s3.find(s2)!=string::npos);
}

int main(){
    string s1,s2;
    cin>>s1>>s2;
    if(rotation(s1,s2))
        cout<<"true"<<endl;
    else
        cout<<"false"<<endl;
}
