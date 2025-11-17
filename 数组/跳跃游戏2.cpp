/*给定一个长度为 `n` 的 **0 索引**整数数组 `nums`。初始位置在下标 0。

每个元素 `nums[i]` 表示从索引 `i` 向后跳转的最大长度。换句话说，如果你在索引 `i` 处，你可以跳转到任意 `(i + j)` 处：

- `0 <= j <= nums[i]` 且
- `i + j < n`

返回到达 `n - 1` 的最小跳跃次数。测试用例保证可以到达 `n - 1`。*/

//参考前面那题，贪心算法即可解决 时间复杂度n 空间复杂度1
int jump(int*nums,int numsSize){
	int count=0;
	int i = 0;
	while(i!=numsSize-1){
		int max_idx = i+1;
		if(i+nums[i]>=numsSize-1){
			count++;
			goto here;
		}
		for(int j = i+1;j<=nums[i]+i&&j<numsSize;j++){
			max_idx = nums[j]+j>nums[max_idx]+max_idx?j:max_idx;
		}
		
		i = max_idx;
		count++;
	}
	here:
	return count;
}