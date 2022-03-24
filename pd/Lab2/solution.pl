%%% Jako pierwsz¹ klauzulê (nie komentarz!) nale¿y zdefiniowaæ swoje dane     %%%
%%% w postaci faktu: student(imiê, nazwisko, numer_indeksu, numer_grupy_lab). %%%
%%% Przyk³adowo:  student(jan,nowak_jeziorañski,150000,2).                    %%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
student(kacper,leporowski,151910,8).


poziomy(odcinek(punkt(X1,Y),punkt(X2,Y))).
pionowy(odcinek(punkt(X,Y1),punkt(X,Y2))).

regularny(prostok¹t(punkt(X1,Y1),punkt(X2,Y2),punkt(X3,Y3),punkt(X4,Y4))) :- X1=X4, X2=X3, Y1=Y2, Y3=Y4.


safe(state(F,W,G,C)) :- F=G.
safe(state(F,W,G,C)) :- G\=F, G\=W, G\=C.

move(state(west,west,G,C),farmer_west_wolf,state(east,east,G,C)) :- safe(state(east,east,G,C)).
move(state(west,W,G,west),farmer_west_cabbage,state(east,W,G,east)) :- safe(state(east,W,G,east)).
move(state(west,W,west,C),farmer_west_goat,state(east,W,east,C)) :- safe(state(east,W,east,C)).
move(state(west,W,G,C),farmer_west_alone,state(east,W,G,C)) :- safe(state(east,W,G,C)).

move(state(east,W,G,C),farmer_east_alone,state(west,W,G,C)) :- safe(state(west,W,G,C)).
move(state(east,W,east,C),farmer_east_goat,state(west,W,west,C)) :- safe(state(west,W,west,C)).
move(state(east,W,G,east),farmer_east_cabbage,state(west,W,G,west)) :- safe(state(west,W,G,west)).
move(state(east,east,G,C),farmer_east_wolf,state(west,west,G,C)) :- safe(state(west,west,G,C)).


can_get(state(east,east,east,east)).
can_get(StateBefore) :- move(StateBefore,Move,StateAfter), can_get(StateAfter).
