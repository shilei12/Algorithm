#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void DisplayVec(const vector<int>& vec)
{
    for_each(vec.begin(), vec.end(), [](int value) { cout << value << ' ';});
    cout << endl;
}

void BucketSort(vector<int>& vec)
{
    size_t size = vec.size();
    if (vec.size() <= 1) {
        return;
    }
    int max_ = *max_element(vec.begin(), vec.end());
    int min_ = *min_element(vec.begin(), vec.end());
    int bucketNum = (max_- min_) / size + 1;
    vector<vector<int>> vecBucket(bucketNum);
    for_each(vec.begin(), vec.end(), [&vecBucket, &min_, &size](int value) {
        int mark = (value - min_) / size;
        vecBucket[mark].emplace_back(value);
        });
    int cur = 0;
    for_each(vecBucket.begin(), vecBucket.end(), [&vec, &cur](vector<int>& innerVec) {
        if (innerVec.empty()) {
            return;
        }
        stable_sort(innerVec.begin(), innerVec.end());
        for (auto& value : innerVec) {
            vec[cur++] = value;
        }
        });
}

int main()
{
    vector<int> vec{2,3,1,4,6,11,34,15};
    BucketSort(vec);
    DisplayVec(vec); // 1 2 3 4 6 11 15 34 
}