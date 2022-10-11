OUTPUTDIR = build
OUTPUTFILE = Twi.exe
INPUT = Lox.cpp
LOXFILE = test.txt
#INCLUDEFILES =  
all: clearscr outputfolder compile

clearscr:
	cls

fresh: clean clearscr outputfolder compile 

outputfolder:
	if not exist $(OUTPUTDIR) mkdir $(OUTPUTDIR)
compile:
	g++ -o $(OUTPUTDIR)/$(OUTPUTFILE) $(INPUT) 

runfile: 
	$(OUTPUTDIR)/$(OUTPUTFILE) $(LOXFILE)
run:
	$(OUTPUTDIR)/$(OUTPUTFILE)
clean:
	rmdir /Q /s $(OUTPUTDIR)