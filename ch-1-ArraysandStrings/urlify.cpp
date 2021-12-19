/*
Chapter 01 - Problem 03 - URLify - CTCI 6th Edition page 90

Problem Statement :
Write a method to replace all spaces in a string with '%20: You may assume that the string
has sufficient space at the end to hold the additional characters, and that you are given the
"true" length of the string.

Example :
'Mr. John Smith ' -> 'Mr.%20John%20Smith%20'

Time complexity : O(N) where N is the length of the string.Because we traverse the array roughly twice, performing constant time operations
with each traversal. 

Space complexity :O(1), because we only store two values: the index of the first space in the string and
the total number of spaces.

*/
#include <iostream>
using namespace std;

string urlify(string &s){
    int true_len=s.length();
    int first_space_idx=-1;
    int num_spaces=0;
    for(int i=0;i<true_len;i++){
        if(s[i]==' '){
            if(num_spaces==0)
                first_space_idx=i;
            ++num_spaces;
        }
    }
    if(num_spaces==0)
        return s;
    s.append(num_spaces*2,' ');
    for(int i=(true_len-1);i>first_space_idx;i--){
        if(s[i]==' '){
            --num_spaces;
            continue;
        }
        cout<<s[i]<<endl;
        s[i+2*num_spaces]=s[i];
        s[i]=' ';
        cout<<s[i]<<endl;
    }
    for(int i=0;i<s.size();i++){
        if(s[i]==' '){
            s[i]='%';
            s[i+1]='2';
            s[i+2]='0';
        }
    }
    return s;
}
int main(){
    string s;
    getline(cin,s);
    cout<<urlify(s)<<endl;
}