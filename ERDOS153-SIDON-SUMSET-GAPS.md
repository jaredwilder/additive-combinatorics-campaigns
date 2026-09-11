# Erdős #153 — Sidon sumset bookkeeping and a gap inequality

Author: Jared Wilder. Public release: 2026-09-11.

Let `A` be a finite Sidon set of integers, using the convention that all unordered pair sums with repetition are distinct. Write `|A|=n` and

`A+A={s_1<...<s_t}`.

## Theorem

`t=n(n+1)/2`.

Moreover,

`(s_t-s_1)^2 <= (t-1) Σ_{i=1}^{t-1}(s_{i+1}-s_i)^2`.

## Proof

Each unordered pair `{a,b}` with `a<=b` gives a distinct sum, and there are exactly

`C(n+1,2)=n(n+1)/2`

such pairs.

Let `g_i=s_{i+1}-s_i`. Then

`Σg_i=s_t-s_1`.

Cauchy-Schwarz gives

`(Σg_i)^2 <= (t-1)Σg_i^2`,

which is the stated inequality.

## Formalization note

A recovered formal receipt checked only the concrete example `A={1,2,4,8}`. It is evidence for that instance, not a universal formalization of the theorem above.
