#include <iostream>
using namespace std;

#include "Node.h"

int main() {

    // 从dot文件读入每一行
    ReadDot sample("/Users/abnerallen/CLionProjects/CodePartition_BPT/sample.dot");
    sample.readFromDot();

    // 基于读入信息构造图(结点)
    initNodes();
    createNodes(sample);

    // BPT算法

    return 0;
}
