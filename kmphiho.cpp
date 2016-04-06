#include <iostream>
#include <vector>
using namespace std;

int kmpmatch(string s, string p){
	//build next array
	vector<int> next(p.length(), 0);
	int k = 0;
	next[0] = -1;
	for(int j = 1;j < p.length(); ++j){
		if(p[j] == p[k]){
			next[j] = k;
			++k;
		}else{
			while(next[k] != -1){
				k = next[k];
				if(p[k] == p[j]) break;
			}
			if(next[k] != -1 || p[k] == p[j]){
				next[j] = k;
				++k;
			}else next[j] = -1;
		}
	}
	
	int is = 0, ip = 0;
	int cnt = 0;
	while(is < s.length()){
		if(s[is] == p[ip]){
			++is;
			++ip;
			if(ip == p.length()){
				++cnt;
				is = is - p.length() + 1;
				ip = 0;
			} 
		}else{
			if(ip == 0) ++is;
			else{
				ip = next[ip - 1] + 1;
			} 
		}

	}
	return cnt;
}

int main(int argc, char* argv[]){
	int num = 0;
	cin>>num;
	vector<string> set(num * 2, "");
	for(int i = 0;i < num * 2; ++i){
	    cin>>set[i];
	}
	for(int i = 0;i < num; ++i){
		cout<<set[i*2+1]<<endl;
		cout<<set[i*2]<<endl;
	    cout<<kmpmatch(set[i*2+1], set[i*2])<<endl;
	}
	
	return 0;
}