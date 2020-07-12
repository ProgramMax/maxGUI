CombineHalves implementation notes:

Recombining bytes from a byte stream involves
surprising behavior.

Imagine we read the first 8 bits:
1111'1111
We then 0-expand to 16-bits in
little-endian -- 1111'1111'0000'0000
big-endian    -- 0000'0000'1111'1111

It is important to notice that the layouts here
are different.

In the case of big-endian, the behavior is closer
to what a programmer might expect:
Shift this left 8 bits. Then do an OR with the second
8 bits.

But in the little-endian case, we actually shift the
second 8 bits left before doing an OR.
This is because in little-endian, shifting "left"
8 bits goes from
1111'1111'0000'0000
to
0000'0000'1111'1111

The end result of all this is we need different behavior
for little- and big-endian when recombining a byte stream
to get the same representation in a variable.
