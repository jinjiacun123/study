
#include<iostream>
#include<vector>
#include<map>
#include<stack>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int value = 0;
        int len = height.size();
        int maxheight = 0;
        int left_position = 0,right_position = 0;
        int left_is_set = 0;


        //find max height
        for(int i = 0; i < len; i++)
            if(maxheight < height[i])
                maxheight = height[i];

        while(maxheight > 0){
            left_is_set = 0;
            left_position = right_position = 0;
            for(int i = 0; i < len; i++){
                //find left
                if(left_is_set == 0
                && height[i] > 0){
                    left_is_set = 1;
                    left_position = i;
                    continue;
                }

                //find water
                /*
                if(left > 0
                && height[i] == 0){
                    value ++;
                    continue;
                }*/

                if(left_is_set == 1
                && height[i] > 0){
                    right_position = i;
                    //if have no water between left and right,and take right to left
                    //and set right is zero
                    if(right_position - left_position == 1){
                        left_position = right_position;
                        right_position = 0;
                        continue;
                    }

                    /*cout<<"level:"<<maxheight
                        <<",left position:"<<left_position
                        <<",right:"<<right_position<<endl;
                        */
                    //get water
                    value += right_position - left_position - 1;
                    //clean left
                    left_position = right_position;
                    right_position = 0;
                }
            }
            /*
            cout<<"value:"<<value<<endl;
            cout<<"--------------------"<<endl;
            */


            //whole drop down one level and calulation again
            for(int i = 0; i < len; i++){
                if(height[i] > 0) height[i] -= 1;
            }
            maxheight--;
        }



        return value;
    }
};

void test1(Solution s, vector<int> a){
    a.push_back(0);a.push_back(1);
    a.push_back(0);a.push_back(2);
    a.push_back(1);a.push_back(0);a.push_back(1);
    a.push_back(3);a.push_back(2);a.push_back(1);
    a.push_back(2);a.push_back(1);

    int value= s.trap(a);
    cout<<value;
    cout<<endl;
}

void test2(Solution s, vector<int> a){
    a.push_back(4);
    a.push_back(2);
    a.push_back(0);
    a.push_back(3);
    a.push_back(2);
    a.push_back(5);

    int value = s.trap(a);
    cout<<value;
    cout<<endl;
}


int
main(){
    Solution s;
    vector<int> a;

    test1(s, a);
    test2(s, a);

    return 0;
}

