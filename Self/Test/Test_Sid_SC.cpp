#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define times(t) int t; cin >> t; while(t--)
#define mod 1000000007

vector<int> a;
int n;
int dp[105][2080];

vector<int> getdig(int x) {
	vector<int> dig;
	while(x>0) {
		dig.push_back(x%10);
		x /= 10;
	}
	return dig;
}
int go(int i,int mask) {
	if(i == n) {
		return 0;
	}
	if(dp[i][mask] != -1) return dp[i][mask];
	auto x = getdig(a[i]);
	
	for(auto it: x) {
		if(mask & 1<<it) {
			return go(i+1,mask);
		}
	}
	int mm = mask;
	for(auto it: x){
		mask |= (1<<it);
	}
	return dp[i][mm] = max(a[i] + go(i+1,mask),go(i+1,mm));
}
void solve() {
	cin>>n;
	a.clear();
	a.resize(n);
	for(int i =0;i<n;i++) {
		cin>>a[i];
		for(int j = 0;j<2080;j++) {
			dp[i][j] = -1;
		}
	}
	cout << go(0,0) << "\n";
}

int main() {
	IOS;
	int t; cin >> t;
	while(t--) 
		solve();
	return 0;
}