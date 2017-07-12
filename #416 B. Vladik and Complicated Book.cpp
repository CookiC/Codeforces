//Author:CookiC
#include<iostream>
#define maxn 10010
using namespace std;

int a[maxn];

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	int n,m,l,r,x,i,j;
	cin>>n>>m;
	for(i=1;i<=n;++i)
		cin>>a[i];
	int cnt;
	for(i=0;i<m;++i){
		cin>>l>>r>>x;
		cnt=0;
		for(j=l;j<=r&&cnt<=x-l;++j)
			if(a[j]<a[x])
				++cnt;
		if(x-l==cnt)
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
	return 0;
}

