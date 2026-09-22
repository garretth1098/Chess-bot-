




## Bitboard mapping 

- need bitboards of each piece type and color combination
- held in an array as a part of my boardstate struct
- 12 bitboards; categorized this way so that a one-bit means a piece of that type resides in that square

- stored as 64-bit integers encoded in Hexadecimal
- white pawns: 
    Hex: 0x0000000000ff00
    Binary: 0000000000000000000000000000000000000000000000001111111100000000


- encoded in Little-Endian Rank File (LERF)
    - a1 = 0
    - h8 = 63

     A    B    C    D    E    F    G    H
   +----+----+----+----+----+----+----+----+
 8 | 56 | 57 | 58 | 59 | 60 | 61 | 62 | 63 |  8th rank
   +----+----+----+----+----+----+----+----+
 7 | 48 | 49 | 50 | 51 | 52 | 53 | 54 | 55 |  7th rank
   +----+----+----+----+----+----+----+----+
 6 | 40 | 41 | 42 | 43 | 44 | 45 | 46 | 47 |  6th rank
   +----+----+----+----+----+----+----+----+
 5 | 32 | 33 | 34 | 35 | 36 | 37 | 38 | 39 |  5th rank
   +----+----+----+----+----+----+----+----+
 4 | 24 | 25 | 26 | 27 | 28 | 29 | 30 | 31 |  4th rank
   +----+----+----+----+----+----+----+----+
 3 | 16 | 17 | 18 | 19 | 20 | 21 | 22 | 23 |  3rd rank
   +----+----+----+----+----+----+----+----+
 2 |  8 |  9 | 10 | 11 | 12 | 13 | 14 | 15 |  2nd rank
   +----+----+----+----+----+----+----+----+
 1 |  0 |  1 |  2 |  3 |  4 |  5 |  6 |  7 |  1st rank
   +----+----+----+----+----+----+----+----+
     A    B    C    D    E    F    G    H - file(s)


rank * 8 + column 



enum enumSquare {
  a1, b1, c1, d1, e1, f1, g1, h1,
  a2, b2, c2, d2, e2, f2, g2, h2,
  a3, b3, c3, d3, e3, f3, g3, h3,
  a4, b4, c4, d4, e4, f4, g4, h4,
  a5, b5, c5, d5, e5, f5, g5, h5,
  a6, b6, c6, d6, e6, f6, g6, h6,
  a7, b7, c7, d7, e7, f7, g7, h7,
  a8, b8, c8, d8, e8, f8, g8, h8
};



**Selecting a square**
- left shift bitwise operation 

- create a bitboard equal to 1; one-bit in the first position: 

```
uint64_t(1);
```
creates: 0x1000000000000000 = 0000000000000000000000000000000000000000000000000000000000000001

- to select square, denoted n, we will shift the bit by n places

```
d4 = 27; // n = 27 
uint64_t << 27;
```

which creates: 0x0000080000000000 = 0000000000000000000000000000000000001000000000000000000000000000
                                    ↑                                   ↑                          ↑
                                  bit 63                             bit27                      bit 0

- visually this appears as follows:

8 |  0   0   0   0   0   0   0   0
7 |  0   0   0   0   0   0   0   0
6 |  0   0   0   0   0   0   0   0
5 |  0   0   0   0   0   0   0   0
4 |  0   0   0   1   0   0   0   0
3 |  0   0   0   0   0   0   0   0
2 |  0   0   0   0   0   0   0   0
1 |  0   0   0   0   0   0   0   0
    ------------------------------
     a   b   c   d   e   f   g   h
