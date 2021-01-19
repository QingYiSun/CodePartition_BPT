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
            // 为结点添加属性nodeNo
            nodes[nx_no].nodeNo = nx;

            // 为结点添加属性label
            int loc_str1 = partLeft.find("label");
            std::string label;
            for(int j = loc_str1 + 7; j < partLeft.length(); j++){
                if(partLeft[j] == '"'){
                    break;
                }
                label += partLeft[j];
            }
            nodes[nx_no].label = label;

            // 为结点添加属性lineNo，可选（包含line属性的结点）
            if(partLeft.find("line=") != std::string::npos){
                int loc_str2 = partLeft.find("line=");
                std::string line;
                for(int j = loc_str2 + 5; j < partLeft.length(); j++){
                    if(partLeft[j] == ','){
                        break;
                    }
                    line += partLeft[j];
                }
                int lineNo = std::stoi(line);
                nodes[nx_no].lineNo = lineNo;
            }
        }

        // case 2: 添加边，源字符串模式: nx -> ny [...];
        if(partLeft[0] == '-'){
            // 寻找出边的指向结点targetNo
            int loc_str1 = 4;
            std::string trg;
            for(int j = loc_str1; partLeft[j] != '['; j++){
                trg += partLeft[j];
            }
            int trgNo = std::stoi(trg);

            // 遍历数组targetNodes，找到第一个空位
            int firstSpace = 0;
            for(; nodes[nx_no].targetNodes[firstSpace].targetNo != -1; firstSpace++);

            // 将trgNo填入nodes[nx_no].targetNodes[firstSpace]
            nodes[nx_no].targetNodes[firstSpace].targetNo = trgNo;

            // 寻找color属性
            int loc_str2 = partLeft.find("color=");
            loc_str2 += 6;
            std::string color;
            for(; partLeft[loc_str2] != ']'; loc_str2++){
                color += partLeft[loc_str2];
            }
            nodes[nx_no].targetNodes[firstSpace].colorInfo = color;
        }

    }

}