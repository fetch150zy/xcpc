#include <bits/stdc++.h>

using namespace std;

bool is_prime(long long n)    {
    for (int i = 2; i * i <= n; ++i)    {
        if (n % i == 0) return false;
    }
    return true;
}

int main(void)    {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, i;
    // cin >> n;
    // for (int i = 2; i * i <= n; ++i)    {
    //     if (n % i == 0)    {
    //         maxn = i;
    //         while (n % i == 0) n /= i;
    //     }
    // }
    // if (n > 1) maxn = n;
    // cout << maxn << "\n";

    cin >> n;
    for (i = 2; i <= n; ++i)    {
        if (n % i == 0) break;
    }
    cout << n / i << endl;

    return 0;
}