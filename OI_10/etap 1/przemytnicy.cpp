#include<bits/stdc++.h>

using namespace std;

const int maxn = 5007;
const long long inf = 2*1e18 + 7;

vector<long long> cost(maxn);
vector<long long> dist(maxn,inf);
vector<long long> distRev(maxn, inf);
vector<pair<long long, long long>> G[maxn];
vector<pair<long long, long long>> RevG[maxn];

int main(){
    int n,m; cin >> n;
    for(int i = 1; i <= n; i++) cin >> cost[i];
    cin >> m;
    for(int i = 0; i < m; i++){
        long long a,b,w; cin >> a >> b >> w;
        RevG[b].push_back(make_pair(a,w));
        G[a].push_back(make_pair(b,w));
    }
    // paths from 1 to all nodes
    priority_queue<pair<long long,long long>> q;
    q.push(make_pair(0,1));
    dist[1] = 0;
    while(!q.empty()){
        int v = q.top().second;
        q.pop();
        for(auto [u,d] : G[v]){
            if(dist[v] + d < dist[u]){
                dist[u] = dist[v] + d;
                q.push(make_pair(-dist[u], u));
            }
        }
    }
    // paths from all nodes to 1
    q.push(make_pair(0,1));
    distRev[1] = 0;
    while(!q.empty()){
        int v = q.top().second;
        q.pop();
        for(auto [u,d] : RevG[v]){
            if(distRev[v] + d < distRev[u]){
                distRev[u] = distRev[v] + d;
                q.push(make_pair(-distRev[u], u));
            }
        }
    }
    long long mini = inf;
    int res = 0;
    for(int i = 1; i <= n; i++){
        long long cena = dist[i] + distRev[i] + (cost[i]/2);
        if(cena < mini){
            mini = cena;
            res = i;
        }
    }
    cout << mini;
}
