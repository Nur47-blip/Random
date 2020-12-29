#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define pii pair<int, int>
#define fi first
#define se second

int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int n; cin >> n;
	vector<int> v(n);
	
	for (int i = 0; i < n; i++){
		cin >> v[i];
	}
	
	sort(v.begin(), v.end());
	
	int q; cin >> q;
	while (q--){
		int a, b; cin >> a >> b;
		
		//lower bound
		int left = 0, right = n-1;
		int ans = n;
		while (left <= right){
			int mid = (left+right)/2;
			if (v[mid] >= a){
				ans = mid;
				right = mid-1;
			}
			else {
				left = mid+1;
			}
		}
		
		//upper bound
		left = 0, right = n-1;
		int ans2 = -1;
		while (left <= right){
			int mid = (left+right)/2;
			if (v[mid] <= b){
				ans2 = mid;
				left = mid+1;
			}
			else {
				right = mid-1;
			}
		}
		
		if (ans2==-1 or ans==n) cout << 0 << endl;
		else cout << ans2-ans+1 << endl;
	}
	
	

	return 0;
}
