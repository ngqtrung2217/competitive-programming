#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll mod = 1e9 + 7;
const int maxN = 1e5 + 5;

int n;
ll a[maxN];
ll p1[maxN], p2[maxN], p3[maxN];

ll mul(ll x, ll y)
{
    return (x * y) % mod;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("CUBESUM.inp", "r", stdin);
    freopen("CUBESUM.out", "w", stdout);

    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    sort(a + 1, a + n + 1);

    for (int i = 1; i <= n; ++i)
    {asdasdasdasdads
        p1[i] = (p1[i - 1] + a[i]) % mod;
        p2[i] = (p2[i - 1] + mul(a[i], a[i])) % mod;
        p3[i] = (p3[i - 1] + mul(mul(a[i], a[i]), a[i])) % mod;
    }

    ll ans = 0;
    for (int i = 1; i <= n; ++i)
    {
        int l = i + 1, r = n, split = i;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (a[mid] < -a[i])
            {
                split = mid;
                l = mid + 1;
            }
            else
                r = mid - 1;
        }asdasdas

        if (split >= i + 1)
        {
            int cnt = split - i;
            ll s1 = (p1[split] - p1[i] + mod) % mod;
            ll s2 = (p2[split] - p2[i] + mod) % mod;
            ll s3 = (p3[split] - p3[i] + mod) % mod;

            ll ai2 = mul(a[i], a[i]);
            ll ai3 = mul(ai2, a[i]);
            ll S = (mul(cnt, ai3) + mul(3, mul(ai2, s1)) + mul(3, mul(a[i], s2)) + s3) % mod;
            ans = (ans - S + mod) % mod;
        }

        if (split + 1 <= n)
        {
            int cnt = n - split;
            ll s1 = (p1[n] - p1[split] + mod) % mod;
            ll s2 = (p2[n] - p2[split] + mod) % mod;
            ll s3 = (p3[n] - p3[split] + mod) % mod;

            ll ai2 = mul(a[i], a[i]);
            ll ai3 = mul(ai2, a[i]);
            ll S = (mul(cnt, ai3) + mul(3, mul(ai2, s1)) + mul(3, mul(a[i], s2)) + s3) % mod;
            ans = (ans + S) % mod;
        }
    }

    ll ans1 = 0;
    for (int i = 1;i <= n;++i)
        for (int j = i + 1;j <= n;++j)

    cout << ans << "\n";
    return 0;
}
