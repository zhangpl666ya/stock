/*给你一个整数数组 `prices` ，其中 `prices[i]` 表示某支股票第 `i` 天的价格。

在每一天，你可以决定是否购买和/或出售股票。你在任何时候 **最多** 只能持有 **一股** 股票。然而，你可以在 **同一天** 多次买卖该股票，但要确保你持有的股票不超过一股。

返回 _你能获得的 **最大** 利润_ 。*/
//这个跟1有点差别，可以用栈解决 时间复杂度n 空间复杂度1
int maxProfit(int* prices, int pricesSize) {
	int top = 1;
	int profit = 0;
	for(int i = 1; i< pricesSize;i++){
		if(prices[i]>prices[top-1]){
			prices[top++]=prices[i];
		}
		if(prices[i]<prices[top-1]){
			profit+=prices[top-1]-prices[0];
			prices[top++]=prices[i];
	k		top = 0;
			prices[top++]=prices[i];
		}
	}
	return profit;
k	profit+=prices[top-1]-prices[0];
	return profit;
}

//找到很有意思的思想 贪心算法 一旦涨了就卖出再买入
//贪心算法：局部最优解产生全局最优解

int maxProfit(int* prices, int pricesSize) {
	int in = prices[0];
	int profit = 0;
	for(int i = 1; i< pricesSize;i++){
		if(prices[i]>=in){
			profit += prices[i]-in;
			in = prices[i];
		}
		else{in = prices[i];}
	}
	return profit;
}