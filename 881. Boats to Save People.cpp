// You are given an array people where people[i] is the weight of the ith person, and an infinite number of boats where each boat can carry a maximum weight of limit. Each boat carries at most two people at the same time, provided the sum of the weight of those people is at most limit.

// Return the minimum number of boats to carry every given person.

 

// Example 1:

// Input: people = [1,2], limit = 3
// Output: 1
// Explanation: 1 boat (1, 2)
// Example 2:

// Input: people = [3,2,2,1], limit = 3
// Output: 3
// Explanation: 3 boats (1, 2), (2) and (3)
// Example 3:

// Input: people = [3,5,3,4], limit = 5
// Output: 4
// Explanation: 4 boats (3), (3), (4), (5)
 

// Constraints:

// 1 <= people.length <= 5 * 104
// 1 <= people[i] <= limit <= 3 * 104


#pragma GCC optimize("O3", "unroll-loops")
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        unsigned freq[30001]={0};
        int maxW=0, minW=30001;
        for(int x: people){
            freq[x]++;
            maxW=max(maxW, x);
            minW=min(minW, x);
        }
        for (int i=minW, j=0; i<=maxW; i++){
            int f=freq[i];
            fill(people.begin()+j, people.begin()+j+f, i);
            j+=f;
        }      
        int x=0;
        for(int l=0, r=people.size()-1;l<=r; r--){
            x++;
            if (people[l]+people[r]<=limit)
                l++;          
        }
        return x;
    }
};


auto init = []() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();