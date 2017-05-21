#include<cstdio>
#include<algorithm>
using namespace std;

int i,n,a,b;
int c[2001];

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	
	scanf("%d%d%d",&n,&a,&b);
	for(i=0;i<n;++i)
		scanf("%d",&c[i]);
	sort(c,c+n);
	printf("%d\n",c[b]-c[b-1]);
	return 0;
}

