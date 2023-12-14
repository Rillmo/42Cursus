#!/bin/bash

echo -e "\033[1;37m##################################################\033[0m"
echo -e "\033[1;37m############## [PUSH SWAP TUTORIAL] ##############\033[0m"
echo -e "\033[1;37m##################################################\033[0m"
echo
echo -e "\033[1;37m----------------  [1. MANDATORY]  ----------------\033[0m"
echo -e "\033[1;37m----------------   [2. BONUS]    ----------------\033[0m"
echo -e "\033[1;37m---------------- [3. REMOVE LOGS] ----------------\033[0m"
echo -n "SELECT MODE : "

read MODE

if [ $MODE == 1 ]
then
	make re

	norminette

	curl -O https://cdn.intra.42.fr/document/document/23048/checker_Mac
	chmod 755 checker_Mac

	TOTAL=0
	MAX=0
	MIN=999999999
	MIN_IDX=0
	MAX_IDX=0

	CNT_KO=0
	CNT_Error=0
	CNT_OK=0

	rm -rf ./push_swap_tutorial
	mkdir push_swap_tutorial
	mkdir push_swap_tutorial/KO
	mkdir push_swap_tutorial/OK
	mkdir push_swap_tutorial/Error

	echo -e "\033[1;37m---------------- [try 100 stack - 2000 times] ----------------\033[0m"

	for (( var=1; var<=2000; var++ ))
	do
		let _progress=($var*100/2000*100)/100
		let _done=(${_progress}*4)/10
		let _left=40-$_done
		_fill=$(printf "%${_done}s")
		_empty=$(printf "%${_left}s")
		printf "\rProgress : [\033[1;32m${_fill// /█}\033[1;0m${_empty// /-}] ${_progress}%%"
		ARGS="$(seq 100 | sort -R | xargs)"
		CMDS="$(echo $(./push_swap "$ARGS") | tr ' ' '\n')"
		VALUE="$( echo "$CMDS" | ./checker_Mac "$ARGS")"
		COUNT="$( echo "$CMDS" | wc -l)"

		if [ -z $VALUE ] || [ $VALUE == "Error" ]
		then
			echo $ARGS > ./push_swap_tutorial/Error/testcase_Error_$NUM\_$var
			((TOTAL = $TOTAL + $COUNT))
			[ $MAX -ge $COUNT ] && MAX=$MAX || MAX_IDX=$var
			[ $COUNT -ge $MIN ] && MIN=$MIN || MIN_IDX=$var
			[ $MAX -ge $COUNT ] && MAX=$MAX || MAX=$COUNT
			[ $COUNT -ge $MIN ] && MIN=$MIN || MIN=$COUNT
		elif [ $VALUE == "KO" ]
		then
			echo $ARGS > ./push_swap_tutorial/KO/testcase_KO_$var
		elif [ $VALUE == "OK" ]
		then
			((TOTAL = $TOTAL + $COUNT))
			[ $MAX -ge $COUNT ] && MAX=$MAX || echo $ARGS > ./push_swap_tutorial/OK/testcase_MAX
			[ $COUNT -ge $MIN ] && MIN=$MIN || echo $ARGS > ./push_swap_tutorial/OK/testcase_MIN
			[ $MAX -ge $COUNT ] && MAX=$MAX || MAX_IDX=$var
			[ $COUNT -ge $MIN ] && MIN=$MIN || MIN_IDX=$var
			[ $MAX -ge $COUNT ] && MAX=$MAX || MAX=$COUNT
			[ $COUNT -ge $MIN ] && MIN=$MIN || MIN=$COUNT
		fi
	done
	AVG=$(expr $TOTAL / 2000)
	echo -e	"		\n\n\033[1;32mAVG : $AVG\033[1;0m, \033[1;32m	MIN : $MIN  at case_$MIN_IDX\033[1;0m, \033[1;31m	MAX : $MAX  at case_$MAX_IDX"
	echo
	echo
	echo -e "\033[1;37m-------------- [try from 1 stack to 1000 stack] --------------\033[0m"
	for (( var=1; var<=1000; var++ ))
	do
		let _progress=($var*100/1000*100)/100
		let _done=(${_progress}*4)/10
		let _left=40-$_done
		_fill=$(printf "%${_done}s")
		_empty=$(printf "%${_left}s")
		printf "\rProgress : [\033[1;32m${_fill// /█}\033[1;0m${_empty// /-}] ${_progress}%%"
		ARGS="$(seq $var | sort -R | xargs)"
		VALUE="$(./push_swap "$ARGS" | ./checker_Mac "$ARGS")"

		if [ -z $VALUE ] || [ $VALUE == "Error" ]
		then
			echo $ARGS > ./push_swap_tutorial/Error/testcase_Error_MAN_RANGE_$var
			((CNT_Error++))
		elif [ $VALUE == "KO" ]
		then
			echo $ARGS > ./push_swap_tutorial/KO/testcase_KO_MAN_RANGE_$var
			((CNT_KO++))
		elif [ $VALUE == "OK" ]
		then
			((CNT_OK++))
		fi
	done
	echo -e	"		\n\n\033[1;32mOK : $CNT_OK\033[1;0m, \033[1;31m	KO : $CNT_KO\033[1;0m, \033[1;31m	Error : $CNT_Error"
	echo
	echo
	echo -e "\033[1;37m---------------- [try stack - (-100 to 100)] -----------------\033[0m\n"

	CNT_KO=0
	CNT_Error=0
	CNT_OK=0

	ARGS="$(seq "-100" "100" | sort -R | xargs)"
	VALUE="$(./push_swap "$ARGS" | ./checker_Mac "$ARGS")"
	
	if [ -z $VALUE ] || [ $VALUE == "Error" ]
	then
		echo $ARGS > ./push_swap_tutorial/Error/testcase_Error_MINUS_TEST
		((CNT_Error++))
	elif [ $VALUE == "KO" ]
	then
		echo $ARGS > ./push_swap_tutorial/KO/testcase_KO_MINUS_TEST
		((CNT_KO++))
	elif [ $VALUE == "OK" ]
	then
		echo $ARGS > ./push_swap_tutorial/OK/testcase_OK_MINUS_TEST
		((CNT_OK++))
	fi
	echo -e	"		\n\n\033[1;32mOK : $CNT_OK\033[1;0m, \033[1;31m	KO : $CNT_KO\033[1;0m, \033[1;31m	Error : $CNT_Error"
	echo
	echo -e "\033[1;37m-------------- [chk range - (MAX/MIN INTEGER)] ---------------\033[0m\n"

	CNT_KO=0
	CNT_Error=0
	CNT_OK=0

	ARGS="1 2 3 4 2147483648"
	VALUE="$(./push_swap "$ARGS" | ./checker_Mac "$ARGS")"
	if [ -z $VALUE ] || [ $VALUE == "Error" ]
	then
		echo "$ARGS" > ./push_swap_tutorial/OK/testcase_OK_BAD_MAX_INT_TEST
		((CNT_OK++))
	elif [ $VALUE == "KO" ]
	then
		echo "$ARGS" > ./push_swap_tutorial/KO/testcase_KO_BAD_MAX_INT_TEST
		((CNT_KO++))
	elif [ $VALUE == "OK" ]
	then
		echo "$ARGS" > ./push_swap_tutorial/KO/testcase_KO_BAD_MAX_INT_TEST
		((CNT_KO++))
	fi

	ARGS="-2147483649 1 2 3 4"
	VALUE="$(./push_swap "$ARGS" | ./checker_Mac "$ARGS")"
	if [ -z $VALUE ] || [ $VALUE == "Error" ]
	then
		echo "$ARGS" > ./push_swap_tutorial/OK/testcase_OK_BAD_MIN_INT_TEST
		((CNT_OK++))
	elif [ $VALUE == "KO" ]
	then
		echo "$ARGS" > ./push_swap_tutorial/KO/testcase_KO_BAD_MIN_INT_TEST
		((CNT_KO++))
	elif [ $VALUE == "OK" ]
	then
		echo "$ARGS" > ./push_swap_tutorial/KO/testcase_KO_BAD_MIN_INT_TEST
		((CNT_KO++))
	fi

	ARGS="2147483647 1 2 3 4"
	VALUE="$(./push_swap "$ARGS" | ./checker_Mac "$ARGS")"
	if [ -z $VALUE ] || [ $VALUE == "Error" ]
	then
		echo "$ARGS" > ./push_swap_tutorial/Error/testcase_Error_FINE_MAX_INT_TEST
		((CNT_Error++))
	elif [ $VALUE == "KO" ]
	then
		echo "$ARGS" > ./push_swap_tutorial/KO/testcase_KO_FINE_MAX_INT_TEST
		((CNT_KO++))
	elif [ $VALUE == "OK" ]
	then
		echo "$ARGS" > ./push_swap_tutorial/OK/testcase_OK_FINE_MAX_INT_TEST
		((CNT_OK++))
	fi

	ARGS="1 2 3 4 -2147483648"
	VALUE="$(./push_swap "$ARGS" | ./checker_Mac "$ARGS")"
	if [ -z $VALUE ] || [ $VALUE == "Error" ]
	then
		echo "$ARGS" > ./push_swap_tutorial/Error/testcase_Error_FINE_MIN_INT_TEST
		((CNT_Error++))
	elif [ $VALUE == "KO" ]
	then
		echo "$ARGS" > ./push_swap_tutorial/KO/testcase_KO_FINE_MIN_INT_TEST
		((CNT_KO++))
	elif [ $VALUE == "OK" ]
	then
		echo "$ARGS" > ./push_swap_tutorial/OK/testcase_OK_FINE_MIN_INT_TEST
		((CNT_OK++))
	fi

	echo -e	"		\n\n\033[1;32mOK : $CNT_OK\033[1;0m, \033[1;31m	KO : $CNT_KO\033[1;0m, \033[1;31m	Error : $CNT_Error"
	echo
	echo -e "\033[1;37m-------------------- [wrong input test] ----------------------\033[0m\n"

	CNT_KO=0
	CNT_Error=0
	CNT_OK=0

	ARGS="1 25 \"3\" 4 \"\" 7"
	VALUE="$(./push_swap "$ARGS" | ./checker_Mac "$ARGS")"
	if [ -z $VALUE ] || [ $VALUE == "Error" ]
	then
		echo "$ARGS" > ./push_swap_tutorial/OK/testcase_OK_wrong_input_test_1
		((CNT_OK++))
	elif [ $VALUE == "KO" ]
	then
		echo "$ARGS" > ./push_swap_tutorial/KO/testcase_KO_wrong_input_test_1
		((CNT_KO++))
	elif [ $VALUE == "OK" ]
	then
		echo "$ARGS" > ./push_swap_tutorial/KO/testcase_KO_wrong_input_test_1
		((CNT_KO++))
	fi

	ARGS="1 1"
	VALUE="$(./push_swap "$ARGS" | ./checker_Mac "$ARGS")"
	if [ -z $VALUE ] || [ $VALUE == "Error" ]
	then
		echo "$ARGS" > ./push_swap_tutorial/OK/testcase_OK_wrong_input_test_1
		((CNT_OK++))
	elif [ $VALUE == "KO" ]
	then
		echo "$ARGS" > ./push_swap_tutorial/KO/testcase_KO_wrong_input_test_1
		((CNT_KO++))
	elif [ $VALUE == "OK" ]
	then
		echo "$ARGS" > ./push_swap_tutorial/KO/testcase_KO_wrong_input_test_1
		((CNT_KO++))
	fi

	ARGS="1 2 1"
	VALUE="$(./push_swap "$ARGS" | ./checker_Mac "$ARGS")"
	if [ -z $VALUE ] || [ $VALUE == "Error" ]
	then
		echo "$ARGS" > ./push_swap_tutorial/OK/testcase_OK_wrong_input_test_1
		((CNT_OK++))
	elif [ $VALUE == "KO" ]
	then
		echo "$ARGS" > ./push_swap_tutorial/KO/testcase_KO_wrong_input_test_1
		((CNT_KO++))
	elif [ $VALUE == "OK" ]
	then
		echo "$ARGS" > ./push_swap_tutorial/KO/testcase_KO_wrong_input_test_1
		((CNT_KO++))
	fi

	ARGS="1 3 5 2 4 3 7"
	VALUE="$(./push_swap "$ARGS" | ./checker_Mac "$ARGS")"
	if [ -z $VALUE ] || [ $VALUE == "Error" ]
	then
		echo "$ARGS" > ./push_swap_tutorial/OK/testcase_OK_wrong_input_test_1
		((CNT_OK++))
	elif [ $VALUE == "KO" ]
	then
		echo "$ARGS" > ./push_swap_tutorial/KO/testcase_KO_wrong_input_test_1
		((CNT_KO++))
	elif [ $VALUE == "OK" ]
	then
		echo "$ARGS" > ./push_swap_tutorial/KO/testcase_KO_wrong_input_test_1
		((CNT_KO++))
	fi

	ARGS="1 2 4 5 6 3 \"13 4\""
	VALUE="$(./push_swap "$ARGS" | ./checker_Mac "$ARGS")"
	if [ -z $VALUE ] || [ $VALUE == "Error" ]
	then
		echo "$ARGS" > ./push_swap_tutorial/OK/testcase_OK_wrong_input_test_1
		((CNT_OK++))
	elif [ $VALUE == "KO" ]
	then
		echo "$ARGS" > ./push_swap_tutorial/KO/testcase_KO_wrong_input_test_1
		((CNT_KO++))
	elif [ $VALUE == "OK" ]
	then
		echo "$ARGS" > ./push_swap_tutorial/KO/testcase_KO_wrong_input_test_1
		((CNT_KO++))
	fi

	ARGS="12 1345 4562 1 31a 346"
	VALUE="$(./push_swap "$ARGS" | ./checker_Mac "$ARGS")"
	if [ -z $VALUE ] || [ $VALUE == "Error" ]
	then
		echo "$ARGS" > ./push_swap_tutorial/OK/testcase_OK_wrong_input_test_1
		((CNT_OK++))
	elif [ $VALUE == "KO" ]
	then
		echo "$ARGS" > ./push_swap_tutorial/KO/testcase_KO_wrong_input_test_1
		((CNT_KO++))
	elif [ $VALUE == "OK" ]
	then
		echo "$ARGS" > ./push_swap_tutorial/KO/testcase_KO_wrong_input_test_1
		((CNT_KO++))
	fi

	ARGS="5 123 56 3 b"
	VALUE="$(./push_swap "$ARGS" | ./checker_Mac "$ARGS")"
	if [ -z $VALUE ] || [ $VALUE == "Error" ]
	then
		echo "$ARGS" > ./push_swap_tutorial/OK/testcase_OK_wrong_input_test_1
		((CNT_OK++))
	elif [ $VALUE == "KO" ]
	then
		echo "$ARGS" > ./push_swap_tutorial/KO/testcase_KO_wrong_input_test_1
		((CNT_KO++))
	elif [ $VALUE == "OK" ]
	then
		echo "$ARGS" > ./push_swap_tutorial/KO/testcase_KO_wrong_input_test_1
		((CNT_KO++))
	fi

	ARGS="a 3 4 5 6"
	VALUE="$(./push_swap "$ARGS" | ./checker_Mac "$ARGS")"
	if [ -z $VALUE ] || [ $VALUE == "Error" ]
	then
		echo "$ARGS" > ./push_swap_tutorial/OK/testcase_OK_wrong_input_test_1
		((CNT_OK++))
	elif [ $VALUE == "KO" ]
	then
		echo "$ARGS" > ./push_swap_tutorial/KO/testcase_KO_wrong_input_test_1
		((CNT_KO++))
	elif [ $VALUE == "OK" ]
	then
		echo "$ARGS" > ./push_swap_tutorial/KO/testcase_KO_wrong_input_test_1
		((CNT_KO++))
	fi

	ARGS="999999999999999999"
	VALUE="$(./push_swap "$ARGS" | ./checker_Mac "$ARGS")"
	if [ -z $VALUE ] || [ $VALUE == "Error" ]
	then
		echo "$ARGS" > ./push_swap_tutorial/OK/testcase_OK_wrong_input_test_1
		((CNT_OK++))
	elif [ $VALUE == "KO" ]
	then
		echo "$ARGS" > ./push_swap_tutorial/KO/testcase_KO_wrong_input_test_1
		((CNT_KO++))
	elif [ $VALUE == "OK" ]
	then
		echo "$ARGS" > ./push_swap_tutorial/KO/testcase_KO_wrong_input_test_1
		((CNT_KO++))
	fi

	ARGS="#1 2"
	VALUE="$(./push_swap "$ARGS" | ./checker_Mac "$ARGS")"
	if [ -z $VALUE ] || [ $VALUE == "Error" ]
	then
		echo "$ARGS" > ./push_swap_tutorial/OK/testcase_OK_wrong_input_test_1
		((CNT_OK++))
	elif [ $VALUE == "KO" ]
	then
		echo "$ARGS" > ./push_swap_tutorial/KO/testcase_KO_wrong_input_test_1
		((CNT_KO++))
	elif [ $VALUE == "OK" ]
	then
		echo "$ARGS" > ./push_swap_tutorial/KO/testcase_KO_wrong_input_test_1
		((CNT_KO++))
	fi

	ARGS="1# 3"
	VALUE="$(./push_swap "$ARGS" | ./checker_Mac "$ARGS")"
	if [ -z $VALUE ] || [ $VALUE == "Error" ]
	then
		echo "$ARGS" > ./push_swap_tutorial/OK/testcase_OK_wrong_input_test_1
		((CNT_OK++))
	elif [ $VALUE == "KO" ]
	then
		echo "$ARGS" > ./push_swap_tutorial/KO/testcase_KO_wrong_input_test_1
		((CNT_KO++))
	elif [ $VALUE == "OK" ]
	then
		echo "$ARGS" > ./push_swap_tutorial/KO/testcase_KO_wrong_input_test_1
		((CNT_KO++))
	fi

	echo -e	"		\n\n\033[1;32mOK : $CNT_OK\033[1;0m, \033[1;31m	KO : $CNT_KO\033[1;0m, \033[1;31m	Error : $CNT_Error"
	echo
	echo
	echo -e "		\033[42;1;37mlog files : ./push_swap_tutorial/\033[0m\n\n--------------------------------------------------------------\n\n"
	echo
