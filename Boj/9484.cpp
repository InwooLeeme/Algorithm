#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2,fma")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/rope>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;

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

const int PRECISION = 1;
const int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};
const int ddx[8] = {0, 1, 1, 1, 0, -1, -1, -1}, ddy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
constexpr int INF = 1LL << 60;
constexpr int NINF = -INF;

pii v[2222];

void solve(){
    int n; while(cin >> n and n){
		for(int i = 0; i < n; i++) cin >> v[i].fi >> v[i].se;
		double mn = 1e9, mx = 0;
		for(int i = 0; i < n; i++){
			auto [x1, y1] = v[i];
			for(int j = i + 1; j < n; j++){
				auto [x2, y2] = v[j];
				auto fx = x2 - x1;
				auto fy = y2 - y1;
				for(int k = j + 1; k < n; k++){
					auto [x3, y3] = v[k];
					auto S = (y3 - y1)*fx - (x3 - x1)*fy;
					if(S < 0) S = -S;
					mn = (mn > S ? S : mn);
					mx = (mx < S ? S : mx);
				}
			}
		}
		cout << (mn / 2.0) << " " << (mx / 2.0) << "\n";
	}    
}

void Main(){
    int t = 1; 
    //cin >> t;
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
