#include<iostream>
using namespace std;

int i;
unsigned m,x,y,rn=0,cn=0;
long long int n,rest;
bool row[100010]={0},col[100010]={0};

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	
	cin>>n>>m;
	rest=n*n;
	for(i=0;i<m;++i){
		cin>>x>>y;
		if(!row[x]){
			row[x]=1;
			++rn;
			rest=rest-n+cn;
		}
		if(!col[y]){
			col[y]=1;
			++cn;
			rest=rest-n+rn;
		}
		cout<<rest<<' ';
	}
	cout<<'\n';
	return 0;
}

