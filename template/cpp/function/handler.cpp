#include <iostream>
#include <string>
#include "handler.h"

// handler函数的实现
std::string handler(const std::string& req) {
    // 在这里实现处理请求的逻辑
    // 处理过程可以根据具体需求来实现
    // 例如，对输入字符串进行处理，并返回处理后的结果
    std::string result = "Handled request: " + req;
    return result;
}
