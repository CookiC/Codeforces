//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#define maxn 510
//#pragma warning(disable : 4996)
using namespace std;

int n,k;
int a[maxn],b[maxn],I[maxn];
char D[maxn];

void erase(int i){
	while(i<n){
		a[i]=a[i+1];
		++i;
	}
	--n;
}

bool ok(int b,int e,int &m){
	if(b==e)
		return true;
	int i,maxa=0,maxi;
	bool d;
	for(i=b;i<e;++i)
		if(a[i]!=a[i+1])
			break;
	if(i>=e)
		return false;
	for(i=b;i<=e;++i)
		if(a[i]>maxa)
			maxa=a[i];
	for(i=b;i<=e;++i)
		if(a[i]==maxa){
			if(i>b&&a[i-1]<a[i]){
				maxi=i;
				d=0;
				break;
			}
			if(i<e&&a[i+1]<a[i]){
				maxi=i;
				d=1;
				break;
			}
		}
	if(d){
		for(i=maxi;i<e;--e){
			erase(i+1);
			I[m]=i;
			D[m]='R';
			++m;
		}
		for(i=maxi;i>b;--i){
			erase(i-1);
			I[m]=i;
			D[m]='L';
			++m;
		}
	}
	else{
		for(i=maxi;i>b;--i){
			erase(i-1);
			I[m]=i;
			D[m]='L';
			++m;
			--e;
		}
		while(i<e){
			erase(i+1);
			I[m]=i;
			D[m]='R';
			++m;
			--e;
		}
	}
	return true;
}

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	int i,j,l=0,m=0,o;
	cin>>n;
	for(i=1;i<=n;++i){
		cin>>a[i];
		l+=a[i];
	}
	cin>>k;
	for(i=1;i<=k;++i){
		cin>>b[i];
		m+=b[i];
	}
	
	bool ans;
	if(m==l)
		ans=1;
	else
		ans=0;
	int sum=0;
	j=1;
	l=1;
	m=0;
	for(i=1;i<=n&&ans;++i){
		sum+=a[i];
		if(sum==b[l]){
//			cout<<j<<' '<<i<<endl;
			if(!ok(j,i,m)){
				ans=0;
				break;
			}
			i=j++;
			++l;
			sum=0;
		}
		else if(sum>b[l]){
			ans=0;
			break;
		}
//		cout<<n<<endl;
	}
	if(ans){
		cout<<"YES"<<endl;
		for(i=0;i<m;++i)
			cout<<I[i]<<' '<<D[i]<<endl;
	}
	else
		cout<<"NO"<<endl;
	return 0;
}

