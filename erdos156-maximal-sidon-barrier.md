# Erdős #156 — repaired maximal-Sidon `N^(1/3)` barrier

**Author:** Jared Wilder  
**Recovered from:** September 2026 proof-repair audit  
**Subject-repo promotion:** 2026-09-11

Let `A⊆[N]` be a maximal Sidon set and put `m=|A|`. Then

`N <= m + m^3 + m^2`.

In particular, for `m>=1`,

`N <= m + 2m^3`,

so

> **`m = Omega(N^(1/3))`.**

## Proof

Because `A` is maximal, every `x∈[N]\A` makes `A∪{x}` non-Sidon. Since all pair sums internal to `A` were already distinct, any new collision must involve `x`.

There are two essential possibilities:

1. `x+a=b+c` for some `a,b,c∈A`;
2. `2x=a+b` for some `a,b∈A`.

The first class contributes at most `m^3` possible excluded values of `x`, and the second at most `m^2`. Adding the `m` elements of `A` itself gives

`N <= m + m^3 + m^2`.

## Why this is a repaired theorem

An earlier argument used only the inclusion

`[N]\A ⊆ (A+A)-A`,

but this misses the collision type `2x=a+b`. The conclusion survives only after adding that second blocker. The original incomplete route remains in the provenance archive; this file gives the corrected theorem readers should cite.

## Scope and literature

This is a universal lower barrier for maximal Sidon sets. Historical novelty is not claimed; the argument is elementary and folklore risk is substantial.

Original extraction: `jaredwilder/unpublished-math-papers/erdos156-maximal-sidon-barrier/`.
