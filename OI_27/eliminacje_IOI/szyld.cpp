#include<bits/stdc++.h>

using namespace std;
vector<int> idx1[300];
int main(){
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	string s1, s2; cin >> s1 >> s2;
	int n = s1.size();
	vector<int> p(n+7,0);
	p[0] = -1;
	int k = -1;
	for(int i = 1; i <= n; i++){
		while(k >= 0 && s1[k] != s1[i-1]) k = p[k];
		p[i] = ++k;
	}
	string s3 = s1.substr(p[n]);
    for(int i = 0; i < s3.size(); i++) idx1[s3[i]].push_back(i);
    int ost = 0;
    for(int i = 0; i < s1.size(); i++){
        if(s1[i] == s2[ost]) ost++;
    }
    int res = 1;
    int indeks = -1;
    for(int i = ost; i < s2.size(); i++){
        auto it = upper_bound(idx1[s2[i]].begin(), idx1[s2[i]].end(), indeks);
        if(it == idx1[s2[i]].end()){
            it = upper_bound(idx1[s2[i]].begin(), idx1[s2[i]].end(), -1);
            if(it == idx1[s2[i]].end()){
                cout << "INF";
                return 0;
            }
            res++;
        }
        indeks = *it;        
    }
    cout << res;
	return 0;
}
