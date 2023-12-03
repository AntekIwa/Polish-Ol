#include <bits/stdc++.h>

using namespace std;


vector<int> G[30007];
bool odw[30007];
int pre[30007];
int post[30007];
int licznik_pr = 0;
int licznik_po = 0;
int l;
int skok[30007][16];
int wys[30007];

void dfs(int a,int b,int wysok){
   skok[a][0] = b;
   wys[a] = wysok;
   for (int i = 1; i <= l; ++i)
       skok[a][i] = skok[skok[a][i-1]][i-1];
    odw[a] = true;
    pre[a] = licznik_pr;
    licznik_pr++;
    for(int u:G[a]){
        if(!odw[u]){
            dfs(u,a,wysok+1);
        }
    }
    post[a] = licznik_po;
    licznik_po++;
}

//czy wspólny przodek a i b
bool czy_prz(int a, int b){
    if(post[a] > post[b] && pre[a] < pre[b]) return true;
    return false;
}

//najniższy wspólny przodek a i b
int LCA(int a,int b){

    if(czy_prz(a,b)) return a;
    if(czy_prz(b,a)) return b;
    for(int i = l; i >=0; i--){
        // jeśli aktualnie żaden nie jest wsp. przod. to jednen z nich skacze o potege 2^i
        if(!czy_prz(skok[a][i],b)) a = skok[a][i];
    }
    return skok[a][0];
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    int n,tempa,tempb,x,y,m,q,sciezka,akt,poprz,wynik = 0;
    cin >> n;
    l = ceil(log2(n));
   // skok.assign(n, vector<int>(l + 1));
    for(int i = 0; i < l;i ++){
        skok[1][i] = 1;
    }
    for(int i = 0; i < n-1; i++){
        cin >> tempa >> tempb;
        G[tempa].push_back(tempb);
        G[tempb].push_back(tempa);
    }
    dfs(1,1,0);
  //  cout << "teraz lca: " << endl;
    cin >>m;
    cin >> poprz;
    for(int i = 1; i < m; i++){
        cin >> akt;
         q = LCA(poprz,akt);
         sciezka = wys[poprz] - (2*wys[q]) + wys[akt];
       //  cout << "lca: " << q << " " << "sciezka: " << sciezka << endl;
         wynik+=sciezka;
         poprz = akt;
    }
    cout << wynik;;
    return 0;
}
