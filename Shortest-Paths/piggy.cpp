#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ifstream inputFile("piggyback.in");
    ofstream outputFile("piggyback.out");

    ll B, E, P, N, M;
    inputFile >> B >> E >> P >> N >> M;
    vector<vector<ll>> adj(N, vector<ll>());
    for (int i = 0; i < M; ++i) {
        ll temp1, temp2; inputFile >> temp1 >> temp2;
        adj[temp1 - 1].push_back(temp2 - 1);
        adj[temp2 - 1].push_back(temp1 - 1);
    }

    vector<ll> w_b(N, INT_MAX);
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq_b;
    pq_b.push({0, 0});
    w_b[0] = 0;
    while (!pq_b.empty()) {
        pair<ll, ll> curr = pq_b.top();
        pq_b.pop();
        ll weight = curr.first, loc = curr.second;

        for (ll i : adj[loc]) {
            if (weight + B < w_b[i]) {
                w_b[i] = weight + B;
                pq_b.push({weight + B, i});
            }
        }
    }

    vector<ll> w_e(N, INT_MAX);
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq_e;
    pq_e.push({0, 1});
    w_e[1] = 0;
    while (!pq_e.empty()) {
        pair<ll, ll> curr = pq_e.top();
        pq_e.pop();
        ll weight = curr.first, loc = curr.second;

        for (ll i : adj[loc]) {
            if (weight + E < w_e[i]) {
                w_e[i] = weight + E;
                pq_e.push({weight + E, i});
            }
        }
    }

    vector<ll> dist(N, INT_MAX);
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> source;
    source.push({0, N - 1});
    dist[N - 1] = 0;
    while (!source.empty()) {
        pair<ll, ll> curr = source.top();
        source.pop();
        ll weight = curr.first, loc = curr.second;

        for (ll i : adj[loc]) {
            if (weight + 1 < dist[i]) {
                dist[i] = weight + 1;
                source.push({weight + 1, i});
            }
        }
    }

    ll rslt = w_b[N - 1] + w_e[N - 1];
    for (int i = 0; i < N; ++i) {
        if (w_e[i] != INT_MAX && w_b[i] != INT_MAX) {
            rslt = min(rslt, (dist[i] * P + w_e[i] + w_b[i]));
        }
    }
    outputFile << rslt << endl;

    return 0;
}