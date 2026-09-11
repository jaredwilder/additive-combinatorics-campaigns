# Structured sparse product encoding

**Release class:** standalone additive/combinatorial mathematics extracted from a mixed systems bank. The surrounding process/capsule architecture is intentionally not released here.

## IK2-01 — Structured-Sparsity Product Encoding Theorem

**Status:** `CLOSED_PROVED_USING_CLASSICAL_INPUTS`

For disjoint shards `j` with dimension `m_j` and signed ternary support budget `s_j`, local shifted `B_{s_j}` encodings combined by balanced mixed radix yield one exact integer encoding of bit size

\[
\sum_j s_j\log m_j + O\!\left(\sum_j s_j + J\right),
\]

where `J` is the number of shards.

### Proof core

Each local shifted-`B_s` code is injective and has radius `m_j^{s_j}` up to constants depending only on the fixed sparsity parameter. Balanced mixed radix is injective on the Cartesian product of the local ranges. Product-state counting gives the matching information-scale lower bound up to fixed-parameter constants.

Historical novelty is unverified; the ingredients are classical additive-combinatorial and mixed-radix tools.

## IK2-02 — Compartmentalization Savings Corollary

**Status:** `CLOSED_COROLLARY`

For `K` equal shards with total sparsity `S` distributed as `S/K` per shard and total ambient dimension `M`, the structured product code uses

\[
S\log(M/K)+O(S+K)
\]

bits instead of the global-family scale

\[
S\log M+O(S).
\]

Thus the leading information saving is

\[
S\log K.
\]

This is not magic compression: the sharded legal state family is strictly smaller than the unrestricted global sparse family.

## IK2-04 — Optimal Heterogeneous Mixed-Radix Packing

**Status:** `CLOSED_WITH_SCOPE`

For centered integer coordinates `x_c` satisfying

\[
|x_c|\le A_c,
\]

mixed radices

\[
2A_c+1
\]

minimize the contiguous output span for an injective positional encoding of the full product box. Uniform padding to `2 max_c A_c+1` is never better and is strictly worse whenever the coordinate bounds are not all equal.

### Proof core

The product box has exactly

\[
\prod_c(2A_c+1)
\]

states, so every injective encoding into consecutive integers needs at least that many output values. Mixed radix with radices `2A_c+1` attains the bound exactly. Uniform worst-case padding uses a product range at least as large, with strict inequality when some `A_c` is smaller than the maximum.

## Boundary

This file releases only the abstract mathematics. Heterogeneous fault channels, authenticated checkpoints, behavioral monoids, worker-update verification, and integrated capsule protocols belong to a mixed systems/IP layer and are not part of this release.
