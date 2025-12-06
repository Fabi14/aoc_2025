# https://adventofcode.com/2025/day/1
Input ← &fras "day01/input.txt"

ParseLine  ← ×⊃(-1×2⨂"LR"↙1)(⋕↘1)
SplitLines ← ⊜□¬⊸⌕@\n
PartOne    ← /+=0◿100\+⊂50♭≡₀(ParseLine°□) SplitLines
PartTwo    ← /+=0◿100\+⊂50˜▽⊙⌵⊸± ♭ ≡₀(ParseLine°□) SplitLines

$"Part one: _" PartOne Input
$"Part two: _" PartTwo Input
