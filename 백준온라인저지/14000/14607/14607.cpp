// 14607번 : 피자(Large)

#include <iostream>
#include <deque>
#include <vector>
#include <queue>
#include <algorithm>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define max 1001
#define INF 1e9
#define ll long long
using namespace std;

ll n;

int main()
{
    fastio;
    cin >> n;
    printf("%lld", (n * (n - 1)) / 2);
    return 0;
}