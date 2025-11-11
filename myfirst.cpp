nclude<stdio.h>
//将两个有序数列合并到第一个序列（第一个序列空间够用）
//大佬的方法，时间复杂度m+n，空间复杂度为零
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
	int p = m + n - 1;
	while (m > 0 || n > 0) {
		if (m > 0 && n > 0) {
			nums1[p--] = nums1[m - 1] > nums2[n - 1] ? nums1[--m] : nums2[--n];
		}
		else if (n > 0) {
			nums1[p--] = nums2[--n];
		}
		else return;
	}
}
//优雅至极
