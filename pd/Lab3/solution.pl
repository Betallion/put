%%% Jako pierwsz¹ klauzulê (nie komentarz!) nale¿y zdefiniowaæ swoje dane     %%%
%%% w postaci faktu: student(imiê, nazwisko, numer_indeksu, numer_grupy_lab). %%%
%%% Przyk³adowo:  student(jan,nowak_jeziorañski,150000,2).                    %%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
student(kacper, leporowski, 151910, 8).
next(œwinoujœcie,ko³obrzeg).
next(œwinoujœcie, szczecin).
next(ko³obrzeg,ustka).
next(ustka, gdañsk).
next(gdañsk,toruñ).
next(gdañsk,olsztyn).
next(olsztyn,toruñ).
next(olsztyn,bia³ystok).
next(szczecin,bydgoszcz).
next(szczecin, gorzów-wlkp).
next(bydgoszcz,toruñ).
next(bydgoszcz,poznañ).
next(poznañ,toruñ).
next(gorzów-wlkp,poznañ).
next(gorzów-wlkp,zielona-góra).
next(zielona-góra,poznañ).
next(zielona-góra,wroc³aw).
next(toruñ,³ódŸ).
next(toruñ,warszawa).
next(bia³ystok, warszawa).
next(bia³ystok,lublin).
next(poznañ,³ódŸ).
next(warszawa,radom).
next(warszawa,³ódŸ).
next(radom,lublin).
next(radom,kielce).
next(wroc³aw,³ódŸ).
next(³ódŸ,radom).
next(³ódŸ,czêstochowa).
next(czêstochowa,kielce).
next(czêstochowa,katowice).
next(katowice,kraków).
next(kielce,kraków).
next(kielce,rzeszów).
next(lublin,kielce).
next(lublin,rzeszów).
next(kraków,rzeszów).

po³¹czenie(A, B) :- next(A, B).
po³¹czenie(A, B) :- next(A, C), po³¹czenie(C, B).


zjazd(X, Y, Z) :-  next(X, Y), Z=X.
zjazd(X, Y, Z) :- next(X, W), zjazd(W, Y, Z).

trasa(X, Y, obok(X, Y)) :-  next(X, Y).
trasa(X, Y, obok(X, obok(W, V))) :- next(X, W), trasa(W, Y, obok(W, V)).

trasa2(X, Y, obok(X, Y)) :- next(X, Y).
trasa2(X, Y, obok(V, Y)) :- next(W, Y), trasa2(X, W, V).

trasa3(X, Y, [X|[Y|[]]]) :- next(X, Y).
trasa3(X, Y, [X|[W|V]]) :- next(X, W), trasa3(W, Y, [W|V]).






















