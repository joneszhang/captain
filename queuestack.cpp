#include <iostream>
#include <queue>
using namespace std;

template <typename T>class CStack
{
public:
	CStack(void){};
	~CStack(void){};
	void push(const T& node);
	T pop();
private:
	queue<T> q1;
	queue<T> q2;
};

template <typename T> void CStack<T>::push(const T& element){
	if(q1.size() > 0){
		q1.push(element);
	}else if(q2.size()>0){
		q1.push(element);
	}else{
		q1.push(element);
	}
}

template <typename T> T CStack<T>::pop(){
	if(q1.size() == 0){
		while(q2.size() > 1){
			q1.push(q2.front());
			q2.pop();
		}
		T& data = q2.front();
		q2.pop();
		return data;
	}
	else{
		while(q1.size() > 1){
			q2.push(q1.front());
			q1.pop();
		}
		T& data = q1.front();
		q1.pop();
		return data;
	}
}


int main(){
	CStack<int> stack = CStack<int>();
	stack.push(5);
	stack.push(4);
	stack.push(3);
	cout<<stack.pop()<<endl;
}