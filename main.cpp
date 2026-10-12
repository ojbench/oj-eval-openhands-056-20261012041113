#include <iostream>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

// Structure to represent an interval
struct Interval {
    int l, r;
    
    Interval(int left, int right) : l(left), r(right) {}
    
    // Define ordering for set
    bool operator<(const Interval& other) const {
        if (l != other.l) return l < other.l;
        return r < other.r;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    // Use a set to store intervals for efficient searching and deletion
    set<Interval> intervals;
    
    for (int i = 0; i < n; i++) {
        char op;
        cin >> op;
        
        if (op == 'A') {
            int l, r;
            cin >> l >> r;
            
            // Find all intervals that conflict with [l, r]
            // An interval [a, b] conflicts with [l, r] if they overlap
            // i.e., if max(a, l) <= min(b, r)
            
            vector<Interval> toRemove;
            
            // Find intervals that start before r and end after l
            for (auto it = intervals.begin(); it != intervals.end(); ++it) {
                const Interval& interval = *it;
                if (interval.l > r) break; // No more overlapping intervals
                if (interval.r >= l) { // Overlapping condition
                    toRemove.push_back(interval);
                }
            }
            
            // Remove all conflicting intervals
            for (const auto& interval : toRemove) {
                intervals.erase(interval);
            }
            
            // Add the new interval
            intervals.insert(Interval(l, r));
            
            // Output the number of deleted intervals
            cout << toRemove.size() << '\n';
        } else if (op == 'B') {
            // Output the current number of intervals
            cout << intervals.size() << '\n';
        }
    }
    
    return 0;
}