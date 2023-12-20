#include<bits/stdc++.h>

using namespace std;

const int inf = 1e9;
const int base = 1 << 16;
vector<int> tree(2*base), lazy(2*base);

void push(int v){
	tree[2*v] += lazy[v];
	tree[2*v + 1] += lazy[v];
	lazy[2*v] += lazy[v];
	lazy[2*v +1] += lazy[v];
	lazy[v] = 0;
}

void update(int v, int tl, int tr, int l, int r, int val){
	if(l > r) return;
	if(l == tl && tr == r){
		tree[v] += val;
		lazy[v] += val;
	}
	else{
		push(v);
		int mid = (tr + tl)/2;
		update(v*2, tl, mid, l, min(r, mid), val);
		update(v*2+1, mid + 1, tr, max(l,mid+1), r, val);
		tree[v] = max(tree[v*2], tree[v*2 + 1]);
	}
}

int query(int v, int tl, int tr, int l, int r){
	if(l > r) return -inf;
	if(l == tl && r == tr) return tree[v];
	push(v);
	int mid = (tr + tl)/2;
	return max(query(v*2, tl, mid, l, min(r,mid)), query(v*2 + 1, mid + 1, tr, max(l,mid+1), r));

}

void upd(int l, int r, int x){
	update(1, base, 2*base - 1, l + base, r + base, x);
}

long long maxx(int l, int r){
	return query(1, base, 2*base - 1, l + base, r + base);
}
int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n,k,q; cin >> n >> k >> q;
	while(q--){
		int l, r, x; cin >> l >> r >> x;
		if(k - maxx(l,r-1) >= x){
			cout << "T\n";
			upd(l,r-1,x);
		}
		else cout << "N\n";
	}
}
