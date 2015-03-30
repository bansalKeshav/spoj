#include<stdio.h>
#include<algorithm>
#include<math.h>
using namespace std;
int a[100000]={0};
int b[100000]={0};
int c[1000];
int temp;
void precompute()
{
    int i,j,k ;
     for(i=2;i<100000;i++)
    {
       // printf("%d \n",i);
        if(a[i]==0)
        {
         //   cout<<i<<" ";
            for(j=i+i;j<10000;j=j+i)
            {
                a[j]=1;
            }
        }
    }
    j=0;
   for(i=2;i<10000;i++)
   {
       if(a[i]==0)
        {
         b[j]=i;
         j++;
        }
   }
 //  printf("%d \n",j);
   temp=0;

   for(i=0;i<j;i++)
   {
      for(k=1;k<=sqrt(b[i]);k++)
      {
          if(floor(sqrt(b[i]-(k*k)))==ceil(sqrt(b[i]-(k*k))))
          {
              c[temp]=b[i];
         //     printf("%d b[%d]=%d k=%d\n",c[temp],i,b[i],k);
              temp++;
              break;
          }
      }
      //printf("i change\n");
   }
  //printf("c[%d]=%d",temp,c[temp-1]);
}
int main()
{
 int t;
 scanf("%d",&t);
 precompute();
 while(t--)
 {
  int n,p,fu,ans=0;
  scanf("%d %d",&n,&p);
  n-=1;
  if(p==1)
  {
      printf("1\n");
  }
  else if(p==2)
  {
      //printf("")
      printf("%d\n",c[n]/2 + 1);
  }
  else
  {
      ans=0;
      fu=c[n]/3;
      for(int i=0;i<=fu;i++)
      {
          ans=ans+(c[n]-3*i)/2+1;
      }
      printf("%d \n",ans);
  }
 }
 return 0;
}
