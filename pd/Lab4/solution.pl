%%% Jako pierwszą klauzulę (nie komentarz!) należy zdefiniować swoje dane     %%%
%%% w postaci faktu: student(imię, nazwisko, numer_indeksu, numer_grupy_lab). %%%
%%% Przykładowo:  student(jan,nowak_jeziorański,150000,2).                    %%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
student(kacper, leporowski, 151910, 8).

ostatni(X, [Y]) :- X=Y.
ostatni(X, [_|Y]) :- ostatni(X, Y).

przedostatni(X, [Y, _]) :- X=Y.
przedostatni(X, [_|Y]) :- przedostatni(X, Y).

bezostatniego([_], L2) :- L2=[].
bezostatniego([X|Y], [X|Z]) :- bezostatniego(Y, Z).

nakoniec(X, [], [X]).
nakoniec(X, [Y|Z], [Y|W]) :- nakoniec(X, Z, W).

podwajaj([], L2) :- L2=[].
podwajaj([X|Y], L2) :- podwajaj(Y, Z), L2=[X, X|Z].

codrugi([_], L2) :- L2=[].
codrugi([_, X], L2) :- L2=[X].
codrugi([X, Y|Z], [Y|W]) :- codrugi(Z, W).

splataj([], [], LS) :- LS=[].
splataj([X1|Y1], [X2|Y2], [X1, X2|Y3]) :- splataj(Y1, Y2, Y3).

lewoprawo(X, [X|Y], [], Y).
lewoprawo(X, [Y|Z1], [Y|Z2], W) :- lewoprawo(X, Z1, Z2, W).

wymiana(X, Y, [], L2) :- L2=[].
wymiana(X, Y, [X|Z1], [Y|Z2]) :- wymiana(X, Y, Z1, Z2).
wymiana(X, Y, [W|Z1], [W|Z2]) :- wymiana(X, Y, Z1, Z2).

polacz([], LP) :- LP=[].
polacz([X|Y], LP) :- polacz(Y, Z), append(X, Z, LP).