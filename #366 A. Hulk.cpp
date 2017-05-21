#include<cstdio>

int i;
unsigned n;

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	
	scanf("%u",&n);
	for(i=1;i<n;++i)
		if(i%2==1)
			printf("I hate that ");
		else
			printf("I love that ");
	if(n%2==1)
		printf("I hate it\n");
	else
		printf("I love it\n");
	return 0;
}

