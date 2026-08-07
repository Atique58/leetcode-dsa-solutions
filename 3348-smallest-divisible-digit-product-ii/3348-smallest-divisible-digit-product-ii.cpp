class Solution {
public:
    int getMinLen(int r2, int r3, int r5, int r7) {
        int len = r5 + r7; 
        int min_23 = 1000000;
        
        for (int c6 = 0; c6 <= min(r2, r3); c6++) 
        {
            int rem2 = max(0, r2 - c6);
            int rem3 = max(0, r3 - c6);
            int c8 = (rem2 + 2) / 3;
            int c9 = (rem3 + 1) / 2;
            min_23 = min(min_23, c6 + c8 + c9);
        }
        return len + min_23;
    }

    string smallestNumber(string num, long long t) {
        long long temp = t;
        int req2 = 0, req3 = 0, req5 = 0, req7 = 0;
        
        while(temp % 2 == 0) { req2++; temp /= 2; }
        while(temp % 3 == 0) { req3++; temp /= 3; }
        while(temp % 5 == 0) { req5++; temp /= 5; }
        while(temp % 7 == 0) { req7++; temp /= 7; }
        
        if (temp > 1) return "-1";

        int min_req_initial = getMinLen(req2, req3, req5, req7);
        if (num.length() < min_req_initial) 
        {
            num = string(min_req_initial, '1'); 
        }

        string ans = "";
        bool found = false;

        auto dfs = [&](auto& self, int index, bool tight, int r2, int r3, int r5, int r7, string& current) -> void {
            if (found) return;
            
            int rem_slots = num.length() - index;
            
            if (getMinLen(r2, r3, r5, r7) > rem_slots) return;

            if (index == num.length()) {
                if (r2 == 0 && r3 == 0 && r5 == 0 && r7 == 0) {
                    ans = current;
                    found = true;
                }
                return;
            }

            int start_d = tight ? max(1, num[index] - '0') : 1;
            
            for (int d = start_d; d <= 9; d++) {
                int n_r2 = r2, n_r3 = r3, n_r5 = r5, n_r7 = r7;
                int temp_d = d;
                
                while(temp_d % 2 == 0) { n_r2--; temp_d /= 2; }
                while(temp_d % 3 == 0) { n_r3--; temp_d /= 3; }
                while(temp_d % 5 == 0) { n_r5--; temp_d /= 5; }
                while(temp_d % 7 == 0) { n_r7--; temp_d /= 7; }
                
                n_r2 = max(0, n_r2);
                n_r3 = max(0, n_r3);
                n_r5 = max(0, n_r5);
                n_r7 = max(0, n_r7);

                current.push_back(d + '0');
                
                self(self, index + 1, tight && (d == (num[index] - '0')), n_r2, n_r3, n_r5, n_r7, current);
                
                current.pop_back();
                if (found) return; 
            }
        };
        while (!found) 
        {
            string current = "";
            dfs(dfs, 0, true, req2, req3, req5, req7, current);
            if (found) break;
            
            num = string(num.length() + 1, '1');
        }

        return ans;
    }
};