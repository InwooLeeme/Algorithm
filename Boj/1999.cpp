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


const int PRECISION = 0;

int n,m,k;
int p[255][255][255];

void Main(){
    cin >> n >> m >> k;
	for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++){
		int t; cin >> t;
		p[t][i][j]++;
	}
	for(int x = 0; x < 251; x++){
		for(int j = 1; j <= n; j++) for(int i = 1; i <= n; i++){
			p[x][i][j] += p[x][i - 1][j];
		}
		for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++){
			p[x][i][j] += p[x][i][j - 1];
		}
	}
	while(k--){
		int r1,c1; cin >> r1 >> c1;
		int mn = 1000, mx = -1000;
		for(int x = 0; x <= 250; x++){
			int r2 = r1 + m - 1, c2 = c1 + m - 1;
			int I = p[x][r2][c2] - p[x][r1 - 1][c2] - p[x][r2][c1 - 1] + p[x][r1 - 1][c1 - 1];
			if(I){
				mn = min<int>(mn, x); mx = max<int>(mx, x);
			}
		}
		cout << (mx - mn) << "\n";
	}
}

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed); cout.precision(PRECISION);
    Main();
    return 0;
}
