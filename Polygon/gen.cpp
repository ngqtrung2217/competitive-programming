#include <bits/stdc++.h>
#include "testlib.h"

using namespace std;

int main(int argc, char *argv[])
{
    registerGen(argc, argv, 1);
    int sub = atoi(argv[1]);
    int n, k;
    int Rl, Rr, Gl, Gr, Bl, Br;
    Rl = Gl = Bl = 0;
    Rr = Gr = Br = 255;
    if (sub == 1)
    {
        n = rnd.next(2, 20);
        k = rnd.next((int)2, (int)abs(n));
    }
    else if (sub == 2)
    {
        Rl = Gl = Bl = 0;
        Rr = rnd.next((int)0, (int)20);
        Gr = rnd.next((int)0, (int)20);
        Br = rnd.next((int)0, (int)20);
        n = rnd.next((int)2, (int)100000);
        k = rnd.next((int)2, (int)abs(n));
    }
    else if (sub == 3)
    {
        Rl = Gl = Bl = 0;
        Rr = rnd.next((int)0, (int)50);
        Gr = rnd.next((int)0, (int)50);
        Br = rnd.next((int)0, (int)50);
        n = rnd.next((int)5000, (int)100000);
        k = rnd.next((int)2, (int)abs(n));
    }
    else
    {
        Rl = Gl = Bl = 0;
        Rr = Gr = Br = 255;
        n = rnd.next((int)10000, (int)100000);
        k = rnd.next((int)2, (int)abs(n));
    }
    cout << n << " " << k << "\n";
    for (int i = 0; i < n; ++i)
    {
        int r = rnd.next(Rl, Rr);
        int g = rnd.next(Gl, Gr);
        int b = rnd.next(Bl, Br);
        cout << r << " " << g << " " << b << "\n";
    }
//    cout << "\n";
}
