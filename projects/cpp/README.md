# 新版 C++ 骨架

按 [当前课程](E:/theCPP/learning_plan_20260914/C++系统学习计划.md) 使用。现在从 **01_observations/main.cpp** 开始。

| 顺序 | 文件夹 | 对应课程 | 做出的东西 |
|---|---|---|---|
| 0 | [00：已有练习](00/README.md) | 之前的 practice | 字符统计、vector、成绩统计，保留原代码及 Git 仓库 |
| 1 | [01_observations](E:/theCPP/learning_plan_20260914/projects/cpp/01_observations/README.md) | 9/21–9/22；做得快可连续推进 | 筛选、最近点、平移、自定义排序与TopK |
| 2 | [02_robot](E:/theCPP/learning_plan_20260914/projects/cpp/02_robot/README.md) | 9/23、9/26–9/27、10/3、10/13 | 地图移动、历史、撤销重放、命令队列、寻路 |
| 3 | [03_text_analyzer](E:/theCPP/learning_plan_20260914/projects/cpp/03_text_analyzer/README.md) | 9/30、10/4–10/7、10/10–10/12、10/17–10/18 | 词频统计、文件、参数、多文件分析与报告 |
| 4 | [04_labs](E:/theCPP/learning_plan_20260914/projects/cpp/04_labs/README.md) | 9/28–9/29、10/12、10/14 | 生命周期、vector失效、TopK、简单模板 |

骨架提供头文件、部分数据结构、函数声明、样例和TODO。**功能尚未实现。** 初始程序只显示骨架提示；编译成功不代表学习任务完成。先在声明后补自己的函数定义，再把main中的调用串起来。

每次按项目README完成一段连续任务；案例是验收依据，不是实现答案。接口是建议，理解需求后可以调整。专项练习是课程指定时才打开的材料，不要现在四组一起做。

早期每个main.cpp是独立程序。进入该目录后运行：

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic -g main.cpp -o app.exe
.\app.exe
```

不要在整个cpp文件夹执行`g++ *.cpp`或把所有项目的main一起链接。文本分析器的多文件模板另有明确构建命令，学到10/10再用。

Python 复习骨架稍后按当前课程重新制作。



