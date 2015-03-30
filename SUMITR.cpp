#include<stdio.h>
#include<iostream>
using namespace std;
#define s(a) scanf("%d",&a);
int t,n,k,a[150][150],i,j;
int main()
{
s(t)
while(t--)
{
    s(n)
    k=0;
    for(i=1;i<=n;i++)
    {
        for(j=0;j<i;j++)
        {
           s(a[i][j])
           a[i][j]+=max(a[i-1][j],a[i-1][j-1]);
           k=max(k,a[i][j]);
        }
    }
    printf("%d\n",k);
}
}
