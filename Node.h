//
// Created by Abner Allen on 2021/1/14.
//

#ifndef CODEPARTITION_BPT_NODE_H
#define CODEPARTITION_BPT_NODE_H

#include "ReadDot.h"

static const int MAX_NODE_NUM = 1024, MAX_TARGET_NUM = 1024;

struct EdgeInfo{
    int targetNo;
    std::string colorInfo;
};

struct GraphNode{
    std::string nodeNo; // 直接记录dot文件中结点编号，例如：n0，n1，...
    std::string label; // 直接记录dot文件中的label属性
    int lineNo; // 直接记录dot文件中的line属性
    struct EdgeInfo targetNodes[MAX_TARGET_NUM]; // 记录当前结点指向的结点集合
};

void initNodes();
void createNodes(ReadDot obj);

#endif //CODEPARTITION_BPT_NODE_H
