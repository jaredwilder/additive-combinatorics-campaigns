## Theorem D — Monomial-level pigeonhole bound and `p`-barrier

Take uniform digit cap `m`, base `B=2m-1`, integer `p>=2`, and

\[
F_p(x)=\sum_{i=1}^d x_i^p,
\qquad x_i\in\{0,\dots,m-1\}.
\]

There is a level `c` with

\[
|F_p^{-1}(c)|\ge
\frac{m^d}{d(m-1)^p+1}.
\]

Encoding this level in base `B` gives a 3-AP-free subset of `[0,B^d)` of at least that size.

Optimizing the crude bound over `m,d` yields the leading natural-log loss

\[
|A|\ge N\exp\left(-(2\sqrt{p\log2}+o(1))\sqrt{\log N}\right).
\]

Equivalently, in the standard base-2 normalization,

\[
|A|\ge N\,2^{-(2\sqrt p+o(1))\sqrt{\log_2N}}.
\]

Therefore **within this simple monomial exact-level + pigeonhole scheme, `p=2` is optimal among integer `p>=2`.** Raising `p` does not improve Behrend; it worsens the leading constant.

This kills a large part of the campaign's “try `p=3,4,5,10`” search space before computation.

## Theorem E — Coarse anisotropic-weight barrier

For

\[
F(x)=\sum_i w_ix_i^2,
\qquad w_i\in\mathbb Z_{>0},
\]

on fixed digit caps, the number of possible integer values is at most

\[
1+\sum_i w_i(m_i-1)^2.
\]

Hence the elementary pigeonhole certificate gives

\[
\max_c|F^{-1}(c)|\ge
\frac{\prod_i m_i}{1+\sum_iw_i(m_i-1)^2}.
\]

For this certificate, increasing positive integer weights can only worsen the guaranteed bound. Thus weighted ellipsoids require a genuinely sharper lattice-concentration theorem to have any chance; the naive value-range argument cannot provide the claimed gain.

## Theorem F — Nonstationary-digit barrier for the crude certificate

For varying digit caps `m_i`, the same quadratic-level argument gives roughly

\[
|A|\gtrsim \frac{\prod_i m_i}{\sum_i m_i^2},
\qquad
N\asymp \prod_i(2m_i).
\]

For fixed `d` and fixed product `\prod_i m_i`, AM-GM gives

\[
\sum_i m_i^2\ge d\left(\prod_i m_i\right)^{2/d},
\]

with equality when the `m_i` are equal. Therefore **nonuniform digit ranges cannot improve the crude Behrend pigeonhole certificate at fixed ambient product.** Any successful nonstationary-base idea must exploit structure beyond this certificate.

## Theorem G — Naive “Behrend of Behrend” product barrier

Suppose a construction at scale `M` has density

\[
\delta(M)\approx\exp(-c\sqrt{\log M}).
\]

A direct product of constructions at scales `N_1,N_2`, carry-free encoded into scale `N=N_1N_2`, has density loss

\[
\exp\left[-c\left(\sqrt{\log N_1}+\sqrt{\log N_2}\right)\right].
\]

Since

\[
\sqrt a+\sqrt b\ge\sqrt{a+b},
\]

this is no better than using the construction once at total scale `N`, and is strictly worse when both factors are nontrivial. Thus the transcript's naive recursive-product claim cannot turn a `sqrt(log N)` exponent into `log N/log log N`.

---

# 4. The genuinely promising extraction: beat the `7/24` torus block

The 2024 lower-bound improvement of Elsholtz, Hunter, Proske, and Sauermann explicitly reduces its numerical constant to a **two-dimensional building-block problem**. Their Proposition 2.2 constructs a measurable set

\[
T\subset[0,1)^2,
\qquad \mu(T)\ge 7/24-\varepsilon,
\]

and a measurable function

\[
f:T\to[0,100/\varepsilon^2]
\]

such that whenever `x,y,z in T` and

\[
x+z\equiv2y\pmod1,
\]

one has

\[
f(x)+f(z)\ge2f(y)+\|x-z\|_2^2.
\]

The authors explicitly state that their `7/24` block is somewhat ad hoc and that **finding a larger-area block would automatically improve the numerical constant in their best-known integer lower bound.**

This is the strongest actionable target I found.

