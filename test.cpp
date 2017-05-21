#include<iostream>
#include<sstream>
#define LL long long int
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	
	int x;
	istringstream iss;
	auto p=iss.rdbuf();
	p->str("1 2");
	while(iss>>x)
		cout<<x<<' ';
	cout<<endl;
	p->str("3 4");
	while(iss>>x)
		cout<<x<<' ';
	cout<<endl;
	return 0;
}
