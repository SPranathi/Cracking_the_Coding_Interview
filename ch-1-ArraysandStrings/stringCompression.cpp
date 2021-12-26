/*
Chapter 01 - Problem 06 - String Compression - CTCI 6th Edition page 91

Problem Statement:
Implement a method to perform basic string compression using the counts of repeated characters. For example,
the string aabcccccaaa would become a2b1c5a3. If the "compressed" string would not become smaller than the
original string, your method should return the original string. You can assume the string has only uppercase
and lowercase letters (a - z).

Example:
aabcccccaaa -> a2b1c5a3 

TIME COMPLEXITY:
O(n), as we iterate through the entire old string, performing constant work with each
iteration.
 
SPACE COMPLEXITY:
O(n). In the worst case, every character in the old string will be different from its
predecessor. Then our compressed string will append a count of 1 after each character,
storing 2n characters in the new string and n characters in the old string for roughly
3n storage. We drop the constant to get O(n).

*/
#include<iostream>
#include<string>
using namespace std;

string compress(string s){
    if(s.size()==0)
        return s;
    
    int counter=0;
    char cur=s[0];
    string res="";
    for(char c:s){
        if(c==cur){
            counter++;
        }
        else{
            res+=cur;
            res+=to_string(counter);
            cur=c;
            counter=1;
        }
    }
    res+=cur;
    res+=to_string(counter);
    if(res.size()>=s.size())
        return s;
    return res;
}

int main(){
    string s;
    cin>>s;
    cout<<compress(s)<<endl;
}