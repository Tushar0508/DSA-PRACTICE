class Solution {
    public boolean findSafeWalk(List<List<Integer>> grid, int health) {
        int m = grid.size();
        int n = grid.get(0).size();
        boolean[][] visited = new boolean[m][n];
   
        Boolean[][][] dp = new Boolean[m][n][health + 1];
        return dfs(grid, 0, 0, health, m, n, visited, dp);
    }

    private boolean dfs(List<List<Integer>> grid, int i, int j, int health, int m, int n, boolean[][] visited, Boolean[][][] dp) {
        if (i < 0 || i >= m || j < 0 || j >= n || visited[i][j]) {
            return false;
        }

        health -= grid.get(i).get(j);

        if (health < 1) {
            return false;
        }

        if (i == m - 1 && j == n - 1 && health >= 1) {
            return true;
        }

        if (dp[i][j][health] != null) {
            return dp[i][j][health];
        }

        visited[i][j] = true;

        boolean foundPath = dfs(grid, i + 1, j, health, m, n, visited, dp) ||  // Down
                            dfs(grid, i, j + 1, health, m, n, visited, dp) ||  // Right
                            dfs(grid, i - 1, j, health, m, n, visited, dp) ||  // Up
                            dfs(grid, i, j - 1, health, m, n, visited, dp);    // Left

 
        visited[i][j] = false;

        dp[i][j][health] = foundPath;

        return foundPath;
    }
}
