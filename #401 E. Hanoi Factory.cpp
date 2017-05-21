//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#include<algorithm>
#define maxN 100010
#define LL long long
//#pragma warning(disable : 4996)
using namespace std;

struct Ring{
	int a,b,h;
};

int N,top,i;
LL H,maxH;
int a[maxN],b[maxN],h[maxN],stk[maxN];
Ring r[maxN];

bool cmp(const Ring &ra,const Ring &rb){
	if(ra.b==rb.b){
		if(ra.a==rb.a)
			return ra.h<rb.h;
		return ra.a>rb.a;
	}
	return ra.b>rb.b;
}

bool canput(const Ring &ra,const Ring &rb){
	if(ra.b<=rb.b&&ra.b>rb.a)
		return true;
	return false;
}

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	cin>>N;
	for(i=0;i<N;++i)
		cin>>r[i].a>>r[i].b>>r[i].h;
	sort(r,r+N,cmp);
	top=0;
	maxH=0;
	H=0;
	for(i=0;i<N;++i){
		while(top&&!canput(r[i],r[stk[top-1]])){
			H-=r[stk[top-1]].h;
			--top;
		}
		H+=r[i].h;
		stk[top++]=i;
		if(H>maxH)
			maxH=H;
	}
	cout<<maxH<<endl;
	return 0;
}

