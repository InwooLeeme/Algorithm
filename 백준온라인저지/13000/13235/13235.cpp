// 13235번 : 팰린드롬

#include <iostream>
#include <deque>
#include <vector>
#include <queue>
#include <string>    // string
#include <algorithm> // reverse
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int main()
{
    fastio;
    string a;
    cin >> a;
    string b = a;
    reverse(a.begin(), a.end());
    if (b == a)
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }
    return 0;
}