## 🚫 Pourquoi les Variable Length Arrays (VLA) sont à proscrire ?

En langage C, il existe historiquement deux façons d'allouer de la mémoire pour un tableau :

1. **Statique (sur la Stack)** : la taille est une constante connue à la compilation (`char tab[10];`).
2. **Dynamique (sur la Heap)** : la taille est définie à l'exécution via `malloc()` (`char *tab = malloc(size);`).

Un **VLA (Variable Length Array)**, introduit par la norme C99, est un hybride tentant mais dangereux : il permet de déclarer un tableau sur la Pile avec une taille qui n'est connue qu'à l'exécution.

```c
// ❌ MAUVAISE PRATIQUE : Utilisation d'un VLA
void ft_rev_int_tab(char *tab, int size) {
    char reverse[size]; // 'size' n'est pas une constante !
    // ...
}


Dangers des VLA


Risque critique de Stack Overflow : la Pile (Stack) est une zone mémoire très limitée (souvent autour de 8 Mo).
Si la variable size est trop grande, le programme va tenter d'allouer cette mémoire sur la pile et crasher immédiatement (Stack Overflow).
Contrairement à malloc(), le C ne vérifie pas si l'espace est suffisant avant de créer un VLA.

Problème de Portabilité : bien qu'introduits en C99, les VLA ont été rétrogradés au statut de fonctionnalité optionnelle dans la norme C11.
Certains compilateurs ne les supportent pas.
Un code avec des VLA n'est donc pas portable à 100%.



La Règle d'Or de la gestion mémoire


- Taille connue à l'avance et petite ? -> utiliser un tableau statique classique (char tab[10];).

- Taille variable ou potentiellement grande ? -> allouer dynamiquement avec malloc(), et toujours vérifier si le retour est NULL avant de l'utiliser. Protéger contre les fuites avec free().



Tip : penser ses algorithmes pour travailler in-place (sur place) en modifiant les données d'origine sans allocation supplémentaire (complexité spatiale O(1)).

