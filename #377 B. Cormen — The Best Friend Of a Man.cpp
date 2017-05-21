#include<iostream>
using namespace std;

int i;
int n,k,ans,t;
int a[600];

int main(){
	ios::sync_with_stdio(false);
	cin>>n>>k;
	for(i=0;i<n;++i)
		cin>>a[i];
		
	ans=0;
	i=1;
	while(i<n){
		if(a[i-1]+a[i]<k){
			t=k-a[i-1]-a[i];
			ans+=t;
			a[i]+=t;
		}
		++i;
	}
	cout<<ans<<endl;
	cout<<a[0];
	for(i=1;i<n;++i)
		cout<<' '<<a[i];
	cout<<endl;
	return 0;
}

