# Additive combinatorics: exact finite results and encoding theorems

A collection of exact results in C3/C5-free sets, zero-sum constructions, sparse additive encodings, and related extremal problems. Highlights include a **minimum span 60 theorem for 13-element C3-free sets**, a complete classification through span 63, an **eight-element C5-free minimum span of 25**, a base-7 construction with exponent `log_7(3) > 1/2`, and a Lean theorem backed by a **447,254-addition LRAT proof**.

Author: Jared Wilder. First public timestamp: 2026-09-10. Expanded 2026-09-11.

## C3-free sets

Historical directory: `apex-c3-campaign/`.

- **The first 13-element C3-free set has minimum span exactly 60.** One witness is
  `[1, 2, 3, 14, 19, 30, 31, 32, 43, 48, 59, 60, 61]`.
- **All 13-element sets of span at most 63 are classified:** exactly 6 sets in 4 orbits, with counts by span `{60: 1, 61: 0, 62: 1, 63: 4}`.
- **Every 12 points in `[0,49]` contain a C3-support.** This is Lean-checked and backed by an LRAT proof with **447,254 additions across 33 semantic segments**.

The complete LRAT proof is shipped as 270 chunks under `runs/APX-031/chunked-lrat/`.

Three alternative CNF encodings exceeded GitHub's 100 MB per-file limit (142.8 MB, 123.1 MB and 107.7 MB). Their SHA-256 hashes are recorded in `runs/APX-031/encoding-sweep/OMITTED-LARGE-FILES.json`; the accepted proof itself is present in full.

## Five zero-sum and carry theorems

Historical directory: `blade-championship/`; Lean artifacts are under `formal/`.

1. **Subset gluing.** If an integer zero-sum coefficient vector `c` has no proper zero-sum subset and `A` is `c`-free with span `L`, then `A ∪ (D+A)` is `c`-free for every `D > L * Σ|c_i|`. Iteration gives a doubling construction. Demonstrated at `c=[1,1,1,-3]`.
2. **Digit-carry construction.** For every `m`, the base-7 integers using only digits `{0,1,2}` form a pairwise-distinct `[1,-3,2]`-free set of size `3^m` below `7^m`, giving exponent **`log_7(3)=0.5646>1/2`**.
3. **C5-free minimum span.** The minimum span of an eight-element C5-free integer set is **exactly 25**.
4. **Geometric carry identity.** For nonzero `a,b` and `B>=2`, distinct powers satisfy
   `aB^u-bB^x+bB^y-aB^v=0` exactly when `a(B^u-B^v)=b(B^x-B^y)`; after gcd reduction this becomes `B^u-B^v=b_0 t` and `B^x-B^y=a_0 t` for a nonzero integer `t`.
5. **Parameter-cell decomposition.** For `[a,-b,c,b-c-a]` on a fixed finite domain, every forbidden support lies on a line `b(x4-x2)+c(x3-x4)=a(x4-x1)`, so the `(b,c)`-plane is partitioned into finitely many support-hypergraph chambers.

Also included: `formal/BvSmoke.lean` and `formal/C3Span50Kernel.lean`, the latter containing
`span50 (x : BitVec 50) : selectedCount x >= 12 -> hasC3Violation x = true`.

## Carry-free and sparse additive encoding

Directory: `carry-free-encoding/`.

The public release extracts the pure mathematics from a larger implementation bundle. It includes:

- sharp no-carry threshold `B>A` for bounded residues and sharp full-cube threshold `B>2A`;
- generation of the positional integer kernel by adjacent carry vectors;
- relation-localization and integer-polynomial evaluation thresholds;
- exact full-box output-span lower bounds, optimality and rigidity of balanced positional weights, and mixed-radix extremality;
- sparse-moment uniqueness and carry-free moment packing;
- finite-field `2s`-syndrome injectivity;
- binary sparse subset-sum lower bounds and `Theta_s(m^s)` optimal encoding scale using classical `B_s` inputs;
- signed two-sparse counting, shifted-Sidon encoding, and optimal `Theta(m^2)` scale.

Many of these statements are classical, elementary, or close to known numeration/Sidon/sparse-interpolation mathematics; historical novelty should therefore be checked result by result.

## Signed sparse exact encodings

Directory: `signed-sparse-encodings/`.

Four additional results are included:

- **SGN-04:** a shifted `B_s` construction exactly encodes every ternary signed vector of support at most `s`;
- **SGN-05:** for fixed `s`, the optimal largest positive weight for exact ternary signed sparse encoding is `Theta_s(m^s)`;
- **SGN-06:** support-at-most-three ternary signed encoding has optimal scale `Theta(m^3)`;
- **SGN-07:** for coefficients in `[-A,A]` and support at most `s`, a `B_{As}` construction gives the upper bound `O_{A,s}(m^(As))`.

These use classical `B_s` inputs. The stronger general `Theta_{A,s}(m^s)` statement for `A>=2` remains a separate open target.

## Erdős 564 reduction work

Directory: `erdos564-expedition/`.

Seven proof-chain files study whether `R_3(n) > 2^(2^(cn))` for some `c>0`. The current mathematical output is a reduction recorded in the accepted proof-chain files, together with the failed intermediate routes needed to reproduce how that reduction was reached.

## License

Apache-2.0.