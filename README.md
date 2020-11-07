# Matrix
算法实验2：矩阵连乘算法
## 矩阵连乘问题（Python实现）

2020/10/9 16:38:18 

### 问题描述

​		给定n个矩阵A1，A2，…，An，其中，Ai与Aj+1是可乘的，i=1，2，…，n-l。  
你的任务是要确定矩阵连乘的运算次序，使计算这n个矩阵的连乘积A1A2…An时总的元素乘法次数达到最少。  
​		例如：3个矩阵A1，A2，A3，阶分别为10×100、100×5、5×50，计算连乘积A1A2A3时按（A1A2）A3所需的元素乘法次数达到最少，为7500次。

### 解题思路

**动态规划**  

1. 分析最优解的结构  
   -  A[1:n]可分为A[1:k]和A[k+1:n]  
   -  每个子问题次序是最优的  
2. 建立递归关系  
   -  最优值为m[1][n]  
   -  ```m[i][j] = min{m[i][k]+m[k+1][j]+pi-1pkpj}```  
3. 计算最优值  
   - MatrixChain()函数  
4. 构造最优解  
   - PrintAnswer()函数

### 实验中遇到的问题与解决方案

1. 无法解决最外面的括号无法去除的问题  

### 参考文档

- [矩阵连乘问题](https://blog.csdn.net/qq_32919451/article/details/80643118)
