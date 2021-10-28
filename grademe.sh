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
check_sig()
{
if [ $1 -eq 142 ] ; then
	echo -e "\033[70G\033[31;1mT${clear}"
	return 0
elif [ $1 -eq 134 ] ; then
	echo -e "\033[70G\033[31;1mA${clear}"
	return 0
elif [ $1 -eq 139 ] ; then
	echo -e "\033[70G\033[31;1mS${clear}"
	return 0
elif [ $1 -eq 138 ] ; then
	echo -e "\033[70G\033[31;1mB${clear}"
	return 0
else
	return 1
fi
}

test_leak()
{
valgrind --leak-check=full "$1" &> "log/${name}.leak"
free=$(cat "log/${name}.leak" | grep "All heap blocks were freed -- no leaks are possible")
[ "$free" != "" ] && { echo -e "\033[75G✅"; rm -f "log/${name}.leak"; } || { echo -e "\033[75G❌"; ko=$(( $ko + 1 )); }
}

ko=0

run_test()
{
echo -e "\n\n${purple}[+] Testing $1\033[40GCompilation\033[60GDiff\033[75GLeak${clear}\n"

mkdir -p "log/$1" "bin/$1"

check_leak=$(whereis valgrind)

files=$(ls srcs/$1/*.cpp)

for file in ${files}; do
	filename=$(echo $file | rev | cut -d\/ -f1 | cut -d. -f2 | rev)
	name="$1/${filename}"
	echo -e "${filename}\c"
	compil "$file" ft "bin/${name}.ft" "log/${name}.ft"
	[[ $? -ne 0 ]] && { ko=$(( $ko + 1 )); echo -e "\033[50G❌\c"; } || echo -e "\033[40G✅\c"
	
	run=$(./bin/${name}.ft >> "log/${name}.ft" 2> "log/${name}.ft")
	sig=$?
	if ! check_sig $sig; then
		compil "$file" std "bin/${name}.std" "log/${name}.std"
		run=$( ./bin/${name}.std >> "log/${name}.std" 2> "log/${name}.std")
		sig=$?
		if ! check_sig $sig; then
			diff "log/${name}.ft" "log/${name}.std" &> "log/${name}.diff"
		[[ $? -ne 0 ]] && { ko=$(( $ko + 1 )); echo -e "\033[70G❌"; } || echo -e "\033[60G✅\c"
		[ "$check_leak" = "" ] && echo -e "\033[75Gvalgrind missing" || test_leak "./bin/${name}.ft"
		fi
	fi
	rm -rf "bin/${name}.ft" "bin/${name}.std"
done
}

run_one()
{
vec=$(echo "$1" | cut -d\/ -f2)
mkdir -p "log/${vec}" "bin/${vec}"

check_leak=$(whereis valgrind)

file=$1

name=$(echo $file | rev | cut -d\/ -f1 | cut -d. -f2 | rev)
echo -e "\n\n${purple}[+] Testing ${vec}/${name}\033[40GCompilation\033[60GDiff\033[75GLeak${clear}\n"
echo -e "${name}\c"

name="${vec}/${name}"
compil "$file" ft "bin/${name}.ft" "log/${name}.ft"
[[ $? -ne 0 ]] && { ko=$(( $ko + 1 )); echo -e "\033[50G❌\c"; } || echo -e "\033[40G✅\c"
	
run=$(./bin/${name}.ft >> "log/${name}.ft" 2> "log/${name}.ft")
sig=$?
if ! check_sig $sig; then
	compil "$file" std "bin/${name}.std" "log/${name}.std"
	run=$( ./bin/${name}.std >> "log/${name}.std" 2> "log/${name}.std")
	sig=$?
	if ! check_sig $sig; then
		diff "log/${name}.ft" "log/${name}.std" &> "log/${name}.diff"
	[[ $? -ne 0 ]] && { ko=$(( $ko + 1 )); echo -e "\033[70G❌"; } || echo -e "\033[60G✅\c"
	[ "$check_leak" = "" ] && echo -e "\033[75Gvalgrind missing" || test_leak "./bin/${name}.ft"
	fi
fi
rm -rf "bin/${name}.ft" "bin/${name}.std"
}



case "$1" in
	"vector" | "stack" | "map")
		run_test "$1"
		;;
	"one")
		[ -z "$2" ] && echo "Usage: ./grademe.sh one [path_to_test_file]" && exit 1
		run_one "$2"
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
