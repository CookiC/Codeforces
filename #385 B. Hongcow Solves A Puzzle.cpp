#include<iostream>
#define maxn 510
using namespace std;

int n,m;
char s[maxn][maxn];

bool rec(){
	bool b=1;
	int i,j,r,c,x,y,cnt=0,sum=0;
	for(i=0;i<n;++i)
		for(j=0;j<m;++j)
			if(s[i][j]=='X'){
				++cnt;
				if(b){
					x=i;
					y=j;
					b=0; 
				} 
			} 
	i=x;j=y;
	for(r=0;i+r<n&&s[i+r][j]=='X';++r);
	for(c=0;j+c<m&&s[i][j+c]=='X';++c);
	for(x=0;x<r;++x)
		for(y=0;y<c;++y)
			if(s[i+x][j+y]=='X')
				++sum;
			else
				sum=0;
	if(sum==cnt)
		return true;
	return false;
}

int main(){
	ios::sync_with_stdio(false);
	
	int i;
	cin>>n>>m;
	for(i=0;i<n;++i)
		cin>>s[i];
	if(rec())
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
	return 0;
}

