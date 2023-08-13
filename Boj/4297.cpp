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

template <size_t sz>
struct FenwickTree
{
    vector<int> tree;
    FenwickTree() : tree(sz + 1) {}
    void update(int i, int val)
    {
        for (; i <= sz; i += i & -i)
            tree[i] += val;
    }
    int query(int i)
    {
        int ret = 0;
        for (; i; i -= i & -i)
            ret += tree[i];
        return ret;
    }
};

void Main(){
	int n; 
	while(cin >> n and n){
		int ret = 0;
		FenwickTree<500101> FT;
		vector<int> cod;
		vector<int> v(n + 1),idx(500101);
		for(int i = 1; i <= n; i++){
			cin >> v[i];
			cod.push_back(v[i]);
		}
		auto IDX = [&](int x) -> int{ return lower_bound(cod.begin(), cod.end(), x) - cod.begin() + 1;};
		sort(cod.begin(), cod.end());
		cod.erase(unique(cod.begin(), cod.end()), cod.end());
		for(int i = 1; i <= n; i++) idx[i] = IDX(v[i]);
		for(int i = n; i >= 1; i--){
			auto t = idx[i];
			ret += FT.query(t - 1);
			FT.update(t, 1);
		}
		cout << ret << "\n";
	}	
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout.setf(ios::fixed); cout.precision(PRECISION);
    Main();
	return 0;
}
