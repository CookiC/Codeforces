#include<iostream>
#define maxn 1010
#define LL long long
using namespace std;

int n,m,k;
bool c[maxn];
int P[maxn],cnt[maxn];

int find(int x){
	if(P[x]==x)
		return x;
	return P[x]=find(P[x]);
}

int main(){
	ios::sync_with_stdio(false);
	
	int i,u,v,x,y,maxcnt,j,sum;
	cin>>n>>m>>k;
	for(i=1;i<=n;++i){
		P[i]=i;
		cnt[i]=1;
	}
	for(i=0;i<k;++i){
		cin>>x;
		c[x]=1;
	}
	for(i=0;i<m;++i){
		cin>>u>>v;
		x=find(u);
		y=find(v);
		if(x!=y){
			if(c[x]){
				P[y]=x;
				cnt[x]+=cnt[y];
			}
			else{
				P[x]=y;
				cnt[y]+=cnt[x];
			}
		}
	}
	maxcnt=0;
	sum=0;
	for(i=1;i<=n;++i)
		if(c[i]){
			if(cnt[i]>maxcnt){
				maxcnt=cnt[i];
				j=i;
			}
			sum+=cnt[i]; 
		}
	LL ans=0;
	for(i=1;i<=n;++i)
		if(c[i])
			if(i==j){
				x=n-sum+cnt[i];
				ans+=x*(x-1)/2;
//				cout<<i<<' '<<x<<endl;
			}
			else{
				ans+=cnt[i]*(cnt[i]-1)/2;
//				cout<<i<<' '<<cnt[i]<<endl;
			}
	cout<<ans-m<<endl;
	return 0;
}

