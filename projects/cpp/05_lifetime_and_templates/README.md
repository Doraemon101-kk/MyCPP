# 05 生命周期与模板练习

今晚的第三、四章练习。与 `04_cli_text_analyzer` 同级，直接打开 `main.cpp` 即可，不依赖其他练习的头文件。

- 第三章：`remove_below`、`remove_short_words_loop`、`remove_short_words_erase_remove`；分析生命周期、视图和迭代器失效。
- 第四章：`select_where`、`keep_report`；泛型筛选、标准算法和所有权。

核心实现由你完成；已有断言供验收。占位函数返回 TODO，不能当作测试通过。

在本目录运行：

```powershell
g++ -std=c++17 -Wall -Wextra -pedantic main.cpp -o practice.exe
.\practice.exe 3
.\practice.exe 4
```

第三章对应参数3，第四章对应参数4。完整节奏见[当前学习任务](../../../每日计划表.md)。

## 字符串删除的两个版本

循环版remove_short_words_loop保留已有实现；erase-remove版remove_short_words_erase_remove的函数体由学习者填写。两者有独立声明，main使用各自的新输入执行相同的断言。

- `./practice.exe 3-loop`：只验收已完成的循环版及map删除。
- `./practice.exe 3-erase-remove`：验收第二版及map删除，未填写时返回2。
- `./practice.exe 3`：依次验收两版，第二版未完成不能显示全部通过。

## 完整知识点阅读

[阅读讲义](知识点阅读.md)系统解释本次与下次内容，并对照C基础、逐段解释CPP代码。[reading_examples.cpp](reading_examples.cpp)是可单独编译的完整参考，涵盖扩容、删除、模板、捕获、标准算法、所有权和组合筛选。原main.cpp不改动；准备独立练习时可先完成再看参考。
