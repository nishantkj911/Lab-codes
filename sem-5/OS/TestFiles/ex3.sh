salutation="Hello"
echo $salutation
echo "The program $0 is now running"
echo "The second parameter was $2"
echo "The first parameter was $1"
echo "The parameter list: $*"
echo "The user's home directory is $HOME"
echo "The current working directory is `pwd`"
echo "Please enter a new greeting"
read salutation
echo $salutation
echo "The script is now complete"
echo $@
echo $#
exit 0
