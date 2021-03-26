#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define int long long
#define pii pair<int, int>
#define fi first
#define se second

#define trace(x) cout << '>' << #x << ':' << x << "\n"
#define trace2(x,y) cout<< '>' << #x << ':' << x << " | " << #y << ':' << y << "\n"
#define trace3(a,b,c) cout<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<"\n"
#define trace4(a,b,c,d) cout<<#a<<"="<<(a)<<", "<<#b<<"="<<(b)<<", "<<#c<<"="<<(c)<<", "<<#d<<"="<<(d)<<"\n"

int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

signed main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	freopen("input.txt", "r", stdin);
	
	int n;
	cin >> n;
	
	vector<int> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	
	vector<vector<int>> pile(n);
	int numpile = 1;
	pile[0].push_back(0);
	
	vector<int> prev(n, -1);
	
	for (int i = 1; i < n; i++){
		
		//pakai binary search
		//untuk cari leftmostpile
		int l = 0, r = numpile-1;
		int res = numpile;
		while (l<=r){
			int mid = (l+r)/2;
			int x = pile[mid][pile[mid].size()-1];
			if (v[x] >= v[i]){
				res = min(res, mid);
				r = mid-1;
			}
			else {
				l = mid+1;
			}
		}
		
		//ada pile yang bisa dimasukkan v[i]
		//atau buat pile baru
		
		pile[res].push_back(i);

		if (res==0) continue;
		else {
			int x = pile[res-1][pile[res-1].size()-1];
			prev[i] = x;
		}
		
		if (res==numpile) numpile++;
	}

	int ans = 1;
	int cur = pile[numpile-1][pile[numpile-1].size()-1];
	while(prev[cur]!=-1){
		ans++;
		cur = prev[cur];
//		cout << v[cur] << " ";
	}
	
	cout << ans << endl;
	
	return 0;
}
