// 10824번 : 네 수(브론즈 3)

#include <iostream>
#include <algorithm>
#include <string>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long
using namespace std;

int main()
{
    fastio;
    string a, b, c, d, tempA, tempB;
    cin >> a >> b >> c >> d;
    tempA = a + b;
    tempB = c + d;
    ll result = stoll(tempA) + stoll(tempB);
    cout << result;
    return 0;
}