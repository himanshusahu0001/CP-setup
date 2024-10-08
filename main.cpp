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

// const int N=3*1e5+10;
// int arr[N];

void solve() {

    int n,q; 
    cin>>n>>q;

    vector<int> uniqu; uniqu.push_back(0);
    vector<tuple<int,int,int>> updates;
    for(int i=0; i<n; i++){
        int l,r,v; cin>>l>>r>>v;
        updates.push_back({l,r,v});
            uniqu.push_back(l);
            uniqu.push_back(r);
    }

    vector<tuple<int,int>> queries;
    for(int i=0; i<n; i++){
        int l,r; cin>>l>>r;
        queries.push_back({l,r});
            uniqu.push_back(l);
            uniqu.push_back(r);
    }

    sort(all(uniqu));
    uniqu.erase(unique(all(uniqu)), uniqu.end());
    // for(auto e : uniqu) cout << e << " "; nl;


    // apply updates
    // memset(arr,0,sizeof(arr));
    vector<int> arr( uniqu.size()+1 ,0);
    for(auto [l,r,v] : updates){
        auto lll = lower_bound(all(uniqu), l) - uniqu.begin() ;
        auto rr = lower_bound(all(uniqu), r) - uniqu.begin() ;

        arr[lll] += v;
        arr[r+1] -= v;
    }
    

    // for(auto e : arr) cout << e << " "; nl;
    for(int i=1; i<arr.size(); i++) {
        arr[i] = arr[i] +  (arr[i-1] * (uniqu[i] - uniqu[i-1])) ;
    }
    // for(auto e : arr) cout << e << " "; nl;


    // process queries
    for(auto [l,r] : queries){
        auto lll = lower_bound(all(uniqu), l) - uniqu.begin() ;
        auto rr = lower_bound(all(uniqu), r) - uniqu.begin() ;

        int ans = arr[rr] - arr[lll-1];
        cout << ans;
        nl;
    }

  
}