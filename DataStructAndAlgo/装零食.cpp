#include <iostream>
#include <algorithm>
using namespace std;

long long v[40];
int n;

long long ans = 0, w;

void dfs(int t, long long sum){
	ans++;
	if (t == n - 1){
		return;
	}
	for (int i = t + 1; i< n; i++){
		if (sum + v[i] <= w){
			dfs(i, sum + v[i]);
		}
	}
}

int main(){
	
	long long sum = 0;
	cin >> n >> w;
	for (int i = 0; i<n; i++){
		cin >> v[i];
		sum += v[i];
	}
	if (sum <= w){
		ans = pow(2,n);
	}
	else{
		dfs(-1, 0);
	}
	cout << ans << endl;
	system("pause");
	return 0;
}