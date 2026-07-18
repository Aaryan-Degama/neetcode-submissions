#include <bits/stdc++.h>
#include <numeric>


using namespace std;
using ll = long long;
using vl = vector<ll>;
using vi = vector<int>;
#define p  pair;
#define pb push_back;
#define um unordered_map;

void pri(bool x){
    if(x)
        cout<< "YES"<<'\n';
    else
        cout<<"NO"<<'\n';
}



void solve(){
    ll n,k,m;
    cin>> n>> k>> m;
    if( m < k ){
        pri(0);
        return;
    }
    
    pri(1);
    vl ak(k, 1);
    

    ak[k-1] = m - k + 1;
    
    
    for(int i = 0; i < n; i++){
        cout<< ak[i%k]<<' ';
    }
    
    cout<<"\n";

}


int main(){
    ll t = 1;
    cin >> t;
    while( t-- ){
        solve();
    }


    return 0;
}