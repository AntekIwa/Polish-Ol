#include<bits/stdc++.h>

using namespace std;

const int maxn = 200;
int dist[maxn][maxn];
bool vist[maxn][maxn];
vector<int> movesx = {1,0,0,-1};
vector<int> movesy = {0,1,-1,0};

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n,m; cin >> n>> m;
	string tab[n];
	for(int i =0; i < n; i++) cin >> tab[i];	
  //bfs from all nodes with value 1
	queue<pair<int,int>> q;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if(tab[i][j] == '1') q.push({i ,j});
		}
	}
	
	while(!q.empty()){
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for(int i = 0; i < 4; i++){
			if(y+movesy[i] >= 0 && y + movesy[i] < n && x+movesx[i] >= 0 && x + movesx[i] < m && !vist[y+movesy[i]][x+movesx[i]] && tab[y+movesy[i]][x+movesx[i]] == '0'){
				vist[y+movesy[i]][x+movesx[i]] = true;
				dist[y+movesy[i]][x+movesx[i]] = dist[y][x] + 1;
				q.push({y+movesy[i], x + movesx[i]});
			}
		}
	}
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++) cout << dist[i][j] << " ";
		cout << "\n";
	}
	return 0;
}
