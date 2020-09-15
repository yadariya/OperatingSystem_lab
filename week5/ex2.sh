#!/bin/bash

# this is program before modifying

#if [[ ! -f "file.txt" ]]; then # if there is no file we create it
#	echo 1 > "file.txt" 
#fi
#while : 
#do  
#		n=$(tail -n 1 < file.txt) #reading from file
#		echo $(($n+1)) >> "file.txt" #writing to file
#done


# critical region is reading and writing to the file.txt
# race condition starts with 1095 iteration (in my case) when number duplicates appear in the file

# this is program after modifying


if [[ ! -f "file.txt" ]]; then # if there is no file we create it
	echo 1 > "file.txt" 
fi
while : 
do  
	 ln "file.txt" "lockfile" &> /dev/null # redirecting stdout stream
	if [[ $? -eq 0 ]]; then # return code of ln
		n=$(tail -n 1 < file.txt) #reading from file
		echo "$(($n+1))" >> "file.txt" #writing to file
		rm "lockfile"
	fi
done