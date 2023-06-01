# 最小生成树可视化程序

## 项目内容

本项目是一个最小生成树的可视化程序，主要实现了克鲁斯卡尔算法和普里姆算法的可可视化


## 使用环境

CLion，EGE图形库

## 环境配置

运行前需要修改CMakeLists.txt文件中的ege图形库路径
[EGE图形库下载](https://xege.org/download/ege20.08_all.7z)
下载后解压，将文件夹拷贝到本地然后添加

```
#ege图形库导入，我的是F:/My_Clion/mycenv/EGE20.08
include_directories(F:/My_Clion/mycenv/EGE20.08/include)
link_directories(F:/My_Clion/mycenv/EGE20.08/lib/mingw64)
```

和

```
#ege图形库的包
target_link_libraries(Minimum_Spanning_Tree_Application_Examples libgraphics64.a
        libgdi32.a libimm32.a libmsimg32.a libole32.a
        liboleaut32.a libwinmm.a libuuid.a libgdiplus.a)
````

这个已经在CMakeLists.txt文中设置好了，只需修改下文件夹路径即可

