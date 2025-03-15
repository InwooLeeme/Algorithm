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

int n,r;
int F[32]{1, 1, };
int mex[3'000'001];

void Main(){
	for(int i = 2; i < 32; i++) F[i] = F[i - 1] + F[i - 2];
	for(int i = 1; i <= 3'000'000; i++){
		vector<bool> vist(33);
		for(int j = 0; i - F[j] >= 0; j++){
			vist[mex[i - F[j]]] = 1;
		}
		for(int j = 0; ; j++){
			if(!vist[j]){
				mex[i] = j;
				break;
			}
		}
	}
	cin >> n;
	for(int i = 0,x; i < n; i++){
		cin >> x; r ^= mex[x];
		//cout << mex[x] << "\n";
	}
	cout << (r ? "koosaga" : "cubelover") << "\n";
}

int main(){
	ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed); cout.precision(PRECISION);
    Main();
    return 0;
}
