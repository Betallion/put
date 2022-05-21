%%% Jako pierwszą klauzulę (nie komentarz!) należy zdefiniować swoje dane     %%%
%%% w postaci faktu: student(imię, nazwisko, numer_indeksu, numer_grupy_lab). %%%
%%% Przykładowo:  student(jan,nowak_jeziorański,150000,2).                    %%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
student(kacper, leporowski, 151910, 8).
next(świnoujście,kołobrzeg).
next(świnoujście, szczecin).
next(kołobrzeg,ustka).
next(ustka, gdańsk).
next(gdańsk,toruń).
next(gdańsk,olsztyn).
next(olsztyn,toruń).
next(olsztyn,białystok).
next(szczecin,bydgoszcz).
next(szczecin, gorzów-wlkp).
next(bydgoszcz,toruń).
next(bydgoszcz,poznań).
next(poznań,toruń).
next(gorzów-wlkp,poznań).
next(gorzów-wlkp,zielona-góra).
next(zielona-góra,poznań).
next(zielona-góra,wrocław).
next(toruń,łódź).
next(toruń,warszawa).
next(białystok, warszawa).
next(białystok,lublin).
next(poznań,łódź).
next(warszawa,radom).
next(warszawa,łódź).
next(radom,lublin).
next(radom,kielce).
next(wrocław,łódź).
next(łódź,radom).
next(łódź,częstochowa).
next(częstochowa,kielce).
next(częstochowa,katowice).
next(katowice,kraków).
next(kielce,kraków).
next(kielce,rzeszów).
next(lublin,kielce).
next(lublin,rzeszów).
next(kraków,rzeszów).

połączenie(A, B) :- next(A, B).
połączenie(A, B) :- next(A, C), połączenie(C, B).


zjazd(X, Y, Z) :-  next(X, Y), Z=X.
zjazd(X, Y, Z) :- next(X, W), zjazd(W, Y, Z).

trasa(X, Y, obok(X, Y)) :-  next(X, Y).
trasa(X, Y, obok(X, obok(W, V))) :- next(X, W), trasa(W, Y, obok(W, V)).

trasa2(X, Y, obok(X, Y)) :- next(X, Y).
trasa2(X, Y, obok(V, Y)) :- next(W, Y), trasa2(X, W, V).

trasa3(X, Y, [X|[Y|[]]]) :- next(X, Y).
trasa3(X, Y, [X|[W|V]]) :- next(X, W), trasa3(W, Y, [W|V]).


