#include<iostream>
#include<cstring>
#define maxn 1010
using namespace std;

unsigned n,i,j,count,m,maxnum=0;     //mΪplayer������
int sumscore[maxn]={0};              //��¼�ܷ� 
int score[maxn],maxscore=0x80000000; //0x80000000Ϊ���ܱ�����Сֵ
char name[maxn][40],player[maxn][40];//player����ÿ��player������ 
bool ismax[maxn];                    //ismax[player id]��ʾ��player�Ƿ�����������ֵ
 
unsigned PlayerId(char name[]){      //�ҵ�player���������ǵڼ���
	for(unsigned i=0;i<m;++i)          //�൱�ڸ�ÿ��player��Ǹ�id 
	  if(strcmp(player[i],name)==0)    //idΪ�����±� 
	    return i;
	return m;
};

int main(){
	cin>>n;
  for(i=0;i<n;++i)
  	cin>>name[i]>>score[i];
  
	m=0;                               //��ʾplayer������ 
	for(i=0;i<n;++i){
	  j=PlayerId(name[i]);
	  if(j==m){
	  	strcpy(player[j],name[i]);
	    ++m;
	  }
	  sumscore[j]+=score[i];
  }

  for(i=0;i<m;++i)
    if(sumscore[i]>maxscore){
    	maxscore=sumscore[i];
    	memset(ismax,0,sizeof(ismax)); //ismax���� 
			ismax[i]=true;
			maxnum=1;
    }
    else if(sumscore[i]==maxscore){
      ismax[i]=true;
      ++maxnum;
    }
  
  if(maxnum==1)
    for(i=0;i<m;++i){
      if(ismax[i]){
      	cout<<player[i];
      	break;
      }
    }
  else{
    memset(sumscore,0,sizeof(sumscore));//�����һ�� 
	  for(i=0;i<n;++i){
	    j=PlayerId(name[i]);
	    sumscore[j]+=score[i];
	    if(sumscore[j]>=maxscore&&ismax[j]){
			  cout<<player[j];
				break;
			}
    }
  }
  return 0;
}

