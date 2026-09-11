import Mathlib

theorem bvSmoke (x : BitVec 8) : x ^^^ x = 0 := by
  revert x
  bv_decide

def count4 (x : BitVec 4) : BitVec 3 :=
  (if x[0] then 1#3 else 0#3) + (if x[1] then 1#3 else 0#3) +
  (if x[2] then 1#3 else 0#3) + (if x[3] then 1#3 else 0#3)

set_option maxRecDepth 100000 in
theorem countSmoke (x : BitVec 4) : count4 x ≤ 4#3 := by
  unfold count4
  revert x
  bv_decide
