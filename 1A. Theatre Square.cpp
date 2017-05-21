#include<stdio.h>
#include<iostream>
using namespace std;

long long int n,m,a,res,h,l;

int main()
{
  cin>>n>>m>>a;
  h=n/a;
  l=m/a;
  if(h*a<n)
    h++;
  if(l*a<m)
  	l++;
  res=l*h;
  cout<<res;
  return 0;
}

