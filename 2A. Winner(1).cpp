#include<iostream>
#include<string>
#include<map>
#include<set>
using namespace std;

unsigned n,i,count;
int score[1010],maxscore=0x80000000;//int所能表达的最小值
string name[1010];
map<string,int> player;
set<string> maxplayer;

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	
	cin>>n;
  for(i=0;i<n;++i)
  	cin>>name[i]>>score[i];
  for(i=0;i<n;++i){
  	if(!player.count(name[i]))
  	  player[name[i]]=0;
  	player[name[i]]+=score[i];
  }
  
  maxplayer.clear();
  for(auto it=player.begin();it!=player.end();++it)
    if(it->second>maxscore){
      maxscore=it->second;
      maxplayer.clear();
      maxplayer.insert(it->first);
    }
    else if(it->second==maxscore)
    	maxplayer.insert(it->first);
  
  if(maxplayer.size()==1)
    cout<<*maxplayer.begin();
  else{
    player.clear();
	  for(i=0;i<n;++i){
    	if(!player.count(name[i]))
  	    player[name[i]]=0;
  	  player[name[i]]+=score[i];
  	  if(player[name[i]]>=maxscore&&maxplayer.find(name[i])!=maxplayer.end()){
  	  	cout<<name[i];
  	  	break;
  	  }
    }
  }
  return 0;
}

