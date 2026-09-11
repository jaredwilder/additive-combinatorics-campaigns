# Ternary cube construction — `2^d` integers with no nontrivial 3-term AP

**Author:** Jared Wilder  
**Recovered from:** A/B transcript mining estate  
**Public extraction:** 2026-09-11

For `d>=1`, define

\[
A_d=\left\{\sum_{i=0}^{d-1}\varepsilon_i3^i:\varepsilon_i\in\{0,1\}\right\}.
\]

## Theorem

`A_d` has exactly `2^d` elements, lies in

\[
\left[0,\frac{3^d-1}{2}\right],
\]

and contains no nontrivial three-term arithmetic progression.

Equivalently,

\[
x,z,y\in A_d,\qquad x+z=2y
\]

implies

\[
\boxed{x=y=z.}
\]

## Proof

Write the least ternary digits of `x,y,z` as `x_0,y_0,z_0∈{0,1}`. Reducing

\[
x+z=2y
\]

modulo 3 gives

\[
x_0+z_0\equiv2y_0\pmod3.
\]

If `y_0=0`, then `x_0+z_0` is one of `0,1,2` and is congruent to 0 modulo 3, so it must be 0. Thus

\[
x_0=z_0=0.
\]

If `y_0=1`, then `x_0+z_0≡2 mod3`; since the sum is again one of `0,1,2`, it must equal 2, so

\[
x_0=z_0=1.
\]

Hence the three least ternary digits agree. Subtract that common digit and divide the equation by 3. The same argument applies recursively to the remaining `d-1` digits. Therefore all ternary digits agree coordinatewise and `x=y=z`.

The cardinality is `2^d` by uniqueness of ternary expansion, and the largest member is

\[
1+3+\cdots+3^{d-1}=\frac{3^d-1}{2}.
\]

## Recovered finite witness

The estate contained the `d=9` instance as a validated finite object:

\[
|A_9|=512,
\qquad
\max A_9=\frac{3^9-1}{2}=9841.
\]

Thus the previously recorded 512-element AP-free set was not merely a finite search result; it is one member of this exact parametric construction.

## Novelty boundary

This is the standard ternary/Cantor-cube construction and is **not claimed historically new**. It is released because the estate contained the result and finite witness, and Release Day preserves correct mathematics even when it is rediscovery rather than novelty.
