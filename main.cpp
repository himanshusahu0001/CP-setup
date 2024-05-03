#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define int long long
#define nl cout<<"\n";

void solve();
int32_t main()
{
#ifndef ONLINE_JUDGE
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    int test;
    cin >> test;
    while (test--)
    {
        solve();
    }
}

void solve()
{
    int n; cin>>n;
    int r[n], a[n];
    for(int i=1; i<n; i++){
        cin>> r[i];
    }
    
    /*
            2    4    1
        1000 1002 1006  1007 
    */

   a[0] = 1000;
   for(int i=1; i<n;i++){
        a[i] = r[i] + a[i-1]; 
   }

    for(auto e : a) cout << e << " " ;nl;

}
