# Zigzag Conversion

We are given a string `s` = `A~1~A~2~A~3~...A~n~`, and `numRows` = `k`.

The basic diagram looks like this:
```
A~1~                   A~2k-1~                 A~4k-3~
A~2~          A~2k-2~  A~2k~          A~4k-4~  A~4k-2~
A~3~        A~2k-3~    A~2k+1~      A~4k-5~    ...
...       ...          ...        ...
A~k-1~  A~k+1~         A~3k-2~  A~3k~
A~k~                   A~3k-1~
```

We can split this format into chunks:
```
**Chunk 1**            **Chunk 2**             **Chunk 3** ...
A~1~                   A~2k-1~                 A~4k-3~
A~2~          A~2k-2~  A~2k~          A~4k-4~  A~4k-2~
A~3~        A~2k-3~    A~2k+1~      A~4k-5~    ...
...       ...          ...        ...
A~k-1~  A~k+1~         A~3k-3~  A~3k-1~
A~k~                   A~3k-2~
```

Corresponding characters from Chunk 1 to Chunk 2 are separated by an offset of `2k-2`. The same goes for Chunk 2 to Chunk 3, and so on.

For each chunk `n`, let `p` be any number in the range `(2nk-2k-2n+3, 2nk-k-2n+2)`. `A~p~` has a "mirroring" character `A~p+2k-2(p-(2nk-2k-2n+3)+1)~`.

With this information, we are able to construct the result as follows:
* Add `A~1~`, `A~2k-1~`, etc.
* Add `A~2~`, `A~2k~`, `A~4k-2~`, etc. and their respective mirroring characters, if any.
* Continue the previous step with `A~3~`, `A~4~`, etc., until after `A~k-1~`.
* Add `A~k~`, `A~3k-2~`, etc.