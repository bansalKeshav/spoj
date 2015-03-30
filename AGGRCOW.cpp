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

int n,c;

int fun(int num,int arr[])
{
    int cows=1,pos=arr[0];
    for (int i=1; i<n; i++)
    {
        if (arr[i]-pos>=num)
        {
            pos=arr[i];
            cows++;
            if (cows==c)
                return 1;
        }
    }
    return 0;
}
int bs(int arr[])
{
    int strt=0,last=arr[n-1],max=-1;
    while (last>strt)
    {
        int mid=(strt+last)/2;
        if (fun(mid,arr)==1)
        {
            if (mid>max)
                max=mid;
            strt=mid+1;
        }
        else
            last=mid;
    }
    return max;
}
int main()
{
    CASE
    {
        scanf("%d %d",&n,&c);
        int arr[n];
        for (int i=0; i<n; i++)
            scanf("%d",&arr[i]);

        sort(arr,arr+n);

        int k=bs(arr);
        printf("%d\n",k);
    }
    return 0;
}
