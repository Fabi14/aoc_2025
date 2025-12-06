# https://adventofcode.com/2025/day/2
# Part 2

Input      ← &fras "day02/input.txt"
SplitInput ← ⊜□¬⊸⌕@,

AllSame       ← =0/+⌵-⊸⊢⋕
Invalid       ← =⊃⧻/+AllSame↯˜⊂ ∞⊸(÷⊙⧻)⊙°⋕
ParseRange    ← ⋕⊜□¬⊸⌕@-
InvalidTwo    ← ↧1/+≡(Invalid⊃⊢⊣) ≡⊂⊸(▽¬⤚◿⊸(↘1⇡)⧻°⋕)
ChackRangeTwo ← /+ ≡₀(⊢×⊸InvalidTwo) +⇡+1⊙(⊡0) ⊸/-
/+≡₀(ChackRangeTwo ParseRange°□) SplitInput Input
