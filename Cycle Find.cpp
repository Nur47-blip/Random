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
	
	int n, m;
	cin >> n >> m;
	
	vector<vector<int>> graf(n);
	
	for (int i = 0; i < m; i++){
		int a, b;
		cin >> a >> b;
		graf[a].pb(b);
		graf[b].pb(a);
	}
	
	vector<bool> pernah(n, false);
	vector<int> prev(n, -1);
	bool cycle = false;
	
	for (int i = 0; i < n; i++){
		if (pernah[i]) continue;
		
		//dfs dari titik ke-i
		stack<int> s;
		prev[i] = i;
		s.push(i);
		while(!s.empty()){
			int x = s.top();
			s.pop();
			
			if (pernah[x]) continue;
			pernah[x] = true;
			
			//mengujungi semua cabang dari x
			for (int i = 0; i < graf[x].size(); i++){
				int xx = graf[x][i];
				if (pernah[xx] and prev[x]!=xx){			//ini kasus terjadi loop
					cycle = true;
					break;
				}
				else if (pernah[xx]) continue;				//ini kasus balik lagi ke previous vertex
				
				prev[xx] = x;								//ini kasus mengunjungi cabang dari x
				s.push(xx);
			}
			if (cycle) break;
		}
		if (cycle) break;
	}
	
	if (cycle) cout << "ada cycle\n";
	else cout << "tidak ada cycle\n";

	return 0;
}
