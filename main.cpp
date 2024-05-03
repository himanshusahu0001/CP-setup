#include <bits/stdc++.h>
#define tests    \
    int test;    \
    cin >> test; \
    while (test--)
using namespace std;

#define all(x) x.begin(), x.end()
#define int long long
#define nl cout << "\n";

void solve();
int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    tests
    solve();
}

void solve()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}
