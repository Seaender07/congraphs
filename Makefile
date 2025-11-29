# Makefile

DIR=.
ONAME=congraphs					# Project name
loop=${DIR}/main.cpp				# main() file
loophead=${DIR}/main.h				# main() file's header
modules=$(wildcard ${DIR}/modules/*.cpp)	# Module implementation source files
moduleshead=$(wildcard ${DIR}/modules/*.h)	# Module declaration headers



edit:	#	#	#	# Opens the project in Vim
	vim -p Makefile ${loop} ${loophead} ${moduleshead} ${modules}

clean:	#	#	#	# Deletes the binary, forcing compilation
	rm -f ${DIR}/${ONAME}

start: ${ONAME}	#	#	# Starts the program if binary is ready
	@echo ======================
	./$<
	@echo ----------------------
	@echo "returned with code $?."
	@echo ======================

${ONAME}: ${loop} ${modules}	# Compiles code and produces binary
	g++ $^ -Wall -O4 -o $@
