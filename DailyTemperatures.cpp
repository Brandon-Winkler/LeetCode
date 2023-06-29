#include <vector>
#include <iostream>
#include <stack>
#include <utility>

class Solution
{
public:
    std::vector<int> dailyTemperatures(std::vector<int> &temperatures)
    {

        // pair: [index, temp]
        std::stack<std::pair<int, int>> stk;

        // initialize result capacity to be temperatures capacity
        int n = temperatures.size();
        std::vector<int> result(n);

        // loop to push day and temp onto stack
        for (int i = 0; i < n; i++)
        {
            int currDay = i;
            int currTemp = temperatures[i];

            // loop to compare what's on the stack to what is in temperatures
            while (!stk.empty() && stk.top().second < currTemp)
            {
                int prevDay = stk.top().first;
                int prevTemp = stk.top().second;
                stk.pop();

                // store the difference on the result vector
                result[prevDay] = currDay - prevDay;
            }

            stk.push({currDay, currTemp});
        }
        return result;
    }
};

int main()
{
    // initialize vector of temps:
    std::vector<int> temps = {79, 83, 86, 89, 86, 83, 80, 80};

    // create class instance
    Solution Solution;

    // print output
    std::vector<int> res = Solution.dailyTemperatures(temps);
    for (int temperature : res)
    {
        std::cout << temperature << " ";
    }
    std::cout << '\n';

    return 0;
}