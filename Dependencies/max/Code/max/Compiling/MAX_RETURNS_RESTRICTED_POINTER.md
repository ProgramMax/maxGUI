# MAX_RETURNS_RESTRICTED_POINTER

API version: [**v0**](../../../Docs/v0.md)

## Note

MAX_RETURNS_RESTRICTED_POINTER allows a developer to provide aliasing information to the compiler.
A developer will want to be familiar with [pointer aliasing optimizations](AliasingOptimizations.md) in order to use MAX_RETURNS_RESTRICTED_POINTER.

A restricted pointer returned from a function is not accessible from any other pointer.

## Example

```c++
MAX_RETURNS_RESTRICTED_POINTER void * malloc( size_t size );
```

## Implementation

Go to [the implementation](AliasingOptimizations.hpp#L87).
