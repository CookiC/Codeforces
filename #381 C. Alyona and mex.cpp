#include<iostream>
#include<set>
#define maxn 100010
using namespace std;

int n,m;
bool vis[maxn];
int a[maxn];
int L[maxn],R[maxn],I[maxn];

bool cmpR(const int a,const int b){
	return R[a]<R[b];
}

int main(){
	ios::sync_with_stdio(false);
	
	int i,j,p;
	cin>>n>>m;
	I[0]=0;
	for(i=1;i<=m;++i){
		cin>>L[i]>>R[i];
		I[i]=i;
	}
	R[0]=0;
	sort(I,I+m+1,cmpR);
	L[0]=L[I[1]];
	int cnt=0;
	for(i=1;i<=m;++i){
		cnt-=L[I[i]]-L[I[i-1]];
		for(j=R[i];j>R[i-1];--j){
				
				a[j]=cnt;
			}
	}
	return 0;
}

