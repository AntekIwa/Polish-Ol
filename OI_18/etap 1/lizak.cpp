#include <bits/stdc++.h>

using  namespace std;
const int maxn = 1e6 + 7;
vector<pair<int,int>> ans(2*maxn);
int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n, q; cin >> n >> q;
	string lizak; cin >> lizak;
	lizak = "x" + lizak;
	int p = 1;
	int k = n;
	int suma = 0;
	int ostW = -1;
	int pierW = -1;
	for(int i = 1; i <= n; i++){
		if(lizak[i] == 'T') suma += 2;
		else{
			if(pierW == -1) pierW = i;
			ostW = max(ostW,i);
			suma++;
		}
	}
	ans[suma] = make_pair(1,n);
	int cnt = suma;
	while(cnt > 0 && p <= k){
		ans[cnt] = make_pair(p,k);
		if(lizak[p] == 'T') p++;
		else if(lizak[k] == 'T') k--;
		else{
			p++;
			k--;
		}
		cnt -= 2;
	}
	cnt = suma;
	if(pierW >= n + 1 - ostW){
		p = 1;
		k = ostW - 1;
		cnt -= (2 * (n - ostW) + 1);
	}else{
		p = pierW + 1;
		k = n;
		cnt -= (2 * (pierW - 1) + 1);
	}
	while(cnt > 0 && p <= k){
		ans[cnt] = make_pair(p,k);
		if(lizak[p] == 'T') p++;
		else if(lizak[k] == 'T') k--;
		else{
			p++;
			k--;
		}
		cnt -= 2;
	}
	while(q--){
		int t; cin >> t;
		if(ans[t].first != 0) cout << ans[t].first << " " << ans[t].second << "\n";
		else cout << "NIE\n";
	}
}
