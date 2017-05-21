#include<iostream>
#include<algorithm>
using namespace std;

long long b,d,s,Max,ans;

int main(){
	ios::sync_with_stdio(false);
	cin>>b>>d>>s;
	Max=max(max(b,d),s);
	ans=Max*3-b-d-s;
	if(b<Max) --ans;
	if(d<Max) --ans;
	if(s<Max) --ans;
	cout<<ans<<endl;
	return 0;
}

