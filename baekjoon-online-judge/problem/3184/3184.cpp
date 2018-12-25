#include <cstdio>
#include <vector>
#include <queue>

using namespace std;

#define PII pair<int,int>

int R, C, group[250][250];
char map[250][250];
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };
vector<PII> v;
int sheep, wolf;

void bfs(int y, int x, int cnt) {
	queue<PII> q;
	q.push(make_pair(y, x));
	group[y][x] = cnt;
	int nsheep = 0, nwolf = 0;

	while (!q.empty()) {
		y = q.front().first;
		x = q.front().second;
		q.pop();
		if (map[y][x] == 'v') nwolf++;
		if (map[y][x] == 'o') nsheep++;

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (0 <= ny && ny < R && 0 <= nx && nx < C) {
				if (map[ny][nx] != '#' && !group[ny][nx]) {
					group[ny][nx] = cnt;
					q.push(make_pair(ny, nx));
				}
			}
		}
	}

	if (nwolf >= nsheep) wolf += nwolf;
	else sheep += nsheep;
}

int main() {
	scanf("%d %d\n", &R, &C);
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			scanf("%c\n", &map[i][j]);
		}
	}

	int cnt = 1;
	v.push_back(make_pair(0, 0));
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (map[i][j] != '#' && !group[i][j])
				bfs(i, j, cnt++);
		}
	}

	printf("%d %d\n", sheep, wolf);

	return 0;
}