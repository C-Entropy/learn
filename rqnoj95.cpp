#include <cstdio>
#include <iostream>
using namespace std;
int f[1002][102];

int main()
{
  int N, M, L, t, m;
  scanf("%d%d%d", &N, &M, &L);
  while(N--)
    {
      scanf("%d%d", &t, &m);
      for(int j = M; j > 0; j--)
	for(int i = L; i >= t; i--)
	  if(j == 1 || f[i-t][j-1] != 0) f[i][j] = max(f[i][j], f[i-t][j-1] + m);
    }
  printf("%d", f[L][M]);	
  return 0;
}
