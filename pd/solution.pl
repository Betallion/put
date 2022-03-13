%%% Jako pierwszą klauzulę (nie komentarz!) należy zdefiniować swoje dane     %%%
%%% w postaci faktu: student(imię, nazwisko, numer_indeksu, numer_grupy_lab). %%%
%%% Przykładowo:  student(jan,nowak_jeziorański,150000,2).                    %%%
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
student(kacper, leporowski, 151910, 8).
kobieta(maria).
kobieta(ewa).
kobieta(joanna).
kobieta(agata).
kobieta(anna).
kobieta(agnieszka).
kobieta(beata).
kobieta(iwona).
mężczyzna(piotr).
mężczyzna(adam).
mężczyzna(marek).
mężczyzna(robert).
mężczyzna(jan).
mężczyzna(krzysztof).
mężczyzna(radek).
mężczyzna(darek).
mężczyzna(tomek).
mężczyzna(jacek).
rodzic(maria, agata).
rodzic(piotr, agata).
rodzic(maria, marek).
rodzic(piotr, marek).
rodzic(maria, jan).
rodzic(piotr, jan).
rodzic(adam, anna).
rodzic(ewa, anna).
rodzic(adam, joanna).
rodzic(ewa, joanna).
rodzic(adam, krzysztof).
rodzic(ewa, krzysztof).
rodzic(robert, radek).
rodzic(agata, radek).
rodzic(robert, beata).
rodzic(agata, beata).
rodzic(jan, darek).
rodzic(anna, darek).
rodzic(jan, tomek).
rodzic(anna, tomek).
rodzic(krzysztof, jacek).
rodzic(agnieszka, jacek).
rodzic(krzysztof, iwona).
rodzic(agnieszka, iwona).

matka(X, Y) :- kobieta(X), rodzic(X, Y).
ojciec(X, Y) :- mężczyzna(X), rodzic(X, Y).
siostra(X, Y) :- kobieta(X), rodzic(Z, X), rodzic(Z, Y), X\=Y.
brat(X, Y) :- mężczyzna(X), rodzic(Z, X), rodzic(Z, Y), X\=Y.
babcia(X, Y) :- kobieta(X), rodzic(X, Z), rodzic(Z, Y).
dziadek(X, Y) :- mężczyzna(X), rodzic(X, Z), rodzic(Z, Y).
wuj(X, Y) :- mężczyzna(X), brat(X, Z), matka(Z, Y).
stryj(X, Y) :- mężczyzna(X), brat(X, Z), ojciec(Z, Y), X\=Z.
kuzyn(X, Y) :- rodzic(Z, X), rodzic(W, Y), rodzic(T, Z), rodzic(T, W), mężczyzna(X).
kuzynka(X, Y) :- rodzic(Z, X), rodzic(W, Y), rodzic(T, Z), rodzic(T, W), kobieta(X).

małżeństwo(maria, piotr).
małżeństwo(adam, ewa).
małżeństwo(robert, agata).
małżeństwo(jan, anna).
małżeństwo(krzysztof, agnieszka).

teściowa(X, Y) :- kobieta(X), małżeństwo(Y, Z), kobieta(Z), matka(X, Z).
teściowa(X, Y) :- kobieta(X), małżeństwo(Z, Y), kobieta(Z), matka(X, Z).
szwagier(X, Y) :- mężczyzna(X), małżeństwo(Y, Z), kobieta(Z), brat(X, Z).
szwagier(X, Y) :- mężczyzna(X), małżeństwo(Z, Y), kobieta(Z), brat(X, Z).
szwagier(X, Y) :- mężczyzna(X), małżeństwo(X, Z), siostra(Z, Y).
szwagier(X, Y) :- mężczyzna(X), małżeństwo(Z, X), siostra(Z, Y).
