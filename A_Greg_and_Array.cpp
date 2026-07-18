#include <bits/stdc++.h>
#include <vector>

using namespace std;

void differenceArray(long long i,long long j, long long d, vector<long long>& data){
    data[i] += d;
    if(j+1 != data.size()){
        data[j+1] -= d;
    }
}


void prefixSum(vector<long long>& data){
    long long prev = 0;
    for(auto &a: data){
        a += prev;
        prev = a;
    }
}


void solve(){

    // All the inputs
    long long n, m, k;
    cin >> n>> m >> k;
    vector<long long> a(n);
    vector<long long> a1(n);
    for(auto& i:a)
        cin >> i;

    vector<vector<long long>> operations(m, vector<long long>(3));
    vector<pair<long long,long long>> queries(k);
    for(auto& o:operations)
        cin>> o[0] >>o[1]>> o[2];

    for(auto& q: queries)
        cin>> q.first>> q.second;

    for(auto& o:operations){
        o[0]--;
        o[1]--;
    }
    for(auto&q:queries){
        q.first--;
        q.second--;
    }

    vector<long long> que(m,0);


    // operations array formation
    for(auto& q:queries)
        differenceArray(q.first, q.second, 1,que);

    prefixSum(que);

    for(auto i:que){
        // cout<< i<<" ";
    }
    for(long long i = 0; i < m;i++){
        differenceArray(operations[i][0], operations[i][1], operations[i][2] * que[i],a1);
    }
    prefixSum(a1);

    for(long long i = 0; i < n; i++){
        cout<< a[i]+a1[i]<<" ";
    }
    cout<<'\n';
}
int main(){
    long long t = 1;
    // cin >> t;
    while( t-- ){
        solve();
    }


    return 0;
}