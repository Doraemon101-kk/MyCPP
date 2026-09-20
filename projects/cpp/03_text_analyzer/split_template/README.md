# 学到多文件课程再用

这里是迁移位置，不是另一个要从头做的项目。把上一级main.cpp中自己的实现分别移入include/src/tests。当前仅有接口和提示；测试程序返回2表示尚未编写测试。

在本目录分别构建应用和测试，不把两个main链接在一起：

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic -g -I include src/main.cpp src/text_analysis.cpp -o analyzer.exe
g++ -std=c++17 -Wall -Wextra -pedantic -g -I include tests/test_text_analysis.cpp src/text_analysis.cpp -o tests.exe
.\tests.exe
```

实现后执行应用，例如：`./analyzer.exe --top 3 ../samples/basic.txt`。这个调用形式要等你完成参数读取后才有效，当前骨架只打印提示。

可选CMake留到10/18按自己的最终文件结构写；这里不提前提供复杂构建配置。
