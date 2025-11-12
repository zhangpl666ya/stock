//我写的，空间复杂度为1，时间n 复用1的思路，引入一个count计数 还算不错
int removeDuplicates(int* nums, int numsSize){
int count = 0;
int fast = 0, slow = 0;
for(;fast<numsSize;fast++){
	if(nums[fast]==nums[slow]){
		count++;
	}
	else{
		if(count>=2){
			nums[++slow]=nums[fast-1];
			nums[++slow]=nums[fast];
			count = 1;
		}
		else{
			nums[++slow]=nums[fast];
			count = 1;
		}
	}
}
if(count>=2){
nums[++slow]=nums[fast-1];}
return slow+1;
}

//看下大佬写的 栈 优雅至极
#define MIN(a,b) a<b? a:b
int removeDuplicates1(int* nums, int numsSize){
	int top = 2; //前两个直接默认入栈
	for(int i = 2; i<numsSize;i++){
		if(nums[i]!=nums[top-2]) nums[top++]=nums[i];
	}
	return MIN(top,numsSize);
}