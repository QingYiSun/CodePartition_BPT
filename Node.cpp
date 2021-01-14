//
// Created by Abner Allen on 2021/1/14.
//

#include "Node.h"

GraphNode nodes[MAX_NODE_NUM];

void initNodes(){

    for(int i = 0; i < MAX_NODE_NUM; i++){
        // 初始化当前结点直接来自dot的属性
        nodes[i].nodeNo = '\0';
        nodes[i].label = '\0';
        nodes[i].lineNo = -1;
        // 将当前结点的出度设置为0
        for(int j = 0; j < MAX_TARGET_NUM; j++){
            nodes[i].targetNodes[j] = -1;
        }
    }

}

void createNodes(ReadDot obj){

    // 依次处理dot中的每一行
    for(int i = 0; i < obj.lines.size(); i++){

        // 只处理以n开头的当前行
        if(obj.lines[i][0] != 'n'){
            continue;
        }

        int index = 0;

        std::string nx; // the first node's No.

        for(; obj.lines[i][index] != ' '; index++){
            nx += obj.lines[i][index];
        }

        index++; // skip the space

        // case 1: 创建结点，源字符串模式: nx [...];
        if(obj.lines[i][index] == '['){
            //TODO: create node
        }

        // case 2: 添加边，源字符串模式: nx -> ny [...];
        if(obj.lines[i][index] == '-'){
            //TODO: create edge
        }

    }

}