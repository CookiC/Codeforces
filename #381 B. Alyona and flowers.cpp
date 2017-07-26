#include<iostream>
#define maxn 110
using namespace std;

int n,m;
int sum[maxn],a[maxn];

int main(){
	ios::sync_with_stdio(false);
	
	int i,l,r;
	cin>>n>>m;
	sum[0]=0;
	for(i=1;i<=n;++i){
		cin>>a[i];
		sum[i]=sum[i-1]+a[i];
	}
	int ans=0;
	for(i=0;i<m;++i){
		cin>>l>>r;
		if(sum[r]-sum[l-1]>0)
			ans+=sum[r]-sum[l-1];
	}
	cout<<ans<<endl;
	return 0;
}

