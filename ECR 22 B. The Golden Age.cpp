#include<iostream>
#include<vector>
#include<algorithm>
#define LL long long
using namespace std;

LL x,y,l,r,px,py;
vector<LL> v;

int main(){
	ios::sync_with_stdio(false);
	
	int i;
	cin>>x>>y>>l>>r;
	for(px=1;px<r;px*=x){
		for(py=1;px+py<=r;py*=y){
			if(px+py>=l)
				v.push_back(px+py);
			if(r/y<py)
				break;
		}
		if(r/x<px)
			break;
	} 
	v.push_back(l-1);
	v.push_back(r+1);
	sort(v.begin(),v.end());
	LL ans=0;
	for(i=1;i<v.size();++i)
		if(v[i]-v[i-1]-1>ans)
			ans=v[i]-v[i-1]-1;
	cout<<ans<<endl;
	return 0;
}

