!# /bin/bash
name=0
read name
if [ $name -gt 100 ]
then
	echo "$1 is lower than 100"
elif [ $name -ge 100 ]
then
	echo "$name is equal to 100"
else
	echo "$name is larger than 100"
fi

