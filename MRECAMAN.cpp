#include<stdio.h>
#include<string.h>
long long int a[500009];
bool hash[1000000];
int main()
{
long long int t;
hash[0]=1;
 a[0]=0;
 //printf("a[0]=%lld\n",a[0]);
 long long int i;
 for(i=1;i<500009;i++)
 {
    a[i]=a[i-1]-i;
    if(a[i]>0&&hash[a[i]]==0)
    {
        hash[a[i]] =1;
    }
    else
    {
        a[i]=a[i-1]+i;
        hash[a[i]]=1;
    }
//    printf("a[%lld]=%lld\n",i,a[i]);
 }

scanf("%lld",&t);
while(t!=-1)
{
     printf("%lld\n",a[t]);
     scanf("%lld",&t);
}
return 0;
}
