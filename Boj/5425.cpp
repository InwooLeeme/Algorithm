#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/rope>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;

#define int int_fast64_t
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define fi first
#define se second
#define pb push_back
#define si(x) (int)x.size()

using pii = pair<int, int>;
using ti3 = tuple<int, int, int>;
using vi = vector<int>;
using vvi = vector<vi>;

const int PRECISION = 0;
const int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};
const int ddx[8] = {0, 1, 1, 1, 0, -1, -1, -1}, ddy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
constexpr int INF = int(2e18);
constexpr int NINF = -INF;

int ten[22];

int f(int n, int k, int d){ // [1 , n] range find number d in 10^k
	int ret = 0;
	if(!ten[0]){
		ten[0] = 1;
		for(int i = 1; i < 22; i++) ten[i] = 10 * ten[i - 1];		
	}
	int q = n / ten[k + 1];
	ret += q * ten[k];
	int kDigit = n / ten[k] % 10;
	if(kDigit > d) ret += ten[k];
	else if(kDigit == d) ret += n % ten[k] + 1;
	else ret += 0;
	return ret;
}

void solve(){
    int L, R; cin >> L >> R;
	auto Sol = [&](int x) -> int{
		int ret = 0;
		for(int d = 1; d < 10; d++){
			for(int k = 0; k < 16; k++){
				ret += f(x, k, d) * d;
			}
		}
		return ret;
	};
	cout << Sol(R) - max<int>(0, Sol(L - 1)) << "\n";
}

void Main(){
    int t = 1; 
    cin >> t;
    while(t--) solve();
    /* for(int tc = 1; tc <= t; tc++){
    cout << "Case #" << tc << ": "; solve();
    } */
}

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed); cout.precision(PRECISION);
    Main();
    return 0;
}
