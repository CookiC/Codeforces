#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

char x0,y0,x1,y1;
int dx,dy,incx,incy;

void output(int incx,int incy){
	switch (incx){
		case -1:cout<<'L';break;
  	case 1:cout<<'R';
  }
  switch (incy){
		case -1:cout<<'D';break;
  	case 1:cout<<'U';
  }
  cout<<endl;
}

int main(){
  cin>>x0>>y0>>x1>>y1;
  dx=x0-x1;
  dy=y0-y1;
  cout<<min(abs(dx),abs(dy))+abs(abs(dx)-abs(dy))<<endl;
	if(dx>0)
    incx=-1;
  else
    incx=1;
  if(dy>0)
    incy=-1;
  else
    incy=1;

  while(dx!=0&&dy!=0){
  	dx+=incx;
  	dy+=incy;
  	output(incx,incy);
  }
  
	if(dx==0)
    incx=0;
  if(dy==0)
    incy=0;
  while(dx!=0||dy!=0){
  	dx+=incx;
  	dy+=incy;
  	output(incx,incy);
	}
  return 0;
}

