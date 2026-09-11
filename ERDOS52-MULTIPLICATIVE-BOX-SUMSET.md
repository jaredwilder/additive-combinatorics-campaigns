# Erdős #52 — the `2^i3^j` multiplicative box has an almost-maximal sumset

Author: Jared Wilder. Public release: 2026-09-11.

Let

`A_N = {2^i 3^j : 0<=i,j<N}`.

## Theorem

For every integer `N>=2`,

`|A_N + A_N| >= C(N,2)^2`,

while

`|A_N A_N| = (2N-1)^2`.

Since `|A_N|=N^2`, the additive lower bound is

`|A_N+A_N| >= (1/4+o(1)) |A_N|^2`,

whereas the product set has only quadratic size in `N`.

## Proof of the sumset bound

Restrict to sums

`2^i3^j + 2^k3^l`

with `0<=i<k<N` and `0<=j<l<N`. There are exactly `C(N,2)^2` such quadruples.

Factor

`2^i3^j(1+2^(k-i)3^(l-j))`.

Because `k-i>=1`, the parenthesized factor is odd; because `l-j>=1`, it is `1 mod 3`. Therefore the sum itself determines

`v_2 = i` and `v_3 = j`.

After dividing by `2^i3^j` and subtracting 1, unique factorization recovers `k-i` and `l-j`, hence `k` and `l`. The map from quadruples to sums is injective.

For the product set, exponent addition gives exactly

`A_N A_N = {2^a3^b : 0<=a,b<=2N-2}`,

so `|A_N A_N|=(2N-1)^2`.

A brute-force check for `N=2,...,7` independently reproduces the restricted-sum counts `1,9,36,100,225,441`.

This theorem eliminates this structured multiplicative box as a counterexample mechanism for the surrounding sum-product problem. Historical novelty is a separate literature question.
