#include<cstdio> 
#include<cstring>

int i,j;
unsigned k,len;
char s[1010];
unsigned cnt[26]={0};

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	
	scanf("%u%s",&k,s);
	len=strlen(s);
	for(i=0;i<len;++i)
		++cnt[s[i]-'a'];
	for(i=0;i<26&&cnt[i]%k==0;++i)
		cnt[i]/=k;
	if(i>=26){
		while(k--)
			for(i=0;i<26;++i)
				for(j=0;j<cnt[i];++j)
					printf("%c",i+'a');
		printf("\n");
	}
	else
		printf("-1\n");
	return 0;
}

