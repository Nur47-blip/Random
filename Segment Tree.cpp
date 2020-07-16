#include <bits/stdc++.h>

using namespace std;

long long n,m;
long long a[100000];
long long t[400000];

void build(long long v, long long tl, long long tr){
	if (tl==tr) t[v]=a[tl];
	else {
		build(2*v, tl, (tl+tr)/2);
		build(2*v+1, (tl+tr)/2+1, tr);
		t[v]=t[2*v]+t[2*v+1];
	}
}

long long sum(long long v, long long tl, long long tr, long long l, long long r){
	if (tl>r or tr<l) return 0;
	else if (tl>=l and tr<=r) return t[v];
	else {
		long long tm=(tl+tr)/2;
		return sum(2*v, tl, tm, l, r)+sum(2*v+1, tm+1, tr, l, r);
	}
}

void update(long long v, long long tl, long long tr, long long pos, long long new_val){
	if (tl==tr) t[v]=new_val;
	else {
		int tm=(tl+tr)/2;
		if (pos<=tm) update(v*2, tl, tm, pos, new_val);
		else update(v*2+1, tm+1, tr, pos, new_val);
		t[v]=t[v*2]+t[v*2+1];
	}
}


int main(){

	cin>>n>>m;
	
	for (long long i=0;i<n;i++) cin>>a[i];
	
	long long z=1;
	while (z<n) z*=2;
	
	n=z;
	
	build(1,0,n-1);
	
	while (m--) {
		long long k,b,c;
		cin>>k>>b>>c;
		if (k==1){
			a[b]=c;
			update(1,0,n-1,b,c);
		}
		else {
			cout<<sum(1,0,n-1,b,c-1)<<endl;
		}
	}

	return 0;
}
