//bansal0301
#include<stdio.h>
#include<algorithm>
#include<math.h>
#include<iostream>
#include<stdlib.h>
#include<vector>
#include<string.h>
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

int main()
{
 int n,i,j,temp;
 scanf("%d",&n);
 char arr[100];
 for(i=0;i<n;i++)
 {
  scanf("%d %s",&temp,&arr);
  printf("%d ",i+1);
  int l=strlen(arr);
    for(j=1;j<=l;j++)
    {
        if(j!=temp)
        {
         printf("%c",arr[j-1]);
        }
    }
    printf("\n");
 }
return 0;
}
