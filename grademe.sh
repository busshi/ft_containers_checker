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
log="${red}DIFF_LOG${clear}"

cd ${PROJECT_DIR}

run_test()
{
echo -e "${orange}[+] Testing $1 time execution${clear}:"
echo -e "ft::$1\c"
time ./${FT} "$1" > ft.out

echo -e "\nstd::$1\c"
time ./${STD} "$1"  > std.out

echo -e "${orange}[+] Checking diff ft::$1 vs std::$1${clear}\033[50G\c"
log+="\n\n${orange}[+]Checking diff ft::$1 vs std::$1${clear}\n"

dif=$(diff std.out ft.out)
[[ $? -ne 0 ]] && { ko=$(( $ko + 1 )); log+="$dif"; echo -e "❌\n"; } || echo -e "✅\n"
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


[[ $ko -ne 0 ]] && echo -e "$log"


### CLEANING
rm -f ft.out std.out
clean=$(make -C ${PROJECT_DIR} fclean)


exit $ko
