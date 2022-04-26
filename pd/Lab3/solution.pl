%%% Jako pierwsz� klauzul� (nie komentarz!) nale�y zdefiniowa� swoje dane     %%%
%%% w postaci faktu: student(imi�, nazwisko, numer_indeksu, numer_grupy_lab). %%%
%%% Przyk�adowo:  student(jan,nowak_jeziora�ski,150000,2).                    %%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
student(kacper, leporowski, 151910, 8).
next(�winouj�cie,ko�obrzeg).
next(�winouj�cie, szczecin).
next(ko�obrzeg,ustka).
next(ustka, gda�sk).
next(gda�sk,toru�).
next(gda�sk,olsztyn).
next(olsztyn,toru�).
next(olsztyn,bia�ystok).
next(szczecin,bydgoszcz).
next(szczecin, gorz�w-wlkp).
next(bydgoszcz,toru�).
next(bydgoszcz,pozna�).
next(pozna�,toru�).
next(gorz�w-wlkp,pozna�).
next(gorz�w-wlkp,zielona-g�ra).
next(zielona-g�ra,pozna�).
next(zielona-g�ra,wroc�aw).
next(toru�,��d�).
next(toru�,warszawa).
next(bia�ystok, warszawa).
next(bia�ystok,lublin).
next(pozna�,��d�).
next(warszawa,radom).
next(warszawa,��d�).
next(radom,lublin).
next(radom,kielce).
next(wroc�aw,��d�).
next(��d�,radom).
next(��d�,cz�stochowa).
next(cz�stochowa,kielce).
next(cz�stochowa,katowice).
next(katowice,krak�w).
next(kielce,krak�w).
next(kielce,rzesz�w).
next(lublin,kielce).
next(lublin,rzesz�w).
next(krak�w,rzesz�w).

po��czenie(A, B) :- next(A, B).
po��czenie(A, B) :- next(A, C), po��czenie(C, B).


zjazd(X, Y, Z) :-  next(X, Y), Z=X.
zjazd(X, Y, Z) :- next(X, W), zjazd(W, Y, Z).

trasa(X, Y, obok(X, Y)) :-  next(X, Y).
trasa(X, Y, obok(X, obok(W, V))) :- next(X, W), trasa(W, Y, obok(W, V)).

trasa2(X, Y, obok(X, Y)) :- next(X, Y).
trasa2(X, Y, obok(V, Y)) :- next(W, Y), trasa2(X, W, V).

trasa3(X, Y, [X|[Y|[]]]) :- next(X, Y).
trasa3(X, Y, [X|[W|V]]) :- next(X, W), trasa3(W, Y, [W|V]).






















