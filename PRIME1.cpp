#include<stdio.h>
#include<string.h>
#include<math.h>
int main()
{
int t;
scanf("%d",&t);
while(t--)
{
long long int i,j,k,n,m,l;
 scanf("%lld %lld",&n,&m);
 long long int a[m-n+4];
 memset(a,0,sizeof(a));
 l=int(sqrt(m))+1;

 if(n==1||n==2)
 {
     a[0]=1;
     a[1]=1;
     for(i=2;i<=l;i++)
     {
         if(a[i]==0)
         {
            for(j=i+i;j<=m;j++)
            {
      //         printf("j=%lld i=%lld a[%lld]=%lld\n",j,i,j,a[j]);
             if(j%i==0)
               a[j]=1;
            }
         }
     }
     for(i=2;i<=m;i++)
     {
        // printf("a[%lld]=%lld \t",i,a[i]);
         if(a[i]==0)
          printf("%lld\n",i);
     }
     //printf("a[13]=%lld",a[13]);

 }
 else
 {
     l++;
    for(i=2;i<=l;i++)
    {
 //       printf("i= %lld \n",i);
        j=n/i;
        j*=i;
        if((j==0||j==1)&&a[i-n]==0)
        j+=2*i;
        if(n==i&&a[0]==0)
        j+=2*i;
        //printf(" \t j=%d\n",j);
        //if(a[j-n]==0)
        //{
            for( ;j<=m;j=j+i)
            {
          //    printf("%lld %lld\n",j,i);
            if(j%i==0&&(j-n)>=0)
                {
            //         printf("%lld %lld\n",j-n,i);
                a[j-n]=1;
              //     printf("a[%lld] =%lld\n",j-n,a[j-n]);
                }
            }
        //}

      }
    // printf("dsf");
    /*for(i=0;i<=m-n+1;i++)
    {
     a[i]=0;
       printf("a[%lld]=%lld\n",i+n,a[i]);
    }
    */

    for(i=0;i<(m-n+1);i++)
    {
        //  printf("dsd\n");
        if(a[i]==0)
            {
            printf("%lld\n",i+n);
            }
    }
 }

    printf("\n");
}
return 0;
}
