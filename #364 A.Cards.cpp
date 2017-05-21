#include<cstdio>
#include<algorithm>
using namespace std;

int i;
unsigned n;
int order[150];
unsigned a[150];

bool cmp(const int &i,const int &j){
		return a[i]<a[j];
}

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);

	scanf("%u",&n);
	for(i=1;i<=n;++i){
		scanf("%d",&a[i]);
		order[i]=i;
	}
	sort(order+1,order+n+1,cmp);
	/*for(i=1;i<=n;++i)
		printf("%3d",a[order[i]]);
	printf("\n");*/
	for(i=1;i<=n/2;++i)
		printf("%d %d\n",order[i],order[n-i+1]);
	return 0;
}

