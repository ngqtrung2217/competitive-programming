#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll maxA = 1e12 + 5;
const ll maxSpecialNumber = 1e3 + 5;
int n;
ll a[maxSpecialNumber], b[maxSpecialNumber];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int cnt = 0;
    ll sqrtA = (int)sqrt(maxA);
    for (int i = 1; i <= sqrtA; ++i)
    {
        ll u, v, temp;
        u = i * i;
        v = 0;
        temp = 1;
        while (u / 10 != 0)
        {
            v += u % 10 * temp;
            u /= 10;
            temp *= 10;
            if ((u + v) * (u + v) == i * i)
                a[++cnt] = i * i;
        }
    }
    for (int i = 1; i <= cnt; ++i)
        b[i] = a[i] + b[i - 1];
    cin >> n;
    while (n--)
    {
        int x;
        cin >> x;
        cout << b[upper_bound(a + 1, a + cnt + 1, x) - a - 1] << " ";
    }
}
