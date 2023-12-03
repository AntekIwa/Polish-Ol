#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()

const int MAX_N = 1e6 + 7;
vector<ll> tree[MAX_N];
vector<ll> instaltime(MAX_N);
vector<ll> T(MAX_N);
vector<ll> K(MAX_N);


void dfs(int v, int par){
	for(int u : tree[v]){
		if(u != par){
			dfs(u,v);
			K[v] += K[u];
		}
	}
	if(tree[v].size() == 1 && v != 1){
		K[v] = 2;
		T[v] = instaltime[v];
	}
	else{
		vector<pair<ll,ll>> stree;
		for(int u : tree[v]){
			if(u == par) continue;
			stree.pb({T[u] - K[u], u});
		}
		sort(all(stree));
		reverse(all(stree));
		ll x = 1, a = 0, b = 0;
		for(auto i : stree){
			b = i.nd;
			if(x + T[b] > a) a = x + T[b];
			x += K[b];
		}
		x = a;
		T[v] = max(instaltime[v], x);
		K[v] += 2;
	}
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n; cin >> n;
	for(int i = 1; i <= n; i++) cin >> instaltime[i];
	for(int i = 0; i < n - 1; i++){
		int a,b; cin >> a >> b;
		tree[a].pb(b);
		tree[b].pb(a);
	}
	dfs(1,0);
	cout << max(instaltime[1] + 2*(n-1), T[1]);
	return 0;
}
