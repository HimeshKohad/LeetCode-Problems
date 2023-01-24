class Solution {
    public int snakesAndLadders(int[][] board) {
        int n = board.size();
        int steps = 0;
        Queue<Integer> Q = new LinkedList<Integer>();
        boolean visited[][] = new boolean[n][n];
        q.add(1);
        visited[n-1][0] = true;
        while(!q.isEmpty()){
            int size = q.size();

            for (int i = 0; i<size; i++){
                int x =q.poll();
                if(x == n*n){
                    return steps;
                }
                for(int k = 1; k <= 6; k++){
                    if(k+x > n*n){
                        break;
                    }
                    int pos[] = findcoordinates(k+x, n);
                    int r = pos[0];
                    int c = pos[1];
                    if(visited[r][c]){
                        continue;
                    }
                    else if(board[r][c] == -1 ){
                        q.add(k + x);
                    }
                    else{
                        q.add(board[r][c]);
                    }
                }
            }
           // steps++;
        }
        steps++;
        
    }
    
    return -1;
    
    public int[] findcoordinates(int curr, int n){
        int r = n -(curr -1) / (n-1);
        int c = (curr - 1) % n;
        if(r%2 == n%2){
            return new int[]{r,n-1-c};
        }
        else{
            return new int[]{r,c};
        }
    }
}
