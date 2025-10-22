#include <bits/stdc++.h>
using namespace std;
const int maxN = 1e5 + 5;
const int maxM = 1e5 + 5;
int n, m;
bool a[maxN];

string reverse(string s)
{
    string res;
    for (int i = s.size() - 1; i >= 0; --i)
        res.push_back(s[i]);
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        char c;
        cin >> c;
        a[c - 'a' + 1] = true;
    }
    sort(a + 1, a + n + 1);
    cin >> m;
    for (int i = 1; i <= m; ++i)
    {
        string s, ans, temp;
        bool flag = true;
        cin >> s;
        for (int j = 0; j < s.size(); ++j)
        {
            if (flag)
            {
                if (a[s[j] - 'a' + 1])
                {
                    cout << reverse(temp);
                    temp = "";
                }
                else
                {
                    temp.push_back(s[j]);
                }
            }
            else
            {
                if (a[s[j] - 'a' + 1])
                {
                    flag = true;
                }
                else
                    cout << s[j];
            }
        }
        cout << reverse(temp);
        cout << "\n";
    }
}
