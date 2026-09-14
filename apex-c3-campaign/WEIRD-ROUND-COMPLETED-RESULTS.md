# Weird Round — completed-result correction

**Status correction.** The files under `apex-c3-campaign/research-targets/` are historical target specifications from before later execution. Several still say `UNPROVED_CHECKABLE_TARGET`. They are valuable provenance, but they are **not the current status** of the results below.

This note records the later theorem-state recovered from the canonical Weird-Round theorem atlas. It does not rewrite the historical target files.

## A. Finite carry automata for geometric-power relations

### OWR-025 — Pascal-order least-base decision

For each supplied Pascal order, the certified carry automaton gives an **exact all-exponent decision** for the least geometric base. The recovered exact atlas covers orders `r = 1..12`, with explicit obstruction witnesses below the certified thresholds.

Boundary: this is an algorithmic exact decision for each fixed order. A closed-form threshold as a function of arbitrary `r` is **not** claimed.

### OWR-026 — all-exponent criterion for fixed coefficient vectors

For a fixed integer coefficient vector and base `B >= 2`, the zero-right-hand-side relation among pairwise-distinct powers of `B` is decided by a **finite carry automaton**. This is an all-exponent result, not a bounded exponent-prefix search.

Boundary: the stated automaton covers the one-coefficient-per-exponent geometric-power problem. Digit alphabets with multiple selected values at one exponent use the larger digit/carry automaton.

### OWR-029 / 037 / 038 — all-length digit languages

The digit/carry automaton compiles a fixed digit alphabet into an exact all-word-length decision. The later campaign records exact optimization for bases `3..12` (up to digit translation):

- OWR-037: maximal normalized fixed digit alphabets for C3 avoidance in that range;
- OWR-038: maximal common fixed digit alphabets avoiding both C2 and C3 in that range;
- OWR-029: whenever an accepted alphabet has more than one digit, the language gives an explicit polynomial-size all-length relation-free family.

No optimization over every base or every stateful automaton is claimed.

### OWR-039 — denser fixed automatic construction

The joint digit/carry product automaton certifies a fixed automatic language that avoids C2 and C3 at every word length and is strictly denser than the earlier three-state `10*` baseline.

Boundary: this is a result inside the declared fixed/memoryless-DFA class. Larger state-cap synthesis remains open.

### OWR-048 — blind held-out transfer

The frozen density constructor was replayed on a held-out non-Pascal coefficient vector and returned another certified polynomial-size all-length construction with **zero second inference**. This is method-transfer evidence attached to the theorem family, not an additional historical-novelty claim.

## B. Antisymmetric coefficient chamber theory

Consider pairwise-distinct ordered coordinates satisfying

```text
x1 - b*x2 + b*x3 - x4 = 0,    b >= 1.
```

### OWR-049 — exact difference-ratio normal form

Set

```text
e = x1 - x4
d = x2 - x3.
```

Then every solution satisfies exactly

```text
e = b*d.
```

Conversely, compatible nonzero signed differences with this ratio, together with endpoint translations inside the ambient interval, parameterize the ordered solutions.

### OWR-051 — sharp all-N empty tail

On `[N] = {1,...,N}`, for every `N >= 4`, the forbidden support is empty **iff**

```text
b >= N.
```

The threshold is sharp: at `b = N-1`, the ordered tuple

```text
(N, 3, 2, 1)
```

satisfies the relation. Hence the last active parameter is exactly `N-1`, and the relation-free optimum is exactly `N` throughout the tail `b >= N`.

### OWR-050 — first nonmonotonicity

For `N = 4`, the exact support cells are

```text
b = 1     active
b = 2     empty
b = 3     active
b >= 4    empty
```

The support at `b=3` is witnessed by `(4,3,2,1)`. The resulting exact extremal sequence for `b=1..6` is

```text
3, 4, 3, 4, 4, 4.
```

### OWR-052 — coefficient cells

For fixed `[N]`, attainable signed-difference ratios partition the integer parameter into exact forbidden-support cells. Only `b=1,...,N-1` can be active; `b>=N` is the single empty-tail cell. Equal adjacent support hashes may be merged without changing the theorem.

### OWR-060 — held-out affine replay

The frozen parameter-cell compiler was replayed with zero second inference on the held-out affine family

```text
[2, -b, b, -2]
```

and produced exact active cells and certified empty tails on `[13]` and `[14]`.

## Authority and novelty boundary

- These statuses supersede the **status labels** in the older target-specification files; those files remain preserved as historical provenance.
- The later theorem atlas classifies OWR-026/029/037/038/039/048/049/050/051/052/060 as worked certified-result nodes and OWR-025 as an exact algorithmic boundary result.
- Historical novelty is **not** inferred from theorem-engine success. The chamber and automaton statements require theorem-by-theorem literature comparison before novelty claims.
- No closed formula for arbitrary Pascal order, no globally optimal automatic construction, and no unrestricted parameter-family asymptotic theorem is claimed here.
