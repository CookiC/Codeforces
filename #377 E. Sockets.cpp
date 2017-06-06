//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#include<queue>
#include<algorithm>
#define maxn 200010
//#pragma warning(disable : 4996)
using namespace std;

struct Socket{
	int id,p,a;
	bool operator < (const Socket &b) const{
		if(p==b.p){
			if(a==b.a)
				return id>b.id;
			return a>b.a;
		}
		return p<b.p;
	}
};
int n,m;
int p[maxn],b[maxn],pi[maxn],a[maxn];
Socket s;
priority_queue<Socket> q;

bool cmp(const int a,const int b){
	return p[a]>p[b];
}

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	int i,j,c,u;
	cin>>n>>m;
	for(i=0;i<n;++i){
		cin>>p[i];
		pi[i]=i;
	}
	sort(pi,pi+n,cmp);
	
	for(i=0;i<m;++i){
		cin>>s.p;
		s.id=i;
		s.a=0;
		q.push(s);
	}
	
	Socket t;
	c=0;
	u=0;
	for(i=0;i<n;++i){
		j=pi[i];
		if(!q.empty()){
			t=q.top();
			while(p[j]<t.p){
				q.pop();
				++t.a;
				t.p=(t.p+1)/2;
				q.push(t);
				t=q.top();
			}
			if(p[j]==t.p){
				q.pop();
				b[j]=t.id+1;
				a[t.id]=t.a;
				++c;
				u+=t.a;
			}
			else
				b[j]=0;
		}
		else
			b[j]=0;
	}
	
	
	cout<<c<<' '<<u<<endl;
	for(i=0;i<m;++i)
		cout<<a[i]<<' ';
	cout<<endl;
	for(i=0;i<n;++i)
		cout<<b[i]<<' ';
	cout<<endl;
	return 0;
}

