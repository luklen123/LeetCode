/*
 * LeetCode 3720: Lexicographically Smallest Permutation Greater Than Target
 * Link: https://leetcode.com/problems/lexicographically-smallest-permutation-greater-than-target
 * Approach: Custom
 */

class Solution {
public:
    string lexGreaterPermutation(string s, string target){
        int n = s.size();
        vector<int> occ(26, 0);
        for(int i=0; i<n; i++) occ[s[i] - 'a']++;

        int idx = 0;
        while(idx < n && occ[target[idx] - 'a'] > 0){
            occ[target[idx] - 'a']--;
            idx++;
        }

        if(idx == n){
            idx--;
            occ[target[idx] - 'a']++;
        }

        string result = "";
        while(idx >= 0){
            for(int i=target[idx] - 'a' + 1; i<26; i++){
                if(occ[i] > 0){
                    result = target.substr(0, idx) + (char)('a' + i);
                    occ[i]--;

                    for(int j=0; j<26; j++){
                        while(occ[j] > 0){
                            occ[j]--;
                            result += (char)('a' + j);
                        }
                    }
                    return result;
                }
            }
            idx--;
            if(idx >= 0) occ[target[idx] - 'a']++;                
        }

        return "";
    }
};

/*
 * TIME COMPLEXITY: O(n)
 * Where 'n' is the length of string 's'. We iterate through the string a constant number of times.
 * 
 * SPACE COMPLEXITY: O(1)
 * We only use a fixed size integer array.
 */
