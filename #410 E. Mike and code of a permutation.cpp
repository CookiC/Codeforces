//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#include<algorithm>
#include<cstring>
#define maxn 500010
//#pragma warning(disable : 4996)
using namespace std;

struct Max{
	int n,i;
	bool operator < (const Max &b) const{
		return n<b.n;
	}
};

struct TreeNode{
	Max m;
	int L,R;
	TreeNode *l,*r;
};

class SegmentTree{
private:
	const static int maxm=maxn*2;
	
	TreeNode tree[maxm];
	int *a,qL,qR,uX,uN,top;
	
	void build(TreeNode *o,int L,int R){
		o->L=L;
		o->R=R;
		if(L==R){
			o->m.n=a[L-1];
			o->m.i=L;
			o->l=NULL;
			o->r=NULL;
			return;
		}
		int M=L+(R-L)/2;
		o->l=tree+top++;
		o->r=tree+top++;
		build(o->l,L,M);
		build(o->r,M+1,R);
		if(o->r->m<o->l->m)
			o->m=o->l->m;
		else
			o->m=o->r->m;
	}
	
	Max query(TreeNode *o){
		int L=o->L;
		int R=o->R;
		if(qL<=L&&R<=qR)
			return o->m;
		int M=L+(R-L)/2;
		Max ans={0,0};
		if(qL<=M) ans=max(ans,query(o->l));
		if(M<qR) ans=max(ans,query(o->r));
		return ans;
	}
	
	void update(TreeNode *o){
		int L=o->L;
		int R=o->R;
		if(L==R){
			o->m.n=uX;
			return;
		}
		int M=L+(R-L)/2;
		if(uN<=M) update(o->l);
		else update(o->r);
		o->m=max(o->l->m,o->r->m);
	}
	
public:	
	void build(int *array,int len){
		top=1;
		a=array+1;
		build(tree,1,len);
	}
	
	Max query(int L,int R){
		qL=L;
		qR=R; 
		return query(tree);
	}
	
	void update(int N,int X){
		uX=X;
		uN=N;
		update(tree);
	}
};

SegmentTree st;
int a[maxn],b[maxn];

class TopoSort{
private: 
	int c[maxn],t;
	
	void Dfs(int u){
		if (c[u])
			return;
		st.update(u, 0);
		c[u]=1;
		int v=b[u];
		Dfs(v);
		Max m;
		if (a[u]>1)
			while((m=st.query(1,a[u]-1)).n>u)
				Dfs(m.i);
		topo[--t]=u;
	}

public:
	int topo[maxn];
	
	void Run(int n){
		t=n;
		memset(c,0,sizeof(c));
		c[0] = 1;
		c[n + 1] = 1;
		for (int u = 1; u<=n ; ++u)
			Dfs(u);
	}
};

TopoSort ts;

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	int n,u,v;
	cin >> n;
	for (u = 1; u <= n; ++u)
		b[u] = n + 1;
	for(v=1;v<=n;++v){
		cin>>u;
		if(u<0)
			a[v]=n+1;
		else{
			a[v]=u;
			b[u]=v;
		}
	}

	st.build(b,n);
	ts.Run(n);
	for(u=0;u<n;++u)
		a[ts.topo[u]]=n-u;
	sort(ts.topo,ts.topo+n);
	for(u=1;u<=n;++u)
		cout<<a[u]<<' ';
	cout<<endl;
	return 0;
}

