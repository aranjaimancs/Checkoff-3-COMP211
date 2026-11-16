## README

## Project Overview

This project explores **mark-and-sweep garbage collection**, a technique for identifying allocated objects that a program can no longer reach.

In C, programmers manually manage dynamically allocated memory using functions such as `malloc()` and `free()`. 

For this checkoff, I explored how mark-and-sweep works, compared garbage collection with manual memory management in C, and built a small C simulation.

## How Mark-and-Sweep Works

Mark-and-sweep has two main phases:

1. **Mark:** Start at a set of **roots** (references in the running program - think a pointer to the root node in a LL), follow references, and mark all reachable objects.
2. **Sweep:** Inspect allocated objects and reclaim those that remain unmarked.

An object can reference another object and still be garbage if neither object can be reached from a root.

## My C Demonstration

My program models five objects: **A, B, C, D, and E**.

```text
Root -> A -> B -> C

        D <-> E
```

- **A, B, and C** are reachable from the root.
- **D and E** point to each other but are unreachable from the root.

The simulation uses:

- `objects[]` to store object labels.
- `next[]` to represent each object's outgoing reference as an array index (`-1` means no reference).
- `marked[]` to track reachable objects.
- A `while` loop to follow references starting at the root.
- A `for` loop to report which objects would be collected.

### Compile and Run

**Terminal:**

```powershell
gcc -Wall -Wextra -std=c11 mark_sweep.c -o mark_sweep
.\mark_sweep
```


### Expected Results

The program marks and keeps **A, B, and C**, and reports **D and E** as collectible.

### Limitations

This is a **teaching simulation**, not a complete garbage collector. It uses one root, allows only one outgoing reference per object, and represents objects with arrays rather than real heap allocations. The program **prints which objects would be reclaimed**; it does not use `malloc()` and `free()` to perform actual memory reclamation.

## Interesting Discoveries

1. **Reachability matters more than usefulness.** An object can remain allocated if the program can still reach it, even when the programmer no longer needs it.
