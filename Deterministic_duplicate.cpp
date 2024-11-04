#include <iostream>
#include <vector>
#include <unordered_map>

int findRepeatingDeterministic(const std::vector<int>& arr) {
    std::unordered_map<int, int> count;
    int N = arr.size();

    for (int num : arr) {
        if (++count[num] > N / 2) return num;
    }
    return -1;
}

int main() {
    std::vector<int> arr = {1, 2, 3, 4, 5, 6, 6, 6, 6, 6};
    std::cout << "Repeating element (Deterministic): " << findRepeatingDeterministic(arr) << std::endl;
    return 0;
}