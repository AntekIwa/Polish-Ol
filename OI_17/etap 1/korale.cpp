#include<bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 7;
long long m1 = 1e9 + 7;
long long m2 = 1e9 + 9;
long long  p = 314519;
vector<int> res[maxn];
pair<long long, long long> hsh_front[maxn];
pair<long long, long long> hsh_back[maxn];
long long arr[maxn];
long long powers[maxn][2];
int n;
pair<long long,long long> get_hash_front(int a, int b){
    return {((hsh_front[b].first - (hsh_front[a-1].first*powers[b-a+1][0])%m1)+m1)%m1, ((hsh_front[b].second - (hsh_front[a-1].second*powers[b-a+1][1])%m2)+m2)%m2};
}
pair<long long,long long> get_hash_back(int a, int b){
    return {((hsh_back[b].first - (hsh_back[a-1].first*powers[b-a+1][0])%m1)+m1)%m1, ((hsh_back[b].second - (hsh_back[a-1].second*powers[b-a+1][1])%m2)+m2)%m2};
}
void comp_hash(){
    powers[0][0] = powers[0][1] = 1;
    for(int i = 1; i <= n; i++){
        powers[i][0] = (powers[i-1][0]*p)%m1;
        powers[i][1] = (powers[i-1][1]*p)%m2;
        hsh_front[i].first = ((hsh_front[i-1].first*p)%m1 + arr[i-1])%m1;
		hsh_front[i].second = ((hsh_front[i-1].second*p)%m2 + arr[i-1])%m2;
    }
    reverse(arr,arr+n);
    for(int i = 1; i <= n; i++){
    	hsh_back[i].first = ((hsh_back[i-1].first*p)%m1 + arr[i-1])%m1;
    	hsh_back[i].second = ((hsh_back[i-1].second*p)%m2 + arr[i-1])%m2;
	}
    reverse(arr, arr+n);
}

int check(int k){
    set<pair<long long,long long>> tmp;
    int cnt = 0;
    for(int i = 1; i+k-1 <= n; i+= k){
        pair<long long,long long> frontH = get_hash_front(i,i+k-1), backH = get_hash_back(n-(i+k-1)+1,n-i+1);
        if(tmp.count(frontH) == 0 && tmp.count(backH) == 0) cnt++;
        tmp.insert(min(frontH, backH));

    }
    return cnt;
}
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++) cin >> arr[i];
    comp_hash();
    for(int i = 1; i <= n; i++) res[check(i)].push_back(i);
    int maks = 0;
    for(int i = 1; i <= n; i++){
        if(!res[i].empty()) maks = i;
    }
    cout << maks << " " << res[maks].size() << "\n";
    for(int i : res[maks]) cout << i << " ";
}
