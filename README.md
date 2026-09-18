# Additive combinatorics: exact finite results and encoding theorems

This repository collects exact results in additive combinatorics, including progression-free constructions, finite extremal classifications, carry-free encodings, sparse signed representations, and sum-product structure.

## Main results

| Topic | Result |
|---|---|
| Erdős #52 | for `A_N={2^i3^j:0<=i,j<N}`, `|A_N+A_N| >= C(N,2)^2` while `|A_NA_N|=(2N-1)^2` |
| `C3`-free sets | the minimum span of a 13-element set is **60**; all examples through span 63 are classified |
| `C5`-free sets | the minimum span of an 8-element set is **25** |
| finite formal certificate | every 12 points in `[0,49]` contain a `C3` support, backed by Lean and a **447,254-addition LRAT proof** |
| digit construction | base-7 digits `{0,1,2}` give a `[1,-3,2]`-free family of size `3^m` below `7^m`, with exponent `log_7(3)>1/2` |
| positional encoding | sharp no-carry and injectivity thresholds, plus optimal full-box positional weights |
| sparse signed encoding | exact constructions with polynomial weight scale, including `Theta(m^2)` for signed two-sparse encoding and `Theta(m^3)` at ternary support three |

The sections below state the mathematics and then point to the original source directories and verification artifacts.

## Erdős #52 — multiplicative boxes with large sumsets

For

\[
A_N=\{2^i3^j:0\le i,j<N\},
\]

valuation decoding gives

\[
\boxed{|A_N+A_N|\ge \binom N2^2}
\]

and

\[
\boxed{|A_NA_N|=(2N-1)^2}.
\]

Thus the same family has very small multiplicative growth and nearly quadratic additive growth. The proof is in [`ERDOS52-MULTIPLICATIVE-BOX-SUMSET.md`](ERDOS52-MULTIPLICATIVE-BOX-SUMSET.md).

## Exact `C3`-free structure

A 13-element `C3`-free integer set has minimum span exactly

\[
\boxed{60}.
\]

One extremal example is

```text
[1, 2, 3, 14, 19, 30, 31, 32, 43, 48, 59, 60, 61].
```

All 13-element examples of span at most 63 are classified: there are exactly six sets in four symmetry orbits, with counts by span

```text
60 : 1
61 : 0
62 : 1
63 : 4
```

A second exact statement says that every 12 selected points in `[0,49]` contain a forbidden `C3` support. The formal certificate is a Lean theorem backed by a shipped LRAT proof containing **447,254 additions across 33 semantic segments**. The complete LRAT proof is stored in 270 chunks under `runs/APX-031/chunked-lrat/`.

The focused finite-sequence tables are indexed separately in [`ck-sequences`](https://github.com/jaredwilder/ck-sequences).

## Zero-sum and carry theorems

### Subset gluing

Let `c` be an integer zero-sum coefficient vector with no proper zero-sum subset. If `A` is `c`-free with span `L`, then

\[
A\cup(D+A)
\]

is again `c`-free whenever

\[
D>L\sum_i |c_i|.
\]

Iterating gives a doubling construction. The package includes the case `c=[1,1,1,-3]`.

### Base-7 digit construction

For every `m`, the integers below `7^m` whose base-7 digits lie in `{0,1,2}` form a pairwise-distinct `[1,-3,2]`-free set of size `3^m`. Hence the construction has exponent

\[
\boxed{\log_7 3=0.5646\ldots>1/2}.
\]

### Exact `C5` minimum span

The minimum span of an eight-element `C5`-free integer set is

\[
\boxed{25}.
\]

### Geometric carry identity

For nonzero integers `a,b` and `B>=2`, distinct powers satisfy

\[
aB^u-bB^x+bB^y-aB^v=0
\]

exactly when

\[
a(B^u-B^v)=b(B^x-B^y).
\]

After dividing by `gcd(a,b)`, this becomes an exact common-parameter description of the two power differences.

### Parameter chambers

For coefficients `[a,-b,c,b-c-a]` on a fixed finite domain, every forbidden support lies on a line

\[
b(x_4-x_2)+c(x_3-x_4)=a(x_4-x_1).
\]

Therefore the `(b,c)` plane is partitioned into finitely many chambers on which the forbidden-support hypergraph is constant.

## Additional exact carry and parameter results

Later computations completed several targets that remain labeled as provisional in older source snapshots. The current mathematical results include:

- a finite carry automaton deciding the fixed-coefficient geometric-power relation for **all exponents**;
- exact least-base decisions for the supplied Pascal-order relations, with an atlas through `r=12` and explicit sub-threshold obstructions;
- all-word-length digit/carry decisions and optimized fixed alphabets for `C3` and joint `C2`–`C3` avoidance over bases `3..12`;
- a fixed automatic `C2/C3`-avoiding construction denser than the earlier baseline inside the declared fixed-DFA class;
- for `[1,-b,b,-1]`, the exact normal form `e=b*d` and the sharp theorem that forbidden support on `[N]` is empty **iff `b>=N`**;
- the exact `N=4` chamber sequence `3,4,3,4,4,4` for `b=1..6`;
- a held-out replay of the parameter-cell compiler on `[2,-b,b,-2]` at `N=13,14`.

Older target files are retained as dated research records; they do not override the completed statements above.

## Carry-free positional encoding

The pure encoding results include:

- sharp zero-detection threshold `B>A` for bounded residues;
- sharp injectivity threshold `B>2A` on the full bounded cube;
- generation of the positional integer kernel by adjacent carry vectors;
- exact full-box output-span lower bounds;
- optimality and rigidity of balanced positional weights;
- mixed-radix extremality;
- sparse-moment uniqueness and carry-free moment packing;
- finite-field `2s`-syndrome injectivity;
- binary sparse subset-sum lower bounds and `Theta_s(m^s)` optimal scale using classical `B_s` constructions;
- signed two-sparse exact encoding at optimal `Theta(m^2)` scale.

A focused statement-and-proof presentation also appears in [`positional-encoding-thresholds`](https://github.com/jaredwilder/positional-encoding-thresholds).

## Signed sparse encodings

For ternary signed vectors and related bounded-coefficient families, the repository contains:

- a shifted `B_s` construction that exactly encodes every ternary vector of support at most `s`;
- optimal largest-weight scale `Theta_s(m^s)` for fixed ternary sparsity;
- optimal `Theta(m^3)` scale for support at most three;
- for coefficients in `[-A,A]` and support at most `s`, a `B_{As}` construction giving `O_{A,s}(m^{As})`.

The stronger general `Theta_{A,s}(m^s)` statement for `A>=2` is not established by this package.

## Erdős #564 reduction

A separate proof sequence studies the double-exponential lower-bound question for `R_3(n)`. Its current contribution is a reduction and a documented set of failed intermediate routes; it is not presented here as a solution of the parent problem.

## Reproducibility and historical layout

Several directory names preserve the names of the original research runs. They are retained so hashes and historical references remain stable:

- `apex-c3-campaign/` — `C3` finite search and LRAT material;
- `blade-championship/` — zero-sum and carry theorem sources;
- `carry-free-encoding/` — positional and sparse encoding results;
- `signed-sparse-encodings/` — signed sparse constructions;
- `erdos564-expedition/` — the #564 reduction record;
- `formal/` and `runs/` — Lean, SAT/LRAT, witnesses, and receipts.

These names are provenance. The mathematical statements above are the intended reading surface.

Author: Jared Wilder. License: Apache-2.0.
