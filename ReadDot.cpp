//
// Created by Abner Allen on 2021/1/13.
//

#include "ReadDot.h"

void ReadDot::readFromDot() {

    // 将dot文件内容按行存入lines数组
    std::ifstream inFile;
    inFile.open(this->fileName, std::ios::binary);
    std::string tmp;
    while(getline(inFile, tmp)){
        this->lines.push_back(tmp);
    }
    inFile.close();

}
