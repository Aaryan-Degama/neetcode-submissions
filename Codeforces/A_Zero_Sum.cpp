#include <bits/stdc++.h>
#include <numeric>


using namespace std;
using ll = long long;
using vl = vector<ll>;
using vi = vector<int>;
#define p  pair;
#define pb push_back;
#define um unordered_map;


void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (auto &x : a) cin >> x;

    if (n % 2) {
        cout << "NO\n";
        return;
    }

    int sum = accumulate(a.begin(), a.end(), 0);

    if (sum % 4 == 0)
        cout << "YES\n";
    else
        cout << "NO\n";
}


int main(){
    ll t = 1;
    cin >> t;
    while( t-- ){
        solve();
    }


    return 0;
}