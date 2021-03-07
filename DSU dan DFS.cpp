#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define pii pair<int, int>
#define fi first
#define se second

#define trace(x) cout << '>' << #x << ':' << x << "\n"
#define trace2(x,y) cout<< '>' << #x << ':' << x << " | " << #y << ':' << y << "\n"
#define trace3(a,b,c) cout<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<"\n"
#define trace4(a,b,c,d) cout<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<", "<<#d<<"="<<(d)<<"\n"

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n, q, e;
	cin >> n >> q >> e;
	vector<vector<int>> graf(n);
	
	for (int i = 0; i < e; i++){
		int a, b;
		cin >> a >> b;
		graf[a].pb(b);
		graf[b].pb(a);
	}
	
	vector<bool> vis(n, false);
	vector<int> par(n);
	for (int i = 0; i < n; i++){
		if (vis[i]==true) continue;
		
		par[i] = i;
		stack<int> s;
		s.push(i);
		while (!s.empty()){
			int x = s.top();
			s.pop();
			par[x] = i;
			
			if (vis[x]) continue;
			vis[x] = true;
			
			for (int j = 0; j < graf[x].size(); j++){
				int xx = graf[x][j];
				if (vis[xx]) continue;
				s.push(xx);
			}
		}
	}
	
	for (int i = 0; i < q; i++){
		int a, b;
		cin >> a >> b;
		if (par[a]==par[b]) cout << "Terhubung" << endl;
		else cout << "Tidak Terhubung" << endl;
	}

	return 0;
}
