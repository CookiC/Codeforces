//Author:CookiC
//#include"stdafx.h"
#include<iostream>
#include<cstring>
#define maxc 16
#define maxa 61
#define LL long long
//#pragma warning(disable : 4996)
using namespace std;

const LL M=1e9+7;
LL n,k;
LL ans[maxc],anst[maxc],d[maxc][maxc][maxc][maxa];

void range(int s,int l,int c,int &a,int &b){
	const static int p[]={1,2,4,8,16,32};
	if(l>5){
		a=0;
		b=c;
	}
	else{
		a=max(0,s-p[l]);
		b=min(c,s+p[l]);
	}
}

void Dinit(){
	int c,s,t,l,i,il,ir,tl,tr;
	memset(d,0,sizeof(d));
	for(c=0;c<maxc;++c){
		for(s=0;s<=c;++s){
			tl=max(0,s-1);
			tr=min(c,s+1);
			for(t=tl;t<=tr;++t)
				d[c][s][t][0]=1;
		}
		
		for(l=1;l<maxa;++l)
			for(s=0;s<=c;++s){
				range(s,l-1,c,il,ir);
				for(i=il;i<=ir;++i){
					range(i,l-1,c,tl,tr);
					for(t=tl;t<=tr;++t)
						d[c][s][t][l]=(d[c][s][t][l]+d[c][s][i][l-1]*d[c][i][t][l-1]%M)%M;
				}
			}
	}
}

void Answer(){
	int c,s,t,i,j,tl,tr;
	LL a,b,l;
	ans[0]=1;
	cin>>n>>k;
	for(i=0;i<n;++i){
		cin>>a>>b>>c;
		if(b>k)
			b=k;
		for(j=c+1;j<maxc;++j)
			ans[j]=0;
		l=b-a;
		j=0;
		do{
			if(l&1){
				memset(anst,0,sizeof(anst));
				for(s=0;s<=c;++s){
					range(s,j,c,tl,tr);
					for(t=tl;t<=tr;++t)
						anst[t]=(anst[t]+ans[s]*d[c][s][t][j]%M)%M;
				}
				memcpy(ans,anst,sizeof(ans));
			}
			++j;
/*			for(a=0;a<=c;++a)
				cout<<ans[a]<<' ';
			cout<<endl;	*/
		}while(l>>=1);
	}
	cout<<ans[0]<<endl;
}

int main(){
//	freopen("test.in","r",stdin);
//	freopen("test.out","w",stdout);
	ios::sync_with_stdio(false);
	
	Dinit();
	Answer();
	return 0;
}

