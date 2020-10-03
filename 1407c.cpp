//			Goli Beta, Masti Nai...

#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
typedef long long ll;

int main()
{
	int n;
	cin >> n;

	int arr[n];
	int ind = 0;

	for(int i = 1 ; i < n ; i++)
	{
	    cout << '?' << " " << i + 1 << " " << ind + 1 << endl;
	    int r1;
	    cin >> r1;

	    cout << '?' << " " << ind + 1 << " " << i + 1 << endl;
	    int r2;
	    cin >> r2;

	    if(r2 > r1)
	    {
		arr[ind] = r2;
		ind = i;
	    }
	    else
	    {
		arr[i] = r1;
	    }
	}

	arr[ind] = n;
	
	cout << "! ";
	for(int i = 0 ; i < n ; i++)
	    cout << arr[i] << " ";

	cout << endl;

    return 0;
}

