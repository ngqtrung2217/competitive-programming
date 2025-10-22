#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll maxA = 1e7 + 5;
int n;
ll p[maxA];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
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
                p[i * i] = i * i;
        }
    }
    for (int i = 1; i < maxA; ++i)
        p[i] += p[i - 1];
    cin >> n;
    while (n--)
    {
        int x;
        cin >> x;
        cout << p[x] << ' ';
    }
}
