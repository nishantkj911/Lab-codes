echo "Menu text program"
stop=0
while test $stop -eq 0
do
cat<<ENDOFMENU
1: print the date
2, 3: print the current working directory
4: exit
ENDOFMENU
echo
echo "Your Choice ?"
read reply
case $reply in
	"1")
		date
		;;
	"2" | "3")
		pwd
		;;
	"4")
		stop=1
		;;
	*)
	echo "Illegal Choice"
	;;
esac
done
