#include <vector>
#include <queue>
#include <graphics.h>
#include <algorithm>
#include "head.h"

void update() { //刷新
    int f = 0;
    for (; is_run(); delay_fps(60)) {
        f++;
        if (f > 3)break;
    }
}


int fin(int *g, int i) { //并查集，查找i的祖先节点
    return i == g[i] ? g[i] : g[i] = fin(g, g[i]);
}

void hb(int *g, int i, int j) { //并查集，将i，j合并为一个祖先
    g[fin(g, i)] = fin(g, j);
}

std::vector<edge> kruskal(node *p, int Len) {//克鲁斯卡尔算法
    std::vector<edge> h;
    for (int i = 0; i < Len; i++) { //创建边集合
        for (int j = i + 1; j < Len; j++) {
            int len = (p[i].x - p[j].x) * (p[i].x - p[j].x) + (p[i].y - p[j].y) * (p[i].y - p[j].y);
            h.push_back(edge(i, j, (int) h.size(), len));
        }
    }
    std::sort(h.begin(), h.end()); //排序
    int g[1000];
    for (int i = 0; i < Len; i++)g[i] = i; //创建并查集

    std::vector<edge> f; //存放最小生成树的变集合
    for (int i = 0; i < h.size(); i++) {
        int u = h[i].u;
        int v = h[i].v;

        if (fin(g, u) != fin(g, v)) {
            hb(g, u, v);
            f.push_back(h[i]);
        }

    }
    return f;
};

std::vector<edge> prim(node *p, int Len) {//普里拇算法
    std::vector<std::vector<edge>> h(1000);
    for (int i = 0; i < Len; i++) { //创建边集合
        for (int j = i + 1; j < Len; j++) {
            int len = (p[i].x - p[j].x) * (p[i].x - p[j].x) + (p[i].y - p[j].y) * (p[i].y - p[j].y);
            edge q(i, j, 0, -len);
            h[i].push_back(q);
            h[j].push_back(q);
        }
    }
    std::priority_queue<edge> q; //优先队列
    for (int i = 0; i < h[0].size(); i++) { //选择0号节点相关变为初始边，
        q.push(h[0][i]);
    }

    int g[1000];
    for (int i = 0; i < Len; i++)g[i] = i; //创建并查集
    std::vector<edge> f;
    while (!q.empty()) {
        edge k = q.top();
        q.pop();
        int u = k.u;
        int v = k.v;
        if (fin(g, u) != fin(g, v)) { //核心，选择当前最短边
            hb(g, u, v);
            f.push_back(k);
            for (int i = 0; i < h[u].size(); i++) {
                q.push(h[u][i]);
            }
            for (int i = 0; i < h[v].size(); i++) {
                q.push(h[v][i]);
            }
        }
    }
    return f;
}

int main() {
    //设置节点数量并生成节点
    int len = 20;
    node::set(10, 1190);
    node *p = new node[len];

    ege::initgraph(1200, 1200);
    setlocale(LC_ALL, "chs");//设置文字输出格式
    ege::setbkcolor(EGERGB(82, 137, 11)); //设置窗口背景色为绿色
    ege::setbkmode(TRANSPARENT);//设置输出文字时的背景色为透明
    ege::ege_enable_aa(true);//设置抗锯齿

    std::vector<edge> h1 = kruskal(p, len); //克鲁斯卡尔算法
    std::vector<edge> h2 = prim(p, len); //普里拇算法

    for (int i = 0; i < len; i++) { //绘制点
        ege::setfillcolor(EGEARGB(250, 2, 5, 5));
        ege::ege_fillellipse(p[i].x - 5, p[i].y - 5, 10, 10);
    }

    //连线
    setcaption("克鲁斯卡尔算法"); //设置窗口的标题
    for (int i = 0; i < h1.size(); i++) {
        int u = h1[i].u;
        int v = h1[i].v;
        ege::setcolor(EGEARGB(250, 245, 245, 250));
        ege::ege_line(p[u].x, p[u].y, p[v].x, p[v].y);
        //更新并停顿
        update();
        for (int j = 0; j < 100000000; j++) {
            len++;
            len--;
        }
    }

    setcaption("普里拇算法"); //设置窗口的标题
    for (int i = 0; i < h2.size(); i++) {
        int u = h2[i].u;
        int v = h2[i].v;
        ege::setcolor(EGEARGB(250, 0, 0, 0));
        ege::ege_line(p[u].x, p[u].y, p[v].x, p[v].y);
        update();
        for (int j = 0; j < 100000000; j++) {
            len++;
            len--;
        }
    }
    ege::getch();
    ege::closegraph();
    return 0;
}
