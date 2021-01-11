#include <bits/stdc++.h>

using namespace std;

int main(){
	
	int n;
	cin >> n;
	
	vector<int> v(n);
	vector<int> nge(n);
	
	for (int i = 0 ; i < n; i++) cin >> v[i];
	
	stack<int> s;
	s.push(0);
	
	for (int i = 1; i < n; i++){
		
		int temp = v[i];
		while (!s.empty() and v[s.top()] < temp){
			nge[s.top()] = temp;
			s.pop();
		} 
		
		s.push(i);
	}
	
	while (!s.empty()){
		nge[s.top()] = -1;
		s.pop();
	}
	
	for (int i =0 ; i < n; i++){
		cout << nge[i] << ' ';
	}
	
}
