#include <cstdio>
#include <iostream>
#define INFN 10005
using namespace std;
long long f[INFN];

int main()
{
  int N, M;
  f[0] = 0;
  scanf("%d%d", &N, &M);
  for(int i = 1; i < N+1; i++) f[i] = -1;
  int weight, value;
  for(int i = 0; i < N; i++)
    {
      scanf("%d%d", &weight, &value);
      for(int j = weight; j <= M; j++)
	if(f[j-weight] != -1 && f[j] < f[j-weight]+value)
	  f[j] = f[j-weight]+value;
    }
  printf("%lld", f[M]);
  return 0;
}
  
