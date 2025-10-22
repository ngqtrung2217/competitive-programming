#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll maxN = 5e5 + 5;
int n, k;
int a[maxN];
map<int, int> mp;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> k;
    int l = 1, ans = 0, cnt = 0;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a[i];
        if (mp[a[i]]++ == 0)
            cnt++;
        while (cnt > k)
        {
            if (--mp[a[l++]] == 0)
                cnt--;
        }
        ans = max(ans, i - l + 1);
    }
    cout << ans;
}
