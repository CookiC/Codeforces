//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#include<cmath>
#include<algorithm>
#define LL long long
#define maxN 200010
//#pragma warning(disable : 4996)
using namespace std;

LL cnt,ans;
int i,j,len;
int N,Q,L,R,Ll,Lr,Rl,Lv,Rv;
int a[maxN],aSort[maxN];

void insert(int n,int x,int y){
	int d,*p;
	int *b=aSort+n;
	int *e=aSort+(n+len>N?N:n+len);
	int *B, *E;
	B = lower_bound(b, e, x);
	E = lower_bound(b, e, y);
	if (B < E){
		d = 1;
		--E;
	}
	else
		d=-1;
	for (p = B; p != E;p+=d)
		*p = *(p + d);
	*E=y;
}

void count(int L,int R){
	int i;
	for(i=L;i<=R;++i){
		if (a[i]>Lv)
			++cnt;
		else
			--cnt;
		if (a[i] < Rv)
			++cnt;
		else
			--cnt;
	}
}

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	cin>>N>>Q;
	len=sqrt(N+0.5);
	for(i=0;i<N;++i){
		a[i]=i+1;
		aSort[i]=i+1;
	}
	ans=0;
	for(i=0;i<Q;++i){
		cin>>L>>R;
		if (L > R)
			swap(L, R);
		Lv=a[--L];
		Rv=a[--R];
		cnt=0;
		Ll=L-L%len;
		Lr=Ll+len-1;
		Rl=R-R%len;
		
		if(Ll==Rl)		
			count(L+1,R-1);
		else{
			count(L+1,Lr);
			count(Rl,R-1);
			for(j=L/len+1;j<=R/len-1;++j){
				int *b=aSort+j*len;
				int *e=aSort+((j+1)*len>N?N:(j+1)*len);
				int *p;
				p = lower_bound(b, e, Lv);
				cnt += e - p + b - p;
				p = lower_bound(b, e, Rv);
				cnt += p - e + p - b;
			}
			insert(Ll,Lv,Rv);
			insert(Rl,Rv,Lv);
		}
		if (Lv < Rv)
			++cnt;
		if (Lv>Rv)
			--cnt;

		a[L]=Rv;
		a[R] = Lv;
		cout<<(ans+=cnt)<<endl;
	}
	return 0;
}

