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
int main()
{
LL a[100000+5];
int arr[7];
arr[0]=2;
arr[1]=3;
arr[2]=6;
arr[3]=7;
arr[4]=8;
memset(a,0,sizeof(a));
a[0]=1;
for(int i=0;i<5;i++)
{
    for(int j=arr[i];j<100005;j++)
    {
         if(a[j-arr[i]] != 0)
         {
                    a[j] += a[j-arr[i]];
         }
    }
}
CASE
{
 int n;
 cin>>n;
 cout<<a[n]<<endl;
}


return 0;
}
