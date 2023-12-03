#include<bits/stdc++.h>

using namespace std;
const int maxn = 3 * 1e5 + 7;
vector<int> h(maxn);
int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n,tmp; cin >> n;
	for(int i = 0; i < n; i++) cin >> tmp >> h[i];
	int res = 0;
	priority_queue<int> q;
	for(int i = 0; i < n; i++){
		if(q.empty()){
			res++;
			q.push(h[i]);
			continue;
		}
		if(q.top() < h[i]){
			res++;
			q.push(h[i]);
			continue;
		}
		while(!q.empty() && q.top() > h[i]) q.pop();
		if(q.empty()){
			res++;
			q.push(h[i]);
			continue;
		}
		if(q.top() < h[i]){
			res++;
			q.push(h[i]);
			continue;
		}
	}
	cout << res;
	return 0;
}
