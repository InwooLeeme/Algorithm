#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

using ll = long long;

ll n,board[101][101],d[101][101];

ll Sol(int x, int y){
  if(x == n - 1 && y == n - 1) return 1;
  if(x >= n || y >= n || !board[x][y]) return 0;
  ll& ret = d[x][y];
  if(ret != -1) return ret;
  return ret = Sol(x + board[x][y],y) + Sol(x, y + board[x][y]);
}

int32_t main(){
  fastio; 
  cin >> n;
  memset(d, -1,sizeof(d));
  for(int i = 0; i < n; i++) for(int j = 0; j < n; j++) cin >> board[i][j]; 
  cout << Sol(0,0) << "\n";
}