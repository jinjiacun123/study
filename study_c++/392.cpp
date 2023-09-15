#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<cstring>

/*
  392. 判断子序列
简单
939
相关企业

给定字符串 s 和 t ，判断 s 是否为 t 的子序列。

字符串的一个子序列是原始字符串删除一些（也可以不删除）字符而不改变剩余字符相对位置形成的新字符串。（例如，"ace"是"abcde"的一个子序列，而"aec"不是）。

进阶：

如果有大量输入的 S，称作 S1, S2, ... , Sk 其中 k >= 10亿，你需要依次检查它们是否为 T 的子序列。在这种情况下，你会怎样改变代码？

致谢：

特别感谢 @pbrother 添加此问题并且创建所有测试用例。

 

示例 1：

输入：s = "abc", t = "ahbgdc"
输出：true

示例 2：

输入：s = "axc", t = "ahbgdc"
输出：false
*/

using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
      bool isOk = true;
      int sLen = s.size();
      int tLen = t.size();
      char *pS = &s[0], *pT = &t[0];

      while(true){
	if(pS - &s[0] >= sLen)
	  return true;

	if(pT - &t[0] >= tLen)
	  return false;
      
	if(*pS == *pT){
	  pS++;
	  pT++;
	}else{
	  pT++;
	}
      }
      
      return isOk;
  }
};

void
test(Solution s,
     map<int,string> paramA,
     map<int,string> paramB,
     map<int,bool> result){
  int i = 0;
  //---------------------------------------------------------
  paramA[i] = "abc";
  paramB[i] = "ahbgdc";
  result[i] = true;
  //---------------------------------------------------------
  i++;
  paramA[i] = "axc";
  paramB[i] = "ahbgdc";
  result[i] = false;
  //---------------------------------------------------------

  //map<int, bool> reValue;
  for(auto [k,v]:paramA){
    cout<<"lab "<<k<<":"<<endl;
    bool value = s.isSubsequence(v, paramB[k]);
    
    //cout<<"|"<<value<<"|"<<endl;
    if(value == result[k]){
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
	map<int, string> a;
	map<int, string> b;
	map<int, bool> result;

	test(s, a, b, result);

	/*string ss = "foo";
	ss.append(20 - ss.length(), ' ');
	cout<<"ss:["<<ss<<"]"<<endl;
	*/

	return 0;	
}
