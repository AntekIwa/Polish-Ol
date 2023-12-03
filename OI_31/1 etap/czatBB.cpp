//https://usaco.guide/gold/string-hashing?lang=cpp

#include<bits/stdc++.h>

using namespace std;

//input
long long n;
long long k;
long long a;
long long b;
string s = "";

//hasze
long long mod1 = 1e9 + 7;
long long mod2 = 1e9 + 9;
long long p = 9973;
vector<long long> p1;
vector<long long> hsh1;
vector<long long> p2;
vector<long long> hsh2;

//sety do dodawania nowych literek
multiset<pair<long long,long long>> alfa[26];
int len = 0;

//jakie hasze byly - szukanie cyklu
vector<pair<long long,long long>> last_hsh;
set<pair<long long,long long>> prev_hsh;

pair<long long,long long> get_hash(int i, int j){ //hasz podslowa
    return {((mod1 + hsh1[j] - hsh1[i-1]*(p1[j - i + 1])%mod1)+mod1)%mod1, ((mod2 + hsh2[j] - hsh2[i-1]*(p2[j - i + 1])%mod2)+mod2)%mod2};
}
void new_hash(char x){ //dohaszowanie nowej literki
    hsh1.push_back(((hsh1.back()*p)%mod1 + x + mod1)%mod1);
    hsh2.push_back(((hsh2.back()*p)%mod2 + x + mod2)%mod2);
}

void compute_hash(){ //preprocess haszy calosci
    p1.push_back(1);
    p2.push_back(1);
    hsh1.push_back(0);
    hsh2.push_back(0);
    for(int i = 1; i <= n; i++){
        p1.push_back((p1.back()*p)%mod1);
        p2.push_back((p2.back()*p)%mod2);
        hsh1.push_back(((hsh1.back()*p)%mod1 + s[i-1] + mod1)%mod1);
        hsh2.push_back(((hsh2.back()*p)%mod2 + s[i-1]+ mod2)%mod2);
    }
}

void fill_sets(){ //wypelnianie multisetow
    for(int i = 0; i + k < n; i++)
        alfa[s[i+k] - 'a'].insert(get_hash(i+1, i+k));
}

int find_letter(pair<long long, long long> sufix){ //znajdowanie nowej literki
    int maxx = 0, maxchar = 0;
    for(int i = 0; i < 26; i++){
        if(alfa[i].count(sufix) > maxx){
            maxx = alfa[i].count(sufix);
            maxchar = i;
        }
    }
    return maxchar;
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> k >> a >> b;
    cin >> s;
    compute_hash();
    fill_sets();
    //dodawanie literek
    len = n;
    string res = "";
    while(true){
        pair<long long,long long> sufix = get_hash(len - k + 1, len);
        last_hsh.push_back(sufix);
        if(prev_hsh.count(sufix) != 0) break;
        prev_hsh.insert(sufix);
        int new_letter = find_letter(sufix);
        alfa[new_letter].insert(sufix);
        res += char('a' + new_letter);
        new_hash(char('a' + new_letter));
        len++;

    }
    //znajdowanie okresu - beg poczatek okresu
    pair<long long,long long> last = last_hsh.back();
    int beg = 0;
    for(int i = 0; i < last_hsh.size(); i++){
        if(last_hsh[i].first == last.first && last_hsh[i].second == last.second){
            beg = i;
            break;
        }
    }
    string okres = "";
    for(int i = beg; i < res.size(); i++) okres += res[i];
    //wypisywanie od a do b
    a -= (n + 1);
    b -= (n + 1);
    for(long long i = a; i <= b; i++){
        if(i < res.size()) cout << res[i];
        else cout << okres[(i-beg)%okres.size()];
    }
    cout << "\n";
}
