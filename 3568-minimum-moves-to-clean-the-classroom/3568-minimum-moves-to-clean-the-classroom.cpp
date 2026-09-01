class Solution {
public:
    int minMoves(vector<string>& classroom, int energy) {

        int m = classroom.size();
        int n = classroom[0].size();
        int sr = 0, sc = 0;
        vector<vector<int>> id(m, vector<int>(n, -1));

        int litterCount = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (classroom[i][j] == 'S') {
                    sr = i;
                    sc = j;
                }

                if (classroom[i][j] == 'L') {
                    id[i][j] = litterCount;
                    litterCount++;
                }
            }
        }
        if (litterCount == 0) {
            return 0;
        }
        int totalMasks = 1 << litterCount;
        vector<vector<vector<vector<bool>>>> visited(
            m,
            vector<vector<vector<bool>>>(
                n,
                vector<vector<bool>>(
                    energy + 1,
                    vector<bool>(totalMasks, false)
                )
            )
        );

        queue<tuple<int, int, int, int>> q;

        int startMask = totalMasks - 1;

        q.push({sr, sc, energy, startMask});

        visited[sr][sc][energy][startMask] = true;

        int moves = 0;

        int dr[] = {-1, 1, 0, 0};
        int dc[] = {0, 0, -1, 1};

        while (!q.empty()) {

            int size = q.size();

            // Process one BFS level
            while (size--) {

                auto [r, c, currEnergy, mask] = q.front();
                q.pop();

                // All litter collected
                if (mask == 0) {
                    return moves;
                }

                // No energy -> cannot move
                if (currEnergy == 0) {
                    continue;
                }

                // Try 4 directions
                for (int k = 0; k < 4; k++) {

                    int nr = r + dr[k];
                    int nc = c + dc[k];

                    // Outside grid
                    if (nr < 0 || nr >= m || nc < 0 || nc >= n) {
                        continue;
                    }

                    // Obstacle
                    if (classroom[nr][nc] == 'X') {
                        continue;
                    }

                    // Every movement costs 1 energy
                    int newEnergy = currEnergy - 1;

                    int newMask = mask;

                    // If we reach litter
                    if (classroom[nr][nc] == 'L') {

                        int litterID = id[nr][nc];

                        // Mark this litter as collected
                        newMask &= ~(1 << litterID);
                    }

                    // If we reach reset area
                    if (classroom[nr][nc] == 'R') {
                        newEnergy = energy;
                    }

                    // If this state hasn't been visited
                    if (!visited[nr][nc][newEnergy][newMask]) {

                        visited[nr][nc][newEnergy][newMask] = true;

                        q.push({
                            nr,
                            nc,
                            newEnergy,
                            newMask
                        });
                    }
                }
            }

            moves++;
        }

        return -1;
    }
};