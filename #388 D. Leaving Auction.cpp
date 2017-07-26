//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#include<algorithm>
#include<vector>
#define INF 0x7FFFFFFF
#define maxn 200010
//#pragma warning(disable : 4996)
using namespace std;

struct Bid{
	int a,b;
	bool operator < (const Bid &y) const{
		if(a==y.a)
			return b<y.b;
		return a<y.a;
	}
};

struct Node{
	Bid max;
	int add;
	Node *l,*r;
	Node(){
		add=0;
	}
};

Bid b[maxn];

void Build(Node* &o,int L,int R){
	o=new Node();
	if(L==R){
		o->max=Bid{b[L].a,b[L].b};
		return;
	}
	int M=L+(R-L)/2;
	Build(o->l,L,M);
	Build(o->r,M+1,R);
	o->max=o->l->max.b<o->r->max.b?o->r->max:o->l->max;
}

int uL,uR,uX;

void Add(Node* &o,int L,int R){
	if(uL<=L&&R<=uR){
		o->add+=uX;
		o->max.b+=uX;
		return;
	}
	int M=L+(R-L)/2;
	if(uL<=M)	Add(o->l,L,M);
	if(M<uR)	Add(o->r,M+1,R);
	o->max=o->l->max.b<o->r->max.b?o->r->max:o->l->max;
	o->max.b+=o->add;
}

int upper(int L,int R,int x){
	while(L<R){
		int M=L+(R-L)/2;
		if(x>=b[M].b)
			L=M+1; 
		else
			R=M;
	}
	return b[L].b;
}

int n,q,k;
int L[maxn],R[maxn],v[maxn];
Node *root;

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	int i,j;
	cin>>n;
	for(i=1;i<=n;++i)
		cin>>b[i].a>>b[i].b;
	sort(b+1,b+n+1);
	for(i=1;i<=n;++i){
		if(!L[b[i].a])
			L[b[i].a]=i;
		R[b[i].a]=i;
	}
	Build(root,1,n);
	Bid t;
	cin>>q;
	for(i=0;i<q;++i){
		cin>>k;
		uX=-INF;
		for(j=0;j<k;++j){
			cin>>v[j];
			uL=L[v[j]];
			uR=R[v[j]];
			if(uL)
				Add(root,1,n);
		}
		
		if(root->max.b>0){
			t=root->max;
			uL=L[t.a];
			uR=R[t.a];
			Add(root,1,n);
			cout<<t.a<<' '<<upper(L[t.a],R[t.a],root->max.b)<<endl;
			uL=L[t.a];
			uR=R[t.a];
			uX=INF;
			Add(root,1,n);
		}
		else
			cout<<"0 0"<<endl;
		
		uX=INF;
		for(j=0;j<k;++j){
			uL=L[v[j]];
			uR=R[v[j]];
			if(uL)
				Add(root,1,n);
		}
	}
	return 0;
}

