/************************************************************************************************************************************************************************
Daily Problem Statement : 7.10.2022
The problem asked for the maximum value of overlapped intervals at some points each time after adding a new interval. The main challenge here is to find an efficient way to maintain those added intervals and query how many intervals cover a single point quickly and dynamically.
************************************************************************************************************************************************************************
*/
class MyCalendarThree {
private:
    map<int, int> diff;

public:
    MyCalendarThree() {}

    int book(int start, int end) {
        int cur = 0, res = 0;
        diff[start]++;
        diff[end]--;
        for (auto& [_, delta] : diff) {
            cur += delta;
            res = max(res, cur);
        }
        return res;
    }
};
