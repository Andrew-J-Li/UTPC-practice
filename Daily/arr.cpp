#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<bool> sieve (6000000);
    sieve[0] = true; sieve[1] = true;
    for (ll i = 4; i < sieve.size(); i += 2) sieve[i] = true;
    for (ll i = 3; i < sieve.size(); i += 2) {
        if (!sieve[i]) {
            for (ll j = i * i; j < sieve.size(); j += i) {
                sieve[j] = true;
            }
        }
    }
    vector<ll> primes;
    ll psum = 0;
    for (ll i = 0; i < sieve.size(); ++i) {
        if (!sieve[i]) {
            psum += (i - 2);
            primes.push_back(psum);
        }
    }

    ll t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        vector<ll> arr (n);
        ll sum = 0;
        for (ll i = 0; i < n; ++i) {
            cin >> arr[i];
            sum += arr[i] - 2;
        }
        sort(arr.begin(), arr.end());
        ll idx = 0; ll nx = n;
        while (nx >= 1 && primes[nx - 1] > sum) {
            sum -= (arr[idx] - 2);
            idx++;
            nx--;
        }
        cout << n - nx << endl;
    }
}