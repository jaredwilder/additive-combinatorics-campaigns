# Finite-window extremal bounds imply infinite upper-density bounds

**Author:** Jared Wilder  
**Status:** elementary general theorem  
**Historical novelty:** not claimed

Let `R` be a translation-invariant forbidden relation on finite subsets or tuples of integers. Suppose that every `R`-free subset of an interval of length `L` has at most `M` elements.

Then every `R`-free set `A subseteq [1,N]` satisfies

\[
\boxed{|A|\le M\left\lceil\frac NL\right\rceil.}
\]

Consequently every infinite `R`-free set `A subseteq N` has upper asymptotic density

\[
\boxed{\overline d(A)\le \frac ML.}
\]

## Proof

Partition `[1,N]` into consecutive blocks of length `L`, except possibly for the last shorter block.

Because `R` is translation-invariant, the intersection of an `R`-free set with any full length-`L` block translates to an `R`-free subset of `[1,L]`. Hence each full block contributes at most `M` elements. The final partial block contributes at most `M` as well, giving

\[
|A|\le M\left\lceil\frac NL\right\rceil.
\]

Divide by `N` and let `N` tend to infinity. Since

\[
\frac{\lceil N/L\rceil}{N}\longrightarrow\frac1L,
\]

we obtain

\[
\limsup_{N\to\infty}\frac{|A\cap[1,N]|}{N}\le\frac ML.
\]

## Why this matters for the estate

A finite extremal table is therefore not merely a bounded computation when the forbidden relation is translation-invariant. Every exact entry `(L,M)` yields a rigorous infinite-density upper bound `M/L` immediately.

This observation was recovered from the archive-seam audit, where it had been applied to one of the exact `C_3` tables. The general theorem is published here independently of any particular `C_k` semantics, because the estate historically used the symbol `C_k` for more than one convention. Any concrete application should state its forbidden relation explicitly before importing the bound.

## Scope

This theorem does **not** say the resulting density bound is sharp. It converts a certified finite extremal value into an unconditional global upper bound and nothing more.
