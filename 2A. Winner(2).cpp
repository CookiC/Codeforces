#include<iostream>
#include<cstring>
#define maxn 1010
using namespace std;

unsigned n,i,j,count,m,maxnum=0;     //m为player的数量
int sumscore[maxn]={0};              //记录总分 
int score[maxn],maxscore=0x80000000; //0x80000000为所能表达的最小值
char name[maxn][40],player[maxn][40];//player储存每个player的名字 
bool ismax[maxn];                    //ismax[player id]表示该player是否最后结果是最大值
 
unsigned PlayerId(char name[]){      //找到player在数组中是第几个
	for(unsigned i=0;i<m;++i)          //相当于给每个player标记个id 
	  if(strcmp(player[i],name)==0)    //id为数组下标 
	    return i;
	return m;
};

int main(){
	cin>>n;
  for(i=0;i<n;++i)
  	cin>>name[i]>>score[i];
  
	m=0;                               //表示player的数量 
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
    	memset(ismax,0,sizeof(ismax)); //ismax清零 
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
    memset(sumscore,0,sizeof(sumscore));//再求和一次 
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

