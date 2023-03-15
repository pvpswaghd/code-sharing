#include <bits/stdc++.h>

using namespace std;

double findMaxAdjDist(vector<double>& nums){
    int size = nums.size();
    if(size == 1 || size == 0) return 0;
    double min_v = 1000000001, max_v = -1;

    for(int i = 0; i < size; i++){
        if (nums[i] > max_v) max_v = nums[i];
        if (nums[i] < min_v) min_v = nums[i];
    }

    double avg_dist = (max_v-min_v) / (size - 1);

    if(avg_dist==0) return 0;

    vector<double> bucket_min(size, 1000000001);
    vector<double> bucket_max(size, -1);

    int tmp;
    for(int i = 0; i <= size-1; i++){
        tmp = floor((nums[i]-min_v)/avg_dist);
        if(nums[i]>bucket_max[tmp]) bucket_max[tmp] = nums[i];
        if(nums[i]<bucket_min[tmp]) bucket_min[tmp] = nums[i];
    }

    double dist = -1, curr_max; 
    for(int i = 0; i <= size-1; i++){
        cout << i << ": " << bucket_max[i] << " " << bucket_min[i]<< endl;
    }
    
    for(int i = 0; i < size-1; i++){
        if(bucket_max[i]!=-1){
            curr_max = bucket_max[i];
        }
        if(bucket_max[i+1]!=-1 && bucket_min[i+1]!=1000000001) {
            cout << dist << " " << bucket_min[i+1] - curr_max << endl;
            dist = max(dist, bucket_min[i+1] - curr_max);
        }
    }

    return dist;
    
}

int main(){

    vector<double> nums;
    
    nums.push_back(14);
    nums.push_back(5);
    nums.push_back(16.12);
    nums.push_back(11.5);
    nums.push_back(3.2);
    nums.push_back(7);
    cout << findMaxAdjDist(nums) << endl;

    return 0;

}
