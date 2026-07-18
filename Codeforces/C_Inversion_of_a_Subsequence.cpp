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
    ll n;
    cin>>n;
    vi a(n),b(n);

    for (auto& i: a){
        cin>>i;
    }
    for(auto& i: b){
        cin>> i;
    }

    int ab10 = 0, ab01 = 0, ab11= 0, ab00 = 0;
    
    for( int i = 0; i< n; i++){
        if(a[i] == 1 && b[i] ==1) ab11++;
        else if(a[i] == 1 && b[i]==0) ab10++;
        else if(a[i]==0 && b[i]==1) ab01++;
        else ab00++;
    }
    if(ab10 ==0 && ab01 == 0)
        cout<< 0<<'\n';
    else if(ab10%2 )
        cout<<1<<'\n';
    else if(ab10> 0 && ab10%2 == 0)
    cout << 2<<'\n';
    else{
        if(ab11>0 && ab00 > 0)
        cout << 2<< '\n';
        else
        cout << -1<<'\n';
    }

}


int main(){
    ll t = 1;
    cin >> t;
    while( t-- ){
        solve();
    }


    return 0;
}