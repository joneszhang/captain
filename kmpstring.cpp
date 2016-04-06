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
	
	for(int i = 0;i < next.size(); ++i){
		cout<<next[i]<<", ";
	}
	cout<<endl;
	
	int is = 0, ip = 0;
	while(is < s.length()){
		if(s[is] == p[ip]){
			++is;
			++ip;
			if(ip == p.length()){
				string sc = s.substr(is - p.length(), p.length());
				cout<<"cut--"<<sc<<endl;
			    return is - 1;	
			} 
		}else{
			if(ip == 0) ++is;
			else{
				ip = next[ip - 1] + 1;
			} 
		}

	}
	return -1;
}

int main(int argc, char* argv[]){
	string s = "";
	string p = "";
	cin>>s;
	cin>>p;
	cout<<kmpmatch(s, p)<<endl;
	return 0;
}