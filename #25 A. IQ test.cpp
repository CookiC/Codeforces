#include<iostream>
#define maxn 110
using namespace std;

int cnto,cnte,o,e;

int main() {
	int n,i,t;
	cin >> n;
	cnto=0;
	cnte=0;
	for (i = 1; i <= n; ++i){
		cin >> t;
		if(t&1){
			o=i;
			++cnto;
		}
		else{
			e=i;
			++cnte;
		}
	}
	if(cnte>cnto)
		cout<<o<<endl;
	else
		cout<<e<<endl;
	return 0;

}
