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
#define MOD 10000007
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

int pow( LL a, LL b){
    LL temp = 1,ans = 1;
    while(b>0)
    {
        if(b & temp)
        {
            ans = (ans * a) % MOD;
            b = b - temp;
        }
        temp = temp << 1;
        a = (a * a) % MOD;
    }
    return ans % MOD;
}
int main()
{
 LL n,k;
 while(1)
 {
        scanf("%lld%lld",&n,&k);
        if(n == 0 && k == 0)
            break;
        int ans = (2*pow(n-1,k)) % MOD  +  (2*pow(n-1,n-1)) % MOD  +  pow(n,k) % MOD +  pow(n,n) % MOD;
        ans = ans % MOD;
        printf("%d\n",ans);
}
return 0;
}
