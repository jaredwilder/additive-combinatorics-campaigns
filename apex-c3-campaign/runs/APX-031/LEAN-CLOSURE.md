# APX-031 Lean closure

## Result

APX-031 is closed in the Lean kernel. For every `x : BitVec 50`, if at least 12 positions are
selected, `C3Span50Semantic.span50` proves that the selection contains an arbitrary-order C3
support.

This is the exact span-50 theorem, not a smaller proxy. The semantic bridge covers all 15,560
forbidden supports and all 886 clauses of the sequential cardinality encoding. The resulting
16,446-clause context is definitionally identical to the CNF refuted by the LRAT certificate.

## Proof chain

1. The independently checked trimmed LRAT proof contains 447,254 additions.
2. Oracle reconstructs the first 65,000 additions in 13 coarse Lean modules.
3. It reconstructs the remaining 382,254 additions in 153 resumable fine modules.
4. `C3Span50Certificate.unsat` proves the exact CNF context unsatisfiable.
5. Thirty-three semantic segments prove that any 12-point C3-free selection satisfies every CNF
   clause.
6. `C3Span50Semantic.span50` derives a contradiction and closes the human theorem.

The final independent audit completed successfully across 8,453 Lake jobs. The theorem has no `sorryAx` and
does not use `native_decide`; its reported dependencies are Lean's standard `propext`,
`Classical.choice`, and `Quot.sound` axioms.

## Permanent technique

The wall was representation volume, not mathematics. The reusable closure blade is:

> Preserve LRAT dependencies across small restartable Lean modules, kernel-check every module,
> then prove the exact semantic encoding equal to the certified CNF.

This is now an executable path for future large finite UNSAT theorems.
