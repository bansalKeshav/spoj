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
long long int arr[1002][1002];
int main()
{
int n,i,x,y,j;
scanf("%d",&n);
long long int a[n+2],max=0;
for(i=1;i<=n;)
{
    scanf("%lld",&a[i]);
    arr[i][i]=a[i];
    i++;
    arr[i][i-1]=0;
}
for(i=1;i<=n;i++)
{
    for(j=i;j<=n;j++)
    {
        arr[i][j]=arr[i][j-1]^a[j];
        if(arr[i][j]>max)
        {
            max=arr[i][j];
            x=i;
            y=j;
        }
    }
}
printf("%lld \n%d %d\n",max,x,y);
return 0;
}
