# yaalg-c
Yet another algorithms package written in C

The primary design principle is to be useful like all many others. Some more specific principles:

1) Self-containment matters. No excessive use of other files in the library.
2) No bulk allocation from memory, if needed an array of bytes should be provided in the parameter list from the callee.
3) Avoid using recursion. 
