#!/bin/bash

configure_CC="/usr/bin/gcc"

check_cc () {
	echo "checking $configure_CC.."

	cat > test.c <<EOF
#include <stdio.h>
int main() {
	printf("Hello World\n");
	return 0;
}
EOF

	$configure_CC -o test test.c
	if [ $? -eq 0 ]; then
		printf "testing Hello World.c"
		out="$(./test)"
		if [ "$out" = "Hello World" ]; then
			printf " OK\n"
		fi
		rm -f test test.c
	else
		printf " FAIL\n"
		echo "$configure_CC is unable to compile this program."
		exit 1
	fi

}

check_prerequisites () {
	if [ "$CC" == "" ]; then
		echo "CC environment variable not set, defaulting to $(which gcc)"
		configure_CC="$(which gcc)"
	else 
		configure_CC=$CC
	fi
	check_cc
}

echo "-- seals-are-bouncy.tech --"
check_prerequisites
