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
	
	int n;
	cin >> n;
	vector<int> v(n);
	
	for (int i = 0; i < n; i++) cin >> v[i];
	
	vector<int> lis(n, 1);
	vector<int> prev(n, -1);
	
	//Kompleksitas O(N^2)
	for (int i = 0; i < n; i++){
		for (int j = 0; j < i; j++){
			if (v[j] < v[i] and (lis[i]<lis[j]+1)){
				lis[i] = lis[j]+1;
				prev[i] = j;
			}
		}
	}
	
	int ans = 0;
	int ansidx = 0;
	for (int i = 0; i < n; i++){
		if (ans < lis[i]){
			ans = lis[i];
			ansidx = i;
		}
	}
	
	cout << ans << endl;
	vector<int> jawaban;
	int cur = ansidx;
	while (prev[cur]!=-1){
		jawaban.push_back(v[cur]);
		cur = prev[cur];
	}
	jawaban.push_back(v[cur]);
	
	reverse(jawaban.begin(), jawaban.end());
	
	for (int i = 0; i < jawaban.size(); i++){
		cout << jawaban[i] << " ";
	}
	
	return 0;
}
