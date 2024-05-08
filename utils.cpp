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


// still there are small chances of hash-collisions  
// so check that too 
class HashedString{
public:    
    vector<ll> ps,psi, hash;
    // change p and M if needed
    ll p = 31; // a prime number
    // const ll M = 1e9+7; 

    HashedString(string &s){
        ll n = s.size();
        ps = vector<ll>(n,1);
        psi = vector<ll>(n);
        hash = vector<ll>(n);

        for(ll i=1; i<n; i++)
            ps[i] = (ps[i-1] * p )%M;
        
        for(ll i=0; i<n; i++)
            psi[i] = modularInverse(ps[i]);
        
        hash[0] = (ctoi(s[0]) * ps[0])%M;
        for(ll i=1; i<n; i++)
            hash[i] =  (hash[i-1] + (ctoi(s[i]) * ps[i])%M ) %M;
        
    }


    // change it as per need
    ll ctoi(char c){
        // return int(c-'a'+1);
        return c;
    }

    // get hash value of substring that starts at i and ends at j
    ll getHash(int i, int j){
        if(i == 0)
            return hash[j];

        return (
            ((hash[j]-hash[i-1]+M) % M)
            * psi[i]
        ) % M;
    }

    // start index and length of sub-string
    ll getHashFromLen(int i, int len){
        return getHash(i, i+len-1);
    }
};

