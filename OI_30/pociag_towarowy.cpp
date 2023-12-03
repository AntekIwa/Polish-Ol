//n log n
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()

const int MAX_N = 3* 1e5 + 7;
vector<int> bajtek(MAX_N);
vector<int> bitek(MAX_N);
vector<int> pozBit[MAX_N];
vector<pair<int,int>> jak(MAX_N);
int n,m,k; 

bool check(int poz){
	int p = 0;
	int k = pozBit[bajtek[poz]].size()-1;
	while(p<=k){
		int srod = (p+k)/2;
		if(jak[poz].st >= pozBit[bajtek[poz]][srod] && jak[poz].nd >= m-1-pozBit[bajtek[poz]][srod] ) return true;
		if(jak[poz].st < pozBit[bajtek[poz]][srod]) k = srod-1;
		else p = srod+1;
	}
	return false;
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin >> n >> m >> k;
	rep(i,n) cin >> bajtek[i];
	rep(i,m){
		cin >> bitek[i];
		pozBit[bitek[i]].pb(i);
	}
	int ktory = 0;
	for(int i = 0; i < n; i++){
		if(ktory >= m){
			jak[i].st = m;
			continue;
		}
		if(bajtek[i] == bitek[ktory]) ktory++;
		jak[i].st = ktory;
	}
	ktory = 0;
	for(int i = n-1; i >= 0; i--){
		if(ktory >= m){
			jak[i].nd = m;
			continue;
		}
		if(bajtek[i] == bitek[m-1-ktory]) ktory++;
		jak[i].nd = ktory;
	}
	for(int i = 0; i < n; i++){
		if(check(i)) cout << 1 << " ";
		else cout << 0 << " ";
	}
	return 0;
}
