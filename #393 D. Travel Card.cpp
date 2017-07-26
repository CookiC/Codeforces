//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#define maxn 200010
using namespace std;

struct Node{
	int n,i;
	bool operator < (const Node &b)const{
		if(n==b.n)
			return i>b.i;
		return n>b.n;
	}
};
int n;
int t[maxn],d[maxn];
priority_queue<Node> q,p; 

int main(){
	ios::sync_with_stdio(false);
	
	int i,j;
	cin>>n;
	for(i=1;i<=n;++i)
		cin>>t[i];
	d[0]=0;
	q.push(Node{0,0});
	p.push(Node{0,0});
	for(i=1;i<=n;++i){
		d[i]=d[i-1]+20;
		while(!q.empty()&&t[i]-t[q.top().i]>=90)
			q.pop();
		if(!q.empty())
			d[i]=min(d[i],d[q.top().i-1]+50);
		while(!p.empty()&&t[i]-t[p.top().i]>=1440)
			p.pop();
		if(!p.empty())
			d[i]=min(d[i],d[p.top().i-1]+120);
		q.push(Node{d[i],i});
		p.push(Node{d[i],i});
	}
	for(i=1;i<=n;++i)
		cout<<d[i]-d[i-1]<<endl;
	return 0;
}

