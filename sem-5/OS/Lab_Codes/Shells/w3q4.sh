echo "Enter the number"
read number
temp=$number
fact=1
while [ $temp -ge 1 ]
do
echo $temp
fact=`expr $fact \* $temp`
temp=`expr $temp - 1`
done
echo "Factorial of $number is $fact"
