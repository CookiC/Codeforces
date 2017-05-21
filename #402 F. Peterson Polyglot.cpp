//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#define maxn 300010
#define maxm 600010
//#pragma warning(disable : 4996)
using namespace std;

struct Node{
	int n;
	int sum;
	Node* C[26];

	Node(){
		Initial();
	}
	
	void Initial(){
		for(int i=0;i<26;++i)
			C[i]=NULL;
	}
	
};

int n,top;
Node T[maxn],P[maxn];
int d[maxn];

int Merge(Node* &o,Node *p){
	int cnt=0;
	Node *q=o;
	o=&P[top++];
	if(q!=NULL)
		*o=*q;
	else
		o->Initial();
	for(int i=0;i<26;++i)
		if(o->C[i]!=NULL&&p->C[i]!=NULL){
			++cnt;
			cnt+=Merge(o->C[i],p->C[i]);
		}
		else if(o->C[i]==NULL&&p->C[i]!=NULL)
			o->C[i]=p->C[i];
	return cnt;
}

int Delete(Node *o){
	Node *r,*p;
	int i,maxs=0,cnt=0;
	
	for(i=0;i<26;++i)
		if(o->C[i]!=NULL){
			++cnt;
			if(maxs<o->sum){
				maxs=o->sum;
				p=o->C[i];
			}
		}
	
	top=0;
	r=p;
	for(i=0;i<26;++i)
		if(o->C[i]!=NULL&&o->C[i]!=p)
			cnt+=Merge(r,o->C[i]);
	return cnt;
}

void Dfs(Node *o){
	o->sum=1;
	for(int i=0;i<26;++i)
		if(o->C[i]!=NULL){
			Dfs(o->C[i]);
			o->sum+=o->C[i]->sum;
		}
}

void Dfs(Node *o,int deep){
	int t=Delete(o);
//	cout<<o->n<<':'<<t<<endl;
	d[deep]+=t;
	for(int i=0;i<26;++i)
		if(o->C[i]!=NULL)
			Dfs(o->C[i],deep+1);
}

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	char w;
	int u,v,i;
	cin>>n;
	for(i=0;i<n-1;++i){
		cin>>u>>v>>w;
		T[u].C[w-'a']=&T[v];
	}
	
	for(i=1;i<=n;++i)
		T[i].n=i;
	Dfs(&T[1]);
	Dfs(&T[1],1);
	
	int maxs=0,maxd;
	for(i=1;d[i];++i)
		if(maxs<d[i]){
			maxs=d[i];
			maxd=i;
		}
	
	cout<<n-maxs<<endl;
	cout<<maxd<<endl;
	return 0;
}

