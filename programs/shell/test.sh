!#/bin/bash
if [ $# -ne 1 ]; then
	echo "You should add a parameter, which is an integer to the file"
	echo "Such that bash test.sh 100"
fi
n=$1
rev=0
sd=0
while [ $n -gt 0 ]; do
	sd=`expr $n % 10`
	rev=`expr $rev \* 10 + $sd`
	n=`expr $n / 10`
done
echo "Reverse number is $rev"


for i in 1 2 3 4 5 //can $(seq 5)
do
	sd=`expr 1`
done




