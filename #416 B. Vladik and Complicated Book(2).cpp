//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#include<cstring>
#include<algorithm>
#define maxn 10010
//#pragma warning(disable : 4996)
using namespace std;

struct Node{
	int sum,L,R;
	Node *l,*r;
	Node(){
		sum=0;
		l=0;
		r=0;
	}
};

Node *root[maxn];

void Build(Node* &o,int L,int R){
	o=new Node();
	o->L=L;
	o->R=R;
	if(L==R)
		return;
	int M=L+(R-L)/2;
	Build(o->l,L,M); 
	Build(o->r,M+1,R);
}

int uX,uN;

void Update(Node* &o,Node *p){
	o=new Node();
	*o=*p;
	o->sum+=uX;
	if(o->L==o->R)
		return;
	int M=o->L+(o->R-o->L)/2;
	if(uN<=M)
		Update(o->l,p->l);
	else
		Update(o->r,p->r);
}

int uql;
int uq[maxn];

void Build(const int *a,int al){
	memcpy(uq,a,sizeof(int)*al);
	sort(uq,uq+al);
	uql=unique(uq,uq+al)-uq;
	Build(root[0],1,uql);
	for(int i=0;i<al;++i){
		uX=1;
		uN=lower_bound(uq,uq+uql,a[i])-uq+1;
		Update(root[i+1],root[i]);
	}
}

int Query(Node* lo,Node *ro,int kth){
	if(lo->L==lo->R)
		return uq[lo->L-1];
	int sum=ro->l->sum-lo->l->sum;
	if(kth>sum)
		return Query(lo->r,ro->r,kth-sum);
	else
		return Query(lo->l,ro->l,kth);
}

int n,m;
int a[maxn];

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	int i,l,r,x;
	cin>>n>>m;
	for(i=0;i<n;++i)
		cin>>a[i];
	Build(a,n);
	for(i=0;i<m;++i){
		cin>>l>>r>>x;
		if(Query(root[l-1],root[r],x-l+1)==a[x-1])
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
	return 0;
}

