#!/bin/bash

### VARIABLES

TEST_DIR="$PWD"


PROJECT_DIR="$PWD/../"		# <===== EDIT PATH HERE IF ft_containers_checker IS NOT IN THE ROOT PATH OF YOUR PROJECT

FT="ft_containers"		# <===== EDIT BINARY VARIABLES HERE
STD="std_containers"



### COLORS

red="\033[0;31m"
green="\033[0;32m"
clear="\033[0;m"
blue="\033[0;94m"
orange="\033[0;33m"
purple="\033[0;35m"


### HEADER
clear

echo -e "${orange}_____________________________________________________________________________________________________\n"
echo -e "_________________________________________ FT_CONTAINERS CHECKER _____________________________________\n"
echo -e "_____________________________________________________________________________________________________\n\n${clear}"


### COMPILATION

compil=$( make -C "$PROJECT_DIR" )
[ $? -ne 0 ] && { echo -e "[ ${red}KO${clear} ] Compilation Error"; exit 1; }


### TESTS
ko=0

cd ${PROJECT_DIR}

run_test()
{
echo -e "${orange}[+] Testing $1${clear}\033[30G\c"
./${FT} "$1" > ft.out
./${STD} "$1" > std.out

dif=$(diff std.out ft.out)

[[ $? -ne 0 ]] && { ko=$(( $ko + 1 )); echo "❌"; } || echo -e "✅"
}


case "$1" in
	"vector" | "stack" | "vector")
		run_test "$1"
		;;
	*)
		for test in vector stack map; do
			run_test "$test"
		done
		;;
esac




### CLEANING
rm -f ft.out std.out
clean=$(make -C ${PROJECT_DIR} fclean)


exit $ko
