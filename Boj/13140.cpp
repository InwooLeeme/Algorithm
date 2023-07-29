#pragma GCC target("avx,avx2,fma")
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

#define FORN(a, b, c) for (char(a) = (b); (a) <= (c); ++(a))

void Sol(){
	int n; scanf("%d", &n);
	FORN(h, 1, 9) FORN(e, 0, 9) FORN(l, 0, 9) FORN(o, 0, 9) FORN(w, 1, 9) FORN(r, 0, 9) FORN(d, 0, 9){
		int s = 10000 * h + 1000 * e + 120 * l + o * 1001 + w * 10000 + r * 100 + d;
		if (h == e || h == l || h == o || h == w || h == r || h == d || e == l || e == o || e == w || e == r || e == d || l == o || l == w || l == r || l == d || o == w || o == r || o == d || w == r || w == d || r == d) 
			continue;
		if(s == n){
			printf("  %d%d%d%d%d\n", h, e, l, l, o);
			printf("+ %d%d%d%d%d\n", w, o, r, l, d);
			printf("-------\n");
			printf("%7d", n);
			return;
		}
	}
	cout << "No Answer" << '\n';
}

int32_t main(){
    //ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    //cout.setf(ios::fixed); cout.precision(PRECISION);
    Sol();
    return 0;
}
