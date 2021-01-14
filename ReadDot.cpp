//
// Created by Abner Allen on 2021/1/13.
//

#include "ReadDot.h"

void ReadDot::readFromDot() {

    std::ifstream inFile;
    inFile.open(this->fileName, std::ios::binary);
    std::string tmp;
    while(getline(inFile, tmp)){
        this->lines.push_back(tmp);
    }
    inFile.close();

}
