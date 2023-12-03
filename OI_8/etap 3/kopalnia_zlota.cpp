#include <bits/stdc++.h>

using namespace std;

struct samo{
	int x;
	int y;
	int w;
	bool operator < (const samo &b){
		if(x == b.x) return w > b.w;
		return x < b.x;
	}
};
const int maxn = 3* 1e4;
vector<samo> zloto;

const int INF = 1e9 + 7;
const int base = 1 << 20;
vector<int> tree(base*2);
vector<int> lazy(base*2);

void push(int v){
	tree[v*2] += lazy[v];
	tree[v*2 + 1] += lazy[v];
	lazy[v*2] += lazy[v];
	lazy[v*2 + 1] += lazy[v];
	lazy[v] = 0;
}

void add(int v, int tl, int tr, int l, int r, int x){

	if(l > r) return;
	if(tr == r && tl == l){
		tree[v] += x;
		lazy[v] += x;
		return;
	}
	push(v);
	int tm = (tl+tr)/2;
	add(v*2, tl, tm, l, min(r, tm),x);
	add(v*2 + 1, tm+1,tr,max(tm+1,l),r, x);
	tree[v] = max(tree[v*2], tree[v*2 + 1]);
}

int maks(int v, int tl, int tr, int l, int r){
	if(l > r) return -INF;
	if(tr <= r && tl <= l) return tree[v];
	int tm = (tl+tr)/2;
	push(v);
	return max(maks(v*2,tl,tm,l,min(r,tm)), maks(v*2, tm+1, tr,max(l,tm+1),r));
}


int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int s,w; cin >> s >> w;
	int q; cin >> q;
	while(q--){
		samo akt; cin >> akt.x >> akt.y;
		akt.x += maxn;
		akt.y += maxn;
		akt.w = 1;
		zloto.push_back(akt);
		akt.w = -1;
		akt.x += s;
		zloto.push_back(akt);
	}
	int res = 0;
	sort(zloto.begin(), zloto.end());
	for(samo akt: zloto){
		add(1, 0, base-1,akt.y,akt.y + w, akt.w);
		res = max(maks(1,0,base-1, 0, base), res);
	}
	cout << res;
}
