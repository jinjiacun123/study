#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<cstring>
/*
15. 三数之和
提示
中等
6.4K
相关企业

给你一个整数数组 nums ，判断是否存在三元组 [nums[i], nums[j], nums[k]] 满足 i != j、i != k 且 j != k ，同时还满足 nums[i] + nums[j] + nums[k] == 0 。请

你返回所有和为 0 且不重复的三元组。

注意：答案中不可以包含重复的三元组。

 

 

示例 1：

输入：nums = [-1,0,1,2,-1,-4]
输出：[[-1,-1,2],[-1,0,1]]
解释：
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0 。
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0 。
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0 。
不同的三元组是 [-1,0,1] 和 [-1,-1,2] 。
注意，输出的顺序和三元组的顺序并不重要。

示例 2：

输入：nums = [0,1,1]
输出：[]
解释：唯一可能的三元组和不为 0 。

示例 3：

输入：nums = [0,0,0]
输出：[[0,0,0]]
解释：唯一可能的三元组和为 0 。
*/
using namespace std;

class Solution {
public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> reVector;
      
      
      return reVector;
  }
};

void
test(Solution s,
     map<int,vector<int>> paramA,
     map<int,int> paramB,
     map<int,vector<int>> result){
  int i = 0;
  //---------------------------------------------------------
  paramA[i].push_back(2);
  paramA[i].push_back(3);
  paramA[i].push_back(4);
  paramB[i] = 6;
  result[i].push_back(1);
  result[i].push_back(3);
  //---------------------------------------------------------
  i++;
  paramA[i].push_back(-1);
  paramA[i].push_back(0);
  paramB[i] = -1;
  result[i].push_back(1);
  result[i].push_back(2);
  //---------------------------------------------------------

  //map<int, bool> reValue;
  for(auto [k,v]:paramA){
    cout<<"lab "<<k<<":"<<endl;
    vector<int> value = s.twoSum(v, paramB[k]);
    
    //cout<<"|"<<value<<"|"<<endl;
    int matchTimes = 0;
    int len = result[k].size();
    for(int i = 0; i < len; i++){
      if(result[k][i] == value[i])
	matchTimes++;
    }
    if(matchTimes == len){
      cout<<"-->success"<<endl;
    }else{
      cout<<"-->fail"<<endl;
    }
    cout<<"--------------------"<<endl;    
   }
  cout<<endl;
}

int
main(){
	Solution s;
	map<int, vector<int>> a;
	map<int, int> b;
	map<int, vector<int>> result;

	test(s, a, b, result);

	/*string ss = "foo";
	ss.append(20 - ss.length(), ' ');
	cout<<"ss:["<<ss<<"]"<<endl;
	*/

	return 0;	
}
