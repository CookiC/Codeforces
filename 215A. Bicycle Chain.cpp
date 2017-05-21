#include<cstdio>

int i,j;
unsigned n,m,Max=0,cnt=0;
unsigned a[60],b[60];

int main(){
	scanf("%u",&n);
	for(i=0;i<n;++i)
		scanf("%u",&a[i]);
	scanf("%u",&m);
	for(i=0;i<m;++i)
		scanf("%u",&b[i]);
	for(i=0;i<n;++i)
		for(j=0;j<m;++j)
			if(b[j]%a[i]==0){
				unsigned res=b[j]/a[i];
				if(res==Max)
					++cnt;
				else if(res>Max){
					Max=res;
					cnt=1;
				}
			}
	printf("%u\n",cnt);
	return 0;
}

