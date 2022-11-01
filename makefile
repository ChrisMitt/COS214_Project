ofiles = main.o WarStrategy.o Fight.o Negotiate.o Diplomacy.o PhasesofWar.o Phase1.o Phase2.o Phase3.o Phase4.o Phase5.o WarPhaseChanger.o
gpp_o = g++ -c -std=c++98 -static

main: $(ofiles)
	g++ -std=c++98 -static $(ofiles) -o main

main.o: main.cpp WarStrategy.h Fight.h Negotiate.h Diplomacy.h PhasesofWar.h Phase1.h Phase2.h Phase3.h Phase4.h Phase5.h WarPhaseChanger.h
	$(gpp_o) main.cpp

WarStrategy.o: WarStrategy.cpp WarStrategy.h
	$(gpp_o) WarStrategy.cpp

Fight.o: Fight.cpp Fight.h WarStrategy.h
	$(gpp_o) Fight.cpp

Negotiate.o: Negotiate.cpp Negotiate.h WarStrategy.h 
	$(gpp_o) Negotiate.cpp

Diplomacy.o: Diplomacy.cpp Diplomacy.h WarStrategy.h
	$(gpp_o) Diplomacy.cpp

PhasesofWar.o: PhasesofWar.cpp PhasesofWar.h WarPhaseChanger.h
	$(gpp_o) PhasesofWar.cpp

Phase1.o: Phase1.cpp Phase1.h PhasesofWar.h Phase2.h
	$(gpp_o) Phase1.cpp

Phase2.o: Phase2.cpp Phase2.h PhasesofWar.h Phase3.h
	$(gpp_o) Phase2.cpp

Phase3.o: Phase3.cpp Phase3.h PhasesofWar.h Phase4.h
	$(gpp_o) Phase3.cpp

Phase4.o: Phase4.cpp Phase4.h PhasesofWar.h Phase5.h
	$(gpp_o) Phase4.cpp

Phase5.o: Phase5.cpp Phase5.h PhasesofWar.h
	$(gpp_o) Phase5.cpp

WarPhaseChanger.o: WarPhaseChanger.cpp WarPhaseChanger.h WarStrategy.h PhasesofWar.h Phase1.h
	$(gpp_o) WarPhaseChanger.cpp

run: main
	./main

clean:
	rm *.o