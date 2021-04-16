#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <vector>
#include <cassert>
#include <set>

using namespace std;

int minimum_index(vector<int> seq) {
    if (seq.empty()) {
        throw invalid_argument("Cannot get the minimum value index from an empty sequence");
    }
    int min_idx = 0;
    for (int i = 1; i < seq.size(); ++i) {
        if (seq[i] < seq[min_idx]) {
            min_idx = i;
        }
    }
    return min_idx;
}

class TestDataEmptyArray {
public:
    static vector<int> get_array() {
        // complete this function
        
        vector<int> a;
        return a;
    }

};

class TestDataUniqueValues {
public:
    static vector<int> get_array() {
        // complete this function
             vector<int> a{1,2,3,4,5,6,7};
             return a;
    }

    static int get_expected_result() {
        // complete this function
        return 0;
    }

};

class TestDataExactlyTwoDifferentMinimums {
public:
    static vector<int> get_array() {
        // complete this function
        vector<int> a{1,2,3,4,5,1,6,7};
        return a;
    }

    static int get_expected_result() {
        // complete this function
        return 0;
    }

};

