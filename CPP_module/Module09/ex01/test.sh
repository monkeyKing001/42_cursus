#!/bin/bash
make

# test 1
test_ex="2 4 8 + *"
ans="24"
printf "\033[1;37m"
printf "testing "
printf "${test_ex} => "
printf "\033[0m"
sol=`./RPN "${test_ex}" | grep "${ans}"`
if [ ${sol} == ${ans} ];
then
	printf "\033[1;32m"
	echo "OK";
	printf "\033[0m"
else
	printf "\e[31m"
	echo "KO"
	printf "\033[0m"
fi

# test 2
test_ex="2 4 8 + *"
ans="24"
printf "\033[1;37m"
printf "testing "
printf "${test_ex} => "
printf "\033[0m"
sol=`./RPN "${test_ex}" | grep "${ans}"`
if [ ${sol} == ${ans} ];
then
	printf "\033[1;32m"
	echo "OK";
	printf "\033[0m"
else
	printf "\e[31m"
	echo "KO"
	printf "\033[0m"
fi

# test 3
test_ex="2 5 * 4 + 3 2 * 1 + /"
ans="2"
printf "\033[1;37m"
printf "testing "
printf "${test_ex} => "
printf "\033[0m"
sol=`./RPN "${test_ex}" | grep "${ans}"`
if [ ${sol} == ${ans} ];
then
	printf "\033[1;32m"
	echo "OK";
	printf "\033[0m"
else
	printf "\e[31m"
	echo "KO"
	printf "\033[0m"
fi

# test pdf1
test_ex="8 9 * 9 - 9 - 9 - 4 - 1 +"
ans="42"
printf "\033[1;37m"
printf "testing "
printf "${test_ex} => "
printf "\033[0m"
sol=`./RPN "${test_ex}" | grep "${ans}"`
if [ ${sol} == ${ans} ];
then
	printf "\033[1;32m"
	echo "OK";
	printf "\033[0m"
else
	printf "\e[31m"
	echo "KO"
	printf "\033[0m"
fi
# test pdf
test_ex="7 7 * 7 -"
ans="42"
printf "\033[1;37m"
printf "testing "
printf "${test_ex} => "
printf "\033[0m"
sol=`./RPN "${test_ex}" | grep "${ans}"`
if [ ${sol} == ${ans} ];
then
	printf "\033[1;32m"
	echo "OK";
	printf "\033[0m"
else
	printf "\e[31m"
	echo "KO"
	printf "\033[0m"
fi
# test pdf
test_ex="1 2 * 2 / 2 * 2 4 - +"
ans="0"
printf "\033[1;37m"
printf "testing "
printf "${test_ex} => "
printf "\033[0m"
sol=`./RPN "${test_ex}" | grep "${ans}"`
if [ ${sol} == ${ans} ];
then
	printf "\033[1;32m"
	echo "OK";
	printf "\033[0m"
else
	printf "\e[31m"
	echo "KO"
	printf "\033[0m"
fi
# test pdf
test_ex="(1 + 1)"
ans="Error: Bad input number."
printf "\033[1;37m"
printf "testing "
printf "${test_ex} => "
printf "\033[0m"
sol=`./RPN "${test_ex}" | grep "${ans}"`
if [ ${sol} == ${anw} ];
then
	printf "\033[1;32m"
	echo "OK";
	printf "\033[0m"
else
	printf "\e[31m"
	echo "KO"
	printf "\033[0m"
fi
