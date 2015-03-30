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
int n;
typedef struct array
{
    int x;
    int y;
}data;

bool arrange(data a ,data b)
{
    float t1 ,t2;
    t1=float(a.y)/float(a.x);
    t2=float(b.y)/float(b.x);
     return t1>t2;
}
int main()
{
int i,j;
cin>>n;
data arr[n+2];
for(i=0;i<n;i++)
{
    scanf("%d %d",&arr[i].x,&arr[i].y);
}
sort(arr,arr+n,arrange);

int lis[n+2],lds[n+2];
printf("\n\n\n\n");
for(i=0;i<=n;i++)
{
    lis[i]=1;
    lds[i]=1;
    printf("%d %d\n",arr[i].x,arr[i].y);
}
printf("\n\n\n");
for(i=1;i<n;i++)
{
    for(j=0;j<i;j++)
    {
        if(arr[i].x>=arr[j].x&&lis[i]<lis[j]+1)
        {

            lis[i]=lis[j]+1;
        }
    }
}
for(i=n-2;i>=0;i--)
{
    for(j=n-1;j>i;j--)
    {
        if(arr[i].x>=arr[j].x&&lds[i]<lds[j]+1)
        {
            lds[i]=lds[j]+1;
        }
    }
}
for(i=0;i<n;i++)
printf("%d %d\n",lis[i],lds[i]);
int max=lis[0]+lds[0]-1;

for(i=1;i<n;i++)
{
    if(lis[i]+lds[j]-1>max)
    {
        max=lis[i]+lds[i]-1;
    }
}
max++;
cout<<max<<endl;





return 0;
}
