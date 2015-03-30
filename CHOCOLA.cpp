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
    int n,m,x[1000],y[1000];
CASE
    {
        scanf("%d %d",&n,&m);
        --n; --m;

        for(int i = 0;i < n;++i)
            scanf("%d",&x[i]);
        for(int i = 0;i < m;++i)
            scanf("%d",&y[i]);

        int ans,s1 = 0,s2 = 0;

        for(int i = 0;i < n;++i)
            s1 += x[i];
        for(int i = 0;i < m;++i)
            s2 += y[i];

        ans = s1+s2;
        sort(x,x+n);
        sort(y,y+m);

        for(int i = n-1,j = m-1;i >= 0 && j >= 0;)
        {
            if(y[j] >= x[i])
            {
                ans += s1;
                s2 -= y[j];
                --j;
            }
            else
            {
                ans += s2;
                s1 -= x[i];
                --i;
            }
        }

        printf("%d\n",ans);
    }

    return 0;
}
