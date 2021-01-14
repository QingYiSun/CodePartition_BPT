//
// Created by Abner Allen on 2021/1/13.
//

#ifndef CODEPARTITION_BPT_READDOT_H
#define CODEPARTITION_BPT_READDOT_H

#include <string>
#include <vector>

#include <fstream>
#include <iostream>

class ReadDot {

public:
    ReadDot(std::string fileName){
        this->fileName = fileName;
    }
    void readFromDot();

private:
     std::string fileName;

public:
     std::vector<std::string> lines;

};


#endif //CODEPARTITION_BPT_READDOT_H
