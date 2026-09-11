# Simultaneous sum-free / 3-AP-free subsets of `Z/31Z`

**Author:** Jared Wilder  
**Recovered from:** MathFire Round 7 research estate  
**Public extraction:** 2026-09-11

## Exact finite theorem

Let `A ⊆ Z/31Z`. Require simultaneously:

1. **standard sum-free:** `(A+A) ∩ A = ∅`;
2. **nontrivial 3-term-AP-free:** there are no three distinct `x,y,z ∈ A` with `x+z = 2y (mod 31)`.

Exact exhaustive enumeration gives:

- maximum size: **6**;
- valid 6-subsets: **330**;
- valid 7-subsets: **0**;
- unit-dilation orbits of extremal 6-subsets: **12**;
- orbit sizes: two orbits of size 15 and ten of size 30;
- one extremizer: `{1,3,7,15,20,24}`.

Because the property is hereditary, the absence of valid 7-subsets together with a valid 6-subset
proves the exact maximum is 6.

## Independent verifier

`schur_roth_z31_independent.c` is an independent C implementation. It enumerates every 6- and
7-subset of the 31-element group, tests the two forbidden configurations directly, and then
recomputes the unit-dilation orbit partition. Its committed output is in
`schur-roth-z31-c-verifier.txt`.

The recovered research packet also recorded two independent Python decision paths. They are not
needed to trust the C certificate published here.

## Novelty boundary

A systematic search in the source packet did not find the exact simultaneous problem, the value
6, the count 330, or the 12-orbit classification in the searched literature. The safe historical
wording is therefore **"apparently new after systematic search"**, not a priority certificate.
Mathematical truth does not depend on novelty status.

## Reproduce

```bash
cc -O2 -std=c11 schur_roth_z31_independent.c -o schur_roth_z31
./schur_roth_z31
```

The program exits nonzero unless all expected counts agree.

## License

Apache-2.0 for repository-authored material.
