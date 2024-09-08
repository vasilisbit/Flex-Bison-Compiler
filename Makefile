myParser: project.l project.y error.h error.cpp
	bison -d -v project.y
	flex project.l
	cc -o $@ myParser project.tab.c lex.yy.c error.cpp -lfl