/*
Given an integer array arr of size N, sorted in ascending order (may contain duplicate values) and a target value k. 
Now the array is rotated at some pivot point unknown to you. Return True if k is present and otherwise, return False. 
*/

bool searchInARotatedSortedArrayII(vector<int>&A, int key) {
   int n = A.size();
   int lo = 0;
   int hi = n-1;
   int ans = -1;

   while(lo<=hi){
       int mid = (hi+lo)/2;

       if(A[mid]==key || A[lo]==key || A[hi]==key) return true;
       if(A[lo]<A[mid]){
           //in left sorted part

           if(A[mid]>key && A[lo]<=key){
               //key lies between lo and mid
               hi = mid-1;
           }else{
               lo = mid + 1;
           }
       }else if(A[lo]>A[mid]){
           //in right sorted part
           if(A[mid]<key && key<A[hi]){
               //key lies between hi and mid
               lo = mid + 1;
           }else{
               hi = mid - 1;
           }
       }else{  // If A[lo] == A[mid], skip duplicates
           lo++;
       }
   }
   return false;
}
/*
Worst Case: 
O(n) - Occurs when all elements in the array are the same, causing the algorithm to degrade to a linear search.

Best Case: 
O(logn) - Occurs when the array has no duplicates and the target can be efficiently found by dividing the search space in half at each step.
*/
