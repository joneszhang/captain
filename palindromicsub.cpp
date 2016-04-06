#include <iostream>
using namespace std;

string LongestPalindrome(string s){
	if(s.length() < 2) return s;
	int k = 0;
	int l = 0;
	int mlen = 1;
	int ms = 0;
	int r = 0;
	while(k < s.length() - mlen / 2){
		l = k;
		while(s[k] == s[k+1]) ++k;
		r = k;
		while(k < s.length() && l > 0 && s[k+1] == s[l-1]){
			++k;
			--l;
		}
		if(k-l+1 > mlen){
			mlen = k-l+1;
			ms = l;
		}
		k = r+1;
	}
	return s.substr(ms, mlen);
}

int main(int argv, char* argc[]){
	string s = "aaaaaaaaaccbbccc";
	cout<<LongestPalindrome(s)<<endl;
}