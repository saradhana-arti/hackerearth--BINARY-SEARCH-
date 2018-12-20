#include <bits/stdc++.h>

using namespace std;
int count_bit(int n)
{
  int count=0;
  while(n)
  {
    count+=n & 1;
    n>>=1;
  }
  return count;
}
int check(int sum[],int n,int mid ,int k)
{
  for(int i=0 ; i<=n-mid ; i++)
  {
    if(sum[mid+i]-sum[i]>=k)
    {
      return 1;
    }
  }
  return 0;
}
int main()
{
  int i , m , n ,q, j;
  cin>>n>>q;
  int a[n+1],c[n+1],sum[n+1]={0}, k;
  for(i=1 ; i<=n ; i++)
  cin>>a[i];

  for(i=1 ; i<=n ; i++)
  {
    c[i]=count_bit(a[i]);  
  }
  sum[0]=0;
  for(i=1 ; i<n+1 ; i++)
  {
    sum[i]=sum[i-1]+c[i];
    //cout<<sum[i]<<" ";
  }
  
  while(q--)
  {
    int ans=0;
    cin>>k;
    int l=1,r=n;
    while(l<=r)
    {
      int mid=(l+r)/2;
      if(check(sum,n,mid,k))
      {
          ans=mid;
          r=mid-1;
      }
      else {
        l=mid+1;
      }
    }
    cout<<ans<<endl;
  }
}
