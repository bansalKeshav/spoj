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

LL gcd(LL a,LL b)
{
 if(a==0)
 return b;
 gcd(b%a,a);
}
int main()
{
    int t;
scanf("%d",&t);
for(int i=1;i<=t;i++)
{
LL x1,y1,x2,y2;
scanf("%lld %lld %lld %lld",&x1,&y1,&x2,&y2);
LL num=x1*(x2+1)+y1*(y2+1);
LL den=(x1+y1)*(x2+y2+1);
//cout<<num<<" "<<den<<endl;
LL div=gcd(num,den);
//cout<<div<<endl;
if(den==0||num==0)
{
printf("Case %d: 0\n",i);
}
else
{
num=num/div;
den=den/div;
printf("Case %d: %lld/%lld\n",i,num,den);
}
}


return 0;
}
