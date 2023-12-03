//https://cp-algorithms.com/graph/finding-cycle.html

#include<bits/stdc++.h>

using namespace std;
const int maxn = 250007;
const int maxm = 500007;

struct para{
    int v1=-1, v2=-1, lca=-1;
};
struct parent{
    int par=-1, nr=-1;
};
stack<int> cycle;
vector<pair<int,int>> G[2*maxn];
vector<int> solve;
vector<int> vist(maxn);
vector<parent> parents(maxn);
vector<int> dopary(maxn,-1);
vector<para> pary;
set<int> secik;
int cycle_start = 1;
int cycle_end = 1;
int n;
int m;
int paruj(int v){
    vist[v] = 1;
    if(G[v].size()%2 == 0) dopary[v] = v;
    for(auto [u,nr] : G[v]){
        if(vist[u] == 0){
            parents[u].par = v;
            parents[u].nr = nr;
            int co = paruj(u);
            if(co == -1) continue;
            if(dopary[v] != -1){
                para tmp;
                tmp.v1 = dopary[v];
                tmp.v2 = co;
                tmp.lca = v;
                pary.push_back(tmp);
                dopary[v] = -1;
            }
            else dopary[v] = co;
        }
    }
    return dopary[v];
}

bool cykl(int v, int par){
    vist[v] = true;
    for (auto[u,nr] : G[v]) {
        if(u == par) continue; // skipping edge to parent vertex
        if (vist[u]) {
            parents[u].par = v;
            parents[u].nr = nr;
            cycle_end = v;
            cycle_start = u;
            return true;
        }
        parents[u].par = v;
        parents[u].nr = nr;
        if (cykl(u, parents[u].par))
            return true;
    }
    return false;
}
bool checkP(){
   // cout<<"tut\n";
    //TODO znajdz cykl
    for(int i = 1; i <= 2*n; i++){
        //cout << i << "\n";
        if(vist[i] == 0){
           // cout << i << "\n";
            if(!cykl(i,i)) continue;
            //cout << cycle_start << " " << cycle_end << "\n";
            for(int v = cycle_end; v != cycle_start; v = parents[v].par){
                solve.push_back(parents[v].nr);
             //   cout << v<<"\n";
            }
            solve.push_back(parents[cycle_start].nr);
            cycle_end = -1;
            cycle_start = -1;
            return true;
        }
    }
    return false;
}

void proceed(int v, int lca){
    while(v != lca){
        secik.insert(parents[v].nr);
        v = parents[v].par;
    }
}
bool checkNP(){
    for(int i = 1; i <= 2*n; i++){
        if(vist[i] == 0){
            if(paruj(i) != -1) return false;
        }
    }
    for(para i : pary){
        proceed(i.v1, i.lca);
        proceed(i.v2, i.lca);
    }
    return true;
}

void zeruj(){
    solve.clear();
    for(int i = 0; i <= 2*n; i++){
        parents[i].nr = -1;
        parents[i].par = -1;
        vist[i] = 0;
        dopary[i] = -1;
    }
}
int main(){
ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int a,b; cin >> a >> b;
        b += n;
        G[a].push_back({b,i});
        G[b].push_back({a,i});
    }
    if(checkP()){
        cout << "TAK\n";
        cout << solve.size()<<"\n";
        for(int i : solve) cout << i << " ";
        cout << "\n";
        return 0;
    }
    zeruj();
    if(checkNP()){
        int ile = 0;
        for(int i = 1; i <= 2*n; i++){
            if(G[i].size() == 0) ile++;
        }
        if(ile != 0){
            cout << "NIE\n";
            return 0;
        }
        cout << "TAK\n";\
        vector<int> res;
        for(int i  = 1; i <= m; i++){
            if(secik.count(i) == 0)res.push_back(i);
        }
        cout << res.size() << "\n";
        for(int i : res) cout << i << " ";
        cout << "\n";
        return 0;
    }
    cout << "NIE\n";
}
