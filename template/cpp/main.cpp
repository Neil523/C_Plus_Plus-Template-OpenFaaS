#include <iostream>
#include <string>
#include "handler.h" // handler函数在handler.h中声明并在handler.cpp中定义

std::string get_stdin() {
    std::string buf;
    while (true) {
        std::string line;
        std::getline(std::cin, line); // 使用std::getline()从标准输入读取一行内容
        buf += line;
        if (line == "")
            break;
    }
    return buf;
}

int main() {
    std::string st = get_stdin(); // 调用get_stdin()函数，将从标准输入读取的内容保存在变量st中
    std::string ret = handler(st); // handler函数在handler.cpp中定义，并在这里调用它处理输入内容
    if (!ret.empty()) {
        std::cout << ret << std::endl; // 将处理结果打印到标准输出
    }
    return 0;
}
