#include<bits/stdc++.h>

using namespace std;

const int maxn = 1e6+7;
vector<pair<int,int>> ciecie;

int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n,m; cin >> m >> n;
	for(int i = 0; i < m-1; i++){
		int a; cin >> a;
		ciecie.push_back(make_pair(a,1));
	}
	for(int i = 0; i < n-1; i++){
		int a; cin >> a;
		ciecie.push_back(make_pair(a,0));
	}
	sort(ciecie.begin(), ciecie.end());
	int ileM = 1, ileN = 1;
	int res = 0;
	for(int i = m+n-3; i >= 0; i--){
		if(ciecie[i].second == 1){
			res += ileN*ciecie[i].first;
			ileM++;
		}
		else{
			res += ileM*ciecie[i].first;
			ileN++;	
		}
	}
	cout<< res;
}
