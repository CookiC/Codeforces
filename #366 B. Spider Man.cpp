#include<cstdio>

int i;
unsigned n,a,cnt=0;

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	
	scanf("%u",&n);
	for(i=0;i<n;++i){
		scanf("%u",&a);
		if(!(a&1))
			++cnt;
		if(cnt&1)
			printf("1\n");
		else
			printf("2\n");
	}
	return 0;
}

