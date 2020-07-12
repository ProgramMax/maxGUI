# MAX_RESTRICTED_POINTER

API version: [**v0**](../../../Docs/v0.md)

## Note

MAX_RESTRICTED_POINTER allows a developer to provide aliasing information to the compiler.
A developer will want to be familiar with [pointer aliasing optimizations](AliasingOptimizations.md) in order to use MAX_RESTRICTED_POINTER.

A restricted pointer parameter requires that the parameter does not overlap any other pointed-to memory.

Use [MAX_RESTRICTED_REFERENCE](MAX_RESTRICTED_REFERENCE.md) instead if the parameter is a reference.

## Example

```c++
void free( MAX_RESTRICTED_POINTER( void * ) ptr );
```

## Implementation

Go to [the implementation](AliasingOptimizations.hpp#L61).