//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#define maxn 200010
#define INF 0x7FFFFFFF
//#pragma warning(disable : 4996)
using namespace std;

int n,t,k;
int a[maxn],f[maxn];

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	int maxk=1,i,j;
	cin>>n>>t>>k;
	a[0]=1;
	for(i=1;i<=t;++i){
		cin>>a[i];
		maxk+=a[i]-1;
	}
	for(i=1;i<=t;++i)
		a[i]+=a[i-1];
	
//	cout<<endl<<maxk<<endl;
	int x=maxk,u,v,b;
	u=1;
	v=2;
	i=1;
	while(v<=n){
		if(v>a[i]){
			u=a[i-1]+1;
			++i;
			f[v]=u;
		}
		else if(x>k){
			if(u<a[i-1]){
				++u;
				--x;
			}
			f[v]=u;
		}
		else
			f[v]=u;
		++v;
	}
	
	if(x==k){
		cout<<n<<endl;
		for(i=2;i<=n;++i)
			cout<<f[i]<<' '<<i<<endl;
	}
	else
		cout<<-1<<endl;
	return 0;
}

