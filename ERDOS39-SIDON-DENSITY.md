# Erdős #39 — Sidon density: formal ceiling and greedy floor

This note is the human-facing home for a Lean development on Erdős Problem #39.

The problem asks whether there is an infinite Sidon set `A ⊆ ℕ` whose counting function satisfies

\[
A(N) \gg_\varepsilon N^{1/2-\varepsilon}
\]

for every `ε > 0`.

The formal source remains preserved in the historical campaign archive at
`jaredwilder/erdos-campaign-archive/campaigns/erdos39-close-2026-09-05/E39.lean`.
It is a 460-line, zero-`sorry` Lean file with 14 named declarations whose recorded axiom footprint is `[propext, Classical.choice, Quot.sound]`.

## Formal ceiling

For a Sidon set `A ⊆ [1,N]` with `k = |A|`, Lean proves

\[
k^2 \le k + 2N + 1.
\]

The proof injects ordered off-diagonal differences into `[-N,N]`. This gives the familiar square-root ceiling and shows why the exponent `1/2` is the natural upper boundary in the problem.

The same inequality is transported to the counting function of an infinite Sidon set.

## Formal greedy floor

The development defines the values blocked by adjoining a new element to a finite Sidon set. If `A` is Sidon and `x` is neither already in `A` nor blocked, then `A ∪ {x}` remains Sidon.

The blocking set has cardinality at most

\[
k^3+k^2.
\]

Consequently a maximal Sidon subset of `[1,N]` satisfies

\[
N \le k+k^3+k^2 \le 3k^3,
\]

and the greedy infinite construction therefore obeys the explicit cube-root lower-density bound

\[
A(N) \ge (N/3)^{1/3}-1.
\]

## Independent checks

The accompanying computational receipts:

- compare the first 50 greedy values with OEIS A005282 with no mismatch;
- verify the greedy predicate through 900 terms;
- check the Sidon property independently by sums and differences;
- verify classical Erdős–Turán-style finite constructions for primes through `p=509`;
- confirm the Lean ceiling and floor inequalities on the recorded instances.

These computations support the formal development but are not substitutes for the Lean proofs.

## Scope

This packet formalizes the classical exponent window and an explicit greedy baseline. The unresolved content of Erdős #39 is the improvement of the lower-density exponent toward `1/2`.

The material belongs here, with the additive-combinatorics estate, rather than being discoverable only through a dated campaign directory.
