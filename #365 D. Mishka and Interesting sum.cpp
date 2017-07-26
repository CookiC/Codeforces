//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#include<cstdio>
#include<map>
#include<algorithm>
#define lowbit(n) (n&-n)
#define maxn 1000010
//#pragma warning(disable : 4996)
using namespace std;

bool QIn(int &x){
	char c;
	while((c=getchar())!=EOF&&!isdigit(c));
	if(c==EOF)
		return false;
	x=0;
	do{
		x*=10;
		x+=c-'0';
	}while((c=getchar())!=EOF&&isdigit(c));
	return true;
}

void QOut(int x){
	char str[13];
	if(x){
		int i;
		for(i=0;x;++i){
			str[i]=x%10+'0';
			x/=10;
		}
		while(i--)
			putchar(str[i]);
	}
	else
		putchar('0');
}

int n,m,N;
int a[maxn],C[maxn],q[maxn],L[maxn],R[maxn],pre[maxn],ans[maxn],s[maxn],ai[maxn];

int Sum(unsigned n){
	int sum=0;
	while(n>0){
		sum^=C[n];
		n-=lowbit(n);
	}
	return sum;
}

void Add(unsigned n,int d){
	while(n<=N){
		C[n]^=d;
		n+=lowbit(n);
	}
}

bool cmpR(const int &x,const int &y){
	return R[x]<R[y];
}

bool cmpA(const int &x,const int &y){
	if(a[x]==a[y])
		return x<y;
	return a[x]<a[y];
}

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
//	ios::sync_with_stdio(false);
	
	int i,j,qi,rs;
	QIn(n);
	N=n;
	for(i=1;i<=n;++i){
		QIn(a[i]);
		s[i]=s[i-1]^a[i];
		ai[i]=i;
	}
	sort(ai+1,ai+n+1,cmpA);
	for(i=1;i<=n;++i)
		if(a[ai[i-1]]==a[ai[i]])
			pre[ai[i]]=ai[i-1];
		else
			pre[ai[i]]=0;
	QIn(m);
	for(i=1;i<=m;++i){
		QIn(L[i]);
		QIn(R[i]);
		q[i]=i;
	}
	sort(q+1,q+m+1,cmpR);
	j=1;
	for(i=1;i<=m;++i){
		qi=q[i];
		while(j<=R[qi]){
			if(pre[j])
				Add(pre[j],a[j]);
			Add(j,a[j]);
			++j;
		}
		ans[qi]=s[L[qi]-1]^s[R[qi]]^Sum(L[qi]-1)^Sum(R[qi]); 
	}
	for(i=1;i<=m;++i){
		QOut(ans[i]);
		putchar('\n');
	}
	return 0;
}

