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
	ll n;
	cin >> n;

	ll arr[n];
	for(ll i = 0 ; i < n ; i++)
	    cin >> arr[i];

	vector<ll> ans;

	ans.push_back(*max_element(arr, arr + n));

	int hash[n] = {0};
	ll bi = ans[0];

	for(ll i = 0 ; i < n ; i++)
	{
	    if(arr[i] == bi)
	    {
		hash[i] = 1;
		break;
	    }
	}

	ll gcd = ans[0];

	for(ll i = 0 ; i < n - 1 ; i++)
	{
	    ll cur = 0;
	    ll pos = -1;

	    for(ll j = 0 ; j < n ; j++)
	    {
		if(hash[j])
		    continue;

		ll g = __gcd(gcd, arr[j]);
		if(g > cur)
		{
		    cur = g;
		    pos = j;
		}
	    }

	    hash[pos] = 1;
	    gcd = cur;

	    ans.push_back(arr[pos]);
	}

	for(ll i = 0 ; i < n ; i++)
	    cout << ans[i] << " ";

	cout << endl;
    }

    return 0;
}

