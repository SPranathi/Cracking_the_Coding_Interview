/*
Chapter 01 - Problem 04 - Palindrome Permutation - CTCI 6th Edition page 91

Problem Statement :
Given a string, write a function to check if it is a permutation of a palindrome. A palindrome is a word or
phrase that is the same forwards and backwards. A permutation is a rearrangement of letters.The palindrome does
not need to be limited to just dictionary words.

Example :
	"tact coa"->true(permutations : "tacocat", "atcocta", etc.)

Time complexity : O(N) where N is the length of the string.

Space complexity : O(1) because the bit vector size does not depend on N.
*/
#include<bits/stdc++.h>
using namespace std;
bool is_permutationPalindrome(string s){
	int count[128]={0};
	int odd_counts=0;
	for(const char c:s){
		if(isalpha(c))
			count[tolower(c)]++;
	}
	for(char c='a';c<='z';c++){
		if(count[c]%2)
			odd_counts++;
	}
	return odd_counts<=1;
}
int main(){
	string s;
	getline(cin,s);
	if(is_permutationPalindrome(s))
		cout<<"true"<<endl;
	else
		cout<<"false"<<endl;
	
}
