# Four Behrend barriers, and why they were the ones that got lost

These four theorems say what **cannot** work. Each one closes off a direction that looks promising
for improving Behrend-type lower bounds on 3-AP-free sets, and each closes it before any computation
is run.

They were written 2026-08-10 and never entered the repository. The two *constructions* from the same
document — strictly convex level sets are 3-AP-free, and the carry-free mixed-radix transfer with
`B_i >= 2m_i - 1` — were both banked. **The four barriers were dropped.**

That is the pattern, and it is worth naming: the ingestion reliably kept constructions and positive
theorems. Results whose entire value is closing off a route fell through.

---

## Theorem D is the one to read

Take uniform digit cap `m`, base `B = 2m-1`, integer `p >= 2`, and `F_p(x) = Σ x_i^p` with
`x_i ∈ {0,...,m-1}`. Pigeonhole over the `d(m-1)^p + 1` possible values gives a level `c` with

```
|F_p^{-1}(c)|  >=  m^d / (d(m-1)^p + 1)
```

and encoding that level in base `B` yields a 3-AP-free subset of `[0, B^d)` of at least that size.
Optimising over `m, d`:

```
|A|  >=  N · exp( −(2√(p log 2) + o(1)) · √(log N) )
```

The leading constant is **`2√(p log 2)`, which increases with `p`.** Therefore, within this
monomial exact-level plus pigeonhole scheme, **`p = 2` is optimal among integer `p >= 2`.** Raising
the exponent does not improve Behrend; it makes the constant worse.

In the document's own words: *"This kills a large part of the campaign's 'try p=3,4,5,10' search
space before computation."*

## Theorem E — anisotropic weights cannot help this certificate

For `F(x) = Σ w_i x_i²` with positive integer weights on fixed digit caps, the value count is at most
`1 + Σ w_i (m_i − 1)²`, so the pigeonhole certificate gives
`max_c |F^{-1}(c)| >= Π m_i / (1 + Σ w_i (m_i − 1)²)`.

**Increasing the weights can only worsen the guaranteed bound.** Weighted ellipsoids therefore need
a genuinely sharper lattice-concentration theorem; the naive value-range argument cannot deliver the
claimed gain.

## Theorems F and G

F is the nonstationary-digit barrier: varying the digit caps `m_i` does not rescue the crude
certificate either. G is the naive "Behrend of Behrend" product barrier — composing the construction
with itself does not compound the way one would hope.

Both are in `BARRIERS-D-E-F-G.md` with their full statements.

## Scope

These are barriers **for a specific certificate**, not impossibility theorems. Each says that one
named elementary scheme cannot be pushed further — the pigeonhole-on-exact-levels argument, the
naive value-range count, the crude nonstationary bound, the naive product. A sharper concentration
result could still beat any of them, and Theorem E says so explicitly.

Nothing here improves a Behrend bound. The value is entirely in the search space removed.
