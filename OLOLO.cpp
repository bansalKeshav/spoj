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

int map()
{
 int n,i,ans,temp;
 scanf("%d",&n);
 scanf("%d",ans);
 for(i=0;i<n-1;i++)
 {
  scanf("%d",&temp);
  ans=ans^i;
 }
 printf("%d\n",ans);
}
