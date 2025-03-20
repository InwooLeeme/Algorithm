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

constexpr int INF = int(2e18);

int n, v[101010], p, q, r, S;

void Main(){
	cin >> n;
	for(int i = 0; i < n; i++) cin >> v[i];
	cin >> p >> q >> r >> S;
	int ok = 0, not_ok = INF;
	auto Check = [&](const int K) -> bool{
		int C = 0;
		for(int i = 0; i < n; i++){
			if(K + r < v[i]) C += (v[i] - p);
			else if(v[i] < K) C += (v[i] + q);
			else C += v[i];
		}
		return C < S;
	};
	while(ok + 1 < not_ok){
		int mid = ok + not_ok >> 1;
		if(Check(mid)) ok = mid;
		else not_ok = mid;
	}
	cout << (not_ok == INF ? -1 : not_ok) << "\n";
}

int32_t main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed); cout.precision(PRECISION);
    Main();
    return 0;
}
