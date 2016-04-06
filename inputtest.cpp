#include <iostream>
using namespace std;

string longestPalindrome(string s){
	if(s.length() < 2) return s;
	int k = 0, mlen = 1, ms = 0, l = 0, i = 0;
	while(k < s.length() - mlen / 2){
		l = k;
		while(s[k] == s[k+1]) ++k;
		i = k;
		while(k < s.length() && l > 0 && s[l-1] == s[k+1]){
			--l;
			++k;
		}
		if(k-l+1 > mlen){
			mlen = k - l + 1;
			ms = l;
		}
		k = i+1;
	}
	return s.substr(ms, mlen);
}


	int main(int argv, char* argc[]){
		string s = "aaacccbbccc";
		cout<<longestPalindrome(s)<<endl;
		return 0;
	}