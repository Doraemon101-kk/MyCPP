# 当前学习入口

2026年11月9日起采用“每周一个 C++ 核心差异章节”的项目式推进，不再执行旧的按日任务表，也不要求先清空历史 TODO。

- [C++ 核心差异计划](C++系统学习计划.md)：四个高密度章节、推进规则和评估方式。
- [当前周章](每日计划表.md)：本周唯一执行任务与验收标准。
- [C++ 项目目录](projects/cpp/README.md)：既有代码和后续项目素材。
- [学习记录](学习记录.md)：每周只记录成果、独立程度、卡点和变形结果。

当前练习为 `05_lifetime_and_templates`，与文本分析器同级；`04_cli_text_analyzer` 保留既有源码。2026-11-15已核对统计、TopK、多文件和参数处理源码；2026-11-16晚间按三小时推进第三、四章，第二章仅核对，不重复搭建。具体任务与骨架见当前学习任务。

## 目录约定

所有练习在 `projects/cpp` 同级连续编号：

```text
projects/cpp/
├─ 00_string_count/
├─ 01_vector_references/
├─ 02_score_statistics/
├─ 03_observations/
├─ 04_cli_text_analyzer/
└─ 05_lifetime_and_templates/   今晚入口
```

下一项06。history完整保留原有仓库与发布快照（包括Git历史），不作为当前学习入口。evidence保存核查，计划和学习记录在本目录。

所有原文件保留。旧build缓存带有历史绝对路径，后续使用build_current重新配置。

## 当前阅读讲义

[生命周期、迭代器、泛型与所有权](projects/cpp/05_lifetime_and_templates/知识点阅读.md)：覆盖本次和下一次收尾，附CPP解释与可运行示例。
