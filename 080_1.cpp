#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
  ll N, D;
  cin >> N >> D;
  vector<ll> A(N);
  for (ll i = 0; i < N; i++)
  {
    cin >> A.at(i);
  }
  
  // addB := d 番目のビットを立てたときに条件が満たされる i の集合
  vector<ll> addB(D, 0);
  for (ll d = 0; d < D; d++)
  {
    for (ll i = 0; i < N; i++)
    {
      if (A.at(i) & (1LL << d))
        addB.at(d) |= (1LL << i);
    }
  }

  // dp[d][b] := d 番目のビットまで立てるか立てないかを見たときの条件が満たされている i の集合が b であるようなビットの立て方の個数
  vector<vector<ll>> dp(D + 1, vector<ll>((1LL << N), 0));
  dp.at(0).at(0) = 1;
  for (ll d = 0; d < D; d++)
  {
    for (ll b = 0; b < (1LL << N); b++)
    {
      // ビットを立てない
      dp.at(d + 1).at(b) += dp.at(d).at(b);

      // ビットを立てる
      ll nb = b | addB.at(d);
      dp.at(d + 1).at(nb) += dp.at(d).at(b);
    }
  }

  cout << dp.at(D).at((1LL << N) - 1) << endl;
}
