#include<cstdio>
#include<queue>
#include<cstring>
#define maxn 200010
using namespace std;

int i;
unsigned n,f;
int way[maxn];
unsigned a[maxn];
queue<unsigned> q;

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	
	scanf("%u",&n);
	memset(way,-1,sizeof(way));
	for(i=1;i<=n;++i)
		scanf("%u",&a[i]);
	way[1]=0;
	q.push(1);
	while(!q.empty()){
		f=q.front();
		q.pop();
		if(f>1&&way[f-1]<0){
			way[f-1]=way[f]+1;
			q.push(f-1);
		}
		if(way[f+1]<0){
			way[f+1]=way[f]+1;
			q.push(f+1);
		}
		if(way[a[f]]<0){
			way[a[f]]=way[f]+1;
			q.push(a[f]);
		}
	}
	for(i=1;i<=n;++i)
		printf("%d ",way[i]);
	return 0;
}

