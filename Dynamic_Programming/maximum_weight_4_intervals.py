class Solution:
    def maximumWeight(self, intervals: list[list[int]]) -> list[int]:
        import bisect
        
        n = len(intervals)
        
        # Package intervals with their original indices to bypass V8 object overhead
        arr = [(intervals[i][0], intervals[i][1], intervals[i][2], i) for i in range(n)]
        
        # Sort chronologically by start time
        arr.sort(key=lambda x: x[0])
        
        start_times = [x[0] for x in arr]
        
        # Precompute the index of the next valid non-overlapping interval
        # bisect_right guarantees we strictly bypass overlapping boundaries (new_L > old_R)
        next_idx = [bisect.bisect_right(start_times, x[1]) for x in arr]
        
        # DP table: dp[i][k] stores (max_weight, list_of_indices)
        # Sized (N + 1) x 5 for exactly max 4 intervals tracking
        dp = [[(0, []) for _ in range(5)] for _ in range(n + 1)]
        
        # Post-order backward traversal to build optimal suffix states
        for i in range(n - 1, -1, -1):
            nxt = next_idx[i]
            w_i = arr[i][2]
            orig_i = arr[i][3]
            
            for k in range(1, 5):
                # Option 1: Skip the current interval completely
                opt1_w, opt1_seq = dp[i+1][k]
                
                # Option 2: Take the current interval and jump to the next valid state
                nxt_w, nxt_seq = dp[nxt][k-1]
                opt2_w = w_i + nxt_w
                # Keep indices sorted for the strict lexicographical rule
                opt2_seq = sorted([orig_i] + nxt_seq)
                
                # Zero-overhead state resolution
                if opt2_w > opt1_w:
                    dp[i][k] = (opt2_w, opt2_seq)
                elif opt2_w < opt1_w:
                    dp[i][k] = (opt1_w, opt1_seq)
                else:
                    # Resolve ties purely by lexicographically smallest index array
                    if opt2_seq < opt1_seq:
                        dp[i][k] = (opt2_w, opt2_seq)
                    else:
                        dp[i][k] = (opt1_w, opt1_seq)
                        
        # Extract the sequence from the absolute root state
        return dp[0][4][1]