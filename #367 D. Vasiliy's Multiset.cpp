//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#include<cstring>
#define maxm 29
#define maxn 400010
//#pragma warning(disable : 4996)
using namespace std;

struct Node{
	int cnt;
	Node *C[2];
	
	TreeNode(){
		C[0]=C[1]=NULL;
		cnt=0;
	}
};
int q,m;
Node *root;

void Insert(int x){
	int i,dest;
	Node *p=root;
	for(i=maxm;i>=0;--i){
		dest=x>>i&1;
		if(p->C[dest]==NULL)
			p->C[dest]=new Node();
		p=p->C[dest];
		++p->cnt;
	}
}

bool Delete(int x){
	int i,dest;
	Node *p=root;
	for(i=maxm;i>=0;--i){
		dest=x>>i&1;
		p=p->C[dest];
		--p->cnt;
	}
}

int Query(int x){
	int i,dest,ans=0;
	x=~x;
	Node *p=root;
	for(i=maxm;i>=0;--i){
		dest=x>>i&1;
		if(p->C[dest]!=NULL&&p->C[dest]->cnt){
			ans+=1<<i;
			p=p->C[dest];
		}
		else if(p->C[dest^1]!=NULL&&p->C[dest^1]->cnt)
			p=p->C[dest^1];
		else
			break;
	}
	return ans;
} 

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	char c;
	int x,i;
	cin>>q;
	root=new Node();
	Insert(0);
	for(i=0;i<q;++i){
		cin>>c>>x;
		if(c=='+')
			Insert(x);
		else if(c=='-')
			Delete(x);
		else
			cout<<Query(x)<<endl;
	}
	return 0;
}

