#include<cstdio>

bool b[72]={0};
int i;
unsigned r,l,n,type=0,len=0xFFFFFFFF;
unsigned cnt[52]={0},cvt[72]={0};
char s[100010];

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	
	scanf("%u%s",&n,s);
	for(i=0;i<n;++i){
		if(!b[s[i]-'A']){
			b[s[i]-'A']=1;
			cvt[s[i]-'A']=type++;
			l=i;
		};
		s[i]=cvt[s[i]-'A'];
	}
	
	for(i=0;i<=l;++i)
		++cnt[s[i]];
	
	r=0;
//	printf("%d\n",s[1]); 
	while(r<n){
		if(l-r+1<len)
			len=l-r+1;
		if(!--cnt[s[r]]){
			while(++l<n&&s[l]!=s[r])
				++cnt[s[l]];
			if(l>=n)
				break;
			++cnt[s[r]];
		}
		++r;
	}
	printf("%u\n",len);
	return 0;
}

