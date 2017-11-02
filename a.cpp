#include <cstdio>
#include <iostream>
using namespace std;

int f[505], value[15], weight[15];
int main()
{
  int n, v;
  scanf("%d%d", &n, &v);
  int m, w, s, count;
  for(int i = 0; i < n; i++)
    {
      scanf("%d%d%d", &m, &w, &s);
      count = 0;
      for(int j = 1; m != 0; j<<=1)
	{value[count]=j*s; weight[count++]=j*w; m-=j;}
      for(int flag = 0; flag < count; flag++)
	for(int j = 0; j <= v; j++)
	  {
	    // cout<<flag<<endl;
	    f[j] = max(f[j-weight[j]]+value[j], f[j]);
	  }
      cout<<i<<endl;
    }
  printf("%d", f[v]);
  return 0;
}
