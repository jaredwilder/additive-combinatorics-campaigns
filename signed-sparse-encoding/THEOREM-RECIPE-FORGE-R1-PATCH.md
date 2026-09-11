# Signed-sparse encoding — Theorem Recipe Forge R1 patch

**Date:** 2026-08-05  
**Purpose:** publish later theorem closures that supersede earlier conjectural status in the carry-free/signed-sparse bank.

Historical novelty is **not** asserted. The source explicitly notes that the `B_s` ingredient is classical and that related signed/generalized Sidon literature must be checked before any novelty claim.

## SGN-04 — Shifted `B_s` Encoding for Signed Ternary Sparse States
**Status:** `CLOSED_PROVED_USING_CLASSICAL_INPUT`

Let `a_1,...,a_m` be a `B_s` set modulo `N`, with representatives in `[0,N-1]`. Set

\[
L=2s(N-1)+1,
\qquad
w_i=L+a_i.
\]

Then

\[
x\longmapsto\sum_i x_iw_i
\]

is injective on every `x in {-1,0,1}^m` with support at most `s`.

**Proof core.** A collision first forces equal total charge because the residual magnitude is below `L`. Move negative terms across. The two sides become equal-length sums of `k` terms with `k<=s`. Pad to `s` terms and invoke `B_s` uniqueness. Multiset equality then recovers the signed coefficient vector exactly.

## SGN-05 — Optimal Signed Ternary Sparse Exponent
**Status:** `CLOSED_PROVED_USING_CLASSICAL_INPUT`

For fixed `s`, the minimum possible largest positive integer weight that exactly encodes every `{-1,0,1}`-valued vector of support at most `s` satisfies

\[
W(m,s)=\Theta_s(m^s).
\]

**Lower bound.** The number of states is

\[
\sum_{r=0}^s2^r\binom mr=\Theta_s(m^s),
\]

while maximum weight `W` gives only `2sW+1` possible signed sums. Thus `W=Omega_s(m^s)`.

**Upper bound.** SGN-04 plus a classical `B_s` construction in a cyclic group of order `O_s(m^s)` gives `W=O_s(m^s)`.

## SGN-06 — Signed Three-Sparse `Theta(m^3)` Closure
**Status:** `CLOSED_COROLLARY`

The optimal largest positive integer weight for encoding all `{-1,0,1}`-valued support-at-most-three vectors is

\[
\Theta(m^3).
\]

This is SGN-05 with `s=3`.

**Status correction:** the earlier carry-free bank listed this statement as `CONJ-02 — Signed Three-Sparse Theta(m^3) Conjecture`. That conjectural status is superseded by this theorem-recipe patch.

## SGN-07 — General Bounded-Coefficient Constructive Upper Bound
**Status:** `CLOSED_PROVED_USING_CLASSICAL_INPUT`

For fixed coefficient bound `A` and sparsity `s`, a `B_{As}` set plus the same charge separator gives positive integer weights of largest size

\[
O_{A,s}(m^{As})
\]

that exactly encode every support-at-most-`s` vector in `[-A,A]^m`.

**Proof core.** Expand coefficient magnitudes as repeated copies only inside the proof. Equal charge makes the moved positive and negative multisets have equal size at most `As`; `B_{As}` uniqueness recovers all multiplicities.

This is a constructive baseline and is **not claimed optimal**. It improves the previously contemplated generic `B_{2As}` overkill to `B_{As}` by using charge separation.

## Conjecture-status corrections

- `CONJ-02` — signed three-sparse `Theta(m^3)`: **CLOSED BY SGN-06**.
- `CONJ-01` — `W_A(m,s)=Theta_{A,s}(m^s)` for all fixed `A,s`: **closed for ternary coefficients `A=1`; still open for general `A>=2`**. Current constructive upper bound from this packet is `O_{A,s}(m^{As})`.

The earlier conjecture text remains in the historical bank intentionally; this file is the later authoritative status patch.