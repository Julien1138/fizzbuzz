# fizzbuzz

Petit CLI FizzBuzz en C++, avec tests unitaires Unity.

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
./build/fizzbuzz
```

## Lancer les tests

```sh
ctest --test-dir build --output-on-failure
```
