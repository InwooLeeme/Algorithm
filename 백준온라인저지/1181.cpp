// 1181번 : 단어 정렬

#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <string>
#include <list>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <tuple>
#include <functional>
#include <utility>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <complex>
#include <cassert>
#define X first
#define Y second
#define pb push_back
#define MAX 20001
#define INF 1000000000
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
using ll = long long;
using ull = unsigned long long;
using dbl = double;
using ldb = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;

string dict[MAX];

bool cmp(const string &a, const string &b)
{
    if (a.length() == b.length())
        return a < b;
    return a.length() < b.length();
}

int main()
{
    fastio;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> dict[i];
    }
    sort(dict, dict + n, cmp);
    string temp;
    for (int i = 0; i < n; i++)
    {
        if (dict[i] == temp)
            continue;
        cout << dict[i] << "\n";
        temp = dict[i];
    }
    return 0;
}