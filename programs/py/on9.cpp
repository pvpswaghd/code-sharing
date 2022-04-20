#include <iostream>
#include <string>

using namespace std;

long long int dp[1001];

int main(){
	int t;
	cin >> t;
	memset(dp, 0, sizeof(dp));
	dp[0] = 1;
	for(int i = 1; i <= t; i++){
			for(int j = 1; j <= 2; j++){
				if(i-j<0) break;
				dp[i] += dp[i-j];
			}
	}
	cout << dp[t];
}
