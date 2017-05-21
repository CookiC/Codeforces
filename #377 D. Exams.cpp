#include<iostream>
#include<algorithm>
#define maxn 110000
using namespace std;

int n,m,sum,ans;
int d[maxn],a[maxn],psort[maxn],pd[maxn];

bool cmp(const int a,const int b){
	return pd[a]<pd[b];
}

bool isPass(){
	int i,sum=0;
	sort(psort,psort+m,cmp);
	if(psort[0]==0)
		return false;
//	for(i=0;i<m;++i)
//		cout<<psort[i]<<' ';
//	cout<<endl<<"-----------------"<<endl;
	for(i=0;i<m;++i){
		sum+=a[psort[i]];
		if(sum>pd[psort[i]])
			return false;
	}
	return true;
}

int main(){
	int i,j;
	
	ios::sync_with_stdio(false);
	cin>>n>>m;
	for(i=1;i<=n;++i)
		cin>>d[i];
	sum=0;
	for(i=1;i<=m;++i){
		cin>>a[i];
		a[i]+=1;
		sum+=a[i];
	}
	
	for(i=0;i<m;++i)
		psort[i]=i+1;
	
	ans=-1;
	for(i=1;i<=n;++i)
		if(d[i]){
			pd[d[i]]=i;
//			for(j=1;j<=m;++j)
//				cout<<pd[j]<<' ';
//			cout<<endl;
			if(i>=sum&&isPass()){
				ans=i;
				break;
			}
		}
	cout<<ans<<endl;
	return 0;
}

