# https://adventofcode.com/2025/day/2
# Part 1
Input      ← &fras "day02/input.txt"
SplitInput ← ⊜□¬⊸⌕@,
Invalid    ← =⊃⧻/+=⊃↙↘⊸(÷2⧻)°⋕
ParseRange ← ⋕⊜□¬⊸⌕@-
ChackRange ← /+ ≡₀(×⊸Invalid) ▽⊸≡₀(¬◿2⧻°⋕) +⇡+1⊙(⊡0) ⊸/-
/+≡₀(ChackRange ParseRange°□) SplitInput Input
