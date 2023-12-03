#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 2 * 1e5 + 7;
vector<int> G[MAX_N];
vector<int> vist(MAX_N);

void bfs(int s){
	queue<int> q;
	q.push(s);
	vist[s] = 1;
	while(!q.empty()){
		int v = q.front();
		q.pop();
		for(int i = 0; i <  G[v].size(); i++){
			int u = G[v][i];
			if(vist[u] == 0){
				if(vist[v] == 1) vist[u] = 2;
				else vist[u] = 1;
				q.push(u);
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n,m; cin >> n >> m;
	for(int i = 0; i < m; i++){
		int a,b; cin >> a >> b;
   		G[a].push_back(b);
   		G[b].push_back(a);
	}
	for(int i = 1; i <= n; i++){
		if(vist[i] == 0) bfs(i);
	}
	for(int i = 1; i <= n; i++){
		bool czy = false;
		if(G[i].size() == 1 && G[i][0] == i){
			vist[i] = 3;
			continue;
		}
		for(int j = 0; j < G[i].size(); j++){
			int u = G[i][j];
			if(vist[u] != vist[i]){
				czy = true;
				break;
			}
		}
		if(!czy){
			cout <<"NIE\n";
			return 0;
		}
	}
	cout << "TAK\n";
	for(int i = 1;  i <= n; i++){
		if(vist[i] == 1) cout << "K\n";
		else if(vist[i] == 2) cout << "S\n";
		else cout << "N\n";
	}
	return 0;
}
