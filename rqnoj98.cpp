#include <cstdio>
#include <iostream>
using namespace std;
int f[502];
int main()
{
  int n, v, m, w, s, weight, value;
  scanf("%d%d", &n, &v);
  for(int i = 0; i < n; i++)
    {
      scanf("%d%d%d", &m, &w, &s);
      
      for(int k = 1; k <= m; k<<=1) 
	{
	  m-=k;
	  weight = k*w; value = k*s;
	  for(int j = v; j >= weight; j--)
	    f[j] = max(f[j], f[j-weight]+value);
	}
      
      if(m > 0)
	{
	  weight = m*w; value = m*s;
	  for(int j = v; j >= weight; j--)
	    f[j] = max(f[j], f[j-weight]+value);
	}
      
    }
  printf("%d", f[v]);
}
