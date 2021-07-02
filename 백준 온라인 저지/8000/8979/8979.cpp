// 8979번 : 올림픽

#include <iostream>
#include <algorithm>
#include <vector>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

typedef struct
{
    int countryName;
    int gold;
    int sliver;
    int bronze;
} Country;
int n, k;

int compare(Country c1, Country c2)
{
    // 금메달 점수가 같다면 은메달 수가 더 많은 나라 정렬
    if (c1.gold == c2.gold)
    {
        // 금, 은메달 수가 모두 같으면, 동메달 수가 더 많은 나라
        if (c1.sliver == c2.sliver)
        {
            if (c1.bronze == c2.bronze)
            {
                return c1.countryName == k;
            }
            return c1.bronze > c2.bronze;
        }
        return c1.sliver > c2.sliver;
    }
    return c1.gold > c2.gold;
}

int main()
{
    vector<Country> country;
    cin >> n >> k;
    country.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> country[i].countryName >> country[i].gold >> country[i].sliver >> country[i].bronze;
    }
    sort(country.begin(), country.end(), compare);
    for (int i = 0; i < country.size(); i++)
    {
        if (country[i].countryName == k)
        {
            cout << i + 1 << '\n';
            return 0;
        }
    }
    return 0;
}
