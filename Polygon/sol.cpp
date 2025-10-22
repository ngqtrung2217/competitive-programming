#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll maxN = 1e5 + 5;
int n;
int a[maxN];

void sol()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    sort(a, a + n);
    if (a[0] == a[n - 1] || n <= 2)
    {
        cout << -1 << "\n";
        return;
    }
    swap(a[0], a[n - 1]);
    for (int i = 0; i < n; ++i)
        cout << a[i] << " ";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--)
        sol();
}
