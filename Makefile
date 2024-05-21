myParser: project.l project.y
	bison -d project.y
	flex project.l
	cc -o $@ myParser project.tab.c lex.yy.c -lfl