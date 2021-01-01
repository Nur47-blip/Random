#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define pii pair<int, int>
#define fi first
#define se second

vector<int> sol;
int n;
vector<int> v;

void solve(int i, int sum){
	if (i==n){
		sol.push_back(sum);
	}
	else {
		solve(i+1, sum); //skip
		solve(i+1, sum+v[i]); //ini kalau ngambil;
	}
}

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n;
	
	for (int i = 0; i < n; i++){
		int x;
		cin >> x;
		v.push_back(x);
	}
	
	solve(0,0);
	
	sort(sol.begin(), sol.end());
	cout << "hasil: " << endl;
	for (int i = 0; i < sol.size(); i++){
		if (i > 0 and sol[i]==sol[i-1]) continue;
		else cout << sol[i] << endl;
	}

	return 0;
}
