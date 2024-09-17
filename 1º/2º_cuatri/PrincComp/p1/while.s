.data
while:
  blez    $s0, while_fin
  b       while_dentro
while_dentro:
  move    $s1, $zero
  li      $v0, 5
  add     $s0, $s1, $v0
  b       while
while_fin:

.text
main:
  move    $s0, 5
