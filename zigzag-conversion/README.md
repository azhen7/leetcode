# Zigzag Conversion

We are given a string `s` = `A_1 A_2 A_3 ...A_n`, and `numRows` = `k`.

The basic diagram looks like this:
```
A_1                    A_(2k-1)                 A_(4k-3)
A_2           A_(2k-2) A_(2k)          A_(4k-4) A_(4k-2)
A_3         A_(2k-3)   A_(2k+1)      A_(4k-5)   ...
...       ...          ...         ...
A_(k-1) A_(k+1)        A_(3k-2)  A_(3k)
A_k                    A_(3k-1)
```

We can split this format into chunks:
```
**Chunk 1**            **Chunk 2**             **Chunk 3** ...
A_1                    A_(2k-1)                 A_(4k-3)
A_2           A_(2k-2) A_(2k)          A_(4k-4) A_(4k-2)
A_3         A_(2k-3)   A_(2k+1)      A_(4k-5)   ...
...       ...          ...         ...
A_(k-1) A_(k+1)        A_(3k-2)  A_(3k)
A_k                    A_(3k-1)
```

Corresponding characters from Chunk 1 to Chunk 2 are separated by an offset of `2k-2`. The same goes for Chunk 2 to Chunk 3, and so on.

For each chunk `n`, let `p` be any number in the range `(2nk-2k-2n+3, 2nk-k-2n+2)`. `A_p` has a "mirroring" character `A_(4(nk-n+1)-2k-p)`.

With this information, we are able to construct the result as follows:
* Add `A_1`, `A_(2k-1)`, etc.
* Add `A_2`, `A_(2k)`, `A_(4k-2)`, etc. and their respective mirroring characters, if any.
* Continue the previous step with `A_3`, `A_4`, etc., until after `A_(k-1)`.
* Add `A_k`, `A_(3k-2)`, etc.