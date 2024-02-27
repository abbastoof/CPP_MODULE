#include <vector>
#include <iostream>

std::vector<std::vector<int>> createPairs(const std::vector<int>& a) {
    std::vector<std::vector<int>> splitArray;
    std::vector<int> tempArray;

    for (int i = 0; i < a.size(); ++i) {
        tempArray.push_back(a[i]);

        // When tempArray has 2 elements, move them to splitArray
        if (tempArray.size() == 2) {
            splitArray.push_back(tempArray);
            tempArray.clear(); // Clear tempArray for next pair
        }
        // Handle the case where the last element needs to be added alone
        else if (i == a.size() - 1 && a.size() % 2 != 0) {
            splitArray.push_back(tempArray);
        }
    }

    return splitArray;
}

int main() {
    // Example usage
    std::vector<int> input = {1, 2, 3, 4, 5};
    std::vector<std::vector<int>> pairs = createPairs(input);

    // Print the pairs
    for (const auto& pair : pairs) {
        std::cout << "(";
        for (const auto& element : pair) {
            std::cout << element << " ";
        }
        std::cout << "\b)\n"; // '\b' is used to backspace the last space for formatting
    }

    return 0;
}
