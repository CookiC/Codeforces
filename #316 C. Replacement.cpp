//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#include<cstring>
#define lowbit(x) (x&-x)
#define maxn 300010
//#pragma warning(disable : 4996)
using namespace std;

class FenwickTree{
private:
	int C[maxn];
public:
	int maxLen;
	
	FenwickTree(){
		maxLen=maxn-1;
	}

	void Clear(){
		memset(C,0,(maxLen+1)*sizeof(int));
	}
	
	int Sum(unsigned x){
		int sum=0;
		while(x>0){
			sum+=C[x];
			x-=lowbit(x);
		}
		return sum;
	}

	int Add(unsigned x,int d){
		while(x<=maxLen){
			C[x]+=d;
			x+=lowbit(x);
		}
	}
};

char s[maxn];
FenwickTree ft;

bool QIn(char *p){
	char c;
	while((c=getchar())!=EOF&&(c==' '||c=='\n'));
	if(c==EOF)
		return false;
	do{
		*p++=c;
	}while((c=getchar())!=EOF&&c!=' '&&c!='\n');
	*p=0;
	return true;
}

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
//	ios::sync_with_stdio(false);
	
	int n,m,i;
	cin>>n>>m;
	getchar();
	QIn(s+1);
	s[0]=' ';
	for(i=2;i<=n;++i)
		if(s[i]=='.'&&s[i-1]=='.')
			ft.Add(i,1);
	
	int x;
	char c;
	for(i=0;i<m;++i){
		cin>>x>>c;
		if((c=='.'||s[x]=='.')&&c!=s[x])
			if(s[x]=='.'){
				if(s[x-1]=='.')
					ft.Add(x,-1);
				if(s[x+1]=='.')
					ft.Add(x+1,-1);
			}
			else{
				if(s[x-1]=='.')
					ft.Add(x,1);
				if(s[x+1]=='.')
					ft.Add(x+1,1);
			}
		s[x]=c;
		cout<<ft.Sum(n)<<endl;
	}
	return 0;
}

