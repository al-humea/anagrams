#just_a_bash_for_quicker_exec
declare wordlength
wordlength=${#1}
clang -Wall -Werror -Wextra -D WSIZE=$wordlength anagram.c ../libft42/libft.a
./a.out $1 > results
cat results
rm a.out
