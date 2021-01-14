#include <iostream>
using namespace std;

#include "ReadDot.h"

int main() {

    ReadDot a("/Users/abnerallen/CLionProjects/CodePartition_BPT/sample.dot");
    a.readFromDot();

    return 0;
}
