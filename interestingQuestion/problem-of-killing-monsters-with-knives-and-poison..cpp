#include <vector>
typedef unsigned long long ull;
using namespace std;

class Solution {
private:

public:
    int solver(ull HP, vector<int>& cuts, vector<int>& poisons) {
        int l = 1, r = HP + 1;
        int ans = 1;
        while (l <= r) {
            int m = l + (r - l) / 2; // 当前设定的杀死怪物回合数
            if (check(cuts, poisons, m, HP)) {
                r = m - 1;
                ans = m;
            } else l = m + 1;
        }
        return ans;
    }

    bool check(vector<int>& cuts, vector<int>& poisons, int turns, ull HP) {
        for (int t = 1; t < turns + 1; t++) {
            HP -= max(1ULL * (turns - t) * poisons[t], 1ULL * cuts[t]);
            if (HP <= 0) return true;
        }
        return false;
    }
};

int main() {

}