## Quantitative payoff

If the same architecture can be certified with block area `rho>7/24`, the corresponding exponent constant becomes (by the same parameter calculation)

\[
C(\rho)=2\sqrt{\log_2(1/\rho)}.
\]

Examples:

| certified block area `rho` | exponent constant `C(rho)` |
|---:|---:|
| `7/24 = 0.291666...` | `2.666539` |
| `0.300` | `2.635880` |
| `0.310` | `2.599738` |
| `1/3` | `2.517906` |

Even `rho=0.300` would be a real numerical improvement to the published lower-bound constant, assuming all hypotheses lift exactly.

---

# 5. A finite certificate-producing search program

This is much better aligned with the frontier than brute-forcing `r_3(N)` itself.

## Candidate representation

Partition the torus `[0,1)^2` into rational polygonal cells. Let binary variables select cells whose union is `T`.

Represent `f` by a restricted exact family, for example:

- piecewise affine on a rational triangulation;
- piecewise quadratic with rational coefficients; or
- the same structural ansatz used in the 2024 construction, but with polygon boundaries and coefficients variable.

The third option is likely the best first strike because it stays close to a known feasible certificate.

## Admissible triple reduction

For each triple of selected cells `C_x,C_y,C_z` and each wrap vector `k in {-1,0,1}^2` that can occur, impose

\[
x+z-2y=k.
\]

Eliminate `y`:

\[
y=(x+z-k)/2.
\]

The required inequality becomes a polynomial inequality in only the four coordinates of `(x,z)`:

\[
\Phi_k(x,z)
= f(x)+f(z)-2f((x+z-k)/2)-\|x-z\|_2^2\ge0
\]

throughout the corresponding rational polytope.

## Two-stage solver architecture

### Stage 1 — discovery

Use MILP/MINLP/SMT to maximize selected area on a coarse rational partition. It is acceptable for this stage to be heuristic; its only job is to produce candidate geometry and coefficients.

### Stage 2 — exact certification

For every relevant selected-cell triple:

1. construct the exact rational feasible polytope;
2. minimize `Phi_k` on that polytope;
3. certify the minimum is nonnegative using exact rational interval branch-and-bound, an exact quadratic optimizer where applicable, or an SOS/SMT certificate;
4. output a machine-checkable certificate per cell triple.

Then independently verify:

- exact area of `T`;
- exact coefficient bounds for `f`;
- every modular-midpoint case;
- the global inequality;
- `rho > 7/24` by a rational margin.

A rational margin is important. A candidate that merely numerically equals `0.291667` is useless; target something like `rho >= 0.292` or higher with strict verified slack.

## Why this target is unusually attractive

- It is **finite-dimensional**.
- It has an **exact published sufficient condition**.
- The existing construction gives a known feasible starting point.
- The authors explicitly say improving the block area improves their record.
- Failure is informative: the optimizer can expose which modular-midpoint configurations bind at `7/24`, suggesting a local extremality theorem.
- Success produces a short enough certificate to formalize independently.

This is the one attack from the entire campaign I would fund with compute first.

---

# 6. Solve status

**Erdős #142 itself: NOT SOLVED by the transcript or this audit.**

What *is* closed by this extraction:

- the exact-level strict-convexity mechanism;
- the carry-free mixed-radix transfer mechanism;
- the failure of the naive thick-shell argument;
- the failure of the naive `p>2` monomial strategy under the elementary counting certificate;
- the failure of the naive anisotropic/nonstationary variants under the same certificate;
- the failure of direct recursive products to improve the `sqrt(log N)` exponent shape.

What remains a serious open strike:

> **Find and exactly certify a Proposition-2.2-type pair `(T,f)` with `mu(T)>7/24`.**

That is not a solution to #142, but it is a concrete path to a genuine new lower-bound improvement in the hardest currently-understood case `k=3`.

## Primary references used for frontier calibration

- Erdős Problems, Problem #142.
- Rushil Raghavan, *Improved Bounds for 3-Progressions*, arXiv:2603.27045 (2026).
- Christian Elsholtz, Zach Hunter, Laura Proske, Lisa Sauermann, *Improving Behrend's construction: Sets without arithmetic progressions in integers and over finite fields*, arXiv:2406.12290 (2024).