elif [ $MODE == 2 ]
then
	make re

	make bonus

	norminette

	CNT_KO=0
	CNT_Error=0
	CNT_OK=0

	rm -rf ./push_swap_tutorial
	mkdir push_swap_tutorial
	mkdir push_swap_tutorial/KO
	mkdir push_swap_tutorial/OK
	mkdir push_swap_tutorial/Error

	echo -e "\033[1;37m---BONUS------ [try from 1 stack to 1000 stack] ------BONUS---\033[0m"

	for (( var=1; var<=1000; var++ ))
	do
		let _progress=($var*100/1000*100)/100
		let _done=(${_progress}*4)/10
		let _left=40-$_done
		_fill=$(printf "%${_done}s")
		_empty=$(printf "%${_left}s")
		printf "\rProgress : [\033[1;32m${_fill// /█}\033[1;0m${_empty// /-}] ${_progress}%%"
		ARGS="$(seq $var | sort -R | xargs)"
		VALUE="$(./push_swap "$ARGS" | ./checker "$ARGS")"

		if [ -z $VALUE ] || [ $VALUE == "Error" ]
		then
			echo $ARGS > ./push_swap_tutorial/Error/testcase_Error_BONUS_RANGE_$var
			((CNT_Error++))
		elif [ $VALUE == "KO" ]
		then
			echo $ARGS > ./push_swap_tutorial/KO/testcase_KO_BONUS_RANGE_$var
			((CNT_KO++))
		elif [ $VALUE == "OK" ]
		then
			((CNT_OK++))
		fi
	done
	echo -e	"		\n\n\033[1;32mOK : $CNT_OK\033[1;0m, \033[1;31m	KO : $CNT_KO\033[1;0m, \033[1;31m	Error : $CNT_Error"
	echo
	echo -e "\033[1;37m---BONUS------- [check ascending with stack B] -------BONUS---\033[0m\n"

	CNT_KO=0
	CNT_Error=0
	CNT_OK=0

	ARGS="$(seq 1000 | xargs)"
	VALUE="$( echo "pb" | ./checker "$ARGS")"
	
	if [ -z $VALUE ] || [ $VALUE == "Error" ]
	then
		echo $ARGS > ./push_swap_tutorial/Error/testcase_Error_stack_B_TEST
		((CNT_Error++))
	elif [ $VALUE == "KO" ]
	then
		echo $ARGS > ./push_swap_tutorial/OK/testcase_OK_stack_B_TEST
		((CNT_KO++))
	elif [ $VALUE == "OK" ]
	then
		echo $ARGS > ./push_swap_tutorial/KO/testcase_KO_stack_B_TEST
		((CNT_OK++))
	fi
	echo -e	"		\n\n\033[1;31mOK : $CNT_OK\033[1;0m, \033[1;32m	KO : $CNT_KO\033[1;0m, \033[1;31m	Error : $CNT_Error"
	echo
	echo
	echo -e "		\033[42;1;37mKO MEANS PERFECT, OK IS NOT OK\033[0m"
	echo
	echo -e "\033[1;37m---BONUS--------------- [check funcs] ----------------BONUS---\033[0m\n"

	CNT_KO=0
	CNT_Error=0
	CNT_OK=0

	VALUE="$( echo -e "sb\nrb\nrrb\npa\nrrr\nss\nrr\npb\nsa\nra\nrra\npb\nrrr\nss\nrr\npa" | ./checker "1" )"

	if [ -z $VALUE ] || [ $VALUE == "Error" ]
	then
		echo -e "		\033[41;1;37mYOUR PUSH_SWAP CMD IS WRONG\033[0m\n\n"
		((CNT_Error++))
	elif [ $VALUE == "KO" ]
	then
		echo -e "		\033[41;1;37mYOUR PUSH_SWAP CMD IS WRONG\033[0m\n\n"
		((CNT_KO++))
	elif [ $VALUE == "OK" ]
	then
		echo -e "		\033[42;1;37mYOUR PUSH_SWAP CMD IS PERFECT\033[0m\n\n"
		((CNT_OK++))
	fi
	
	echo -e "\033[1;37m-------------- [chk range - (MAX/MIN INTEGER)] ---------------\033[0m\n"

	CNT_KO=0
	CNT_Error=0
	CNT_OK=0

	ARGS="1 2 3 4 2147483648"
	VALUE="$(./push_swap "$ARGS" | ./checker "$ARGS")"
	if [ -z $VALUE ] || [ $VALUE == "Error" ]
	then
		echo "$ARGS" > ./push_swap_tutorial/OK/testcase_OK_BAD_MAX_INT_TEST
		((CNT_OK++))
	elif [ $VALUE == "KO" ]
	then
		echo "$ARGS" > ./push_swap_tutorial/KO/testcase_KO_BAD_MAX_INT_TEST
		((CNT_KO++))
	elif [ $VALUE == "OK" ]
	then
		echo "$ARGS" > ./push_swap_tutorial/KO/testcase_KO_BAD_MAX_INT_TEST
		((CNT_KO++))
	fi

	ARGS="-2147483649 1 2 3 4"
	VALUE="$(./push_swap "$ARGS" | ./checker "$ARGS")"
	if [ -z $VALUE ] || [ $VALUE == "Error" ]
	then
		echo "$ARGS" > ./push_swap_tutorial/OK/testcase_OK_BAD_MIN_INT_TEST
		((CNT_OK++))
	elif [ $VALUE == "KO" ]
	then
		echo "$ARGS" > ./push_swap_tutorial/KO/testcase_KO_BAD_MIN_INT_TEST
		((CNT_KO++))
	elif [ $VALUE == "OK" ]
	then
		echo "$ARGS" > ./push_swap_tutorial/KO/testcase_KO_BAD_MIN_INT_TEST
		((CNT_KO++))
	fi

	ARGS="2147483647 1 2 3 4"
	VALUE="$(./push_swap "$ARGS" | ./checker "$ARGS")"
	if [ -z $VALUE ] || [ $VALUE == "Error" ]
	then
		echo "$ARGS" > ./push_swap_tutorial/Error/testcase_Error_FINE_MAX_INT_TEST
		((CNT_Error++))
	elif [ $VALUE == "KO" ]
	then
		echo "$ARGS" > ./push_swap_tutorial/KO/testcase_KO_FINE_MAX_INT_TEST
		((CNT_KO++))
	elif [ $VALUE == "OK" ]
	then
		echo "$ARGS" > ./push_swap_tutorial/OK/testcase_OK_FINE_MAX_INT_TEST
		((CNT_OK++))
	fi

	ARGS="1 2 3 4 -2147483648"
	VALUE="$(./push_swap "$ARGS" | ./checker "$ARGS")"
	if [ -z $VALUE ] || [ $VALUE == "Error" ]
	then
		echo "$ARGS" > ./push_swap_tutorial/Error/testcase_Error_FINE_MIN_INT_TEST
		((CNT_Error++))
	elif [ $VALUE == "KO" ]
	then
		echo "$ARGS" > ./push_swap_tutorial/KO/testcase_KO_FINE_MIN_INT_TEST
		((CNT_KO++))
	elif [ $VALUE == "OK" ]
	then
		echo "$ARGS" > ./push_swap_tutorial/OK/testcase_OK_FINE_MIN_INT_TEST
		((CNT_OK++))
	fi

	echo -e	"		\n\n\033[1;32mOK : $CNT_OK\033[1;0m, \033[1;31m	KO : $CNT_KO\033[1;0m, \033[1;31m	Error : $CNT_Error"
	echo
	echo -e "\033[1;37m-------------------- [wrong input test] ----------------------\033[0m\n"

	CNT_KO=0
	CNT_Error=0
	CNT_OK=0

	ARGS="1 25 \"3\" 4 \"\" 7"
	VALUE="$(./push_swap "$ARGS" | ./checker "$ARGS")"
	if [ -z $VALUE ] || [ $VALUE == "Error" ]
	then
		echo "$ARGS" > ./push_swap_tutorial/OK/testcase_OK_wrong_input_test_1
		((CNT_OK++))
	elif [ $VALUE == "KO" ]
	then
		echo "$ARGS" > ./push_swap_tutorial/KO/testcase_KO_wrong_input_test_1
		((CNT_KO++))
	elif [ $VALUE == "OK" ]
	then
		echo "$ARGS" > ./push_swap_tutorial/KO/testcase_KO_wrong_input_test_1
		((CNT_KO++))
	fi

	ARGS="1 1"
	VALUE="$(./push_swap "$ARGS" | ./checker "$ARGS")"
	if [ -z $VALUE ] || [ $VALUE == "Error" ]
	then
		echo "$ARGS" > ./push_swap_tutorial/OK/testcase_OK_wrong_input_test_1
		((CNT_OK++))
	elif [ $VALUE == "KO" ]
	then
		echo "$ARGS" > ./push_swap_tutorial/KO/testcase_KO_wrong_input_test_1
		((CNT_KO++))
	elif [ $VALUE == "OK" ]
	then
		echo "$ARGS" > ./push_swap_tutorial/KO/testcase_KO_wrong_input_test_1
		((CNT_KO++))
	fi

	ARGS="1 2 1"
	VALUE="$(./push_swap "$ARGS" | ./checker "$ARGS")"
	if [ -z $VALUE ] || [ $VALUE == "Error" ]
	then
		echo "$ARGS" > ./push_swap_tutorial/OK/testcase_OK_wrong_input_test_1
		((CNT_OK++))
	elif [ $VALUE == "KO" ]
	then
		echo "$ARGS" > ./push_swap_tutorial/KO/testcase_KO_wrong_input_test_1
		((CNT_KO++))
	elif [ $VALUE == "OK" ]
	then
		echo "$ARGS" > ./push_swap_tutorial/KO/testcase_KO_wrong_input_test_1
		((CNT_KO++))
	fi

	ARGS="1 3 5 2 4 3 7"
	VALUE="$(./push_swap "$ARGS" | ./checker "$ARGS")"
	if [ -z $VALUE ] || [ $VALUE == "Error" ]
	then
		echo "$ARGS" > ./push_swap_tutorial/OK/testcase_OK_wrong_input_test_1
		((CNT_OK++))
	elif [ $VALUE == "KO" ]
	then
		echo "$ARGS" > ./push_swap_tutorial/KO/testcase_KO_wrong_input_test_1
		((CNT_KO++))
	elif [ $VALUE == "OK" ]
	then
		echo "$ARGS" > ./push_swap_tutorial/KO/testcase_KO_wrong_input_test_1
		((CNT_KO++))
	fi

	ARGS="1 2 4 5 6 3 \"13 4\""
	VALUE="$(./push_swap "$ARGS" | ./checker "$ARGS")"
	if [ -z $VALUE ] || [ $VALUE == "Error" ]
	then
		echo "$ARGS" > ./push_swap_tutorial/OK/testcase_OK_wrong_input_test_1
		((CNT_OK++))
	elif [ $VALUE == "KO" ]
	then
		echo "$ARGS" > ./push_swap_tutorial/KO/testcase_KO_wrong_input_test_1
		((CNT_KO++))
	elif [ $VALUE == "OK" ]
	then
		echo "$ARGS" > ./push_swap_tutorial/KO/testcase_KO_wrong_input_test_1
		((CNT_KO++))
	fi

	ARGS="12 1345 4562 1 31a 346"
	VALUE="$(./push_swap "$ARGS" | ./checker "$ARGS")"
	if [ -z $VALUE ] || [ $VALUE == "Error" ]
	then
		echo "$ARGS" > ./push_swap_tutorial/OK/testcase_OK_wrong_input_test_1
		((CNT_OK++))
	elif [ $VALUE == "KO" ]
	then
		echo "$ARGS" > ./push_swap_tutorial/KO/testcase_KO_wrong_input_test_1
		((CNT_KO++))
	elif [ $VALUE == "OK" ]
	then
		echo "$ARGS" > ./push_swap_tutorial/KO/testcase_KO_wrong_input_test_1
		((CNT_KO++))
	fi

	ARGS="5 123 56 3 b"
	VALUE="$(./push_swap "$ARGS" | ./checker "$ARGS")"
	if [ -z $VALUE ] || [ $VALUE == "Error" ]
	then
		echo "$ARGS" > ./push_swap_tutorial/OK/testcase_OK_wrong_input_test_1
		((CNT_OK++))
	elif [ $VALUE == "KO" ]
	then
		echo "$ARGS" > ./push_swap_tutorial/KO/testcase_KO_wrong_input_test_1
		((CNT_KO++))
	elif [ $VALUE == "OK" ]
	then
		echo "$ARGS" > ./push_swap_tutorial/KO/testcase_KO_wrong_input_test_1
		((CNT_KO++))
	fi

	ARGS="a 3 4 5 6"
	VALUE="$(./push_swap "$ARGS" | ./checker "$ARGS")"
	if [ -z $VALUE ] || [ $VALUE == "Error" ]
	then
		echo "$ARGS" > ./push_swap_tutorial/OK/testcase_OK_wrong_input_test_1
		((CNT_OK++))
	elif [ $VALUE == "KO" ]
	then
		echo "$ARGS" > ./push_swap_tutorial/KO/testcase_KO_wrong_input_test_1
		((CNT_KO++))
	elif [ $VALUE == "OK" ]
	then
		echo "$ARGS" > ./push_swap_tutorial/KO/testcase_KO_wrong_input_test_1
		((CNT_KO++))
	fi

	ARGS="999999999999999999"
	VALUE="$(./push_swap "$ARGS" | ./checker "$ARGS")"
	if [ -z $VALUE ] || [ $VALUE == "Error" ]
	then
		echo "$ARGS" > ./push_swap_tutorial/OK/testcase_OK_wrong_input_test_1
		((CNT_OK++))
	elif [ $VALUE == "KO" ]
	then
		echo "$ARGS" > ./push_swap_tutorial/KO/testcase_KO_wrong_input_test_1
		((CNT_KO++))
	elif [ $VALUE == "OK" ]
	then
		echo "$ARGS" > ./push_swap_tutorial/KO/testcase_KO_wrong_input_test_1
		((CNT_KO++))
	fi

	ARGS="#1 2"
	VALUE="$(./push_swap "$ARGS" | ./checker "$ARGS")"
	if [ -z $VALUE ] || [ $VALUE == "Error" ]
	then
		echo "$ARGS" > ./push_swap_tutorial/OK/testcase_OK_wrong_input_test_1
		((CNT_OK++))
	elif [ $VALUE == "KO" ]
	then
		echo "$ARGS" > ./push_swap_tutorial/KO/testcase_KO_wrong_input_test_1
		((CNT_KO++))
	elif [ $VALUE == "OK" ]
	then
		echo "$ARGS" > ./push_swap_tutorial/KO/testcase_KO_wrong_input_test_1
		((CNT_KO++))
	fi

	ARGS="1# 3"
	VALUE="$(./push_swap "$ARGS" | ./checker "$ARGS")"
	if [ -z $VALUE ] || [ $VALUE == "Error" ]
	then
		echo "$ARGS" > ./push_swap_tutorial/OK/testcase_OK_wrong_input_test_1
		((CNT_OK++))
	elif [ $VALUE == "KO" ]
	then
		echo "$ARGS" > ./push_swap_tutorial/KO/testcase_KO_wrong_input_test_1
		((CNT_KO++))
	elif [ $VALUE == "OK" ]
	then
		echo "$ARGS" > ./push_swap_tutorial/KO/testcase_KO_wrong_input_test_1
		((CNT_KO++))
	fi

	echo -e	"		\n\n\033[1;32mOK : $CNT_OK\033[1;0m, \033[1;31m	KO : $CNT_KO\033[1;0m, \033[1;31m	Error : $CNT_Error"
	echo
	echo
	echo -e "		\033[42;1;37mlog files : ./push_swap_tutorial/\033[0m\n\n--------------------------------------------------------------\n\n"
	echo
elif [ $MODE == 3 ]
then
	rm -rf ./push_swap_tutorial
	rm -f checker_Mac	
	make fclean
else
	echo
	echo -e "		\033[41;1;37mWrong MODE\033[0m"
	echo
fi
