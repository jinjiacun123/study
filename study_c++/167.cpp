#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<cstring>

/*
  167. 两数之和 II - 输入有序数组
中等
1.1K
相关企业

给你一个下标从 1 开始的整数数组 numbers ，该数组已按 非递减顺序排列  ，请你从数组中找出满足相加之和等于目标数 target 的两个数。如果设这两个数分别是 numbers[index1] 和 numbers[index2] ，则 1 <= index1 < index2 <= numbers.length 。

以长度为 2 的整数数组 [index1, index2] 的形式返回这两个整数的下标 index1 和 index2。

你可以假设每个输入 只对应唯一的答案 ，而且你 不可以 重复使用相同的元素。

你所设计的解决方案必须只使用常量级的额外空间。
 

示例 1：

输入：numbers = [2,7,11,15], target = 9
输出：[1,2]
解释：2 与 7 之和等于目标数 9 。因此 index1 = 1, index2 = 2 。返回 [1, 2] 。

示例 2：

输入：numbers = [2,3,4], target = 6
输出：[1,3]
解释：2 与 4 之和等于目标数 6 。因此 index1 = 1, index2 = 3 。返回 [1, 3] 。

示例 3：

输入：numbers = [-1,0], target = -1
输出：[1,2]
解释：-1 与 0 之和等于目标数 -1 。因此 index1 = 1, index2 = 2 。返回 [1, 2] 。
*/

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
      vector<int> reVector;
      
      
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
