/**
解説
**/
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <climits>
#include <sstream>

using namespace std;

const int limit = 50;

int N, M;
int a[limit], b[limit];
bool graph[limit][limit];
bool visited[limit];
 
void dfs(int v) {
	visited[v] = true;
	for (int i = 0; i < N; i++) {
		if (visited[i]) continue;
		if (graph[v][i] == false) continue;
		dfs(i);
	}
}
 
int main() {

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		cin >> a[i] >> b[i];
		a[i]--;
		b[i]--;
		graph[a[i]][b[i]] = graph[b[i]][a[i]] = true;
	}

	int ans = 0;
	for (int i = 0; i < M; i++) {
		graph[a[i]][b[i]] = graph[b[i]][a[i]] = false;

		dfs(a[i]);

		graph[a[i]][b[i]] = graph[b[i]][a[i]] = true;

		bool connected = true;

		for (int j = 0; j < N; j++){
            if (visited[j] == false) connected = false;
        }
			
		if (connected == false) ans++;

		for (int j = 0; j < N; j++) visited[j] = false;
	}

	cout << ans << endl;

	return 0;
}