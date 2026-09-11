# Signed sparse exact encoding — release-day theorem patch

**Author:** Jared Wilder  
**Source campaign date:** 2026-08-05  
**Public release:** 2026-09-11

This directory extracts four pure additive/combinatorial encoding results from the wider theorem estate. The classical `B_s` existence/uniqueness input is not claimed as new. Historical novelty of the exact signed formulations has **not** been checked; the point of this release is to expose the mathematics with its scope intact.

## SGN-04 — Shifted `B_s` encoding for signed ternary sparse states

Let `a_1,...,a_m` be a `B_s` set modulo `N`, represented in `[0,N-1]`. Put

`L = 2s(N-1)+1`, `w_i = L+a_i`.

Then

`x -> sum_i x_i w_i`

is injective on every `x in {-1,0,1}^m` with support at most `s`.

Proof core: a collision first forces equal total charge because the residual `a_i` contribution has magnitude strictly below `L`. Move negative terms across. The two sides are now equal-length sums of `k` elements with `k<=s`; pad to `s` terms and invoke `B_s` uniqueness. Multiset equality recovers the signed coefficient vector.

**Source status:** `CLOSED_PROVED_USING_CLASSICAL_INPUT`.

## SGN-05 — Optimal signed ternary sparse exponent

For fixed `s`, the minimum possible largest positive integer weight required to encode all `{-1,0,1}`-valued vectors of support at most `s` exactly is

`Theta_s(m^s)`.

Lower bound: the number of states is

`sum_{r=0}^s 2^r binom(m,r) = Theta_s(m^s)`,

while weights bounded by `W` produce only `2sW+1` possible sums.

Upper bound: SGN-04 plus a classical `B_s` construction in a cyclic group of order `O_s(m^s)`.

**Source status:** `CLOSED_PROVED_USING_CLASSICAL_INPUT`. The source explicitly notes likely overlap with signed/generalized Sidon-sequence literature; historical novelty is unverified.

## SGN-06 — Signed three-sparse closure

Specializing SGN-05 to `s=3`, the optimal largest positive integer weight for exact encoding of all support-at-most-three ternary signed vectors is

`Theta(m^3)`.

**Source status:** `CLOSED_COROLLARY`.

## SGN-07 — General bounded-coefficient constructive upper bound

For fixed coefficient bound `A` and support bound `s`, a `B_{As}` set plus the same charge separator yields positive integer weights of largest size

`O_{A,s}(m^(As))`

that exactly encode every support-at-most-`s` vector in `[-A,A]^m`.

Proof core: expand coefficient magnitudes as repeated copies only inside the proof. Equal charge makes the moved positive and negative multisets have equal size at most `As`; `B_{As}` uniqueness recovers multiplicities.

**Source status:** `CLOSED_PROVED_USING_CLASSICAL_INPUT`. This is a constructive baseline, not claimed optimal for `A>=2`.

## Remaining boundary

The source conjecture `W_A(m,s)=Theta_{A,s}(m^s)` is closed by SGN-05 only for ternary coefficients `A=1`. For general `A>=2`, the theorem patch records the `O_{A,s}(m^(As))` construction above and leaves the stronger optimal exponent open.

Machine-readable source statuses and dependencies are in `THEOREM-BANK-PATCH.json`.