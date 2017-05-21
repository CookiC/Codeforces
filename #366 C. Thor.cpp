#include<cstdio>
#include<vector>
#define maxq 300010
using namespace std;

int i,j,t;
bool b[maxq];
unsigned n,m,q,type,cnt=0,head;
unsigned left[maxq],right[maxq];
vector<unsigned> x[maxq];

int main(){
	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);

	int T=0;
	scanf("%u%u",&n,&q);
		m=1;
		left[0]=right[0]=0;
		for(i=1;i<=q;++i){
			scanf("%u%d",&type,&t);
			if(type==1){
				b[m]=1;
				right[m]=0;
				left[m]=left[0];
				left[0]=m;
				x[t].push_back(m);
				++cnt; ++m;
			}
			else if(type==2){
				for(j=0;j<x[t].size();++j){
					int k=x[t][j];
					if(b[k]){
						b[k]=0;
						left[right[k]]=left[k];
						right[left[k]]=right[k];
						--cnt;
					}
				}
				x[t].clear();
			}
			else{
				for(j=left[0];j&&m-j<=t;j=left[j]){
					if(b[j]){
						b[j]=0;
						--cnt;
					}
					left[right[j]]=left[j];
					right[left[j]]=right[j];
				}
			}
			printf("%3d: %u\n",++T,cnt);
			for(j=left[0];j;j=left[j])
				if(b[j])
					printf("%3u",j);
			printf("\n");
		}
	return 0;
}

