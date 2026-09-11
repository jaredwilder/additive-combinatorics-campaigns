# additive-combinatorics-campaigns

Three deterministic campaigns on zero-sum and C3-free integer sets, including a Lean-kernel-checked
theorem backed by a 447,254-addition LRAT proof.

Author: Jared Wilder. First public timestamp: 2026-09-10. Campaigns dated 2026-07-29.

## APEX: C3-free sets

`apex-c3-campaign/`

- **The first 13-element C3-free set has minimum span exactly 60.** Witness:
  `[1, 2, 3, 14, 19, 30, 31, 32, 43, 48, 59, 60, 61]`.
- **Classification of all 13-element sets of span at most 63: exactly 6 sets in 4 orbits**, with
  exact counts by span {60: 1, 61: 0, 62: 1, 63: 4}. Maximum replacement distance to the span-60
  orbit is 7.
- **Every 12 points in [0, 49] contain a C3-support.** Lean-kernel-checked, terminal module
  `EG411Formal.C3Span50Fine.Fine152`, backed by an LRAT proof with **447,254 additions across 33
  semantic segments**.

The LRAT proof is shipped **in full** as 270 chunked files under
`runs/APX-031/chunked-lrat/`.

**Three files were omitted**, each over GitHub's 100 MB per-file limit: alternative cardinality
encodings of the same UNSAT instance, at 142.8 MB, 123.1 MB and 107.7 MB. Their SHA-256 digests
are recorded in `runs/APX-031/encoding-sweep/OMITTED-LARGE-FILES.json` so a regenerated file can be
checked against them. The accepted encoding's proof is present and complete.

Infrastructure record: a 48-attack campaign against C3-birth calculus, of which 12 were completed
as decisive attacks.

## Blade championship: five zero-sum theorems

`blade-championship/`, with Lean artifacts under `formal/`.

1. **Subset-gluing.** If an integer zero-sum coefficient vector c has no proper zero-sum subset,
   and A is c-free with span L, then A union (D + A) is c-free for every D > L * sum |c_i|.
   Iterating gives a certified doubling construction. Demonstrated at c = [1, 1, 1, -3].
2. **Digit-carry compiler.** For every m, the base-7 integers using only digits {0, 1, 2} form a
   pairwise-distinct [1, -3, 2]-free set of size 3^m below 7^m, giving exponent
   **log_7(3) = 0.5646 > 1/2**.
3. **Gap-birth.** The minimum span of an eight-element C5-free integer set is **exactly 25**, with
   first normalized birth on [26].
4. **Geometric carry automaton.** For a, b nonzero and B >= 2, distinct powers satisfy
   a*B^u - b*B^x + b*B^y - a*B^v = 0 exactly when a(B^u - B^v) = b(B^x - B^y); after gcd reduction
   this becomes B^u - B^v = b_0 * t and B^x - B^y = a_0 * t for a nonzero integer t.
5. **Parameter-cell.** For the two-parameter family [a, -b, c, b-c-a] on a fixed finite domain,
   every forbidden support lies on the parameter line b(x4-x2) + c(x3-x4) = a(x4-x1), and the
   (b, c)-plane is partitioned by finitely many tuple-lines into support-hypergraph chambers.

Also here: `formal/BvSmoke.lean` and `formal/C3Span50Kernel.lean`, the latter carrying
`span50 (x : BitVec 50) : selectedCount x >= 12 -> hasC3Violation x = true`.

## Erdos 564 expedition

`erdos564-expedition/` — seven proof-chain files against **is R_3(n) > 2^(2^(cn)) for some c > 0?**
Four rounds completed, three accepted, terminal decision **REDUCED**. **The problem is not
closed.**

## License

Apache-2.0.
