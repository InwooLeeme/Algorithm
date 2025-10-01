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

const int PRECISION = 0;

using pii = pair<int, int>;

int n,m;
vector<pii> g[1 << 17];

void solve(){
    cin >> n >> m;
	vector<int> A(n + 1), B(n + 1);
	for(int i = 1; i <= n; i++) cin >> A[i];
	for(int i = 1; i <= n; i++) cin >> B[i];
	for(int i = 0; i < m; i++){
		int a,b,c; cin >> a >> b >> c;
		g[a].push_back({c, b}); g[b].push_back({c, a});
	}
	auto dijk = [](int st){
		vector<int> dist(n + 1, 1 << 30);
		priority_queue<pii, vector<pii>, greater<>> pq;
		pq.push({dist[st] = 0, st});
		while(pq.size()){
			auto [cdist, cur] = pq.top(); pq.pop();
			if(dist[cur] < cdist) continue;
			for(const auto& [cost, nxt] : g[cur]){
				if(dist[nxt] > cdist + cost){
					pq.push({dist[nxt] = cdist + cost, nxt});
				}
			}
		}
		return dist;
	};
    auto dist1 = dijk(1);
	int mnb = 1 << 30, mna = 1 << 30, mnai = -1, mnbi = -1;
	for(int i = 1; i <= n; i++){
		if(dist1[i] == (1 << 30)) continue;
        if(A[i]){
			if(mna > A[i]) mna = A[i], mnai = i;
		}
		if(B[i]){
			if(mnb > B[i]) mnb = B[i], mnbi = i;
		}
	}
    auto dist2 = dijk(mnai), dist3 = dijk(mnbi);
	int t1 = dist1[mnai] + dist2[mnbi] + dist3[1];
	int t2 = dist1[mnbi] + dist3[mnai] + dist2[1];
	cout << min<int>(t1, t2) << "\n";
}

void Main(){
    int t = 1; 
//ri(t);
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
