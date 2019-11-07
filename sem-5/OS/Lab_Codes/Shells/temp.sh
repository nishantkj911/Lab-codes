mkdir ~/$1 ~/$1/$2 ~/$1/$3
cd ~/$1/$2
echo Input into first file
cat<<file1.txt
I love cookies
Going to New York
Watching movies
Reading books
file1
echo Input into second file
cat>file2.txt
echo Input into third file
cat>file3.txt 
cp file1.txt ~/$1/$3
cd ~/$1/$3
who | wc -l | cat>abc.txt
ls | wc -l | cat>>abc.txt
ls | grep {a*, A*}.txt
ls | wc -l
cd ~/$1/$2        
cat file1.txt | grep o
cat file2.txt | grep o
# cd ~/Desktop/Nishant/Week2