#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll MOD = 1e9 + 7;

// Sinh test case và kiểm tra
void testCase(int testNum)
{
    srand(time(0) + testNum);
    int n = rand() % 10 + 2; // n từ 2 đến 11

    cout << "Test " << testNum << ": n = " << n << endl;
    cout << "Array: ";

    vector<ll> a(n);
    for (int i = 0; i < n; ++i)
    {
        a[i] = (rand() % 21) - 10; // Số từ -10 đến 10
        cout << a[i] << " ";
    }
    cout << endl;

    // Tính brute force
    ll bruteAns = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            ll sum = a[i] + a[j];
            ll cube = abs(sum);
            cube = (cube * cube % MOD * cube) % MOD;
            bruteAns = (bruteAns + cube) % MOD;
            cout << "|" << a[i] << " + " << a[j] << "| = " << abs(sum) << ", cube = " << (abs(sum) * abs(sum) % MOD * abs(sum)) % MOD << endl;
        }
    }

    cout << "Result: " << bruteAns << endl;
    cout << "-------------------" << endl;
}

int main()
{
    // Sinh 3 test case
    for (int i = 1; i <= 3; ++i)
    {
        testCase(i);
    }

    // Test case cụ thể với số âm và dương
    cout << "Manual test case:" << endl;
    vector<ll> test = {-3, -1, 2, 5};
    cout << "Array: ";
    for (ll x : test)
        cout << x << " ";
    cout << endl;

    ll ans = 0;
    for (int i = 0; i < test.size(); ++i)
    {
        for (int j = i + 1; j < test.size(); ++j)
        {
            ll sum = test[i] + test[j];
            ll cube = abs(sum);
            cube = (cube * cube % MOD * cube) % MOD;
            ans = (ans + cube) % MOD;
            cout << "|" << test[i] << " + " << test[j] << "| = " << abs(sum) << ", cube = " << cube << endl;
        }
    }
    cout << "Result: " << ans << endl;

    return 0;
}
