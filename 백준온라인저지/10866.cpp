// 10866번 : 덱

#include <bits/stdc++.h>
#define X first
#define Y second
#define pb push_back
#define sz(a) int((a).size())
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define MAX(a, b) (((a) > (b)) ? (a) : (b))
using namespace std;
using ll = long long;
using ull = unsigned long long;
using dbl = double;
using ldb = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using wector = vector<vector<int>>;
using tiii = tuple<int, int, int>;

int main()
{
    fastio;
    int tc, t;
    cin >> tc;
    string s;
    deque<int> dq;
    while (tc--)
    {
        cin >> s;
        if (s == "push_front")
            cin >> t, dq.push_front(t);
        else if (s == "push_back")
            cin >> t, dq.push_back(t);
        else if (s == "pop_front")
            cout << (dq.empty() ? -1 : dq.front()) << "\n", dq.size() ? dq.pop_front() : void();
        else if (s == "pop_back")
            cout << (dq.empty() ? -1 : dq.back()) << "\n", dq.size() ? dq.pop_back() : void();
        else if (s == "size")
            cout << dq.size() << "\n";
        else if (s == "empty")
            cout << dq.empty() << "\n";
        else if (s == "front")
            cout << (dq.empty() ? -1 : dq.front()) << "\n";
        else if (s == "back")
            cout << (dq.empty() ? -1 : dq.back()) << "\n";
    }
    return 0;
}