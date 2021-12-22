/*
Chapter 01 - Problem 05 - One Away - CTCI 6th Edition page 91

Problem Statement:
There are three types of edits that can be performed on strings:
insert a character, remove a character, or replace a character.
Given two strings, write a function to check if they are one edit (or zero edits) away.

Example:
pale, ple -> true
pales, pale -> true
pale, bale -> true
pale, bae -> false

Time complexity: O(N) where N is the length of the shorter string.

Space complexity: O(1)

*/

#include<iostream>
#include<cstdlib>
using namespace std;

bool oneaway(string s,string t){
	//Length checks
	if(abs((int)s.length()-(int)t.length())>1){
		return false;
	}

	//Get shorter and longer strings
	string s1=s.length()<=t.length()?s:t;
	string s2=s.length()<t.length()?t:s;

	int index1=0;
	int index2=0;
	bool foundDifference=false;
	while(index2<s2.length() && index1<s1.length()){
		if(s1[index1]!=s2[index2]){
			//Ensure that this is the first difference found
			if(foundDifference)
				return false;
			foundDifference=true;
			if(s1.length()==s2.length()) //on replace, move shorter pointer
				index1++;
			
		}
		else
		{
			index1++; //if matching move shorter pointer
		}
		index2++;   //Always move pointer for longer string
		
	}
	return true;
}

int main(){
    string s1,s2;
	cin>>s1>>s2;
	
	if(oneaway(s1,s2))
		cout<<"true"<<endl;
	else
		cout<<"false"<<endl;
} 
