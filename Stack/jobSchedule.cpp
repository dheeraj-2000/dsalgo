#include<bits/stdc++.h>
using namespace std;
struct Job
{
    int id;  // Job Id
    int dead; // Deadline of job
    int profit; // Profit if job is over before or on deadline
};


class Solution
{
public:
    //Function to find the maximum profit and the number of jobs done.
    static bool comparator(struct Job m1, struct  Job m2) {
        if (m1.profit > m2.profit)return true;
        else return false;
    }
    vector<int> JobScheduling(Job arr[], int n)
    {
        // your code here
        sort(arr, arr + n, comparator);
        vector<int> ans;

        for (int i = 0; i < n; i++) {
            cout << "Profit : " << arr[i].profit << endl;
        }

        int count = 0;
        int maxDead = arr[0].dead;
        for (int i = 1; i < n; i++)
            maxDead = max(arr[i].dead, maxDead);

        int vis[maxDead + 1] = {0};
        int sum = 0;


        for (int i = 0; i < n; i++) {
            if (vis[arr[i].dead] == 0) {
                sum += arr[i].profit;
                cout << "SUM : " << sum << " id : " << arr[i].id << endl;
                vis[arr[i].dead] = arr[i].dead;
                count++;
            }


            else {
                int j = arr[i].dead;
                while (vis[j ] != 0) {
                    j--;
                }
                if (j > 0 && arr[i].dead > j) {
                    sum += arr[i].profit;
                    cout << "SUM : " << sum << " id : " << arr[i].id << endl;
                    vis[j] = arr[j].dead;
                    count++;
                }
            }
        }


        ans.push_back(count);
        ans.push_back(sum);

        return ans;
    }
};


int main() {
#ifndef ONLINE_JUDGE
    //for getting input from input.txt
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    struct Job jb[n];
    for (int i = 0; i < n; i++) {
        int x, y, z;
        cin >> x >> y >> z;

        jb[i].id = x;
        jb[i].dead = y;
        jb[i].profit = z;
    }
    // cout << n;
    Solution st;

    vector<int> ans = st.JobScheduling(jb, n);

    cout << ans[0] << " " << ans[1];
}