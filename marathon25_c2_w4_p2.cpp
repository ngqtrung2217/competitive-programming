#include <bits/stdc++.h>
#define int ll
using namespace std;
using ll = long long;
const int maxN = 1e5 + 5;
const int maxRGB = 255;
int n, k;
int r[maxN], g[maxN], b[maxN];
int cnt[maxRGB + 5][maxRGB + 5][maxRGB + 5];
int x_best, y_best, z_best;

int get(int x, int y, int z)
{
    if (x < 0 || y < 0 || z < 0 || x > maxRGB || y > maxRGB || z > maxRGB)
        return 0;
    return cnt[x][y][z];
}

int sum3(int x1, int y1, int z1, int x2, int y2, int z2)
{
    return get(x2, y2, z2) - get(x1 - 1, y2, z2) - get(x2, y1 - 1, z2) + get(x1 - 1, y1 - 1, z2) - get(x2, y2, z1 - 1) + get(x1 - 1, y2, z1 - 1) + get(x2, y1 - 1, z1 - 1) - get(x1 - 1, y1 - 1, z1 - 1);
}

bool check(int d)
{
    for (int i = 0; i + d <= 255; ++i)
        for (int j = 0; j + d <= 255; ++j)
            for (int u = 0; u + d <= 255; ++u)
                if ((ll)sum3(i, j, u, min(i + d, maxRGB), min(j + d, maxRGB), min(u + d, maxRGB)) >= k)
                {
                    x_best = i;
                    y_best = j;
                    z_best = u;
                    return true;
                }
    return false;
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> r[i] >> g[i] >> b[i];
        cnt[r[i]][g[i]][b[i]]++;
    }
    for (int i = 0; i <= maxRGB; i++)
        for (int j = 0; j <= maxRGB; j++)
            for (int u = 0; u <= maxRGB; u++)
                cnt[i][j][u] += get(i - 1, j, u) + get(i, j - 1, u) - get(i - 1, j - 1, u) + get(i, j, u - 1) - get(i - 1, j, u - 1) - get(i, j - 1, u - 1) + get(i - 1, j - 1, u - 1);
    int left = 0, right = maxRGB;
    while (left <= right)
    {
        int mid = left + right >> 1;
        if (check(mid))
            right = mid - 1;
        else
            left = mid + 1;
    }
    cout << left << "\n";
    for (int i = 1; i <= n; ++i)
        if (x_best <= r[i] && r[i] <= x_best + left &&y_best <= g[i] && g[i] <= y_best + left && z_best <= b[i] &&  b[i] <= z_best + left)
            if (k-- > 0)
                cout << i << " ";
}
