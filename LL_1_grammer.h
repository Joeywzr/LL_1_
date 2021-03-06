//
// Created by Memo on 2018/11/24.
//

#ifndef LL_1_LL_1_GRAMMER_H
#define LL_1_LL_1_GRAMMER_H

#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <map>
#include <string>
#include <iomanip>
#include <stack>

using namespace std;

typedef struct DEDUCTION
{
    string left;
    string right;
    bool is_left_recursion = false;
} DEDUCTION;


class LL_1_grammer
{

    //产生式
    vector<DEDUCTION> deduction;
    //终结符集、非终结符集
    vector<string> nonterminal, terminal;
    //first集、follow集
    map<string, vector<string>> first, follow;
    //起始符
    string start;
    //用于预测分析程序中
    string x;
    //保存预测分析表
    string table[7][10];

public:
    //消除直接左递归
    void remove_direct_left_recursion();
    //初始化
    void init();
    //输出消除直接左递归后的产生式、非终结符集、终结符集、first集、follow集
    void print_test();
    //用于保存产生式
    void ll_pushback(DEDUCTION mid) { deduction.push_back(mid); }
    //生成各非终结符的first集
    void first_set();
    //生成各非终结符的follow集
    void follow_set();
    //获取first集
    vector<string> get_first_set(string to_get_first);
    //获取follow集
    vector<string> get_follow_set(string to_get_follow);
    //生成预测分析表
    void analysis_table();
    //预测分析程序
    void analysis_program(string text);

    int number_non(string s);

    int number_ter(string s);
    //处理数字
    string number_process(string input);
};

#endif //LL_1_LL_1_GRAMMER_H
