#pragma once // 只编译一次
#include <iostream>
#include <string>
#include <vector>
double cal_number(double num_1, char op, double num_2); // 计算函数定义
void displayLCD(const std::string &number);             // 液晶化函数定义
// 这是液晶化数字的vector
const std::vector<std::vector<std::string>> lcdCharacters =
    {
        {" - ", "| |", "   ", "| |", " - "}, // 0
        {"   ", "  |", "   ", "  |", "   "}, // 1
        {" - ", "  |", " - ", "|  ", " - "}, // 2
        {" - ", "  |", " - ", "  |", " - "}, // 3
        {"   ", "| |", " - ", "  |", "   "}, // 4
        {" - ", "|  ", " - ", "  |", " - "}, // 5
        {" - ", "|  ", " - ", "| |", " - "}, // 6
        {" - ", "  |", "   ", "  |", "   "}, // 7
        {" - ", "| |", " - ", "| |", " - "}, // 8
        {" - ", "| |", " - ", "  |", " - "}, // 9
        {"   ", "   ", "   ", "   ", " . "}, // 小数点 10
        {"   ", "   ", " - ", "   ", "   "}  // 负号 11
};
