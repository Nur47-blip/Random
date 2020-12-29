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
	
	int q;
	cin >> q;
	
	while (q--){
		int x; cin >> x;
		int left=0, right=n-1;
		int ans = -1;
		while (left <= right){
			int mid = (left+right)/2;
			if (v[mid]==x){
				ans = mid;
				right = mid-1;
			}
			else if (x < v[mid]){
				right = mid-1;
			}
			else if (x > v[mid]){
				left = mid+1;
			}
		}
		cout << ans << endl;
	}

	return 0;
}
