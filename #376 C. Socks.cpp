//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#include<map>
#define maxn 200010
//#pragma warning(disable : 4996)
using namespace std;

int c[maxn],si[maxn];
int P[maxn];
int sum[maxn],mcnt[maxn];
map<int,int> mp[maxn];

int find(int x){
	if(P[x]==x)
		return x;
	return P[x]=find(P[x]);
}

int n,m,k;

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	cin>>n>>m>>k;
	if(m){
		int i,j,l,r,x,y;
		for(i=1;i<=n;++i){
			cin>>c[i];
			P[i]=i;
		}
		for(i=0;i<m;++i){
			cin>>l>>r;
			x=find(l);
			y=find(r);
			if(x!=y)
				P[y]=x;
		}
		j=0;
		for(i=1;i<=n;++i){
//			cout<<find(i)<<' '<<i<<endl;
			if(P[i]==i)
				si[i]=j++;
		}
		y=j;
//		cout<<y<<endl;
		for(i=1;i<=n;++i){
			j=si[find(i)];
			++sum[j];
			if(mp[j].find(c[i])!=mp[j].end())
				x=++mp[j][c[i]];
			else
				x=mp[j][c[i]]=1;
			if(x>mcnt[j])
				mcnt[j]=x;
//			cout<<j<<' '<<sum[j]<<' '<<mcnt[j]<<endl;
		}
		
		int ans=0;
		for(i=0;i<y;++i){
			ans+=sum[i]-mcnt[i];
//			cout<<i<<' '<<sum[i]<<' '<<mcnt[i]<<endl;
		}
		cout<<ans<<endl;
	}
	else
		cout<<0<<endl;
	return 0;
}

