#include<iostream>
#include<cstring>
#define maxn 1010
using namespace std;

int i,n,ans;
char a[maxn],b[maxn],c[300];

int main(){
	ios::sync_with_stdio(false);

	cin>>a>>b;
	ans=0;
	n=strlen(a);
	memset(c,0,sizeof(c));
	for(i=0;i<n;++i)
		if(a[i]!=b[i]&&!(c[a[i]]==b[i]&&c[b[i]]==a[i]))
			if(c[a[i]]||c[b[i]]){
				ans=-1;
				break;
			}
			else{
				c[a[i]]=b[i];
				c[b[i]]=a[i];
				++ans;
			}
	cout<<ans<<endl;
	if(ans>0){
		for(i='a';i<='z';++i)
			
	}
	return 0;
}

