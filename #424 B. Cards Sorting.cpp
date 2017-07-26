//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#include<algorithm>
#define lowbit(n) (n&-n)
#define maxn 100010
#define LL long long
//#pragma warning(disable : 4996)
using namespace std;

int N;
int C[maxn];
	
int Sum(unsigned n){
	int sum=0;
	while(n>0){
		sum+=C[n];
		n-=lowbit(n);
	}
	return sum;
}

void Add(unsigned n,int d){
	while(n<=N){
		C[n]+=d;
		n+=lowbit(n);
	}
}

int a[maxn],ai[maxn],b[maxn];

bool cmpA(const int &x, const int &y){
	if(a[x]==a[y])
		return x<y;
	return a[x]<a[y];
}

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	int i,j;
	cin>>N;
	for(i=1;i<=N;++i){
		cin>>a[i];
		ai[i]=i;
	}
	sort(ai+1,ai+N+1,cmpA);
	int L=1,R=1;
	ai[0]=0;
	while(R<=N){
		while(R<=N&&a[ai[L]]==a[ai[R]])
			++R;
		j=upper_bound(ai+L,ai+R,ai[L-1])-ai;
		if(j<R){
			for(i=0;i<R-L;++i){
				b[i]=ai[j];
				++j;
				if(j==R)
					j=L;
			}
			for(i=0;i<R-L;++i)
				ai[L+i]=b[i];
		}
		L=R;
	}
	for(i=1;i<=N;++i)
		Add(i,1);
	LL ans=ai[1];
	Add(ai[1],-1);
	for(i=2;i<=N;++i){
		if(ai[i-1]<ai[i])
			ans+=Sum(ai[i])-Sum(ai[i-1]);
		else
			ans+=Sum(N)-Sum(ai[i-1])+Sum(ai[i]);
//		cout<<ai[i]<<' '<<a[ai[i]]<<endl;
		Add(ai[i],-1);
	}
	cout<<ans<<endl;
	return 0;
}

