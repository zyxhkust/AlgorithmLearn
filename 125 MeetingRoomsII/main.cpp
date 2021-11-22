#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
class Solution{
public:
    /*It's a greedy solution*/
    int minMeetingRooms(vector<vector<int>>& intervals) {
        if (intervals.empty()) return 0;
        // first sort the intervals by start time
        sort(intervals.begin(), intervals.end(), [](auto& i1, auto& i2){return i1[0] < i2[0];});
        // maintian a min heap to store end time (only storing an end time is not enough)
        priority_queue<int> endTimes;
        // here we add minus sign because priority queue is max heap while we want a min heap
        endTimes.push(-intervals[0][1]);
        // the max num of meeting room is the max size of the priority_queue
        size_t res = 1;
        for(int i = 1; i < intervals.size(); i++){
            while(!endTimes.empty() && -endTimes.top() <= intervals[i][0]){
                endTimes.pop();
            }
            endTimes.push(-intervals[i][1]);
            res = max(endTimes.size(), res);
        }
        return res;
    }
};

int main(){
    Solution s;
    vector<vector<int>> input = {{0,30}, {5, 10}, {15,20}};
    vector<vector<int>> input1 = {{7, 10}, {2, 4}};
    cout << s.minMeetingRooms(input) << endl;
    cout << s.minMeetingRooms(input1) << endl;

}
