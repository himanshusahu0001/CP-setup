#include <bits/stdc++.h>
using namespace std;

int main()
{
    // For getting input from "input.txt"
    freopen("in.txt", "r", stdin);

    // For printing the output to "output.txt" file
    freopen("out.txt", "w", stdout);

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    for (auto e : arr)
    {
        cout << e << " ";

    }
}
