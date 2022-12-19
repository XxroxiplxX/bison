main: parser.y analyzer.l
		bison -d -o parsery.cpp parser.y
		flex -o analyzerl.c analyzer.l
		g++ -o final parsery.cpp GF.cpp GF_r.cpp analyzerl.c
