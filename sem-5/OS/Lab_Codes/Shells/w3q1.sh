echo "Enter a number"
read no
if [ `expr $no % 2` -eq 0 ] 
then
echo "Even"
else
echo "Odd"
fi