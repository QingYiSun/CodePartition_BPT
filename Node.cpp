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
            nodes[i].targetNodes[j].targetNo = -1;
            nodes[i].targetNodes[j].colorInfo = '\0';
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

        int nx_no = std::stoi(nx.substr(1));

        index++; // skip the space

        std::string partLeft = obj.lines[i].substr(index); // 提取完首结点编号后剩余的字符串

        // case 1: 创建结点，源字符串模式: nx [...];
        if(partLeft[0] == '['){
            //TODO: create node
            nodes[nx_no].nodeNo = nx;

            int loc_str1 = partLeft.find("label");
            std::string label;
            for(int j = loc_str1 + 7; j < partLeft.length(); j++){
                if(partLeft[j] == '"'){
                    break;
                }
                label += partLeft[j];
            }
            nodes[nx_no].label = label;

            if(partLeft.find("line=") != std::string::npos){
                int loc_str2 = partLeft.find("line=");
                //TODO: here to continue
            }
        }

        // case 2: 添加边，源字符串模式: nx -> ny [...];
        if(partLeft[0] == '-'){
            //TODO: create edge
        }

    }

}