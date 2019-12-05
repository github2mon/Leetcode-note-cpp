/*
有两个大小分别为m和n的有序数组A和B。请找出这两个数组的中位数。你需要给出时间复杂度在O(log (m+n))以内的算法。

There are two sorted arrays A and B of size m and n respectively. Find the median of the two sorted arrays.
The overall run time complexity should be O(log (m+n)).
*/

class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) 
    {
        if (abs(m - n) & 0x1)
            return medianRecursion(A, m, B, n, m + (n - m + 1) / 2);
        else
            return m_ave(medianRecursion(A, m, B, n, m + (n - m) / 2), medianRecursion(A, m, B, n, m + (n - m) / 2 + 1));
    }
	
private:
    double medianRecursion(int A[], int m, int B[], int n, int k) //Convert to the kth smallest number
    {
        if (m > n)
            return medianRecursion(B, n, A, m, k);
        if (m == 0)
            return B[k - 1];
        if (k == 1)
            return min(A[0], B[0]);
        int mA = min(k / 2, m), mB = k - mA;
        if (A[mA-1] < B[mB-1])
            return medianRecursion(A + mA, m - mA, B, n, k - mA);
        else if (A[mA-1] == B[mB-1])
            return A[mA-1];
        else
            return medianRecursion(A, m, B + mB, n - mB, k - mB);
    }

    double m_ave(double x, double y)
    {
        return x + (y - x) / 2;
    }
};
