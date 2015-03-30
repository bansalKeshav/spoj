//bansal0301
#include<stdio.h>
#include<iostream>
#include<stdlib.h>
#include<algorithm>
#include<string.h>
#include<math.h>
#include<limits.h>
#include<vector>
#include<queue>
#include<ctype.h>
#include<map>
# define CASE int t;scanf("%d",&t);while(t--)
# define LL long long int
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
int arr[1000000];

int main()
{
int k ,l ,i;
scanf("%d %d",&k,&l);
arr[1]=0;
arr[k]=0;
arr[l]=0;
 for(i=2;i<=1000000;i++)
 {
     int flag=0;
     if(i==k||i==l)
     {
      arr[i]=0;
      flag=1;
     }
     if(arr[i-1])
     {
      arr[i]=0;
      flag=1;
     }

     if(i>k&&flag==0)
     {
        if(arr[i-k])
        {
         arr[i]=0;
         flag=1;
        }
     }

     if(i>l&&flag==0)
     {
        if(arr[i-l])
        {
         arr[i]=0;
         flag=1;
        }
     }
     if(flag==0)
     arr[i]=1;
 }
// printf("\nk=%d l=%d\n\n",k,l);
CASE
{
 int n;
 scanf("%d",&n);
 //printf("%d",n);
 printf("%c",arr[n]+65);
}
printf("\n");


return 0;
}
