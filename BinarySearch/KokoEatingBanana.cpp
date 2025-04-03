/*
A monkey is given ‘n’ piles of bananas, whereas the 'ith' pile has ‘a[i]’ bananas.
An integer ‘h’ is also given, which denotes the time (in hours) for all the bananas to be eaten.
*/
class Solution {
public:

    bool check(int mid,vector<int>&piles,int h){
        long long cnt = 0;
        for(int i=0;i<piles.size();i++){
          cnt += (piles[i] + mid - 1)/mid;
          if(cnt>h) return false;
        }
        return cnt<=h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {

        int n = piles.size();
        int lo = 1;
        int hi = *max_element(piles.begin(), piles.end());
        int ans = hi;
        while(lo<=hi){
            int mid = lo + (hi - lo) / 2; 
            if(check(mid,piles,h)){
                ans = mid;
                hi = mid -1;
            }else{
                lo = mid + 1;
            }
        }
        return ans;
    }
};
