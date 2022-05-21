%%% Jako pierwszą klauzulę (nie komentarz!) należy zdefiniować swoje dane     %%%
%%% w postaci faktu: student(imię, nazwisko, numer_indeksu, numer_grupy_lab). %%%
%%% Przykładowo:  student(jan,nowak_jeziorański,150000,2).                    %%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
student(kacper, leporowski, 151910, 8).
parami([], []).
parami([X,Y|Z], [[X, Y]|W]) :- parami(Z, W).
symetryczna([]).
symetryczna([_]).
symetryczna([X|Y]):- append(Z, [X], Y), symetryczna(Z).
polowki([], [], []).
polowki([X|Y], [X|Z], [W|V]) :- append(A, [W|V], Y), append(A, V, B), polowki(B, Z, V).
sumuj([], 0).
sumuj([X|Y], Z) :- sumuj(Y, W), Z is W + X.
ile_dodatnich([], 0).
ile_dodatnich([X|Y], Z) :- ile_dodatnich(Y, W), X>0, Z is W + 1.
ile_dodatnich([X|Y], Z) :- ile_dodatnich(Y, Z), X=<0.
plus_minus([], 0).
plus_minus([X|Y], Z) :- plus_minus(Y, W), X=='+', Z is W + 1.
plus_minus([X|Y], Z) :- plus_minus(Y, W), X=='-', Z is W - 1.
wstawiaj([], X, 1, [X]).
wstawiaj([X|Y], Z, 1, [Z, X|Y]).
wstawiaj([X|Y], Z, W, [X|V]) :- U is W - 1, wstawiaj(Y, Z, U, V).
usuwaj([_], 1, []).
usuwaj([_|Y], 1, Y).
usuwaj([_|Y], Z, W) :- V is Z - 1, usuwaj(Y, V, W).
rozdziel([], _, [], []).
rozdziel([X|Y], Z, [X|V], U) :- X<Z, rozdziel(Y, Z, V, U).
rozdziel([X|Y], Z, U, [X|V]) :- X>=Z, rozdziel(Y, Z, U, V).
powiel([], [], []).
powiel([X|Y], [Z|W], [X|U]) :- Z>1, V is Z - 1, powiel([X|Y], [V|W], U).
powiel([X|Y], [_|W], [X|U]) :- powiel(Y, W, U).
