#include <bits/stdc++.h>

using namespace std;


struct Job {
    int deadline, duration, idx;

    bool operator<(Job o) const {
        return deadline < o.deadline;
    }
};

vector<int> ktore(vector<Job> jobs) {
    set<pair<int,int>> s;
    vector<int> uklad;
    sort(jobs.begin(), jobs.end());
    for (int i = jobs.size()-1; i >= 0; i--) {
        int t = jobs[i].deadline - (i ? jobs[i-1].deadline : 0);
        s.insert(make_pair(jobs[i].duration, jobs[i].idx));
        while (t && !s.empty()) {
            auto it = s.begin();
            if (it->first <= t) {
                t -= it->first;
                uklad.push_back(it->second);
            } else {
                s.insert(make_pair(it->first - t, it->second));
                t = 0;
            }
            s.erase(it);
        }
    }
    return uklad;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n,akt=1;
    vector<Job> prace;
    vector<int> harmo;
    vector<Job> konc;
    struct Job tmp;
    cin >> n;
    for(int i = 1; i <= n;i++){
        cin >> tmp.duration >> tmp.deadline;
        tmp.idx = i;
        prace.push_back(tmp);
    }
    harmo = ktore(prace);

    for(int i = 0; i < harmo.size(); i++){
        tmp.deadline = prace[harmo[i]-1].deadline;
        tmp.duration = prace[harmo[i]-1].duration;
        tmp.idx = harmo[i];
        konc.push_back(tmp);
    }
    sort(konc.begin(), konc.end());
    cout << konc.size() << "\n";
    for(int i = 0; i < harmo.size(); i++){
        cout<<konc[i].idx << " " << akt << "\n";
        akt+=konc[i].duration;
    }
    return 0;
}
