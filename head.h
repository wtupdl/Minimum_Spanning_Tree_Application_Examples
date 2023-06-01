//
// Created by asus on 2023/5/9.
//

#include <iostream>
#include <random>

#ifndef CSTUDY_NODE_H
#define CSTUDY_NODE_H

//用于生成指定范围且不重复随机数的类
class ran {
public:
    static int ra(int min_number, int max_number);
};
//生成节点坐标的类
class node {
public:
    int x, y, t;//节点横纵坐标，节点编号
    static int min_number, max_number, n;//静态成员，用于设置坐标范围和当前总节点个数
    static void set(int l, int r); //设置节点坐标范围
    node(); //构造函数，生成节点坐标
    void prin();
};

//存放边信息的类
class edge {
public:
    int u, v, t, len;//存放边的节点编号，边编号，边长度的平方

    edge(int u, int v, int t, int len);

    bool operator<(const edge &a) const { //重载运算符
        return this->len < a.len;
    }

    bool operator>(const edge &a) const { //重载运算符
        return this->len > a.len;
    }
};

#endif //CSTUDY_NODE_H
