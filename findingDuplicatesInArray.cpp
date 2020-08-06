/*
Given that find value which appears "twice" (only twice not more than that)
and the constraint given that values in array must be greater than 1 and less
than size of array i.e 1 <= a[i] <= n
Using these two knowledge we can find solution in n times without extra space

the idea is that:
mark every number in given array as negative number so that the next time when
we visit the same value and if it is marked negative then it is already visited
and is appears twice.
index                 element                       Todo
0                      A[0] = 4                   A[4-1] Not negative
                                             do it negetive mean we visited 4
                                             array - [4,3,2,-7,8,2,3,1]

1                     A[1] = 3                      A[3-1] Not negative
                                             do it negetive mean we visited 3
                                               array - [4,3,-2,-7,8,2,3,1]

2                      A[2] = 2                      A[2-1] Not negative
                                           do it negetive mean we visited 2
                                           array - [4,-3,-2,-7,8,2,3,1]

3                        A[3]=7                      A[7-1] Not negative
                                             do it negetive mean we visited 7
                                              Array- [4,-3,-2,-7,8,2,-3,1]

4                       A[4]=8                      A[8-1] Not negative
                                          do it negetive mean we visited 8
                                          Array- [4,-3,-2,-7,8,2,-3,-1]

5                     A[5]=2                       A[2-1] is Negative Mean It is A
                                         duplicate ele so Put it into ans array
                                    Array- [4,-3,-2,-7,8,2,-3,-1]

6                   A[6]=3                        A[3-1] is Negative Mean It is A
                                        duplicate ele so Put it into ans array
                                             Array- [4,-3,-2,-7,8,2,-3,-1]

7                  A[7] = 1                     A[1-1] Not negative
                                             do it negetive mean we visited 1
                                            Array- [-4,-3,-2,-7,8,2,-3,-1]
*/
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        //checking if array is empty or not
        if(nums.empty())
            return {};
        for(int i = 0; i < nums.size(); i++)
        {
            //checking if the value at [value of ith ] - 1 is negative or not
            // if negative push_back in ans array
            if(nums[abs(nums[i]) - 1] < 0)
                ans.push_back(abs(nums[i]));

            //if the value is not negative mark it as negative
            nums[abs(nums[i]) - 1] = - nums[abs(nums[i]) - 1];

        }
        return ans;
    }
};
