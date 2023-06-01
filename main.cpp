#include <vector>
#include <queue>
#include <graphics.h>
#include <algorithm>
#include "head.h"

void update() { //ˢ��
    int f = 0;
    for (; is_run(); delay_fps(60)) {
        f++;
        if (f > 3)break;
    }
}


int fin(int *g, int i) { //���鼯������i�����Ƚڵ�
    return i == g[i] ? g[i] : g[i] = fin(g, g[i]);
}

void hb(int *g, int i, int j) { //���鼯����i��j�ϲ�Ϊһ������
    g[fin(g, i)] = fin(g, j);
}

std::vector<edge> kruskal(node *p, int Len) {//��³˹�����㷨
    std::vector<edge> h;
    for (int i = 0; i < Len; i++) { //�����߼���
        for (int j = i + 1; j < Len; j++) {
            int len = (p[i].x - p[j].x) * (p[i].x - p[j].x) + (p[i].y - p[j].y) * (p[i].y - p[j].y);
            h.push_back(edge(i, j, (int) h.size(), len));
        }
    }
    std::sort(h.begin(), h.end()); //����
    int g[1000];
    for (int i = 0; i < Len; i++)g[i] = i; //�������鼯

    std::vector<edge> f; //�����С�������ı伯��
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

std::vector<edge> prim(node *p, int Len) {//����Ĵ�㷨
    std::vector<std::vector<edge>> h(1000);
    for (int i = 0; i < Len; i++) { //�����߼���
        for (int j = i + 1; j < Len; j++) {
            int len = (p[i].x - p[j].x) * (p[i].x - p[j].x) + (p[i].y - p[j].y) * (p[i].y - p[j].y);
            edge q(i, j, 0, -len);
            h[i].push_back(q);
            h[j].push_back(q);
        }
    }
    std::priority_queue<edge> q; //���ȶ���
    for (int i = 0; i < h[0].size(); i++) { //ѡ��0�Žڵ���ر�Ϊ��ʼ�ߣ�
        q.push(h[0][i]);
    }

    int g[1000];
    for (int i = 0; i < Len; i++)g[i] = i; //�������鼯
    std::vector<edge> f;
    while (!q.empty()) {
        edge k = q.top();
        q.pop();
        int u = k.u;
        int v = k.v;
        if (fin(g, u) != fin(g, v)) { //���ģ�ѡ��ǰ��̱�
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
    //���ýڵ����������ɽڵ�
    int len = 20;
    node::set(10, 1190);
    node *p = new node[len];

    ege::initgraph(1200, 1200);
    setlocale(LC_ALL, "chs");//�������������ʽ
    ege::setbkcolor(EGERGB(82, 137, 11)); //���ô��ڱ���ɫΪ��ɫ
    ege::setbkmode(TRANSPARENT);//�����������ʱ�ı���ɫΪ͸��
    ege::ege_enable_aa(true);//���ÿ����

    std::vector<edge> h1 = kruskal(p, len); //��³˹�����㷨
    std::vector<edge> h2 = prim(p, len); //����Ĵ�㷨

    for (int i = 0; i < len; i++) { //���Ƶ�
        ege::setfillcolor(EGEARGB(250, 2, 5, 5));
        ege::ege_fillellipse(p[i].x - 5, p[i].y - 5, 10, 10);
    }

    //����
    setcaption("��³˹�����㷨"); //���ô��ڵı���
    for (int i = 0; i < h1.size(); i++) {
        int u = h1[i].u;
        int v = h1[i].v;
        ege::setcolor(EGEARGB(250, 245, 245, 250));
        ege::ege_line(p[u].x, p[u].y, p[v].x, p[v].y);
        //���²�ͣ��
        update();
        for (int j = 0; j < 100000000; j++) {
            len++;
            len--;
        }
    }

    setcaption("����Ĵ�㷨"); //���ô��ڵı���
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
