
// 010525
/* POTD_LC : Maximum Number of Tasks You Can Assign. (2071)
    * Given 'n' tasks and 'm' workers.
    * Two arrays 'tasks' and 'workers' are given.
        - tasks[i] => strength requirement of i'th task.
        - workers[j] => strength of j'th worker.
    * Every worker can be assigned only one task, such that the task is lesser than or equal to the worker's strength.
        => worker[j] >= tasks[i].

    * Additionally, 'pills' no of magic pills => each pill of having strength 'strength'.
    * We can decide which workers receive the magic pill, but they receive atmost one pill only.
    * It will increase their strength by its corresponding value.

    * Return the maximum number of tasks to be assigned.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

class Solution {
    public:
        static bool desc_order(int a, int b){
            return a > b;
        }

        int assignMaxTasks(vector<int>& tasks, vector<int>& workers, int pills, int strength)        
        {
            // Sorting tasks in ASC.
            sort(tasks.begin(), tasks.end());
            // Sorting workers in DESC.
            sort(workers.begin(), workers.end(), desc_order);

            int l=0, r=min(tasks.size(), workers.size()), mid;
            int maxTasks;

            while(l <= r) {
                mid = l + (r-l)/2;

                if(canComplete(tasks, workers, pills, strength, mid)) {
                    maxTasks = mid;
                    l = mid + 1;
                }
                else {
                    r = mid - 1;
                }
            }
            return maxTasks;
        }

        bool canComplete(vector<int>& tasks, vector<int>& workers, int pills, int strength, int mid)
        {
            multiset<int> workers_set (workers.begin(), workers.begin()+mid);
            int currTaskStrength;

            for(int i=mid-1; i>=0; i--) {
                currTaskStrength = tasks[i];

                auto strongestWorkerIt = prev(workers_set.end());
                if(*strongestWorkerIt >= currTaskStrength) {
                    workers_set.erase(strongestWorkerIt);
                }
                else if(pills > 0) {
                    auto weakestWorkerIt = workers_set.lower_bound(currTaskStrength - strength);
                    if(weakestWorkerIt == workers_set.end()) {
                        // No such worker exists whose strength + pill's strength will solve the task.
                        return false;
                    }
                    workers_set.erase(weakestWorkerIt);
                    pills--;
                }
                else {
                    return false;
                }
            }
            return true;
        }
};

int main(void) {
    int n, m;
    // cout << "Enter tasks count : ";
    cin >> n;
    // cout << "Enter workers count : ";
    cin >> m;

    vector<int> tasks (n);
    vector<int> workers (m);
    // cout << "Enter the " << n << "tasks : ";
    for(int i=0; i<n; i++) {
        cin >> tasks[i];
    }

    // cout << "Enter the " << m << "workers : ";
    for(int i=0; i<m; i++) {
        cin >> workers[i];
    }
    
    int pills, strength;
    // cout << "Enter magic-pills count : ";
    cin >> pills;
    // cout << "Enter magic-pill strength : ";
    cin >> strength;
    int maxTasksAssigned = Solution().assignMaxTasks(tasks, workers, pills, strength);

    cout << "Max Tasks Assigned = " << maxTasksAssigned << endl;

    return 0;
}

/*
//  TCs :-
    1) tasks = [3,2,1], workers = [0,3,3], pills=1, strength=1
        => 3
    2) tasks = [10,15,30], workers = [0,10,10,10,10], pills=3, strength=10
        => 2
    3) tasks = [35], workers = [83,20,4,66], pills=3, strength=41
        => 1
*/