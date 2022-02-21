#pragma GCC target("avx,avx2,fma")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define int int64_t
using namespace std;

pair<char, char> Tree[27];

void preOrder(char root) // 전위 순회
{
    if (root == '.')
        return;
    auto [left, right] = Tree[root - 'A'];
    cout << root;
    preOrder(left);
    preOrder(right);
}

void inOrder(char root) // 중위 순회
{
    if (root == '.')
        return;
    auto [left, right] = Tree[root - 'A'];
    inOrder(left);
    cout << root;
    inOrder(right);
}

void postOrder(char root) // 후위 순회
{
    if (root == '.')
        return;
    auto [left, right] = Tree[root - 'A'];
    postOrder(left);
    postOrder(right);
    cout << root;
}

int32_t main()
{
    fastio;
    int n;
    cin >> n;
    while (n--)
    {
        char a, b, c;
        cin >> a >> b >> c;
        Tree[a - 'A'] = {b, c};
    }
    preOrder('A');
    cout << "\n";
    inOrder('A');
    cout << "\n";
    postOrder('A');
    cout << "\n";
}