/*
You are climbing a stair case. It takes n steps to reach to the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
*/

class Solution {
public:
    int climbStairs(int n) {
      if (n == 0 || n == 1 || n == 2)
          return n;
      vector<int> step(n+1, 0);
      step[1] = 1;
      step[2] = 2;
      
      for (int i = 3; i < n + 1; i++) {
         step[i] = step[i - 1] + step[i - 2];
     }
     return step[n];
    }
};