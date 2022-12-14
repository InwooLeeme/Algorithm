#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/rope>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;

#define int int64_t

/* 
 MOD는 합성수가 아닌 소수여야함.
 주워져야하는 DP 점화식은 선형이어야 함.
 */
const int MOD = 1000000009;
using ll = long long;

int ipow(int x, int p){
	int ret = 1, piv = x;
	while(p){
		if(p & 1) ret = ret * piv % MOD;
		piv = piv * piv % MOD;
		p >>= 1;
	}
	return ret;
}

vector<int> berlekamp_massey(vector<int> x) {
	vector<int> ls, cur;
	int lf, ld;
	for (int i = 0; i < x.size(); i++) {
		ll t = 0;
		for (int j = 0; j < cur.size(); j++) {
			t = (t + 1ll * x[i - j - 1] * cur[j]) % MOD;
		}
		if ((t - x[i]) % MOD == 0) continue;
		if (cur.empty()) {
			cur.resize(i + 1);
			lf = i;
			ld = (t - x[i]) % MOD;
			continue;
		}
		ll k = -(x[i] - t) * ipow(ld, MOD - 2) % MOD;
		vector<int> c(i - lf - 1);
		c.push_back(k);
		for (auto& j : ls) c.push_back(-j * k % MOD);
		if (c.size() < cur.size()) c.resize(cur.size());
		for (int j = 0; j < cur.size(); j++) {
			c[j] = (c[j] + cur[j]) % MOD;
		}
		if (i - lf + (int)ls.size() >= (int)cur.size()) {
			tie(ls, lf, ld) = make_tuple(cur, i, (t - x[i]) % MOD);
		}
		cur = c;
	}
	for (auto& i : cur) i = (i % MOD + MOD) % MOD;
	return cur;
}
int get_nth(vector<int> rec, vector<int> dp, ll n) {
	int m = rec.size();
	vector<int> s(m), t(m);
	s[0] = 1;
	if (m != 1) t[1] = 1;
	else t[0] = rec[0];
	auto mul = [&rec](vector<int> v, vector<int> w) {
		int m = v.size();
		vector<int> t(2 * m);
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < m; k++) {
				t[j + k] += 1ll * v[j] * w[k] % MOD;
				if (t[j + k] >= MOD) t[j + k] -= MOD;
			}
		}
		for (int j = 2 * m - 1; j >= m; j--) {
			for (int k = 1; k <= m; k++) {
				t[j - k] += 1ll * t[j] * rec[k - 1] % MOD;
				if (t[j - k] >= MOD) t[j - k] -= MOD;
			}
		}
		t.resize(m);
		return t;
	};
	while (n) {
		if (n & 1) s = mul(s, t);
		t = mul(t, t);
		n >>= 1;
	}
	ll ret = 0;
	for (int i = 0; i < m; i++) ret += 1ll * s[i] * dp[i] % MOD;
	return ret % MOD;
}
int guess_nth_term(vector<int> x, ll n) {
	if (n < x.size()) return x[n];
	vector<int> v = berlekamp_massey(x);
	if (v.empty()) return 0;
	return get_nth(v, x, n);
}

int ret;
const int dx[4] = {-1,0,1,0},dy[4] = {0,1,0,-1};
bool vist[3][22];

void DFS(int i, int x, int y){
	if(x == 2 and y == i){
		ret++;
		return;
	}
	vist[x][y] = 1;
	for(int dir = 0; dir < 4; dir++){
		auto nx = x + dx[dir],ny = y + dy[dir];
		if(nx < 0 || nx >= 3 || ny < 0 || ny > i) continue;
		if(vist[nx][ny]) continue;
		DFS(i, nx, ny);
	}
	vist[x][y] = 0;
}

int Sol(int x){
	ret = 0;
	DFS(x, 0, 0);
	return ret;
}

int32_t main(){
    fastio;
	ll N; cin >> N; N--;
	vector<int> v;
	for(int i = 0; i < 10; i++) v.push_back(Sol(i));
	cout << guess_nth_term(v, N) << "\n";
    return 0;
}