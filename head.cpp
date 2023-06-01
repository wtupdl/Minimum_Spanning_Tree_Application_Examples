//
// Created by asus on 2023/5/9.
//
#include <iostream>
#include "head.h"
#include <time.h>
int node::max_number=100;
int node::min_number=1;
int node::n=0;

int ran::ra(int min_number, int max_number){

    return (int ) rand()  % (max_number + 1 - min_number) + min_number;
}

void node::set(int l, int r){ //设置生成节点坐标的范围
    srand(time(NULL));
    node::min_number=l;
    node::max_number=r;
}
node::node() { //生生坐标和编号
    this->t=node::n;
    this->x = ran::ra(node::min_number, node::max_number);
    this->y = ran::ra(node::min_number, node::max_number);
    node::n++;
}

void node::prin(){ //打印信息
    std::cout<<this->x<<" "<<this->y<<" "<<this->t<<std::endl;
}


edge::edge(int u, int v, int t, int len) {
    this->u = u;
    this->v = v;
    this->t = t;
    this->len = len;
}