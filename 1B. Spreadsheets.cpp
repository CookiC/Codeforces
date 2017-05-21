#include<stdio.h>
#include<string.h>

int n,i,j,l,c,r;
char sin[100],sout[100];

bool TypeExcel()
{
  int l,i,j;
  l=strlen(sin);
  j=-1;
  for(i=0;i<l;i++)
  	if(sin[i]>='0'&&sin[i]<='9')
	{
  	  for(;i<l&&sin[i]>='0'&&sin[i]<='9';i++);
  	  j++;
    }
  return !j;
}

int main()
{
  scanf("%d",&n);
  for(i=0;i<n;i++)
  {
  	scanf("%s",sin);
  	if(TypeExcel())
  	{
  	  l=strlen(sin);
  	  c=0;
  	  r=0;
  	  for(j=0;sin[j]>='A'&&sin[j]<='Z';j++)
  	    c=c*26+sin[j]-'A'+1;//ZZ AAA
  	  for(;j<l;j++)
  	    r=r*10+sin[j]-'0';
  	  printf("R%dC%d\n",r,c);
	}
	else
	{
	  l=strlen(sin);
	  c=0;
	  r=0;
	  for(j=1;sin[j]>='0'&&sin[j]<='9';j++)
	  	r=r*10+sin[j]-'0';
	  j++;
	  for(;sin[j]>='0'&&sin[j]<='9';j++)
	  	c=c*10+sin[j]-'0';
	  for(j=0;c!=0;j++)
	  {
	  	sout[j]=(c-1)%26+'A';
		c=(c-1)/26;
      }
      j--;
      while(j>=0)
      {
       printf("%c",sout[j]);
	   j--;
	  }
      printf("%d\n",r);
	}
  }
  return 0;
}

