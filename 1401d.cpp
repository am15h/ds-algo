//			Goli Beta, Masti Nai...

#include <bits/stdc++.h>

using namespace std;

#define mod 1000000007
typedef long long ll;

ll child[100010];
bool vis[100010];

void dfs(vector<vector<ll>> gr, ll u)
{
    vis[u] = 1;

    for(auto v : gr[u])
    {
	if(!vis[v])
	{
	    dfs(gr, v);
	    child[u] += child[v];
	}    
    }
}

int main()
{
    int t;
    cin >> t;

    while(t--)
    {
	ll n;
	cin >> n;
	
	memset(vis, 0, sizeof(vis));

	for(ll i = 0 ; i < n ; i++)
	    child[i] = 1;

	vector<vector<ll>> gr(n, vector<ll>());
	vector<pair<ll, ll>> ed;

	for(ll i = 0 ; i < n - 1 ; i++)
	{
	    ll u,v;
	    cin >> u >> v;

	    u--;
	    v--;

	    ed.push_back({u, v});

	    gr[u].push_back(v);
	    gr[v].push_back(u);
	}

	ll m;
	cin >> m;

	ll p[m];
	for(ll i = 0 ; i < m ; i++)
	    cin >> p[i];

	sort(p, p + m, greater<ll>());

	dfs(gr, 0);

	ll wt[n - 1];
	for(ll i = 0 ; i < n - 1 ; i++)
	{
	    ll temp = min(child[ed[i].first], child[ed[i].second]);
	    wt[i] = (temp*(n - temp));
	}

	sort(wt, wt + (n - 1), greater<ll>());

	ll ans = 0;

	vector<ll> mul;
	if(m < (n - 1))
	{
	    for(ll i = 0 ; i < m ; i++)
	    {
		mul.push_back(p[i]);
		ans = (ans + mul[i]*wt[i]) % mod;
	    }

	    ll i = m;

	    while(mul.size() < (n - 1))
	    {
		mul.push_back(1);
		ans = (ans + wt[i]) % mod;
		i++;
	    }	
	}
	else
	{
	    ll temp = 1;
	    for(ll i = 0 ; i < (m - n + 2) ; i++)
	    {
		temp = (temp*p[i]) % mod;
	    }

	    mul.push_back(temp);
	    ans = (ans + mul[0]*wt[0]) % mod;
	    ll ind = 1;
	    for(ll i = m - n + 2 ; i < m ; i++)
	    {
		mul.push_back(p[i]);
		ans = (ans + mul[ind]*wt[ind]) % mod;
		ind++;
	    }
	}

	cout << ans << endl;

	
    }

    return 0;
}

