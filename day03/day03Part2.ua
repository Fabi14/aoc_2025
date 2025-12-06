# https://adventofcode.com/2025/day/3
# Part 2
ParseLine  ← ⋕⊜∘+₁⇡⊸⧻°□ # ⇌⊥₁₀⋕
SplitLines ← ⊜□¬⊸⌕@\n

🔋         ← 12
Number    ← ⊃(↘+₁)⊡⊢ ▽⊸<⊙⊸⍖ -˜-🔋 ⊙⊸⧻
EB        ← ⊙⊙˜⊂(⟜Number +1)
CalcLine₂ ← °⊥₁₀⇌˜⊂ ◌◌ ⟜Number +1 EB EB EB EB EB EB EB EB EB EB ⟜Number 1

Part₂ ← /+≡₀(CalcLine₂ ParseLine) SplitLines

┌─╴test
  ˙⍤ =3121910778619 Part₂ "987654321111111\n811111111111119\n234234234234278\n818181911112111"
└─╴

Input ← &fras "day03/input.txt"

$"Part two: _" Part₂ Input
