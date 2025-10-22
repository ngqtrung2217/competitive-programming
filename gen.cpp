#include <bits/stdc++.h>
#include "testlib.h"
using namespace std;
using ll = long long;
vector<pair<int, int>> b[26];
vector<int> p;

const ll maxN = 1e3 + 5;
vector<pair<int, int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int n, m, q;
int L, R;
int a[maxN][maxN];
int maxL[maxN][maxN][4], ok[maxN][maxN], cnt;

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

void solve()
{
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
}

int get(int x1, int y1, int x2, int y2)
{
    if (cnt == 100)
        cnt = 1;
    //    cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << "\n";
    if (check(x1, y1, x2, y2, cnt++))
    {
        del(x1, y1);
        del(x2, y2);
        //        cout << "hehehehehe\n";
        return 1;
    }
    return rnd.next(1, (int)max(1000000, 1000000000 / n / m / (L + 1) / (R + 1))) <= 1 ? 1 : 0;
}

int main(int argc, char *argv[])
{
    registerGen(argc, argv, 1);
    int sub = atoi(argv[1]);
        sub = 3;
    L = rnd.next(0, 24);
    R = rnd.next(L + 1, 25);
    if (sub == 1)
    {
        n = rnd.next(1, 5);
        m = rnd.next(1, 5);
        q = rnd.next(1, 10);
        L = 0;
        R = 2;
    }
    else if (sub == 2)
    {
        n = rnd.next(10, 20);
        m = rnd.next(10, 20);
        q = 1;
        L = 0;
        R = 5;
    }
    else if (sub == 3)
    {
        n = rnd.next(100, 1000);
        m = rnd.next(100, 1000);
        q = rnd.next(40, 50);
        L = 0;
        R = 10;
    }
    else
    {
        n = rnd.next(900, 1000);
        m = rnd.next(900, 1000);
        q = rnd.next((int)1e4, (int)5e4);
        if (rnd.next(1, 100) == 1)
            R = max(25, L + 3);
    }
    cout << n << " " << m << " " << q << "\n";
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            int x = rnd.next(0, 27);
            if (x > 25)
                cout << (a[i][j] = 0);
            else
            {
                x = rnd.next((int)L, (int)R);
                cout << char(x + 'A');
                a[i][j] = x;
                b[x].push_back({i, j});
                p.push_back(x);
            }
        }
        cout << "\n";
    }
    cnt = 1;
    solve();
    bool flag;
    for (int i = 0; i < q; ++i)
    {
        flag = 0;
        while (1)
        {
            if (flag)
                break;
            //            cout << p.size() << " ";
            int rd = rnd.next(1, (int)max(200000, 20000000 / n / m / (L + 1) / (R + 1)));
            if (rd == 1 || p.size() < 2)
            {
                cout << rnd.next(1, n) << " " << rnd.next(1, m) << " " << rnd.next(1, n) << " " << rnd.next(1, m) << "\n";
                flag = 1;
                break;
            }
            else
            {
                int x, y;
                y = rnd.next(0, (int)p.size() - 1);
                x = p[y];
                for (int u = 0; u < b[x].size() - 1; ++u)
                {
                    if (flag)
                        break;
                    for (int v = u + 1; v < b[x].size(); ++v)
                    // int u, v;
                    {
                        if (flag)
                            break;
                        u = rnd.next(0, (int)b[x].size() - 1);
                        v = rnd.next(0, (int)b[x].size() - 1);
                        int x1 = b[x][u].first, y1 = b[x][u].second, x2 = b[x][v].first, y2 = b[x][v].second;
                        if (get(x1, y1, x2, y2))
                        {
                            cout << x1 << " " << y1 << " " << x2 << " " << y2 << "\n";
                            swap(p[p.size() - 1], p[y]);
                            p.pop_back();
                            //                            cout << "asdasd " << p.size() << " ";
                            flag = 1;
                            break;
                        }
                    }
                }
            }
        }
    }
}
//    cout << get(1, 1, 1, 2);
