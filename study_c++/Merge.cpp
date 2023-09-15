
#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n);
};

void Solution::merge(vector<int>& nums1, int m, vector<int>& nums2, int n){
        int j = 0,k;
        int i = 0;
        int has_move = 0;
        int all_len = m + n;

        //nums1 is empty
        if(m == 0 && n > 0){
            while(j< n){
                nums1[i++] = nums2[j++];
            }
        }else if(n == 0 && m > 0){
            //
        }else if(m > 0 && n > 0){
            for (i = 0; i < m; i++){
                if(j<n
                tt&& nums2[j] < nums1[i]){//move to back,and insert new elem
                    //move
                    for(k = all_len -1; k > i; k--){
                        nums1[k] = nums1[k-1];
                    }
                    //insert
                    nums1[i] = nums2[j++];
                    has_move = 1;
                    m++;
                }
            }
            if(has_move == 1){//move
                while(j < n){
                        nums1[i++] = nums2[j++];
                }
            }else{
                while(j < n){
                    nums1[i++] = nums2[j++];
                }
            }

        }
}

void test1(){
    Solution s;
	vector<int> one;
	one.push_back(1);one.push_back(2);one.push_back(3);
    one.push_back(0);one.push_back(0);one.push_back(0);

	vector<int> two;
	two.push_back(2);two.push_back(5);two.push_back(6);

	s.merge(one, 3, two, 3);

	for(auto i = one.begin(); i < one.end(); i++){
		cout << *i << " ";
	}
	cout<<endl;
}

void test2(){
    Solution s;
	vector<int> one;
	one.push_back(1);


	vector<int> two;

	s.merge(one, 1, two, 0);

	for(auto i = one.begin(); i < one.end(); i++){
		cout << *i << " ";
	}
	cout<<endl;
}

void test3(){
    Solution s;
	vector<int> one;
	one.push_back(0);


	vector<int> two;
	two.push_back(1);

	s.merge(one, 0, two, 1);

	for(auto i = one.begin(); i < one.end(); i++){
		cout << *i << " ";
	}
	cout<<endl;
}

void test4(){
    Solution s;
	vector<int> one;
	one.push_back(1);
    one.push_back(0);

	vector<int> two;
	two.push_back(2);

	s.merge(one, 1, two, 1);

	for(auto i = one.begin(); i < one.end(); i++){
		cout << *i << " ";
	}
	cout<<endl;
}

void test5(){
    Solution s;
	vector<int> one;
	one.push_back(4);
    one.push_back(0);one.push_back(0);one.push_back(0);one.push_back(0);one.push_back(0);

	vector<int> two;
	two.push_back(1);
	two.push_back(2);
	two.push_back(3);
	two.push_back(5);
	two.push_back(6);

	s.merge(one, 1, two, 5);

	for(auto i = one.begin(); i < one.end(); i++){
		cout << *i << " ";
	}
	cout<<endl;
}

void test6(){
Solution s;
	vector<int> one;
	one.push_back(2);
    one.push_back(0);

	vector<int> two;
	two.push_back(1);

	s.merge(one, 1, two, 1);

	for(auto i = one.begin(); i < one.end(); i++){
		cout << *i << " ";
	}
	cout<<endl;
}


int
main(){
    test1();test2();
    test3();test4();
    test5();test6();

	return 0;
}
