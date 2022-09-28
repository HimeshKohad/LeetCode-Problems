class Solution:
    def findTheDistanceValue(self, arr1, arr2, d):
        ans=len(arr1)
        for i in arr1:
            for j in arr2:
                if abs(i-j) <=d:
                    ans-=1
                    break
        return ans
