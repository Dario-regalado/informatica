.data
.text
main:
if:
    blt    $s0,$s1,if_2
    b      if_fin
if_2:
    beq    $s1,$s2,if_then
    b      if_fin
if_then:
    b      $s3
    move   $s0,$s1
if_fin:
