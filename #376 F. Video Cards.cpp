//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#define lowbit(n) (n&-n)
#define maxn 200010
#define LL long long
//#pragma warning(disable : 4996)
using namespace std;

const LL N=2e5;
bool b[maxn];
int a[maxn]={0};

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	int n;
	LL x,y,i,j;
	cin>>n;
	for(i=0;i<n;++i){
		cin>>x;
		b[x]=1;
		++a[x];
	}
	for(i=1;i<=N;++i)
		a[i]+=a[i-1];
	
	LL ansS=0,S;
	for(i=1;i<=N;++i)
		if(b[i]){
			x=a[i-1];
			S=0;
			for(j=2;i*j-1<N;++j){
				y=a[i*j-1];
				S+=(y-x)*(j-1);
				x=y;
			}
			y=a[N];
			S+=(y-x)*(N/i);
//			cout<<i<<' '<<S<<endl;
			S*=i;
			if(S>ansS){
				ansS=S;
//				cout<<i<<' '<<ansS<<endl;
			}
		}
	cout<<ansS<<endl;
	return 0;
}

