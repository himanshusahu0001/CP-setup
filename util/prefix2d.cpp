#include <bits/stdc++.h> 
#include<iostream>
using namespace std;
#define TESTS int test;cin>>test;while(test--)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define ll long long
// #define int(x) toInt(x)
template<class T> int toInt(T x){return x;}
#define int long long
#define nl cout << "\n"
const ll M = 1e9+7;

void solve();
int32_t main()
{

// #ifndef ONLINE_JUDGE
//     freopen("in.txt", "r", stdin);
//     freopen("out.txt", "w", stdout);
// #endif


// #ifndef ONLINE_JUDGE
//     freopen("maxcross.in", "r", stdin);
//     freopen("maxcross.out", "w", stdout);
// #endif

   	ios_base::sync_with_stdio(false);
	cin.tie(0);

    // TESTS
    solve();
    
}

#define N 1010
int pre[N][N];
char arr[N][N];

void solve() {
    // memset(pre, sizeof(pre), 0LL);
    for(int i=0; i<N; i++) pre[i][0] = pre[0][i] =0;

    int n,q; cin>>n>>q;
    // for(int i=1; i<=n; i++)
    // for(int j=1; j<=n; j++){
    //     cin>>arr[i][j];
    // }

    for(int i=1; i<=n; i++)
    for(int j=1; j<=n; j++){
        char x; cin>>x;

        pre[i][j] = (x=='*') + 
            pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1];
    }

    // for(int i=1; i<=n; i++){
    //     for(int j=1; j<=n; j++){
    //         cout << pre[i][j] << " ";
    //     }
    //     nl;
    // }
    




    while(q--){
        int a,b,c,d; 
        cin>>a>>b>>c>>d;
        a--,b--;
        auto ans = pre[c][d] +  pre[a][b] - pre[c][b] - pre[a][d] ;
        cout << ans;
        nl;
    }



}