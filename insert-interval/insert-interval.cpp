#include <vector>
#include <algorithm>

std::vector<std::vector<int>> insert(std::vector<std::vector<int>>& intervals, std::vector<int>& newInterval) {
    int indexOfStartOfInsert = -10;
    int indexOfEndOfInsert = -10;
    for (int i = 0; i < intervals.size(); i++)
    {
        if (newInterval[0] <= intervals[i][1] && indexOfStartOfInsert == -10)
        {
            indexOfStartOfInsert = i;
            /**
             * If start of range-to-be-inserted falls between the start and end
             * of the previous range.
            */
            if (newInterval[0] < intervals[i][0]
                && (i > 0 && newInterval[0] < intervals[i - 1][1] || i == 0))
            {
                indexOfStartOfInsert--;
            }
        }
        if (newInterval[1] <= intervals[i][1] && indexOfEndOfInsert == -10)
        {
            indexOfEndOfInsert = i;
            /**
             * If end of range-to-be-inserted doesn't actually reach the current range,
             * the range-to-be-inserted must be inserted somewhere around the previous range. 
            */
            if (newInterval[1] < intervals[i][0])
            {
                indexOfEndOfInsert--;
            }
        }
    }


    if (indexOfStartOfInsert == -10)
    {
        //insert at end
        intervals.push_back(newInterval);
        return intervals;
    }

    if (indexOfEndOfInsert == -10)
    {
        //insert from indexOfStartOfInsert to end of intervals
        indexOfEndOfInsert = intervals.size() - 1;
    }

    //insert at very start
    if (indexOfStartOfInsert == -1)
    {
        if (indexOfEndOfInsert == -1)
        {
            intervals.insert(intervals.begin(), newInterval);
            return intervals;
        }
        int newRangeEnd = std::max(newInterval[1], intervals[indexOfEndOfInsert][1]);

        auto it = intervals.erase(intervals.begin(), intervals.begin() + indexOfEndOfInsert + 1);
        intervals.insert(intervals.begin(), {newInterval[0], newRangeEnd});

        return intervals;
    }

    int newRangeStart = std::min(newInterval[0], intervals[indexOfStartOfInsert][0]);
    int newRangeEnd = std::max(newInterval[1], intervals[indexOfEndOfInsert][1]);

    auto it = intervals.erase(intervals.begin() + indexOfStartOfInsert, intervals.begin() + indexOfEndOfInsert + 1);
    intervals.insert(it, {newRangeStart, newRangeEnd});

    return intervals;
}

int main()
{
}