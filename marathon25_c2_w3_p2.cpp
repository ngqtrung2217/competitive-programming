#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll mod = 1e9 + 7;

ll gcd(ll a, ll b)
{
    while (a != 0 && b != 0)
    {
        if (a > b)
            a %= b;
        else
            b %= a;
    }
    return a + b;
}

ll lcm(ll a, ll b)
{
    return a / gcd(a, b) * b;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t, n;
    cin >> t;
    while (t--)
    {
        cin >> n;
        ll g = 1, ans = 0;
        for (int i = 1; g <= n; ++i)
        {
            g = lcm(g, i);
            if (g > n)
                break;
            ans += n / g;
        }
        cout << (ans + n) % mod << '\n';
    }
}
