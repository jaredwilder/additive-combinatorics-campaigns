# Erdős #241 — counting bound for distinct three-term multiset sums

Author: Jared Wilder. Public release: 2026-09-11.

Let `A⊂{1,...,N}` with `|A|=m`. Suppose the sums

`a+b+c`

are all distinct as `{a,b,c}` ranges over unordered triples from `A` with repetition allowed.

## Theorem

`C(m+2,3) <= 3N-2`.

In particular,

`m^3 < 18N`.

## Proof

There are exactly `C(m+2,3)` unordered triples with repetition from an `m`-element set. Every resulting sum lies in the integer interval `[3,3N]`, which contains `3N-2` values. Distinctness therefore gives

`C(m+2,3) <= 3N-2`.

Since

`C(m+2,3)=m(m+1)(m+2)/6 > m^3/6`,

we obtain `m^3<18N`.

The historical archive contained stronger constants attributed to the same counting argument. Those do not follow from this proof; the statement above is the exact elementary consequence.
