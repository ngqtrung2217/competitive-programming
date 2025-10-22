#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll maxN = 1e7 + 5;
int n;
ll p[maxN], mu[10];

ll check(int x) {
    int y = (int)sqrt(x);;
    if (y * y != x) return 0;   
    for (int i = 0;i < 10;++i)
        if ((x . ))
}

int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    mu[0] = 1;
    for (int i = 1;i < 10;++i)
        mu[i] = mu[i - 1] * 10;
    for (int i = 0;i < maxN;++i)
        p[i] = p[i - 1] + check(i);
    cin >> n;
}