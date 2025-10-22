#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const ll maxN = 1e6 + 5;
ll g[maxN];
unordered_map<ll, ull> dp;
vector<ll> cubes;

ull f(ull n)
{
    if (n <= 0)
        return 0;
    auto it = dp.find(n);
    if (it != dp.end())
        return it->second;

    ll k = upper_bound(cubes.begin(), cubes.end(), n) - cubes.begin() - 1;
    ll c = cubes[k];
    ll cnt = n - c + 1;

    ull res = f(c - 1) + cnt + f(n - c);
    return dp[n] = res;
}

ll calc(ll n)
{
    if (n == 0) return 0;
    ll c = cbrt(n);
    return 1 + calc(n - c * c * c);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    for (int i = 1;i < maxN;++i)
        g[i] = g[i - 1] + calc(i);
    for (ll i = 1; i * i * i <= (ll)1e16; ++i)
        cubes.push_back(i * i * i);
    dp.reserve(cubes.size() * 2);
    ll t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;

        cout << g[n] << '\n';
//        cout << f(n) << '\n';
    }
}
