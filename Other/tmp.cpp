#include <bits/stdc++.h>
using namespace std;

const int n = 8;

int G[n][n], vis[n], fuck = 0;

void dfs(int u) {
	fuck++, vis[u] = 1;
	for (int i = 0; i < n; i++) if (G[u][i] && !vis[i])
		dfs(i);
}

int main() {
	int t = n * (n - 1) / 2, res = 0;
	for (int s = 0; s < 1 << t; s++) {
		if (__builtin_popcount(s) < n - 2) continue;
		int ct = 0; memset(G, 0, sizeof(G)), memset(vis, 0, sizeof(vis)), fuck = 0;
		for (int i = 0; i < n; i++)
			for (int j = i + 1; j < n; j++) {
				if (s & 1 << ct) G[i][j] = G[j][i] = 1;
				ct++;
			}
		G[0][n - 1] = 1, dfs(0);
		if (fuck == n) res++;
	}
	cout << res << endl;
}
