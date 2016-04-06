#include <iostream>
#include <vector>
using namespace std;

void printSpiralMatrix(int n){
	int size = n * n;
	vector<int> list(size,0);
	int bnd = n - 1;
	int bndx = bnd;
	int l = 0, c = 0;
	for(int i = 1;i <= size; ++i){
		int index = l * n + c;
		list[index] = i;
		if(l == bnd - bndx && c < bndx) ++c;
		else if(c == bndx && l < bndx) ++l;
		else if(l == bndx && c > bnd - bndx) --c;
		else if(c == bnd - bndx && l > bnd - bndx) --l;
		if(l == bnd - bndx && c == l){
			++l;
			++c;
			--bndx;
		}
	}
	for(int i = 0;i < list.size();++i){
		cout<<list[i]<<" ";
		if((i + 1) % n == 0) cout<<endl;
	}
}

int main(int argv, char* argc[]){
	int s = 0;
	cin>>s;
	printSpiralMatrix(s);
}