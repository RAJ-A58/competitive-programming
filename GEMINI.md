# Competitive Programming Workspace Guidelines & Rules

## 1. Directory Structure & Problem Organization
- **Practice Problems (`Codeforces/`)**:
  - `Rating_0800_1100/`: Fundamental problems rated 800–1100.
  - `Rating_1200_1400/`: Intermediate problems rated 1200–1400.
  - `Rating_1500_plus/`: Advanced problems rated 1500 and higher.
  - `Upsolve/`: Problems from contests or practice sets that were attempted but not yet solved during contest time.
- **CSES Problem Set (`CSES/`)**:
  - Organized strictly by category (e.g., `01_Introductory`, `02_Sorting_Searching`, `04_Graph_Algorithms`, `11_Sliding_Window_Problems`, etc.).

## 2. Contest & Upsolve Workflow (Always Follow)
- **Contest Problems**:
  - When contest problems are solved, they should be categorized and placed/moved into the appropriate rating bracket folder (`Rating_0800_1100`, `Rating_1200_1400`, or `Rating_1500_plus`) according to their official rating or typical contest problem difficulty (Div. 2 / Div. 3 tier).
- **Unsolved / Target Upsolve Problems**:
  - Any problem not solved during the live contest round is placed into `Codeforces/Upsolve/` with a boilerplate template.
  - Once successfully solved and verified with the local judge, move the file from `Upsolve/` to its corresponding `Rating_...` folder.

## 3. Template & Local Judge
- Always preserve the fast I/O boilerplate from `Template.cpp`.
- Never insert complete solutions when requested to set up templates or files.
- The local judge is triggered via `judge.py` or `.\judge.bat` (`Ctrl+Shift+B` in VS Code).
