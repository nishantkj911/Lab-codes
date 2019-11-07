echo "Enter n"
read n
x=1
y=1
echo "First $n odd numbers are"
while [ $x -le $n ]
do
echo $y
y=`expr $y + 2`
x=`expr $x + 1`
done
