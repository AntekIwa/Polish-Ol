#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()
const int maxn = 1507;
pair<int,int> up[maxn][maxn];
pair<int,int> down[maxn][maxn];
int maxup[maxn][maxn];
int maxdown[maxn][maxn];
string grid[maxn];

void licz(int n){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(grid[i][j] == '.'){
				up[i][j].st = 1;
				up[i][j].nd = 1;
				if(i > 0) up[i][j].st += up[i-1][j].st;
				if(j > 0) up[i][j].nd += up[i][j-1].nd;
				maxup[i][j] = max(up[i][j].st, up[i][j].nd);
			}
			if(i > 0) maxup[i][j] = max(maxup[i][j], maxup[i-1][j]);
			if(j > 0) maxup[i][j] = max(maxup[i][j], maxup[i][j-1]);
		}
	}
	for(int i = n-1; i >= 0; i--){
		for(int j = n - 1; j >= 0; j--){
			if(grid[i][j] == '.'){
				down[i][j].st = 1;
				down[i][j].nd = 1;
				if(i < n - 1) down[i][j].st += down[i+1][j].st;
				if(j < n - 1) down[i][j].nd += down[i][j+1].nd;
				maxdown[i][j] = max(down[i][j].st, down[i][j].nd);
			}
			if(i < n - 1) maxdown[i][j] = max(maxdown[i][j], maxdown[i+1][j]);
			if(j < n - 1) maxdown[i][j] = max(maxdown[i][j], maxdown[i][j+1]);
		}
	}
}
int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m; cin >> n >> m;
	for(int i = 0; i < n; i++) cin >> grid[i];
	licz(n);
	int maxk = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if(m == 1) maxk = max(maxk, maxup[i][j]);
			else{
				if(i == n - 1 && j == n - 1) continue;
				int pierwszy = maxup[i][j];
				int drugi = 0;
				if(i < n - 1) drugi = max(drugi, maxdown[i+1][0]);
				if(j < n - 1) drugi = max(drugi, maxdown[0][j+1]);
				maxk = max(maxk, min(pierwszy, drugi));
			}
		}
	}
	cout << maxk;
	return 0;
}
