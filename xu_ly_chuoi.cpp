#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    
    // Tính tổng theo công thức: Σ|ai + aj|
    long long sum = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            sum += abs(a[i] + a[j]);
        }
    }
    
    cout << sum << endl;
    
    return 0;
}
