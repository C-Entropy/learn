#include <cstring>
#include <cstdio>
#include <iostream>
using namespace std;

int bugs[2005];
bool gender[2005];


int find(int x)
{
  if(x != bugs[x])
    {
      gender[x] = !gender[bugs[x]];
      x = find(bugs[x]);
    }
  return x;
}

void merge(int x, int y)
{
  bugs[x] = y;
  gender[x] = !gender[y];
  return;
}

int main()
{
  int T;
  freopen("ina", "r", stdin);
  scanf("%d", &T);
  int num, times, x, y;
  bool flag;
  cout<<'a';
  for(int i =  1; i <= T; i++)
    {
      flag = false;
      scanf("%d%d", &num, &times);
      for(int j = 1; j <= num; j++) bugs[j] = j;
      memset(gender, false, sizeof(bugs));
      for(int h = 0; h < times; h++)
	{
	  scanf("%d%d", &x, &y);
	  if(flag) continue;
	  if(gender[x] == gender[y]) flag = true;
	  merge(find(x), find(y));
	}
      printf("Scenario #%d:\n", i);
      if(flag) printf("Suspicious bugs found!");
      else printf("No suspicious bugs found!");
      printf("\n\n");
    }
  return 0;
}

