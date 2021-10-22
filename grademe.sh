#!/bin/bash

### VARIABLES


INC_DIR="$PWD/../includes"	# <===== EDIT PATH HERE IF ft_containers_checker IS NOT IN THE ROOT PATH OF YOUR PROJECT




### COLORS

red="\033[0;31m"
green="\033[0;32m"
clear="\033[0;m"
blue="\033[0;94m"
orange="\033[0;33m"
purple="\033[0;35m"


### HEADER
clear

echo -e "${orange}___________________________________________________________________________________________\n"
echo -e "__________________________________ FT_CONTAINERS CHECKER __________________________________\n"
echo -e "___________________________________________________________________________________________\n${clear}"


### COMPILATION
compil()
{
clang++ -Wall -Wextra -Werror -std=c++98 -I${INC_DIR} -DCONTAINER=$2 $1 -o $3 &> $4
}



### TESTS
ko=0

run_test()
{
echo -e "\n\n${purple}[+] Testing $1${clear}\033[50GCompilation\033[70GDiff\n"

mkdir -p "log/$1" "bin/$1"

files=$(ls srcs/$1/*.cpp)

for file in ${files}; do
	filename=$(echo $file | rev | cut -d\/ -f1 | cut -d. -f2 | rev)
	name="$1/${filename}"
	echo -e "${filename}\c"
	compil "$file" ft "bin/${name}.ft" "log/${name}.ft"
	[[ $? -ne 0 ]] && { ko=$(( $ko + 1 )); echo -e "\033[50G❌\c"; } || echo -e "\033[50G✅\c"
	
	./bin/${name}.ft >> "log/${name}.ft" 2> /dev/null

	compil "$file" std "bin/${name}.std" "log/${name}.std"
	./bin/${name}.std >> "log/${name}.std" 2> /dev/null

	diff "log/${name}.ft" "log/${name}.std" &> "log/${name}.diff"
	[[ $? -ne 0 ]] && { ko=$(( $ko + 1 )); echo -e "\033[70G❌"; } || echo -e "\033[70G✅"

	rm -rf "bin/${name}.ft" "bin/${name}.std"
done
}


case "$1" in
	"vector" | "stack" | "map")
		run_test "$1"
		;;
	*)
		for test in vector stack map; do
			run_test "$test"
		done
		;;
esac



### CLEANING
rm -rf bin
[[ $ko -eq 0 ]] && rm -rf log


exit $ko
