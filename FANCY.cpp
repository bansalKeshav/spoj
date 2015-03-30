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
LL fun(string str)
{
    int len=str.length();
    LL ans=1;
    int same[len+2],i;
    for(i=0;i<len;i++)
     same[i]=i;
    LL temp;
    for(i=0;i<len;i++)
    {
        temp=1;
        if(str[i]==str[i+1])
        {
            same[i+1]=same[i];
        }
        else
        {
            temp=i-same[i];
            temp=pow(2,temp);
            ans=ans*temp;
        }
    }
return ans;
}
int main()
{
CASE
{
string str;
cin>>str;
cout<<fun(str)<<endl;
}


return 0;
}
