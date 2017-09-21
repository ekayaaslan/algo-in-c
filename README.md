# yaalg-c
Yet another algorithms package written in C

The primary design principle is to be useful like all many others. Some more specific principles:

1) Each directory should be self-contained: no reference to other directories, replicate if needed.
2) API methods should return 0 whenever Success. The output of the method should be specified through the parameters.
3) No bulk allocation from memory, if needed an array of bytes should be provided in the parameter list from the callee.
4) Avoid using asterixes for pointers if easy to avoid.
5) Readibility matters.
