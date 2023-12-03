#include<bits/stdc++.h>

using namespace std;

struct wyk{
    int pocz, kon, nr;
};

bool cmp(wyk a, wyk b){
    if(a.kon == b.kon) return a.pocz < b.pocz;
    return a.kon < b.kon;
}

const int INF = 1e9 + 7, maxn = 5e5 + 7;
vector<wyk> wyklady, org;

int main(){
ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n; cin >> n;
    for(int i = 0; i < n; i++){
        wyk tmp;
        cin >> tmp.pocz >> tmp.kon;
        tmp.nr = i+1;
        wyklady.push_back(tmp);
        org.push_back(tmp);
    }
    if(n == 1){
        cout << 0<<"\n";
        return 0;
    }
    //liczenie maksymalengo rozlacznego zbioru odcinkow
    sort(wyklady.begin(), wyklady.end(), cmp);
    vector<wyk> podst, zapas,proste;
    podst.push_back(wyklady[0]);
    zapas.push_back(wyklady[1]);
    for(int i = 2; i < n; i++){
        wyk wc = wyklady[i], zap = zapas[zapas.size() - 1], pod = podst[podst.size() - 1];
        if(zapas.size() == podst.size()){ //dowolnie ktory dobierzemy
            if(zap.kon <= pod.kon){ //zapasowy nie wystaje - mozemy dobrac podstawowy
                if(wc.pocz >= pod.kon) podst.push_back(wc);
            }
            else{
                if(wc.pocz >= zap.kon) podst.push_back(wc);
                else if(wc.pocz >= pod.kon) zapas.push_back(wc);
            }
            continue;
        }
        else if(zapas.size() < podst.size()){ //szukamy zapasowego
            if(wc.pocz >= podst[podst.size() - 2].kon)zapas.push_back(wc); //TODO upewnic sie
            continue;
        }
        else{ //szukamy podstawowego
            if(wc.pocz >= pod.kon && wc.pocz >= zapas[zapas.size() - 2].kon) podst.push_back(wc);
        }
    }
    proste.push_back(wyklady[0]);
    for(int i = 1; i < n; i++){
        if(wyklady[i].pocz >= proste[proste.size() - 1].kon) proste.push_back(wyklady[i]);
    }
    if(proste.size() - 1 >= min(podst.size(),zapas.size())){
        cout << proste.size() - 1 << "\n";
        for(int i = 0; i < proste.size() - 1; i++) cout << proste[i].nr << " " << proste[proste.size() - 1].nr << "\n";
    }

    else{
        cout << min(podst.size(),zapas.size()) << "\n";
        for(int i = 0; i <  min(podst.size(),zapas.size()); i++) cout << podst[i].nr << " " << zapas[i].nr << "\n";
    }
}
