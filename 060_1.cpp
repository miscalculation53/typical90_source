#include <bits/stdc++.h>
using namespace std;
int INF = 1 << 30;

int main()
{
  int N;
  cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++)
  {
    cin >> A.at(i);
    A.at(i) = N + 1 - A.at(i);
  }

  vector<int> dp(N + 2, INF);
  dp.at(0) = -INF;

  for (auto a : A)
  {
    auto itmi = lower_bound(dp.begin(), dp.end(), -a);
    auto itpl = lower_bound(dp.begin(), dp.end(), a);

    int imi = itmi - dp.begin(), ipl = itpl - dp.begin();

    if (dp.at(ipl - 1) != -a) dp.at(ipl) = a;
    dp.at(imi) = -a;
  }

  for (int i = 1; i < N + 2; i++)
  {
    if (dp.at(i) == INF)
    {
      cout << i - 1 << endl;
      return 0;
    }
  }
}
