#include<iostream>
#include<vector>
using namespace std;

const int MAX_N=250'007;

vector <int> G[MAX_N];
int pre[MAX_N];
int gdzie=1;
bool czy[MAX_N];
int makspre[MAX_N];
int tree[2*MAX_N];
int n;
int odleglosc[MAX_N];

void dfs(int v){
    pre[v]=gdzie;
    makspre[v]=pre[v];
    gdzie++;
    czy[v]=true;
    for(int i=0;i<G[v].size();i++){
        if(czy[G[v][i]]==false){
            odleglosc[G[v][i]]=odleglosc[v]+1;
            dfs(G[v][i]);
            makspre[v]=max(makspre[v],makspre[G[v][i]]);
        }
    }
}

void dodaj(int l,int p,int x){
    l+=n-1;
    p+=n-1;
    while(l>0&&p>0&&l<=p){
        if(l%2==1) tree[l]+=x;
        if(p%2==0) tree[p]+=x;
        l=(l+1)/2;
        p=(p-1)/2;
    }
}

int suma(int x){
    int wynik=0;
    x=pre[x];
    x+=n-1;
    while(x>0){
        wynik+=tree[x];
        x/=2;
    }
    return wynik;
}

int main(){
    ios_base::sync_with_stdio(0), cin.tie(0);
    int q,p1,p2,w,maks;
    char a;
    cin>>n;
    odleglosc[1]=0;
    for(int i=0;i<n-1;i++){
        int a,b;
        cin>>a>>b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dfs(1);
    cin>>q;
    for(int i=0;i<n+q-1;i++){
        cin>>a;
        if(a=='W'){
            cin>>w;
            cout<<odleglosc[w]-suma(w)<<endl;
        }
        else{
            cin>>p1>>p2;
            maks=max(p1,p2);
            dodaj(pre[maks],makspre[maks],1);
        }
    }
}
