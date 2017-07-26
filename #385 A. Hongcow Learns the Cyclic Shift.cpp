#include<iostream>
#include<cstring>
#define maxn 100
using namespace std;

char s[maxn];

int main(){
	ios::sync_with_stdio(false);
	
	int i,j,sl;
	cin>>s;
	sl=strlen(s);
	for(i=1;i<sl;++i){
		for(j=0;j<sl&&s[j]==s[(i+j)%sl];++j);
		if(j==sl)
			break;
	}
	cout<<i<<endl;
	return 0;
}

