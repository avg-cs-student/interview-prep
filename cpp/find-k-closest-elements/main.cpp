/*
 * LeetCode: Find K Closest Elements [Daily puzzle 9/29/2022]
 * Author: Justin Cromer
 * Date: Sept 29, 2022
 */

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        // edge cases
        if (x <= arr.at(0))
            return vector<int>(arr.begin(), arr.begin()+k);
        else if (x >= arr.at(arr.size()-1))
            return vector<int>(arr.end()-k, arr.end());      
        
        
        int hi = arr.size()-1;
        int low = 0;
        int mid = arr.size() / 2;
        
        // binary search to find closest element to x
        while (hi > low) {
            if (x > arr.at(mid)) {
                low = mid + 1;
                mid = ((hi - low) / 2 ) + low;
            } else if (x < arr.at(mid)) {
                hi = mid - 1;
                mid = ((hi - low) / 2) + low;
            } else {
                // found x, mid is the marker
                break;
            }
        }
        
        low = max(0, mid-k);
        hi = min((int)arr.size()-1, mid+k);
        
        while (hi - low >= k) {
            if (abs((arr.at(low) - x)) <= abs((arr.at(hi) - x))) {
                --hi;
            } else {
                ++low;
            }
        }
        
        vector<int> v(arr.begin() + low, arr.begin() + hi + 1);
        
        return v;
    }
};
