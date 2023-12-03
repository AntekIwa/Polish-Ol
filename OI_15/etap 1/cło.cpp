#include<bits/stdc++.h>

using namespace std;

const int maxn = 1e6 + 7;
vector<int> G[maxn];
vector<int> matching_node(maxn, -1);
vector<bool> vist(maxn);
vector<int> matchCity(maxn,-1);

bool augment(int u){
    vist[u] = true;
    for(auto v : G[u]){
        if(matching_node[v] == -1){
            matching_node[v] = u;
            matching_node[u] = v;
            return true;
        }
    }
    for(auto v : G[u]){
        if(!vist[matching_node[v]] && augment(matching_node[v])){
            matching_node[v] = u;
            matching_node[u] = v;
            return true;
        }
    }
    return false;
}

void zeruj(int n){
    for(int i = 0; i <= 2*n; i++) vist[i] = false;
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n,m; cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int a,b; cin >> a >> b;
        G[n+i].push_back(a);
        G[n+i].push_back(b);
        G[a].push_back(n+i);
        G[b].push_back(n+i);
    }

    while(true){
        zeruj(n+m);
        bool czy = false;
        for(int i = 1; i <= m + n; i++)
            if(matching_node[i] == -1 && augment(i)) czy = true;
        if(!czy) break;
    }
    bool czy = true;
    for(int i = 1; i<= n; i++)
        if(matching_node[i] == -1) czy = false;  
    if(!czy) cout << "NIE\n";
    else{
        for(int i = 1; i <= n; i++){
            int u = matching_node[i];
            if(G[u][0] == i) matchCity[i] = G[u][1];
            else matchCity[i] = G[u][0];
        }
        cout << "TAK\n";
        for(int i =1; i <= n; i++) cout << matchCity[i]<< "\n";
    }

}
