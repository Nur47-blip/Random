#include <bits/stdc++.h>

using namespace std;;

int main(){

	int kombinasi[1001][1001];
	const int mod = 1e9+7;
	
	for (int i = 0; i <= 1000; i++) {
		for (int j = 0; j <= 1000; j++) {
			if (j == 1) kombinasi[i][j] = i; //base case
			else if (i == j) kombinasi[i][j] = 1;
			else {
				kombinasi[i][j] = (kombinasi[i-1][j-1] + kombinasi[i-1][j]) % mod;
			}
		}
	}
	
	int n,r;
	
	cin>>n>>r;
	
	cout<<"C(n,r) = "<<kombinasi[n][r]<<endl<<endl;
	
	cout<<"Segitiga Pascal sampai Baris ke-"<<n<<endl;
	cout<<"(Dimulai dari Baris ke-0)"<<endl<<endl;
	
	for (int i=0;i<=n;i++){
		for (int j=0;j<=i;j++){
			cout<<kombinasi[i][j]<<" ";
		}
		cout<<endl;
	}

	return 0;
}
