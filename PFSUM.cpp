#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e5 + 5;
int n;
int a[maxN], ans;

void add(int x)
{
    a[x]++;
    if (a[x] == 10)
    {
        a[x] = 0;
        add(x + 1);
    }
    ans = max(ans, x);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("PFSUM.inp", "r", stdin);
    freopen("PFSUM.out", "w", stdout);

    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        add(x);
        cout << ans << " ";
    }
}
