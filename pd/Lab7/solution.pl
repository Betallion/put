%%% Jako pierwszą klauzulę (nie komentarz!) należy zdefiniować swoje dane     %%%
%%% w postaci faktu: student(imię, nazwisko, numer_indeksu, numer_grupy_lab). %%%
%%% Przykładowo:  student(jan,nowak_jeziorański,150000,2).                    %%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
student(kacper,leporowski,151910,8). 

podzielniki(A, A, []).
podzielniki(A, B, [B|Y]) :- B>0, B<A, A mod B =:= 0, C is B+1, podzielniki(A, C, Y).
podzielniki(A, B, Y) :- B>0, B<A, A mod B =\= 0, C is B+1, podzielniki(A, C, Y).

sumuj([], 0).
sumuj([X|Y], Z) :- sumuj(Y, W), Z is W + X.

doskonala(A):- podzielniki(A, 1, B), sumuj(B, A).

przekroj([], _, []).
przekroj(_, [], []).
przekroj([A|X], [A|Y], [A|Z]) :- przekroj(X, Y, Z).
przekroj([A|X], [B|Y], Z) :- A<B, przekroj(X, [B|Y], Z).
przekroj([A|X], [B|Y], Z) :- A>B, przekroj([A|X], Y, Z).

glowyogony([], [], []).
glowyogony([[A|B]|X], [A|Y], [B|Z]) :- glowyogony(X, Y, Z).

slad([[X]], X).
slad(X, Y) :- glowyogony(X, [A|_], [_|B]), slad(B, C), Y is C+A.

rozszerzaj([[X, Y]], [X, Y]).
rozszerzaj([[X, Y]|Z], [A, B]) :- rozszerzaj(Z, [A, B]), X>=A, Y=<B.
rozszerzaj([[X, Y]|Z], [X, B]) :- rozszerzaj(Z, [A, B]), X<A, Y=<B.
rozszerzaj([[X, Y]|Z], [A, Y]) :- rozszerzaj(Z, [A, B]), X>=A, Y>B.
rozszerzaj([[X, Y]|Z], [X, Y]) :- rozszerzaj(Z, [A, B]), X<A, Y>B.

ciagliczb(X, X, [X]).
ciagliczb(X, Y, [X|Z]) :- X<Y, W is X+1, ciagliczb(W, Y, Z).
liczpodziel(X, X, 0).
liczpodziel(X, Y, Z) :- X>Y, X mod Y =:= 0, W is Y+1, liczpodziel(X, W, V), Z is V+1.
liczpodziel(X, Y, Z) :- X>Y, X mod Y =\= 0, W is Y+1, liczpodziel(X, W, Z).
antyp([], _).
antyp([X|Y], Z) :- liczpodziel(X, 1, W), W<Z, antyp(Y, Z).
antypierwsza(X) :- Y is X-1, ciagliczb(1, Y, Z), liczpodziel(X, 1, W), antyp(Z, W).

rozmien(L,N,[N]) :- append(_,[X],L), N-X =:= 0.
rozmien(L,N,R) :- append(_,[X],L), N >= X, N1 is N-X, rozmien(L,N1,R1), append(R1,[X],R).
rozmien(L,N,R) :- append(L1,[X],L), N < X, rozmien(L1,N,R).

wpolu([], _, []).
wpolu([[X, Y]|Z], [[X1, Y1], [X2, Y2]], [[X, Y]|W]) :- X>=X1, X=<X2, Y>=Y1, Y=<Y2, wpolu(Z, [[X1, Y1], [X2, Y2]], W). 
wpolu([[X, _]|Z], [[X1, Y1], [X2, Y2]], W) :- X<X1, wpolu(Z, [[X1, Y1], [X2, Y2]], W). 
wpolu([[X, _]|Z], [[X1, Y1], [X2, Y2]], W) :- X>X2, wpolu(Z, [[X1, Y1], [X2, Y2]], W). 
wpolu([[_, Y]|Z], [[X1, Y1], [X2, Y2]], W) :- Y<Y1, wpolu(Z, [[X1, Y1], [X2, Y2]], W). 
wpolu([[_, Y]|Z], [[X1, Y1], [X2, Y2]], W) :- Y>Y2, wpolu(Z, [[X1, Y1], [X2, Y2]], W).

minX([[X, _]], X).
minX([[X, _]|Y], X1) :- minX(Y, X1), X>=X1.
minX([[X, _]|Y], X) :- minX(Y, X1), X<X1.

maxX([[X, _]], X).
maxX([[X, _]|Y], X1) :- maxX(Y, X1), X=<X1.
maxX([[X, _]|Y], X) :- maxX(Y, X1), X>X1.

minY([[_, Y]], Y).
minY([[_, Y]|Z], Y1) :- minY(Z, Y1), Y>=Y1.
minY([[_, Y]|Z], Y) :- minY(Z, Y1), Y<Y1.

maxY([[_, Y]], Y).
maxY([[_, Y]|Z], Y1) :- maxY(Z, Y1), Y=<Y1.
maxY([[_, Y]|Z], Y) :- maxY(Z, Y1), Y>Y1.

minpole(X, [[X1, Y1], [X2, Y2]]) :- minX(X, X1), minY(X, Y1), maxX(X, X2), maxY(X, Y2).

zamien_g([], []).
zamien_g([X], [X]).
zamien_g([X, Y|T], [Y|L]) :- X>Y, zamien_g([X|T], L), !.
zamien_g([X, Y|T], [X|L]) :- X=<Y, zamien_g([Y|T], L).

zamien_d([], []).
zamien_d([X], [X]).
zamien_d([X, Y|Z], [Y|W]) :- X<Y, zamien_d([X|Z], W), !.
zamien_d([X, Y|Z], [X|W]) :- X>=Y, zamien_d([Y|Z], W).

odwracaj([], []).
odwracaj([X|Y], Z) :- odwracaj(Y, W), append(W, [X], Z).

koktajl([], []).
koktajl([X], [X]).
koktajl(A, X) :-zamien_g(A, B), odwracaj(B, [Y|C]), zamien_d(C, D), odwracaj(D, [Z|E]), koktajl(E, W), append([Z|W], [Y], X), !.
    
ciagFib(X, Y, _, []) :- Y>X, !.
ciagFib(X, Y, Z, [Y|W]) :- Y=<X, V is Z+Y, ciagFib(X, Z, V, W), !.

rozklad(X, Y, [Y]) :- append(_, [Z], X), Y-Z =:= 0, !.
rozklad(X, Y, Z) :- append(_, [W], X), W=<Y, V is Y-W, rozklad(X, V, U), append(U, [W], Z), !.
rozklad(X, Y, Z) :- append(W, [V], X), V>Y, rozklad(W, Y, Z), !.

rozklad_fib(X, Y) :- ciagFib(X, 0, 1, Z), rozklad(Z, X, Y).