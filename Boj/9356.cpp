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
const int MOD = int(1e9) + 7;

/*
자릿수가 감소하지 않는다
ex) N = 2
0_ -> (1 ~ 9)C1 ..
1_ -> (2 ~ 9)C1..
....
10(0 ~ 9)를 뽑는 경우의 수 + (자릿수 N) - 1 C n 이 답이된다 -> 중복조합
=> (10+n-1)Cn
*/

int f[100001];

// mod inverse
int nCr(int x,int y){
	int p = MOD - 2;
	for(; p; p >>= 1){
		if(p & 1) x = x * y % MOD;
		y = y * y % MOD;
	}
	return x;
}

void Main(){
    f[0] = 1;
    for(int i = 1; i <= 100000; i++) f[i] = i * f[i - 1] % MOD;
    int t; cin >> t; while(t--){
        int n; cin >> n;
        cout << nCr(f[10 + n - 1], f[n] * f[10 + n - 1 - n] % MOD) << "\n";
    }
}

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed); cout.precision(PRECISION);
    Main();
    return 0;
}