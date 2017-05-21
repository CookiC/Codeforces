//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#include<vector>
#include<cstring>
#include<queue>
#define LL long long int
//#pragma warning(disable : 4996)
using namespace std;

const int maxN=1e5+7;
const int maxn=maxN*4;

struct Edge{
	unsigned v;
	int w;
	Edge(unsigned v,int w):v(v),w(w){}
};

int N,Q,s,cnt;
vector<Edge> G[maxn];
bool inq[maxn];
LL d[maxn];

struct TreeNode{
	int n;
	int L,R;
};

class SegmentTree{
private:
	TreeNode su[maxn];
	TreeNode sv[maxn];
	TreeNode *s;
	int W,n,qL,qR;
	
	void Build(int o,int L,int R){
		su[o].L=L;
		su[o].R=R;
		sv[o].L=L;
		sv[o].R=R;
		if(L==R){
			sv[o].n=R;
			su[o].n=L;
			return;
		}
		sv[o].n=cnt++;
		su[o].n=cnt++;
		int M=L+(R-L)/2;
		Build(o*2,L,M);
		Build(o*2+1,M+1,R);
		G[su[o].n].push_back(Edge(su[o*2].n,0));
		G[su[o].n].push_back(Edge(su[o*2+1].n,0));
		G[sv[o*2].n].push_back(Edge(sv[o].n,0));
		G[sv[o*2+1].n].push_back(Edge(sv[o].n,0));
	}
	
	void AddUEdge(int o){
		int L=su[o].L;
		int R=su[o].R;
		if(qL<=L&&R<=qR){
			G[n].push_back(Edge(su[o].n,W));
			return;
		}
		int M=L+(R-L)/2;
		if(qL<=M) AddUEdge(o*2);
		if(M<qR) AddUEdge(o*2+1);
	}
	
	void AddVEdge(int o){
		int L=sv[o].L;
		int R=sv[o].R;
		if(qL<=L&&R<=qR){
			G[sv[o].n].push_back(Edge(n,W));
			return;
		}
		int M=L+(R-L)/2;
		if(qL<=M) AddVEdge(o*2);
		if(M<qR) AddVEdge(o*2+1);
	}
public:	
	void Build(int len){
		cnt=N+1;
		Build(1,1,len);
	}
	
	void AddEdge(int t,int node,int L,int R,int w){
		n=node;
		qL=L;
		qR=R;
		W=w;
		if(t==2)
			AddUEdge(1);
		else
			AddVEdge(1);
	}
	
	int Count(){
		return cnt;
	}
};

SegmentTree seg;

void SPFA(int s){
	queue<int> q;
	memset(inq,0,sizeof(inq));
	for(int i=1;i<cnt;++i)
		d[i]=-1;
	d[s]=0;
	inq[s]=1;
	q.push(s);
	
	int u;
	while(!q.empty()){
		u=q.front();
		q.pop();
		inq[u]=0;
		
		for(auto e=G[u].begin();e!=G[u].end();++e)
			if(d[e->v]<0||d[e->v]>d[u]+e->w){
				d[e->v]=d[u]+e->w;
				if(!inq[e->v]){
					q.push(e->v);
					inq[e->v]=1;
				}
			}
	}
}

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	int t,u,v,w,l,r,i;
	cin>>N>>Q>>s;
	seg.Build(N);
	
	for(i=0;i<Q;++i){
		cin>>t;
		if(t==1){
			cin>>u>>v>>w;
			G[u].push_back(Edge(v,w));
		}
		else{
			cin>>v>>l>>r>>w;
			seg.AddEdge(t,v,l,r,w);
		}
	}
	SPFA(s);
	for(i=1;i<=N;++i)
		cout<<d[i]<<' ';
	cout<<endl;
	return 0;
}

