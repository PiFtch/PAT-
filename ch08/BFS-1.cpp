#include <cstdio>
#include <queue>
using namespace std;

const int maxn = 100;
char matrix[maxn][maxn];
bool inq[maxn][maxn] = {false};

struct node {
    int x, y;
    int step;
} S, T, Node;

int n, m;
int X[4] = {0, 0, 1, -1};
int Y[4] = {1, -1, 0, 0};

bool test(int x, int y) {
    if (x >= n || x < 0 || y >= m || y < 0)
        return false;
    if (matrix[x][y] == '*')
        return false;
    if (inq[x][y])
        return false;
    return true;
}

int BFS() {
    queue<node> q;
    q.push(S);
    while (!q.empty()) {
        node top = q.front();
        q.pop();
        if (T.x == top.x && T.y == top.y)
            return top.step;

        for (int i = 0; i < 4; i++) {
            int newX = top.x + X[i];
            int newY = top.y + Y[i];
            if (test(newX, newY)) {
                Node.x = newX;
                Node.y = newY;
                Node.step = top.step + 1;
                inq[newX][newY] = true;
                q.push(Node);
            }
        }
    }
    return -1;
}

int main() {
    scanf("%d%d", &n, &m);
    for (int x = 0; x < n; x++) {
        getchar();
        for (int y = 0; y < m; y++) {
            matrix[x][y] = getchar();
        }
        matrix[x][m+1] = '\0';
    }
    scanf("%d%d%d%d", &S.x, &S.y, &T.x, &T.y);
    S.step = 0;
    printf("%d\n", BFS());
}