# 🚀 Competitive Programming

[![Codeforces Rating](https://img.shields.io/badge/Codeforces-1246%20(Pupil)-blue?logo=codeforces)](https://codeforces.com/profile/Raj0106)
[![CSES Solved](https://img.shields.io/badge/CSES-33%20Solved-brightgreen)](https://cses.fi/problemset/)
[![Total Solved](https://img.shields.io/badge/Total%20Solved-64%20Problems-orange)]()
[![Language](https://img.shields.io/badge/Language-C%2B%2B-00599C?logo=c%2B%2B)]()

A structured repository containing clean, optimized, and documented solutions to competitive programming problems from **CSES Problem Set**, **Codeforces**, and **Live Contests**. Focused on algorithmic efficiency, speed, and continuous daily practice.

---

## 📊 Profiles & Live Stats

| Platform | Handle | Rating / Rank | Problems Solved |
| :--- | :--- | :--- | :--- |
| **Codeforces** | [@Raj0106](https://codeforces.com/profile/Raj0106) | **1246** (Pupil) *(Max: 1283)* | **31** |
| **CSES** | [CSES Profile](https://cses.fi/problemset/) | 33 Solved | **33** |
| **Total Practice Problems** | — | — | **64+** |

---

## 📚 CSES Problem Set (33 Solved)

| # | Section | Solved | Status |
| :---: | :--- | :---: | :---: |
| 01 | **Introductory Problems** | 14 | 🟢 In Progress |
| 02 | **Sorting and Searching** | 9 | 🟢 In Progress |
| 03 | **Dynamic Programming** | 0 | ⚪ Planned |
| 04 | **Graph Algorithms** | 4 | 🟢 In Progress |
| 05 | **Range Queries** | 1 | 🟢 In Progress |
| 06 | **Tree Algorithms** | 0 | ⚪ Planned |
| 07 | **Mathematics** | 2 | 🟢 In Progress |
| 08 | **String Algorithms** | 1 | 🟢 In Progress |
| 09 | **Geometry** | 0 | ⚪ Planned |
| 10 | **Advanced Techniques** | 0 | ⚪ Planned |
| 11 | **Sliding Window Problems** | 1 | 🟢 In Progress |
| 12 | **Interactive Problems** | 1 | 🟢 In Progress |
| 13 | **Bitwise Operations** | 0 | ⚪ Planned |
| 14 | **Construction Problems** | 0 | ⚪ Planned |
| 15 | **Advanced Graph Problems** | 0 | ⚪ Planned |
| 16 | **Counting Problems** | 0 | ⚪ Planned |
| 17 | **Additional Problems I** | 0 | ⚪ Planned |
| 18 | **Additional Problems II** | 0 | ⚪ Planned |

👉 *See full breakdown and problem lists in [CSES/README.md](file:///e:/cpp/competitive-programming/CSES/README.md)*

---

## ⚔️ Codeforces Solutions (31 Solved)

Organized strictly by problem difficulty and rating brackets:

| Difficulty Bracket | Problems Solved | Highlights |
| :--- | :---: | :--- |
| **Rating 800–1100** | 28 | Fundamentals, Implementation, Greedy, Math, Number Theory, Bitwise |
| **Rating 1200–1400** | 2 | Graph Traversals (DFS/BFS), Combinatorics, Map / Frequency Counting |
| **Rating 1500+** | 1 | Advanced Data Structures, Complex Simulation, Hashing |

👉 *See full breakdown and problem lists in [Codeforces/README.md](file:///e:/cpp/competitive-programming/Codeforces/README.md)*

---

## 🏆 Codeforces Live Contests

Logs and code for live contest rounds and post-contest upsolving.

- **Logged Rounds:** [Educational Codeforces Round 195](CF%20Contests/Educational_Round%20195/) (4 problems solved)
- 👉 *See contest logs and strategy in [CF Contests/README.md](file:///e:/cpp/competitive-programming/CF%20Contests/README.md)*

---

## 📁 Repository Structure

```text
competitive-programming/
├── CF Contests/                       # Live contest logs & submissions
│   ├── Educational_Round 195/         # Round 195 solutions (A, B, C, D)
│   └── README.md
├── CSES/                              # CSES problem set (18 categories)
│   ├── 01_Introductory/               # 14 problems
│   ├── 02_Sorting_Searching/          # 9 problems
│   ├── 03_Dynamic_Programming/
│   ├── 04_Graph_Algorithms/           # 4 problems
│   ├── 05_Range_Queries/              # 1 problem
│   ├── 06_Tree_Algorithms/
│   ├── 07_Mathematics/                # 2 problems
│   ├── 08_String_Algorithms/          # 1 problem
│   ├── 09_Geometry/
│   ├── 10_Advanced_Techniques/
│   ├── 11_Sliding_Window_Problems/    # 1 problem
│   ├── 12_Interactive_Problems/       # 1 problem
│   ├── 13_Bitwise_Operations/
│   ├── 14_Construction_Problems/
│   ├── 15_Advanced_Graph_Problems/
│   ├── 16_Counting_Problems/
│   ├── 17_Additional_Problems_I/
│   └── 18_Additional_Problems_II/
├── Codeforces/                        # Codeforces practice problems by rating
│   ├── Rating_0800_1100/              # 28 problems
│   ├── Rating_1200_1400/              # 2 problems
│   ├── Rating_1500_plus/              # 1 problem
│   └── README.md
├── Template.cpp                       # Fast I/O & CP boilerplate (from Roadmap)
├── judge.py                           # One-command Local Judge script
├── judge.bat / judge.ps1              # Local Judge terminal wrappers
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
