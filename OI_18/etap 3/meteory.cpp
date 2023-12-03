#include <bits/stdc++.h>
using namespace std;

const int base = 1 << 19;
const int max_m = 3e5 + 7;
vector<long long> tree(2*base);
vector<long long> req(max_m);
vector<int> stations[max_m];
vector<int> midy[max_m];
struct rain{
	int l,r, val;
};
struct interval{
	int lo,  hi, mid;
};
vector<rain> rains(max_m);
vector<interval> intervals(max_m);

void add(int l, int r, int x){
	l += base;
	r += base;
	while(l <= r && l != 0 && r != 0){
		if(l%2 == 1) tree[l] += x;
		if(r%2 == 0) tree[r] += x;
		l = (l+1)/2;
		r = (r-1)/2;
	}
}

long long query(int x){
	x += base;
	long long res = 0;
	while(x > 0){
		res += tree[x];
		x/=2;
	}
	return res;
}

int main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m; cin >> n >> m;
	for(int i = 1; i <= m; i++){
		int a; cin >> a;
		stations[a].push_back(i);
	}
	for(int i = 1; i <= n; i++) cin >> req[i];
	int k; cin >> k;
	for(int i = 1; i <= k; i++) cin >> rains[i].l >> rains[i].r >> rains[i].val;
	
	for(int i = 1; i <= n; i++){
		intervals[i].lo = 1;
		intervals[i].hi = k + 1;
		intervals[i].mid = (k+2)/2;
		midy[intervals[i].mid].push_back(i);
	}
	int left = n;
	while(left > 0){
		for(int i = 1; i <= k; i++){
			if(rains[i].l <= rains[i].r) add(rains[i].l, rains[i].r, rains[i].val);
			else{
				add(1, rains[i].r, rains[i].val);
				add(rains[i].l, m, rains[i].val);
			}
			for(int j : midy[i]){
				long long cnt = 0;
				for(int u : stations[j]){
					cnt += query(u);
					if(cnt >= req[j]) break;	
				} 
				if(cnt >= req[j]){
					intervals[j].hi = i;
					intervals[j].mid = (intervals[j].lo + intervals[j].hi)/2;
				}else{
					intervals[j].lo = i+1;
					intervals[j].mid = (intervals[j].lo + intervals[j].hi)/2;
				}
				
				if(intervals[j].hi == intervals[j].lo) left--;
				else midy[intervals[j].mid].push_back(j);
			}
			midy[i].clear();
		}
		for(int i = 0; i < 2*base; i++) tree[i] = 0;
	}
	for(int i = 1; i <= n; i++){
		if(intervals[i].lo == k + 1) cout << "NIE\n";
		else cout << intervals[i].hi <<"\n";
	}
	return 0;
}
