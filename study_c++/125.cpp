#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<cstring>

/*
  如果在将所有大写字符转换为小写字符、并移除所有非字母数字字符之后，短语正着读和反着读都一样。则可以认为该短语是一个 回文串 。

字母和数字都属于字母数字字符。

给你一个字符串 s，如果它是 回文串 ，返回 true ；否则，返回 false 。

 

示例 1：

输入: s = "A man, a plan, a canal: Panama"
输出：true
解释："amanaplanacanalpanama" 是回文串。

示例 2：

输入：s = "race a car"
输出：false
解释："raceacar" 不是回文串。

示例 3：

输入：s = " "
输出：true
解释：在移除非字母数字字符之后，s 是一个空字符串 "" 。
由于空字符串正着反着读都一样，所以是回文串。
*/

using namespace std;

class Solution {
public:
    bool isPalindrome(string s)  {
      bool isOk = true;
      string targetStr;
      int sLen = s.size();
      char *pLeft, *pRight;
      char ch;

      if(sLen == 1)
	return true;
	 
      pLeft = &s[0]; pRight = pLeft + sLen -1;

      while(true){
	//upper case to lower case
	if( (ch = *pLeft) >= 'A'
	       && ch <= 'Z'){
	  ch = ch - 'A' + 'a';
	  *pLeft = ch;
	}
	if( (ch = *pRight) > 'A'
	       && ch <= 'Z'){
	  ch = ch - 'A' + 'a';
	  *pRight = ch;
	}
	//clean black and other is not letter
        if(!((ch = *pLeft) >= 'a' && ch <= 'z')
	   && pRight - pLeft >= 0 ){
	  pLeft++;
	  continue;
	}
	if(!((ch = *pRight) >= 'a' && ch <= 'z')
	  && pRight - pLeft >= 0){
	  pRight--;
	  continue;
	}
      
      
	if(*pLeft == *pRight
	   && pRight - pLeft >= 0){
	  //cout<<"pLeft:"<<*pLeft<<",pRight:"<<*pRight<<endl;
	  //cout<<"pLeft point:"<<pLeft<<",pRight point:"<<pRight<<endl;
	  //cout<<"pRight-pLeft:"<<pRight - pLeft <<endl;
	  if(pRight - pLeft == 0){
	    break;
	  }
	  pLeft ++;
	  pRight --;
	}else{
	  //cout<<"pRight-pLeft:"<<pRight - pLeft <<endl;
	  //cout<<"failt"<<endl;
	  if(pRight - pLeft > 0){
	    return false;
	  }
	}
      }

      
      
      return isOk;
  }
};

void
test(Solution s,
     map<int,string> paramA,
     map<int,bool> result){
  int i = 0;
  //---------------------------------------------------------
  paramA[i] = "A man, a plan, a canal: Panama";
  result[i] = true;
  //---------------------------------------------------------
  i++;
  paramA[i] = "race a car";  
  result[i] = false;
  //---------------------------------------------------------
  i++;
  paramA[i] = " ";
  
  result[i] = true;

  //map<int, bool> reValue;
  for(auto [k,v]:paramA){
    cout<<"lab "<<k<<":"<<endl;
    bool value = s.isPalindrome(v);
    
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
	map<int, bool> result;

	test(s, a, result);

	/*string ss = "foo";
	ss.append(20 - ss.length(), ' ');
	cout<<"ss:["<<ss<<"]"<<endl;
	*/

	return 0;	
}
