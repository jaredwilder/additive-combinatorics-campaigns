#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define N 31

static uint64_t valid6_masks[400];
static int valid6_count = 0;
static int valid7_count = 0;
static uint64_t first_witness = 0;

static int contains(uint64_t mask, int x) { return (int)((mask >> x) & 1ULL); }

/* Independent predicate implementation: ordered Schur triples and middle-first APs. */
static int valid_mask(uint64_t mask) {
    for (int x = 0; x < N; ++x) if (contains(mask, x)) {
        for (int y = 0; y < N; ++y) if (contains(mask, y)) {
            if (contains(mask, (x + y) % N)) return 0;
        }
    }
    for (int y = 0; y < N; ++y) if (contains(mask, y)) {
        for (int x = 0; x < N; ++x) if (contains(mask, x)) {
            int z = (2 * y - x) % N;
            if (z < 0) z += N;
            if (x != y && z != y && z != x && contains(mask, z)) return 0;
        }
    }
    return 1;
}

static void enumerate_layer(int k, int start, int chosen, uint64_t mask) {
    if (chosen == k) {
        if (!valid_mask(mask)) return;
        if (k == 6) {
            if (valid6_count >= 400) { fprintf(stderr, "valid6 buffer exceeded\n"); exit(2); }
            if (!first_witness) first_witness = mask;
            valid6_masks[valid6_count++] = mask;
        } else if (k == 7) {
            ++valid7_count;
        }
        return;
    }
    int need = k - chosen;
    for (int x = start; x <= N - need; ++x) {
        enumerate_layer(k, x + 1, chosen + 1, mask | (1ULL << x));
    }
}

static uint64_t dilate(uint64_t mask, int u) {
    uint64_t out = 0;
    for (int x = 0; x < N; ++x) if (contains(mask, x)) out |= 1ULL << ((u * x) % N);
    return out;
}

static uint64_t canonical(uint64_t mask) {
    uint64_t best = UINT64_MAX;
    for (int u = 1; u < N; ++u) {
        uint64_t d = dilate(mask, u);
        if (d < best) best = d;
    }
    return best;
}

static int seen_u64(const uint64_t *xs, int count, uint64_t value) {
    for (int i = 0; i < count; ++i) if (xs[i] == value) return 1;
    return 0;
}

static void print_set(uint64_t mask) {
    putchar('[');
    int first = 1;
    for (int x = 0; x < N; ++x) if (contains(mask, x)) {
        if (!first) putchar(',');
        printf("%d", x);
        first = 0;
    }
    putchar(']');
}

int main(void) {
    enumerate_layer(6, 0, 0, 0);
    enumerate_layer(7, 0, 0, 0);

    uint64_t reps[400];
    int rep_count = 0;
    for (int i = 0; i < valid6_count; ++i) {
        uint64_t rep = canonical(valid6_masks[i]);
        if (!seen_u64(reps, rep_count, rep)) reps[rep_count++] = rep;
    }

    int orbit15 = 0, orbit30 = 0, orbit_other = 0, orbit_total = 0;
    for (int i = 0; i < rep_count; ++i) {
        uint64_t orbit[30]; int count = 0;
        for (int u = 1; u < N; ++u) {
            uint64_t d = dilate(reps[i], u);
            if (!seen_u64(orbit, count, d)) orbit[count++] = d;
        }
        orbit_total += count;
        if (count == 15) ++orbit15;
        else if (count == 30) ++orbit30;
        else ++orbit_other;
    }

    printf("modulus=31\n");
    printf("valid_size_6_count=%d\n", valid6_count);
    printf("valid_size_7_count=%d\n", valid7_count);
    printf("orbit_count=%d\n", rep_count);
    printf("orbit_size_15_count=%d\n", orbit15);
    printf("orbit_size_30_count=%d\n", orbit30);
    printf("orbit_other_count=%d\n", orbit_other);
    printf("orbit_total=%d\n", orbit_total);
    printf("first_witness="); print_set(first_witness); putchar('\n');

    if (valid6_count != 330 || valid7_count != 0 || rep_count != 12 ||
        orbit15 != 2 || orbit30 != 10 || orbit_other != 0 || orbit_total != 330) {
        return 1;
    }
    return 0;
}
