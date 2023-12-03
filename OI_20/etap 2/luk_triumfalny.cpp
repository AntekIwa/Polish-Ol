#include<bits/stdc++.h>

using namespace std;

const int maxn = 300007;
vector<int> G[maxn];
vector<int> dp(maxn);
void dfs(int v, int p, int k){
	dp[v] = 0;
	for(int u : G[v]){
		if(u == p) continue;
		dfs(u,v,k);
		dp[v] += dp[u] + 1;
	}
	dp[v] = max(0, dp[v]-k);
}
int main(){
	int n;  cin >> n;
	for(int i = 0; i < n - 1; i++){
		int a,b; cin >>a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	int p = 0; int k = maxn;
	int res;
	while(p <= k){
		int mid = (p+k)/2;
		dfs(1,0, mid);
		if(dp[1] == 0){
			res = mid;
			k = mid - 1;
		}else p = mid+1;
	}
	cout << res;
}
