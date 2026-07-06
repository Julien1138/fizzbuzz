# fizzbuzz

Petit CLI FizzBuzz en C++, avec tests unitaires Unity.

## Étapes du développement

Le code n'a pas été écrit directement dans sa forme finale : il a été construit étape par étape, en validant les tests à chaque étape avant de passer à la suivante.

1. **Implémentation naïve + tests unitaires (Unity)** — l'algorithme FizzBuzz classique (3 → Fizz, 5 → Buzz, 15 → FizzBuzz), avec une suite de tests dès le départ.
2. **Strategy Pattern** — chaque règle de substitution (multiple de 3, de 5, ...) devient une stratégie interchangeable (`SubstitutionRule`, `DivisorRule`), plutôt qu'un enchaînement de `if`.
3. **Composite Pattern** — les règles se combinent (`CompositeRule`) : un nombre multiple de plusieurs diviseurs concatène les mots correspondants, sans cas particulier codé en dur pour "FizzBuzz".
4. **Factory Pattern** — construction du jeu de règles à partir de paramètres (`buildRules`), et branchement sur des arguments en ligne de commande pour généraliser l'exercice (`int1`, `int2`, `limit`, `str1`, `str2`).
5. **Passage à une classe** — regroupement de la logique dans une classe `FizzBuzz` plutôt que des fonctions libres.

### Pourquoi ne pas avoir écrit directement la dernière étape ?

L'algorithme de FizzBuzz est trivial — ce n'est pas là que réside la difficulté de l'exercice. L'accent a plutôt été mis sur :

- **les tests unitaires**, présents dès la première implémentation, pas ajoutés après coup ;
- **les design patterns**, parce qu'il s'agit d'un exercice de conception orientée objet, et parce qu'ils rendent le code plus facile à maintenir, à faire évoluer (ajouter une règle, changer la façon de les combiner) et à tester (chaque brique — règle, composition, construction — se teste isolément).

## Prérequis

- CMake >= 3.16
- Un compilateur C++17 (g++/clang++)

## Build

```sh
cmake -S . -B build
cmake --build build
```

## Lancer le programme

```sh
./build/fizzbuzz <int1> <int2> <limit> <str1> <str2>
# ex: ./build/fizzbuzz 3 5 20 Fizz Buzz
```

## Lancer les tests

```sh
ctest --test-dir build --output-on-failure
```
