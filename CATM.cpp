//bansal0301
#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<iostream>
#include<stdlib.h>
#include<vector>
#include<queue>
#include<limits.h>
using namespace std;
int MIN(int a ,int b)
{
if(a>b)
return b;
return a;
}
int MAX(int a,int b)
{
if(a>b)
return a;
return b;
}

int main(){
 int m, n, t, x1, x2, x3, y1, y2, y3;
 cin>>n>>m>>t;
 while(t--)
 {
  cin>>x1>>y1>>x2>>y2>>x3>>y3;

  if((x1<x2+abs(y1-y2) && x1<x3+abs(y1-y3)))
   cout<<"YES"<<endl;

  else if((x1>x2-abs(y1-y2) && x1>x3-abs(y1-y3)))
   cout<<"YES"<<endl;

  else if((y1<y2+abs(x1-x2) && y1<y3+abs(x1-x3)))
   cout<<"YES"<<endl;

  else if((y1>y2-abs(x1-x2) && y1>y3-abs(x1-x3)))
   cout<<"YES"<<endl;

  else
   cout<<"NO"<<endl;
 }
 return 0;
}
