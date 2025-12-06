# https://adventofcode.com/2025/day/4
# Part 2

Input ← &fras "day04/input.txt"

Input
⊜□¬⊸⌕@\n
≡₀(⌕@@°□)

AddBorder      ← ˜⊂0⊂0⍉ ˜⊂0⊂0⍉
CanRemove      ← ×⊙(≤4)⊸↧1×≡₂⊃(⊡ 1_1)(/+/+)⧈∘3_3 AddBorder
CountAndRemove ← ⊃(/+/+)(-)⊸CanRemove

/+/+-◌⊸⍢(◌⊙CountAndRemove)(>0) 1
