# https://adventofcode.com/2025/day/3
# Part 1
ParseLine  ← ⋕⊜∘+₁⇡⊸⧻°□ # ⇌⊥₁₀⋕
SplitLines ← ⊜□¬⊸⌕@\n

🔋      ← 2
Number ← ⊃(↘+₁)⊡⊢ ▽⊸<⊙⊸⍖ -˜-🔋 ⊙⊸⧻

CalcLine₁ ← °⊥₁₀⇌˜⊂ ◌◌ ⟜Number +1 ⟜Number 1

Part₁ ← /+≡₀(CalcLine₁ ParseLine) SplitLines

┌─╴test
  ˙⍤ =357 Part₁ "987654321111111\n811111111111119\n234234234234278\n818181911112111"
└─╴

Input ← &fras "day03/input.txt"
$"Part one: _" Part₁ Input
