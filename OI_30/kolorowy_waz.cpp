#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define rep(a, b) for(int a = 0; a < (b); ++a)
#define st first
#define nd second
#define pb push_back
#define all(a) a.begin(), a.end()

const int MAX_N = 2007;
int plansza[MAX_N][MAX_N];
int jedzenie[MAX_N][MAX_N];
vector<int> snake;
int runda = 0;
int ktoryWiersz = 1;
int ktoraKolumna = 1;
int dlg = 1;
int main(){
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int m,p,n; cin >> m >> p >> n;
	int kolumna,wiersz,przek;
	snake.pb(0);
	for(int i = 0; i<=m; i++){
		for(int j = 0; j <=m;j++){
			jedzenie[i][j] = -1;
			plansza[i][j] = -1;
		}
	}
	plansza[1][1] = 0;
	for(int i = 0; i < p; i++){
		cin >> wiersz >> kolumna >> przek;
		jedzenie[wiersz][kolumna] = przek;
	}
	for(int i = 0; i < n; i++){
		char rodzaj;
		cin >> rodzaj;
		if(rodzaj == 'Z'){
			cin >> wiersz >> kolumna;
			int ktory = plansza[wiersz][kolumna];
			if(ktory <= runda - dlg) cout << -1 << "\n";
			else cout << snake[dlg - 1- (runda-ktory)] << "\n";	
		}else{
			if(rodzaj =='P')ktoraKolumna++;
			else if(rodzaj == 'L') ktoraKolumna--;
			else if(rodzaj == 'G') ktoryWiersz--;
			else ktoryWiersz++;
			runda++;
			plansza[ktoryWiersz][ktoraKolumna] = runda;
			if(jedzenie[ktoryWiersz][ktoraKolumna] != -1){
				snake.pb(jedzenie[ktoryWiersz][ktoraKolumna]);
				dlg++;
				jedzenie[ktoryWiersz][ktoraKolumna] = -1;
			}
		}
	}
	return 0;
}
