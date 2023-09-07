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

using cpx = complex<double>;
constexpr int MOD = 100003;

void FFT(vector<cpx>& P, bool inv = 0) {
	const int n = P.size();
	vector<cpx> root(n / 2);
	for (int i = 1, j = 0; i < n; i++) {
		int bit = n >> 1;
		while (j >= bit) j -= bit, bit >>= 1;
		j += bit;
		if (i < j) swap(P[i], P[j]);
	}
	double ang = (inv ? -2 : 2) * acos(-1) / n;
	for (int i = 0; i < n / 2; i++) root[i] = cpx(cos(ang * i), sin(ang * i));
	for (int i = 2; i <= n; i *= 2) {
		for (int j = 0; j < n; j += i) for (int k = 0; k < i / 2; k++) {
			cpx u = P[j + k], v = P[j + k + i / 2] * root[n / i * k];
			P[j + k] = u + v;
			P[j + k + i / 2] = u - v;
		}
	}
	if (inv) for (int i = 0; i < n; i++) P[i] /= n;
}

vector<int> Mul(const vector<int>& a, const vector<int>& b) {
	int n = 1;
	while (n < a.size() + b.size() - 1) n <<= 1;
	vector<cpx> A(a.begin(), a.end()); A.resize(n);
	vector<cpx> B(b.begin(), b.end()); B.resize(n);
	FFT(A, 0), FFT(B, 0);
	for (int i = 0; i < n; i++) A[i] *= B[i];
	FFT(A, 1);
	vector<int> ret(a.size() + b.size() - 1);
	for (int i = 0; i < ret.size(); i++) ret[i] = (int)round(A[i].real()) % MOD;
	return ret;
}

vector<int> mul(const vector<vector<int>>& v, int l, int r){
    if(l == r) return v[l];
    int mid = l + r >> 1;
    return Mul(mul(v, l, mid), mul(v, mid + 1, r));
}

void Main(){
    int n; cin >> n;
    vector<vector<int>> v(n);
    for(int i = 0,t; i < n; i++){
        cin >> t;
        v[i] = {t, 1};
    }
    auto ret = mul(v, 0, n - 1);
    int q; cin >> q;
    while(q--){
        int x; cin >> x;
        cout << ret[n - x] << "\n";
    }
}

int32_t main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cout.setf(ios::fixed); cout.precision(PRECISION);
    Main();
    return 0;
}