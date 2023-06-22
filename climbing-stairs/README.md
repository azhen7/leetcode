# Climbing Stairs

This question solution uses tabulation.

The idea is as follows: to climb the `n`th step, you can:
* Climb the first step
* Climb the first two steps

In the first case, there would be `n-1` steps left. In the second case, there would be `n-2` cases left.
In total, the number of ways to climb `n` steps is the sum of the number of ways to climb `n-1` steps and `n-2` steps.

To solve this, we start by computing the number of ways to climb 1 stair, then 2 stairs. Assuming `N(x)` is the number of ways to climb
`x` stairs, we can proceed iteratively as such:

```
N(3) = N(2) + N(1)
N(4) = N(3) + N(2)
N(5) = N(4) + N(3)
...
N(n) = N(n - 1) + N(n - 2)
```

We can easily compute `N(n)` as we've already computed `N(n - 1)` and `N(n - 2)` previously.