#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

int findRepeatingRandomized(const std::vector<int>& arr) {
    std::srand(std::time(0));
    int N = arr.size();

    for (int i = 0; i < 100; ++i) {  // 100 random trials
        int candidate = arr[std::rand() % N];
        int count = 0;
        for (int num : arr) {
            if (num == candidate) ++count;
        }
        if (count > N / 2) return candidate;
    }
    return -1;
}

int main() {
    std::vector<int> arr = {1, 2, 3, 4, 5, 6, 6, 6, 6, 6};
    std::cout << "Repeating element (Randomized): " << findRepeatingRandomized(arr) << std::endl;
    return 0;
}