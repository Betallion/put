%%% Jako pierwszą klauzulę (nie komentarz!) należy zdefiniować swoje dane     %%%
%%% w postaci faktu: student(imię, nazwisko, numer_indeksu, numer_grupy_lab). %%%
%%% Przykładowo:  student(jan,nowak_jeziorański,150000,2).                    %%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
student(kacper, leporowski, 151910, 8).
kobieta(Maria).
kobieta(Ewa).
kobieta(Joanna).
kobieta(Agata).
kobieta(Anna).
kobieta(Agnieszka).
kobieta(Beata).
kobieta(Iwona).
mężczyzna(Piotr).
mężczyzna(Adam).
mężczyzna(Marek).
mężczyzna(Robert).
mężczyzna(Jan).
mężczyzna(Krzysztof).
mężczyzna(Radek).
mężczyzna(Darek).
mężczyzna(Tomek).
mężczyzna(Jacek).
rodzic(Maria, Agata).
rodzic(Piotr, Agata).
rodzic(Maria, Marek).
rodzic(Piotr, Marek).
rodzic(Maria, Jan).
rodzic(Piotr, Jan).
rodzic(Adam, Anna).
rodzic(Ewa, Anna).
rodzic(Adam, Joanna).
rodzic(Ewa, Joanna).
rodzic(Adam, Krzysztof).
rodzic(Ewa, Krzysztof).
rodzic(Robert, Radek).
rodzic(Agata, Radek).
rodzic(Robert, Beata).
rodzic(Agata, Beata).
rodzic(Jan, Darek).
rodzic(Anna, Darek).
rodzic(Jan, Tomek).
rodzic(Anna, Tomek).
rodzic(Krzysztof, Jacek).
rodzic(Agnieszka, Jacek).
rodzic(Krzysztof, Iwona).
rodzic(Agnieszka, Iwona).

matka(X, Y) :- kobieta(X), rodzic(X, Y).
ojciec(X, Y) :- mężczyzna(X), rodzic(X, Y).
siostra(X, Y) :- kobieta(X), rodzic(Z, X), rodzic(Z, Y).
brat(X, Y) :- mężczyzna(X), rodzic(Z, X), rodzic(Z, Y).
babcia(X, Y) :- kobieta(X), rodzic(X, Z), rodzic(Z, Y).
dziadek(X, Y) :- mężczyzna(X), rodzic(X, Z), rodzic(Z, Y).
wuj(X, Y) :-
stryj(X, Y) :-
kuzyn(X, Y) :-