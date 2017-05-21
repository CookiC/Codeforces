#include<cstdio>

int i,n;

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	
	scanf("%u",&n);
	printf("%u ",n);
	for(i=1;i<=n-1;++i)
		printf("%u ",i);
	printf("\n");
	return 0;
}

