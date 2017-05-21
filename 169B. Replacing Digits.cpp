#include<cstdio>
#include<cstring>
#define maxn 100010

char a[maxn],s[maxn];
int i;
unsigned la,ls,Max=0;
unsigned cnt[10]={0};

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	
	scanf("%s%s",a,s);
	la=strlen(a);
	ls=strlen(s);
	for(i=0;i<ls;++i){
		++cnt[s[i]-'0'];
		if(s[i]-'0'>Max)
			Max=s[i]-'0';
	}
	for(i=0;i<la;++i)
		if(a[i]-'0'<Max){
			a[i]=Max+'0';
			--cnt[Max];
			while(!cnt[Max]&&Max)
				--Max;
		}
	printf("%s\n",a);
	return 0;
}

