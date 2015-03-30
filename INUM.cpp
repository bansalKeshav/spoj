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
# define ll long long int
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
    ll n;
    scanf("%lli", &n);
    ll a[n];
    for(int i=0; i<n; i++)
        scanf("%lli", &a[i]);
    sort(a, a+n);
    ll maxdiff = a[n-1] - a[0];
    ll minans = 0, maxans;
    if (maxdiff == 0)
     {
        maxans = (n*(n-1))/2;
     }
    else
    {
        ll low = 0;
        for(int i=0; i<n; i++)
        {
            if (a[i] == a[0])
                low++;
            else
                break;
        }
        ll high = 0;
        for(int i=n-1; i>=0; i--)
        {
            if (a[i] == a[n-1])
                high++;
            else
                break;
        }
        maxans = low*high;
    }
    ll mindiff = LLONG_MAX;
    for(int i=1; i<n; i++)
     {
        ll d = a[i] - a[i-1];
        if (d == mindiff)
         {
            minans ++;
         }
        else if (d < mindiff)
         {
            minans = 1;
            mindiff = d;
        }
    }
    if (mindiff == 0)
    {
        minans = 0;
        ll curr = 1;
        for(int i=1; i<n; i++)
        {
            if (a[i] == a[i-1])
            {
                curr++;
            }
            else
            {
                minans += (curr*(curr-1))/2;
                curr = 1;
            }
        }
        minans += (curr*(curr-1))/2;
    }
    printf("%lli %lli", minans, maxans);
    return 0;
}
