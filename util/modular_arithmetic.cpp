#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define ll long long
#define nl cout << "\n"
#define int long long
#define nl cout << "\n"
const ll M = 1e9+7;

// calculate a^b % MOD using binary expo.
ll power(ll a, ll b)
{
    a = a % M;
    ll res = 1;
    while (b)
    {
        if (b & 1)
            res = (a*res)%M ;
        a = (a*a)%M;
        b >>= 1;
    }
    return res;
}


// finds modular inverse of a w.r.t M
ll modularInverse(ll a) {return power(a, M - 2);}

// modular arithmetic