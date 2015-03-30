#include<stdio.h>
#include<stack>
#include<algorithm>
using namespace std;
int top=-1;
int main()
{
int n,i;
long long int ans=1;
scanf("%d",&n);
int a[n+2];
for(i=0;i<n;i++)
{
  scanf("%d",&a[i]);
}
stack <int>s;
s.push(a[n-1]);
int cur_max=a[n-1];

for(i=n-2;i>=0;i--)
{
 if(a[i]>cur_max)
 {
     cur_max=a[i];
     s.push(a[i]);
 }
 {
    for(int j=s.size();!s.empty();j--)
    {
 else
        if(a[i]>s.top())
        {
            s.pop();
        }
        else
        {
            ans=(ans*s.top())%1000000007;
            s.push(a[i]);
            break;
        }

    }
 }

}
printf("%lld\n",ans);

return 0;
}

