#include <dynamic_array.h>

#include <iostream>

int main() {
    nonsense::DynamicArray<int> ints;
    std::cout << "made an array...\n";

    ints.push_back(1);
    ints.push_back(2);
    ints.push_back(3);

    for (auto & i : ints) {
	std::cout << i << "\n";
    }

    std::cout << ints.front() << "\n";
    std::cout << ints.back() << "\n";

    for (int i = 0; i < 100; ++i) {
	ints.push_back(i);
    }

    std::cout << ints.back() << "\n";

    for (int i =0 ; i < 10; ++i) {
	ints.pop_back();
    }
    std::cout << ints.back() << "\n";
}
