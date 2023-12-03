#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1e6 + 7;
vector<int> idx[MAX_N];

int main(){
	ios_base::sync_with_stdio(0);
	int n; cin >> n;
	for(int i = 0; i < n; i++){
		int a; cin >> a;
		idx[a].push_back(i);
	}
	int t; cin >> t;
	while(t--){
		int m; cin >> m;
		int akt = 0;
		bool czy = false;
		for(int i = 0; i < m; i++){
			int x; cin >> x;
			if(czy) continue;
			if(idx[x].size() == 0 || idx[x][idx[x].size()-1] < akt){
				czy = true;
				cout << "NIE\n";
				continue;
			}
			auto it = lower_bound(idx[x].begin(), idx[x].end(), akt);
			if(*it < akt){
			czy = true;
				cout << "NIE\n";
				continue;
			}
			akt = *it + 1;
			
		}
		if(!czy) cout << "TAK\n";
	}
}
