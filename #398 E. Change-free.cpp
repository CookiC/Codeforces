//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#include<algorithm>
#include<set>
#define LL long long
#define maxn 100010
//#pragma warning(disable : 4996)
using namespace std;

LL n,m;
LL c[maxn],w[maxn],r[maxn],v[maxn];

struct cmp{  
    bool operator ()(const int a,const int b){
    	if(v[a]==v[b])
    		return a<b;
		return v[a]<v[b];
	}
};  

set<int,cmp> st;
int note[maxn],coin[maxn];

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	int i,j;
	cin>>n>>m;
	for(i=0;i<n;++i)
		cin>>c[i];
	for(i=0;i<n;++i){
		cin>>w[i];
		r[i]=99-(c[i]-1)%100;
		v[i]=r[i]*w[i];
	}
	
	LL ans=0;
	for(i=0;i<n;++i){
		st.insert(i);
		if(c[i]%100<=m){
			m-=c[i]%100;
			note[i]=c[i]/100;
			coin[i]=c[i]%100;
//			cout<<1<<' ';
			if(c[i]%100==0)
				st.erase(i);
		}
		else if(*st.begin()==i){
			m+=r[i];
			note[i]=(c[i]+99)/100;
			coin[i]=0;
			st.erase(i);
			ans+=v[i];
//			cout<<2<<' ';
		}
		else{
			m+=r[i];
			note[i]=c[i]/100;
			coin[i]=c[i]%100;
			j=*st.begin();
			note[j]=(c[j]+99)/100;
			coin[j]=0;
			st.erase(j);
			ans+=v[j];
//			cout<<3<<' ';
		}
//		cout<<i<<':'<<m<<endl;
	}
	
	cout<<ans<<endl;
	for(i=0;i<n;++i)
		cout<<note[i]<<' '<<coin[i]<<endl;
	return 0;
}

