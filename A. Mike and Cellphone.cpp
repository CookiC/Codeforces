#include<cstdio>

char s[10];
int i;
bool up=0,down=0,left=0,right=0;
unsigned n;

int main(){
	scanf("%u%s",&n,s);
	for(i=0;i<n;++i){
		switch(s[i]-'0'){
			case 0:down=1;left=1;right=1;break;
			case 1:left=1;up=1;break;
			case 2:up=1;break;
			case 3:right=1;up=1;break;
			case 4:left=1;break;
			case 6:right=1;break;
			case 7:left=1;down=1;break;
			case 9:right=1;down=1;
		}
	}
	if(up&&down&&left&&right)
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}

