Récursivité & debugging GDB

## 1. Modèle "Avant / Après"

La récursivité n'est pas une boucle, c'est un voyage aller-retour (descente puis remontée).
Le placement de l'appel récursif agit comme un **"Marque-Page"**.

```c
#include <unistd.h>

void ft_putchar(char c)
{
    write(1, &c, 1);
}

void ft_putnbr(int nb)
{
    long n;
    n = nb; // Utilisation d'un long pour gérer l'overflow de INT_MIN

    // ==========================================
    // ZONE 1 : AVANT L'APPEL (EMPILEMENT / DESCENTE)
    // Travail préparatoire. Exécuté de haut en bas.
    // ==========================================
    if (n < 0)
    {
        ft_putchar('-'); // S'affiche PENDANT la descente
        n = -n;
    }

    if (n >= 10)
    {
        // ==========================================
        // LA FRONTIÈRE : LE MARQUE-PAGE
        // ==========================================
        ft_putnbr(n / 10); 
        // L'exécution se fige ICI. 
        // La variable 'n' est sauvegardée dans une "bulle" (Frame).
    }

    // ==========================================
    // ZONE 2 : APRÈS L'APPEL (DÉPILEMENT / REMONTÉE)
    // Phase active d'affichage. Exécuté du fond vers la surface.
    // ==========================================
    
    // On reprend exactement ici avec le "n" sauvegardé !
    ft_putchar((n % 10) + '0'); 
}

```

---

## 2. Comprendre le mécanisme

### A. L'empilement (la descente)

* **Ce qu'il se passe :** La fonction s'appelle elle-même avec une version réduite du problème (`n / 10`).
* **La règle d'or :** Chaque nouvel appel met le précédent en **PAUSE**. On empile des couches (Frames) dans la mémoire (la Stack).
* **La mémoire :** Chaque couche possède sa propre copie intacte de la variable `n`.

### B. Le dépilement (la remontée)

* Au dépilement, on ne relance pas la fonction du début ! On reprend l'exécution **exactement après le marque-page** (l'instruction d'appel).
* Les appels en pause se réveillent un par un, en partant du dernier créé (LIFO : Last In, First Out).
* C'est ici que `ft_putchar` s'exécute pour afficher les chiffres de gauche à droite, en utilisant la variable `n` qui avait été congelée à chaque étage.

---

## 3. utilisation de GDB (debugging)

### Compilation

Il faut compiler sans optimisation et avec les symboles de débogage pour que GDB puisse lier le code source à la mémoire.

```bash
gcc -g -O0 mon_fichier.c -o mon_programme

```

### Commandes GDB essentielles

| Commande | Raccourci | Action |
| --- | --- | --- |
| `gdb ./prog` | - | Lancer l'interface GDB. |
| `list` | `l` | Afficher le code source (10 lignes par défaut). |
| `break [ligne/func]` | `b` | Poser un point d'arrêt (ex: `b 23` ou `b ft_putnbr`). |
| `run` | `r` | Lancer l'exécution du programme. |
| `next` | `n` | Exécuter la ligne courante (Passe par-dessus les fonctions). |
| `step` | `s` | Exécuter la ligne courante (**Entre** dans les fonctions). |
| `continue` | `c` | Reprendre l'exécution jusqu'au prochain point d'arrêt. |
| `backtrace` | `bt` | Afficher la Stack (la pile des appels en cours). |
| `print [var]` | `p` | Afficher la valeur d'une variable ou expression. |
| `frame [num]` | `f` | Naviguer dans les couches de la Stack (ex: `f 2`). |
| `info locals` | - | Afficher toutes les variables locales de la frame actuelle. |

### Prouver la remontée

Pour voir le dépilement en direct, on ignore la descente et on s'arrête uniquement sur l'affichage :

1. **Poser le piège :** `break 23` *(Mettre le numéro de ligne du dernier `ft_putchar`)*.
2. **Lancer :** `run` *(Le programme avale toute la descente et s'arrête au fond du puits).*
3. **Inspecter :** * `bt` (Pour voir les appels empilés).
* `print n` (Pour voir que `n` vaut le premier chiffre, ex: `1`).
* `print /c (n % 10) + '0'` (Pour évaluer le caractère qui va s'afficher).


4. **Remonter :** `continue` *(Passe à l'étage supérieur de la pile. Répéter pour voir `n` grandir à nouveau).*


