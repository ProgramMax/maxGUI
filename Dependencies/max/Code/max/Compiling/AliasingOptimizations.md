# max::Compiling::AliasingOptimizations

API version: [**v0**](../../../Docs/v0.md)

## What is it?

Pointer aliasing is when two or more pointers to different types point to the same area in memory.
This does not include when the pointers are for types in the same inheritance tree.

The compiler can optimize better by rearranging operations, which includes operations involving pointers.
But if the compiler does not know that pointers are not aliased, it cannot safely rearrange the operations.

Similarly, a write to a pointed-to address may be read back from memory if another write to a pointed-to address happened in the mean time.
This is because the compiler does not know that the second write did not clobber the first write.

In general, the compiler can optimize better if the developer provides non-aliasing promises.

These macros allow a developer to provide information to the compiler about aliasing.

## Macros of interest

* [MAX_PURE](MAX_PURE.md)
* [MAX_PURE_WITH_GLOBALS](MAX_PURE_WITH_GLOBALS.md)
* [MAX_SEMI_PURE](MAX_SEMI_PURE.md)
* [MAX_RESTRICTED_POINTER](MAX_RESTRICTED_POINTER.md)
* [MAX_RESTRICTED_REFERENCE](MAX_RESTRICTED_REFERENCE.md)
* [MAX_RETURNS_RESTRICTED_POINTER](MAX_RETURNS_RESTRICTED_POINTER.md)