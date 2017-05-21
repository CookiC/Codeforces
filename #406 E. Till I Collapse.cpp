//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#include<cstdlib>
#define pause system("pause")
#define maxn 100010
//#pragma warning(disable : 4996)
using namespace std;

struct Node{
	int sum,L,R;
	Node *l,*r;
	Node(){
		sum=0;
		l=NULL;
		r=NULL;
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

int Query(Node *o,int kth){
	if(o->L==o->R)
		return o->L;
	if(kth>o->l->sum)
		return Query(o->r,kth-o->l->sum);
	else
		return Query(o->l,kth);
}

int n;
int a[maxn];
int pre[maxn];

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	int i,j;
	cin>>n;
	Build(root[n+1],1,n);
	for(i=1;i<=n;++i)
		cin>>a[i];
	
	for(i=n;i>0;--i){
		if(pre[a[i]]){
			uN=pre[a[i]];
			uX=-1;
			Update(root[i],root[i+1]);
			uN=i;
			uX=1;
			Update(root[i],root[i]);
		}
		else{
			uN=i;
			uX=1;
			Update(root[i],root[i+1]);
		}
		pre[a[i]]=i;
	}
	int cnt;
	for(i=1;i<=n;++i){
		j=1;
		cnt=0;
		while(j<=n){
			if(i+1<=root[j]->sum)
				j=Query(root[j],i+1);
			else
				j=n+1;
			++cnt;
		}
		cout<<cnt<<' ';
	}
	cout<<endl;
	return 0;
}

