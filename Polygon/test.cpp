#include <bits/stdc++.h>
using namespace std;

double avg(int n)
{
    if (n == 1)
        return 1;
    else {
        int sum = n + avg(n - 1);
        return sum / n;
    }
}

int main ()
{
    for (int i = 2;i <= 10;++i)
        cout << "=SUM(E" << i << ":G" << i << ")\n";
}
