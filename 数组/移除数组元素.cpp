#include<stdio.h>
/*给一个数组num和一个值val，要移除num中等于val的元素，并将不等于val的k个元素移到前面
顺序可能发生改变，但不必管他，您需要输出k的值*/

//我自己写的 9.46MB 时间复杂度为n
int removeElement(int* nums, int numsSize, int val) {
	int p = numsSize - 1;
	int mem = p;
	while (p >= 0 && mem >= 0) {
		if (nums[p] == val) {
			if (p == mem);
			else {
				nums[p] = nums[mem];
			}
			p--;
			mem--;
		}
		else {
			p--;
		}
	}
	return mem - p;
}

//网友的 时间复杂度n 空间复杂度1
int removeElement1(int* nums, int numsSize, int val) {
	int slow = 0, fast = 0;
	for (; fast < numsSize;fast++) {
		if (nums[fast] != val) {
			nums[slow++] = nums[fast];
		}
	}
	return slow;
}
