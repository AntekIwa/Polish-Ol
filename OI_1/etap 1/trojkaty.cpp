#include<bits/stdc++.h>

using namespace std;

pair<long long,long long> gen(string tmp){
    long long a = 0, b = 0, i = 0;
    for(; tmp[i] != '/'; i++){
        a*=10;
        a += tmp[i] - '0';
    }
    i++;
    for(; i < tmp.size(); i++){
        b*=10;
        b += tmp[i] - '0';
    }
    return {a,b};
}

bool cmp(pair<long long,long long> a, pair<long long,long long> b){
    if(a.second == b.second) return a.first < b.first;
    if(a.first == b.first) return a.second > b.second;
    long long licza = a.first, liczb = b.first, miana = a.second, mianb = b.second;
    mianb/__gcd(miana,mianb);
    licza *= mianb/__gcd(miana,mianb);
    liczb *= miana/__gcd(miana,mianb);
    return licza < liczb;
}

bool check(pair<long long, long long> a, pair<long long, long long> b, pair<long long, long long> c){
    pair<long long, long long> suma;
    long long nwd = __gcd(a.second, b.second);
    a.first *= b.second/nwd;
    b.first *= a.second/nwd;
    suma.first = a.first + b.first;
    suma.second = a.second * b.second / nwd;
    nwd = __gcd(suma.second, c.second);
    suma.first *= c.second/nwd;
    c.first *= suma.second/nwd;
    if(suma.first > c.first) return true;
    return false;
}
int main(){
    int n; cin >> n;
    string tmp;
    vector<pair<long long, long long>> dlugosci;
    for(int i = 0; i < n; i++){
        string tmp; cin >> tmp;
        dlugosci.push_back(gen(tmp));
    }
    sort(dlugosci.begin(), dlugosci.end(), cmp);
    if(check(dlugosci[0], dlugosci[1], dlugosci[n-1])) cout << "TAK\n";
    else cout << "NIE\n";
}
