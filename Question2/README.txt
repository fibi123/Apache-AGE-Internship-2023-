Recursive.c 

The recursive function calls the same function again and agian, only to stop at the base cases. 
Advantages: It is easy to program. 
Disadvantages: Time complexity is high for larger values of n, since repetitve calls are being made to the same function

---
Dynamic Programming with memoization

Advantages: Memoization is used to store previously calculated values, so that they are not calculated again. This reduces the time of program execution; i.e time complexity is reduced. This process can be used for larger values of n.
Disadvantages: Needs space to allocate the maximum value of n, beyond which the program cannot be handled. This method is difficult to code, compared to the recursive method. 
---

Bottom-up

Advantages: Uses a loop to calculate the F(n) values, instead of calling them recursively. No additional space is required to store arrays. Only 1 array is needed to store the values of F(n). Disadvantage: More coding compared to memoization and recursive.
---
