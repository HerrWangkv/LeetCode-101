#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void max_heapify(vector<int> &vec, int start, int end) {
    int dad = start;
    int son = dad * 2 + 1;
    while (son <= end) { 
        if (son + 1 <= end && vec[son] < vec[son + 1]) // 选择较大的子节点
            ++son;
        if (vec[dad] > vec[son]) // 如果父节点大于子节点，直接跳出函數
            return;
        else { // 否则交换父子内容，再比较子孙节点
            swap(vec[dad], vec[son]);
            //交换之后不能保证子节点的值(原父节点的值)大于孙节点的值，故需要继续下去
            dad = son;
            son = dad * 2 + 1;
        }
    }
}

void heap_sort(vector<int> &vec) {
    int len = vec.size();
    // 从最后一个子树开始交换最大值到父节点，保证父节点不比子节点小。结果就是父节点此时最大
    for (int i = len / 2 - 1; i >= 0; i--)
        max_heapify(vec, i, len - 1);
    // 依次将最大元素交换到最后，再缩小考虑范围。
    for (int i = len - 1; i > 0; i--) {
        swap(vec[0], vec[i]);
        max_heapify(vec, 0, i - 1);
    }
}

int main() {
    vector<int> vec{ 3, 5, 3, 0, 8, 6, 1, 5, 8, 6, 2, 4, 9, 4, 7, 0, 1, 8, 9, 7, 3, 1, 2, 5, 9, 7, 4, 0, 2, 6 };
    int len = vec.size();
    heap_sort(vec);
    for (int i = 0; i < len; i++)
        cout << vec[i] << ' ';
    cout << endl;
    return 0;
}