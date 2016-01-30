#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), compare);
        vector<vector<Interval>> rooms;
        int n = intervals.size();
        for (int i = 0; i < n; i++) {
            int idx = findNonOverlapping(rooms, intervals[i]);
            if (rooms.empty() || idx == -1)
                rooms.push_back({intervals[i]});
            else rooms[idx].push_back(intervals[i]);
        }
        return (int)rooms.size();
    }
private:
    static bool compare(Interval& interval1, Interval& interval2) {
        return interval1.start < interval2.start;
    }
    int findNonOverlapping(vector<vector<Interval>>& rooms, Interval& interval) {
        int n = rooms.size();
        for (int i = 0; i < n; i++)
            if (interval.start >= rooms[i].back().end)
                return i;
        return -1;
    }
};
