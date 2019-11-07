case $1 in
*.c)
cc $1		
;;
*.h | *.sh)
;;
*)
echo "$1 of unknown type"
;;
esac