#include <cstdio>
#include <iostream>
using namespace std;

int w[105], f[105];
int main()
{

  int num, sum;
  scanf("%d", &num);
  for(int i = 0; i < num; i++)
    {
      scanf("%d", &w[i]);
      sum+=w[i];
    }
  int ave = sum/2;
  for(int i = 0; i <= ave; i++) f[i] = i > w[0] ? w[0] : 0;

  for(int i = 1; i < num; i++)
    for(int j = 0; j <= ave; j++)
      f[j] = j >= w[i] ? max(f[j], f[j-w[i]]+w[i]) : f[j];
  printf("%d", sum-f[ave]*2);
  return 0;
}
