//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#include<cstring>
#define maxn 100010
//#pragma warning(disable : 4996)
using namespace std;

bool b[26];
char s[maxn],t[maxn];

bool cmp(char *sb,char *se,char *tb,char *te){
	while(sb!=se&&tb!=te){
		if(*sb!=*tb&&!(*sb=='?'&&b[*tb-'a']))
			break;
		++sb;
		++tb;
	}
	if(sb==se&&tb==te)
		return true;
	return false;
}

bool rep(char *t, int l,int r){
	while(l<r){
		if(t[l]>0&&b[t[l]-'a'])
			return false;
		++l;
	}
	return true;
}

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	int i,q,sl,tl,ign=-1;
	cin>>s;
	for(i=0;s[i];++i)
		b[s[i]-'a']=1;
	cin>>s;
	
	for(i=0;s[i];++i)
		if(s[i]=='*'){
			ign=i;
			break;
		}
	sl=strlen(s);
	cin>>q;
	for(i=0;i<q;++i){
		cin>>t;
		tl=strlen(t);
		if(ign<0){
			if(cmp(s,s+sl,t,t+tl))
				cout<<"YES"<<endl;
			else
				cout<<"NO"<<endl;
		}
		else{
			if(tl>=sl-1&&cmp(s,s+ign,t,t+ign)&&rep(t,ign,tl-sl+ign+1)&&cmp(s+ign+1,s+sl,t+tl-(sl-ign-1),t+tl))
				cout<<"YES"<<endl;
			else
				cout<<"NO"<<endl;
		}
	}
	return 0;
}

