# Rotate Image

The idea of this solution is perform a 90 degree clockwise rotation on the outer layer, and iteratively work inwards.
This is implemented as follows:

Given a 2D matrix
```
a b c d
e f g h
i j k l
m n o p
```
We can take `a`, `d`, `p`, and `m`. After performing a series of swaps with `a`, `d`, `p`, and `m`, we can succesfully perform a
90 degree rotation on those 4 points. Then, we move right, taking `b`, `h`, `o`, and `i`, and "rotating" them. We continue
until the entire outer layer has been rotated.

Then, we move inwards (taking `f`, `g`, `k`, and `j`, in this case), and repeat the above process.

The end result is that the entire matrix as been rotated 90 degrees clockwise.