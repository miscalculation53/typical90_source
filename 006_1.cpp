#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

using p = pair<char, int>;

p op(p a, p b)
{
  char ca = a.first, cb = b.first;
  int ia = a.second, ib = b.second;
  
  if (ca < cb) return a;
  else if (ca > cb) return b;
  else
  {
    if (ia < ib) return a;
    else return b;
  }
}

p e()
{
  return make_pair('{', 1e9);
}

int main()
{
  // i 文字選んで辞書順最小になるような選び方は, i - 1 文字選んで辞書順最小になるような選び方をもとに 1 文字選んだもの
  // よって, 辞書順最小になるように 1 文字選ぶ, という操作を K 回行えばよい
  // この操作で選ばれる文字は次のように決まる
  // 選ばれた文字を # で, 選ばれていない文字を添字で書くと
  // たとえば 1#345#78## のとき, 7 文字目と 8 文字目のうち辞書順で小さいほうを選べばよい
  
  int N, K;
  cin >> N >> K;
  string S;
  cin >> S;
  
  vector<p> s(N);
  for (int i = 0; i < N; i++)
  {
    s.at(i) = make_pair(S.at(i), i);
  }
  
  segtree<p, op, e> seg(s); // 文字の辞書順の区間 min (同じ文字は添字が小さいほうを採用)
  
  vector<bool> used(N, false); // 文字を選んだかどうか
  vector<int> L(1, 0); // 選んだ文字の添字を追加していく
  int R = N; // 埋まっている右側の位置を管理
  for (int k = 0; k < K; k++)
  {
    p ci = seg.prod(L.back(), R);
    char c = ci.first;
    int i = ci.second;
    
    used.at(i) = true;
    
    L.push_back(i + 1);
    while (L.back() == R) // 埋まっている右側の位置を更新
    {
      L.pop_back();
      R--;
    }
  }
  
  for (int i = 0; i < N; i++)
  {
    if (used.at(i)) cout << S.at(i);
  }
  cout << endl;
}
