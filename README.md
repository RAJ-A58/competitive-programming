# 🚀 Competitive Programming

[![Codeforces Rating](https://img.shields.io/badge/Codeforces-1332%20(Pupil)-blue?logo=codeforces)](https://codeforces.com/profile/Raj0106)
[![CSES Solved](https://img.shields.io/badge/CSES-34%20Solved-brightgreen)](https://cses.fi/problemset/)
[![Total Solved](https://img.shields.io/badge/Total%20Solved-90%2B%20Problems-orange)]()
[![Language](https://img.shields.io/badge/Language-C%2B%2B-00599C?logo=c%2B%2B)]()

A structured repository containing clean, optimized, and documented solutions to competitive programming problems from **CSES Problem Set**, **Codeforces**, and **Live Contests**. Focused on algorithmic efficiency, speed, and continuous daily practice.

---

## 📊 Profiles & Live Stats

| Platform | Handle | Rating / Rank | Problems Solved |
| :--- | :--- | :--- | :--- |
| **Codeforces** | [@Raj0106](https://codeforces.com/profile/Raj0106) | **1332** (Pupil) *(Max: 1345)* | **56** in repo *(+1 upsolve staged)* / **93+** on profile |
| **CSES** | [CSES Profile](https://cses.fi/problemset/) | 34 Solved | **34** *(+10 sliding window templates)* |
| **Total Practice Solved** | — | — | **90+ in Repo** *(130+ overall)* |

---

## ⚔️ Codeforces Solutions (56 Solved)

Organized strictly by problem difficulty and rating brackets (contest solutions graduate here directly):

| Difficulty Bracket | Problems Solved | Highlights & Techniques | Folder |
| :--- | :---: | :--- | :--- |
| **Rating 800–1100** | 40 | Fundamentals, Implementation, Greedy, Math, Number Theory, Bitwise | [`Codeforces/Rating_0800_1100/`](Codeforces/Rating_0800_1100/) |
| **Rating 1200–1400** | 13 | Dynamic Programming (2D DP, Pick/No Pick), Sieve, Binary Search, Graph Traversals | [`Codeforces/Rating_1200_1400/`](Codeforces/Rating_1200_1400/) |
| **Rating 1500+** | 3 | Tree Traversals (DFS), Advanced DP, Simulation & State Machines | [`Codeforces/Rating_1500_plus/`](Codeforces/Rating_1500_plus/) |
| **Upsolve** | 1 Staged | Contest problems staged for post-contest solving (`2280D.cpp`) | [`Codeforces/Upsolve/`](Codeforces/Upsolve/) |

👉 *See full breakdown and problem lists in [Codeforces/README.md](Codeforces/README.md)*

---

## 📚 CSES Problem Set (34 Solved)

| # | Section | Solved | Status |
| :---: | :--- | :---: | :---: |
| 01 | **Introductory Problems** | 14 | 🟢 In Progress |
| 02 | **Sorting and Searching** | 9 | 🟢 In Progress |
| 03 | **Dynamic Programming** | 0 | ⚪ Planned |
| 04 | **Graph Algorithms** | 5 | 🟢 In Progress |
| 05 | **Range Queries** | 1 | 🟢 In Progress |
| 06 | **Tree Algorithms** | 0 | ⚪ Planned |
| 07 | **Mathematics** | 2 | 🟢 In Progress |
| 08 | **String Algorithms** | 1 | 🟢 In Progress |
| 09 | **Geometry** | 0 | ⚪ Planned |
| 10 | **Advanced Techniques** | 0 | ⚪ Planned |
| 11 | **Sliding Window Problems** | 1 | 🟢 In Progress (10 templates ready) |
| 12 | **Interactive Problems** | 1 | 🟢 In Progress |
| 13 | **Bitwise Operations** | 0 | ⚪ Planned |
| 14 | **Construction Problems** | 0 | ⚪ Planned |
| 15 | **Advanced Graph Problems** | 0 | ⚪ Planned |
| 16 | **Counting Problems** | 0 | ⚪ Planned |
| 17 | **Additional Problems I** | 0 | ⚪ Planned |
| 18 | **Additional Problems II** | 0 | ⚪ Planned |

👉 *See full breakdown and problem lists in [CSES/README.md](CSES/README.md)*

---

## 🏆 Codeforces Contests Log

Summary of live contest rounds and historical performance:

- **Educational Round 195 (Div. 2)**: 4 problems solved (A, B, C, D) — Rating jump to 1345!
- **Round 1131 (Div. 3)**: 4 problems solved (A, B, C, D) — Fast speed & greedy implementation.
- **Round 2283 / Div. 2**: 3 problems solved (A, B, C) — Tree DP & combinatorics.
- **Round 1133 (Div. 2)**: 4 problems solved (A, B, C, E) — Solved 4 in Div. 2; D staged in Upsolve.

👉 *See contest history and problem links in [CF Contests/README.md](CF%20Contests/README.md)*

---

## 📁 Repository Structure

```text
competitive-programming/
├── CF Contests/                       # Contest history & round logs
│   └── README.md
├── CSES/                              # CSES problem set (18 categories, 34 solved)
│   ├── 01_Introductory/               # 14 problems
│   ├── 02_Sorting_Searching/          # 9 problems
│   ├── 03_Dynamic_Programming/
│   ├── 04_Graph_Algorithms/           # 5 problems (Round Trip, etc.)
│   ├── 05_Range_Queries/              # 1 problem
│   ├── 06_Tree_Algorithms/
│   ├── 07_Mathematics/                # 2 problems
│   ├── 08_String_Algorithms/          # 1 problem
│   ├── 09_Geometry/
│   ├── 10_Advanced_Techniques/
│   ├── 11_Sliding_Window_Problems/    # 1 solved + 10 templates ready
│   ├── 12_Interactive_Problems/       # 1 problem
│   └── ...
├── Codeforces/                        # All practice & contest problems organized by rating
│   ├── Rating_0800_1100/              # 40 problems
│   ├── Rating_1200_1400/              # 13 problems (DP, Sieve, Binary Search, Trees)
│   ├── Rating_1500_plus/              # 3 problems (2A, 580C, 2280E)
│   ├── Upsolve/                       # Contest upsolve staging (2280D.cpp)
│   └── README.md
├── Template.cpp                       # Fast I/O & CP boilerplate (from Roadmap)
├── judge.py                           # One-command Local Judge script
├── judge.bat / judge.ps1              # Local Judge terminal wrappers
├── GEMINI.md                          # Repository workflow & organization rules
├── .gitignore                         # Ignores executables (*.exe) and build files
└── README.md
```

---

## ⚖️ Local Judge & Fast Workflow

- **C++ Template**: Located at [`Template.cpp`](Template.cpp). Follows the roadmap boilerplate with `solve()`, fast I/O (`cin.tie(nullptr)`), and `t` test case handling.
  - *VS Code Snippet*: Type `cf` or `template` inside any `.cpp` file and press `Tab` to expand.
- **Local Judge**: Compile and run against sample tests in **one command**:
  - **VS Code Shortcut**: Press `Ctrl+Shift+B` with any problem `.cpp` file active.
  - **Terminal**: `python judge.py <file.cpp>` or `.\judge.bat <file.cpp>`.
  - **Interactive Mode**: `python judge.py <file.cpp> -i`.
  - **Test Case Formats Supported**:
    - `input.txt` & `expected.txt` (or `output.txt`) in problem folder or root.
    - Numbered pairs: `in1.txt` & `out1.txt`, `sample1.in` & `sample1.out`, etc.
    - Multi-test delimiters in `tests.txt` (`=== INPUT ===` / `=== OUTPUT ===`).
  - **Features**: Automatic compilation with `-O2 -std=c++17`, ms execution timer, TLE detection, colored diff on WA, and zero artifact clutter.

---

## 🛠️ Standards & Best Practices

- **Language**: Modern C++ (C++17 / C++20).
- **Time & Space Complexity**: Analyzed and optimized to comfortably avoid TLE/MLE.
- **Fast I/O**: `ios::sync_with_stdio(false); cin.tie(nullptr);` where appropriate.
- **Clean Commits**: Meaningful commit messages pushed consistently on the day of solving.
