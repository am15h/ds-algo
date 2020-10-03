//			Goli Beta, Masti Nai...

#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
typedef long long ll;

int main()
{
    ll t;
    cin >> t;

    while(t--)
    {
	ll n,k;
	cin >> n >> k;

	ll x[n];
	for(ll i = 0 ; i < n ; i++)
	    cin >> x[i];

	for(ll i = 0 ; i < n ; i++)
	{
	    ll y;
	    cin >> y;
	}

	sort(x, x + n);

	ll dp[n], arr[n];
	dp[n - 1] = 1;
	arr[n - 1] = 1;

	for(ll i = n - 2 ; i >= 0 ; i--)
	{
	    ll temp = upper_bound(x, x + n, x[i] + k) - x;
	    temp -= i;
	    dp[i] = temp;
	    arr[i] = max(arr[i + 1], temp);
	}

	ll ans = 0;

	for(ll i = 0 ; i < n ; i++)
	{
	    if(i + dp[i] >= n)
	    {
		ans = max(ans, dp[i]);
		continue;
	    }

	    ans = max(ans, dp[i] + arr[i + dp[i]]);
	}

	cout << ans << endl;
    }

    return 0;
}

