class Solution {
public:
    long long xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        const long long MOD = 1e9 + 7;
        int n = nums.size();
        int T = (int)sqrt(n) + 1;

        auto modinv = [&](long long a) {
            long long res = 1, p = MOD - 2, m = MOD;
            while (p) { if (p & 1) res = res * a % m; a = a * a % m; p >>= 1; }
            return res;
        };

        vector<long long> large_mult(n, 1);
        vector<vector<tuple<int,int,long long>>> small_q(T + 1);

        for (auto& q : queries) {
            int l = q[0], r = q[1], k = q[2];
            long long v = q[3];
            if (k <= T)
                small_q[k].emplace_back(l, r, v);
            else
                for (int idx = l; idx <= r; idx += k)
                    large_mult[idx] = large_mult[idx] * v % MOD;
        }

        vector<long long> total_mult(n, 1);

        for (int k = 1; k <= T; k++) {
            if (small_q[k].empty()) continue;

            int seq_len = (n + k - 1) / k;
            // diff[res][p]: difference array for residue class res, position p in sequence
            vector<vector<long long>> diff(k, vector<long long>(seq_len + 1, 1));

            for (auto& [l, r, v] : small_q[k]) {
                int res = l % k;
                int p_start = l / k;
                // last index in residue class <= r
                int last = (r / k) * k + res;
                if (last > r) last -= k;
                if (last < l) continue;
                int p_end = last / k;

                diff[res][p_start] = diff[res][p_start] * v % MOD;
                if (p_end + 1 <= seq_len)
                    diff[res][p_end + 1] = diff[res][p_end + 1] * modinv(v) % MOD;
            }

            for (int res = 0; res < k; res++) {
                long long running = 1;
                int p = 0;
                for (int idx = res; idx < n; idx += k, p++) {
                    running = running * diff[res][p] % MOD;
                    total_mult[idx] = total_mult[idx] * running % MOD;
                }
            }
        }

        long long ans = 0;
        for (int i = 0; i < n; i++)
            ans ^= (long long)nums[i] * large_mult[i] % MOD * total_mult[i] % MOD;

        return ans;
    }
};