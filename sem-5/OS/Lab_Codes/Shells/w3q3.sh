echo "Enter the values of a b c in the expression ax2 + bx + c"
read a
read b
read c
# d=`expr \(b \* b\) - \(4 \* $a \* $c\)`
d=$((b*b-4*a*c))
if [ $d -eq 0 ]
then
echo "Equal roots with roots equal to `expr -1 * \($b\) \/ \(2 * $a\)`"
fi