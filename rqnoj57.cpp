#include <cstdio>
#include <iostream>
using namespace std;

int rmb[102], rp[102], w[102], f[102][102], ft[102][102];
int main()
{
  int n, m, r;
  scanf("%d", &n);
  for(int i = 0; i < n; i++) scanf("%d%d%d", &rmb[i], &rp[i], &w[i]);
  scanf("%d%d", &m, &r);

  for(int i = 0; i < n; i++)
    for(int j = m; j >= rmb[i]; j--)
      for(int k = r; k >= rp[i]; k--)
	if(f[j][k] < f[j-rmb[i]][k-rp[i]] + 1 || (ft[j][k] > ft[j-rmb[i]][k-rp[i]] +w[i] && f[j][k] == f[j-rmb[i]][k-rp[i]] + 1))
	  {
	    f[j][k] = f[j-rmb[i]][k-rp[i]] + 1;
	    ft[j][k] = ft[j-rmb[i]][k-rp[i]] + w[i];	    
	  }
  int max = -1, min = 10000000000;

  for(int i = 0; i <= m; i++)
    for(int j = 0; j <= r; j++)
      if(max >= f[i][j] && min < ft[i][j]) {max = f[i][l]; min = ft[i][j];}

  printf("%d", min);
  return 0;
}
