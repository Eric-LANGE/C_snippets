## Pourquoi les VLA (Variable Length Arrays) sont à proscrire ?

En langage C, il existe historiquement deux façons d'allouer de la mémoire pour un tableau :

1. **Statique (sur la Stack)** : la taille est une constante connue à la compilation (`char tab[10];`).
2. **Dynamique (sur la Heap)** : la taille est définie à l'exécution via `malloc()` (`char *tab = malloc(size);`).

Un **VLA (Variable Length Array)**, introduit par la norme C99, est un hybride tentant mais dangereux : il permet de déclarer un tableau sur la Pile avec une taille qui n'est connue qu'à l'exécution.

```c
// MAUVAISE PRATIQUE : utilisation d'un VLA

void ft_rev_int_tab(char *tab, int size) {
    char reverse[size]; // 'size' n'est pas une constante !
    // ...
}
```

## Dangers des VLA


**Risque critique de stack overflow**

La Pile (Stack) est une zone mémoire très limitée (souvent autour de 8 Mo).
Si la variable size est trop grande, le programme va tenter d'allouer cette mémoire sur la pile et crasher immédiatement (Stack Overflow).
Contrairement à malloc(), le C ne vérifie pas si l'espace est suffisant avant de créer un VLA.

**Problème de portabilité**

Bien qu'introduits en C99, les VLA ont été rétrogradés au statut de fonctionnalité optionnelle dans la norme C11.
Certains compilateurs ne les supportent pas.
Un code avec des VLA n'est donc pas portable à 100%.



## Règle d'or de la gestion mémoire


- Taille connue à l'avance et petite ? -> utiliser un tableau statique classique (char tab[10];).

- Taille variable ou potentiellement grande ? -> allouer dynamiquement avec malloc(), et toujours vérifier si le retour est NULL avant de l'utiliser. Protéger contre les fuites avec free().



## Tip
Penser ses algorithmes pour travailler in-place (sur place) en modifiant les données d'origine sans allocation supplémentaire (complexité spatiale O(1)).





## Comprendre la mémoire : Stack vs Heap

La mémoire se divise en deux grandes zones d'allocation : la **Stack** et la **Heap**.



### La Stack : le bloc-notes rapide

* C'est ici que sont stockées toutes les variables locales déclarées dans des fonctions (ex: `int a = 5;`). Elle fonctionne selon le principe LIFO (*Last In, First Out*).
* La gestion est **100% automatique**. Dès qu'une fonction se termine, toutes les variables qu'elle a créées sont instantanément détruites et la mémoire est libérée.
* L'espace est très restreint (généralement quelques mégaoctets). Si trop de données (récursion infinie...), ça déborde : c'est le **stack overflow**.

### La Heap : l'entrepôt géant

* C'est ici que vous allouez de la mémoire manuellement quand vous ne connaissez pas la taille des données à l'avance, ou qu'elles sont très volumineuses.
* L'espace est limité uniquement par la RAM de votre machine. Vos données persistent même après la fin de la fonction qui les a créées.
* La gestion est **100% manuelle**. Vous devez explicitement demander de l'espace avec `malloc()` et, surtout, vous devez impérativement le rendre avec `free()` quand vous n'en avez plus besoin. Si vous oubliez, c'est la **fuite de mémoire (memory leak)**.

### Comparatif rapide

| Caractéristique | Stack | Heap |
| :--- | :--- | :--- |
| **Gestion** | Automatique (par le CPU / compilateur) | Manuelle (par le développeur via `malloc`/`free`) |
| **Vitesse d'accès** | Ultra-rapide | Plus lente (nécessite des pointeurs) |
| **Taille disponible** | Très limitée (~8 Mo) | Immense (dépend de la RAM système) |
| **Durée de vie** | Temporaire (fin de la fonction) | Persistante (jusqu'au `free()` ou fin du programme) |
| **Risque principal** | Stack overflow (dépassement) | Memory leak (fuite de mémoire) |




### L'allocation mémoire en pratique


```c
#include <stdlib.h>
#include <stdio.h>

void demo_memory_allocation(void)
{
    // ==========================================
    // 1. ALLOCATION SUR LA STACK
    // ==========================================
    // La taille (5) est fixe et connue à la compilation. 
    // La destruction sera AUTOMATIQUE à la fin de cette fonction.

    int stack_array[5] = {1, 2, 3, 4, 5};
    
    printf("Valeur Stack : %d\n", stack_array[0]);


    // ==========================================
    // 2. ALLOCATION SUR LA HEAP
    // ==========================================
    // Allocation DYNAMIQUE.
    // Cette mémoire survivra à la fin de la fonction si elle n'est pas explicitement libérée (créant une fuite !).

    int *heap_array;
    
    // Demande de l'espace pour 5 entiers

    heap_array = (int *)malloc(5 * sizeof(int));
    
    // RÈGLE D'OR : Toujours vérifier si le malloc a réussi

    if (heap_array == NULL)
    {
        return; // Échec de l'allocation, on quitte la fonction
    }

    heap_array[0] = 42;
    printf("Valeur Heap : %d\n", heap_array[0]);

    // RÈGLE D'OR : Destruction MANUELLE obligatoire

    free(heap_array);
}
