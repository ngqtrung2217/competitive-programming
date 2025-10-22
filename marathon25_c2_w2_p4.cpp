#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll maxN = 1e3 + 5;
vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int n, m, q;
int a[maxN][maxN];
int maxL[maxN][maxN][4], ok[maxN][maxN];

void getMax(int i, int j, int p)
{
    int x, y;
    x = i + dir[p].first;
    y = j + dir[p].second;
    if (0 <= x && x <= n + 1 && 0 <= y && y <= m + 1)
        if (a[x][y] == 0)
            maxL[i][j][p] = max(maxL[i][j][p], maxL[x][y][p] + 1);
}

bool checkgiaonhau(int x, int y, int u, int v)
{
    if (y > v)
        swap(y, v);
    if (0 <= x && x <= n + 1 && 0 <= y && y <= m + 1)
        if (maxL[x][y][1] < v - y + 1)
            return false;
    return true;
}

bool check(int x, int y, int u, int v, int num)
{
    if ((a[x][y] != a[u][v]) || (a[x][y] == 0) || (a[u][v] == 0) || (x == u && y == v))
        return false;
    ok[x][y] = num;
    ok[u][v] = num;
    for (int p = 0; p < 4; ++p)
        for (int g = 1; g < maxL[x][y][p]; ++g)
        {
            int nx = x + dir[p].first * g;
            int ny = y + dir[p].second * g;
            ok[nx][ny] = num;
        }
    for (int p = 0; p < 4; ++p)
        for (int g = 1; g < maxL[u][v][p]; ++g)
        {
            int nx = u + dir[p].first * g;
            int ny = v + dir[p].second * g;
            if (ok[nx][ny] == num)
                return true;
        }
    for (int i = 0; i <= n + 1; ++i)
        if (ok[i][y] == num && ok[i][v] == num && checkgiaonhau(i, y, i, v))
            return true;
    for (int j = 0; j <= m + 1; ++j)
        if (ok[x][j] == num && ok[u][j] == num && checkgiaonhau(x, j, u, j))
            return true;
    return false;
}

void del(int x, int y)
{
    a[x][y] = 0;
    for (int i = 0; i <= n + 1; ++i)
        getMax(i, y, 2);
    for (int i = n + 1; i >= 0; --i)
        getMax(i, y, 0);
    for (int j = 0; j <= m + 1; ++j)
        getMax(x, j, 3);
    for (int j = m + 1; j >= 0; --j)
        getMax(x, j, 1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            char x;
            cin >> x;
            a[i][j] = (x == '0' ? 0 : x - 'A' + 1);
        }
    for (int i = 0; i <= n + 1; ++i)
        for (int j = 0; j <= m + 1; ++j)
            for (int p = 0; p < 4; ++p)
                maxL[i][j][p] = 1;
    for (int i = 0; i <= n + 1; ++i)
        for (int j = 0; j <= m + 1; ++j)
            for (int p = 0; p < 4; ++p)
                getMax(i, j, p);
    for (int i = n + 1; i >= 0; --i)
        for (int j = m + 1; j >= 0; --j)
            for (int p = 0; p < 4; ++p)
                getMax(i, j, p);
    for (int i = 1; i <= q; ++i)
    {
        int x, y, u, v;
        cin >> x >> y >> u >> v;
        if (check(x, y, u, v, i))
        {
            cout << "YES\n";
            del(x, y);
            del(u, v);
        }
        else
            cout << "NO\n";
    }
}
