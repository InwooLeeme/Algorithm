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

// ref : https://ei1333.github.io/library/graph/flow/hungarian.hpp
template<typename T>
pair<T, vector<T>> Hungarian(vector<vector<T>>& A){
	const T INF = T(2e18);
	const int N = (int)A.size();
	const int M = (int)A[0].size();
	vector<int> P(M), way(M);
	vector<T> U(N, 0), V(M, 0), minV;
	vector<bool> used;
	
	for(int i = 1; i < N; i++){
		P[0] = i;
		minV.assign(M, INF);
		used.assign(M, false);
		int j0 = 0;
		while(P[j0] != 0){
			int i0 = P[j0], j1 = 0;
			used[j0] = 1;
			T delta = INF;
			for(int j = 1; j < M; j++){
				if(used[j]) continue;
				T cur = A[i0][j] - U[i0] - V[j];
				if(cur < minV[j]) minV[j] = cur, way[j] = j0;
				if(minV[j] < delta) delta = minV[j], j1 = j;
			}
			for(int j = 0; j < M; j++){
				if(used[j]) U[P[j]] += delta, V[j] -= delta;
				else minV[j] -= delta;
			}
			j0 = j1;
		}
		do{
			P[j0] = P[way[j0]];
			j0 = way[j0];
		}while(j0 != 0);
	}
	return {-V[0], P};
}

void solve(){
    constexpr int INF = int(2e18);
    int n; cin >> n;
    vector<vector<int>> d(n + 1, vector<int>(n + 1, INF));
    vector<vector<int>> c(n + 1, vector<int>(n + 1, INF));
    for(int i = 1; i <= n; i++){
        for(int j = i + 1; j <= n; j++){
            int x; cin >> x;
            d[i][j] = d[j][i] = x;
        }
    }
    for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++){
        if(i == j) c[i][j] = INF;
        else c[i][j] = d[i][j];
    }
    auto res = Hungarian<int>(c);
    cout << res.first << "\n";
}

void Main(){
    int t; cin >> t;
    for(int tc = 1; tc <= t; tc++){
        cout << "Case " << tc << ": "; solve();
    }
}

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed); cout.precision(PRECISION);
    Main();
    return 0;
}
