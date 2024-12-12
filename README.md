# CMSC-142-Project

# Subset and Subset Sum Problem Programs

This repository contains various programs that solve or explore the subset and subset sum problems using different techniques. Below is a detailed description of each file and its purpose:

## Program Descriptions

### 1. `milestone0.c`
This program generates all subsets of integers from 1 to N using a backtracking approach. It systematically explores all possible subsets by including or excluding each integer.

### 2. `milestone1.c`
This program solves the subset sum problem using a backtracking approach.

### 3. `milestone2.c`
This program solves the subset sum problem using a dynamic programming approach.

### 4. `milestone3.c`
This program solves the subset sum problem using a backtracking approach, but it works with an initial set of integers.

### 5. `milestone1_one_solution.c`
This program is a variation of `milestone1.c` that terminates as soon as it finds one valid solution to the subset sum problem.

### 6. `milestone2_optimization1.c` and `milestone2_optimization2.c`
These programs optimize the dynamic programming approach used in `milestone2.c` by reducing the space complexity to \(O(X)\), where \(X\) is the target sum.

### 7. `comparative_analysis.pdf`
This document compares the backtracking approach and the dynamic programming approach used in the subset sum problem. It analyzes their:
- Time complexity
- Space complexity
- Assumptions and limitations on input

### 8. `milestone0_tracing.pdf`
This document explains the functionality of `milestone0.c` in detail by tracing the execution of the code with an input of \(N = 4\). It provides insights into the backtracking process and the subsets generated.

## How to Run the Programs
To compile and run any of the C programs, use the following command:

```bash
gcc filename.c && ./a.out && rm a.out
