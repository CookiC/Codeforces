//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#include<queue>
#define maxn 7010
//#pragma warning(disable : 4996)
using namespace std;

int N,cnt,n,m,i,j;
int s[2][maxn],k[2];
int f[2][maxn]={0};
queue<int> q;

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	cin>>N;
	for(i=0;i<2;++i){
		cin>>k[i];
		for(j=0;j<k[i];++j)
			cin>>s[i][j];
	}
	
	f[0][N-1]=-2;
	f[1][N-1]=-2;
	q.push(N-1);
	q.push(1*N+N-1);
	while(!q.empty()){
		n=q.front()/N;
		m=q.front()%N;
		q.pop();
		if(f[n][m]==-1)
			for(i=0;i<k[!n];++i){
				j=(m-s[!n][i]+N)%N;
				if(f[!n][j]>=0){
					++f[!n][j];
					if(f[!n][j]==k[!n]){
						f[!n][j]=-2;
						q.push((!n)*N+j);
					}
				}
			}
		else
			for(i=0;i<k[!n];++i){ 
				j=(m-s[!n][i]+N)%N;
				if(f[!n][j]>=0){
					f[!n][j]=-1;
					q.push((!n)*N+j);
				}
			}
	}
	
	for(i=0;i<2;++i){
		for(j=0;j<N-1;++j)
			if(f[i][j]==-1)
				cout<<"Win"<<' ';
			else if(f[i][j]==-2)
				cout<<"Lose"<<' ';
			else
				cout<<"Loop"<<' ';
		cout<<endl;
	}
	return 0;
}

