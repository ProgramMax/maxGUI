# MAX_RESTRICTED_REFERENCE

API version: [**v0**](../../../Docs/v0.md)

## Note

MAX_RESTRICTED_REFERENCE allows a developer to provide aliasing information to the compiler.
A developer will want to be familiar with [pointer aliasing optimizations](AliasingOptimizations.md) in order to use MAX_RESTRICTED_REFERENCE.

A restricted reference parameter requires that the parameter does not overlap any other pointed-to memory.

Use [MAX_RESTRICTED_POINTER](MAX_RESTRICTED_POINTER.md) instead if the parameter is a pointer.

## Example

```c++
void Consume( MAX_RESTRICTED_REFERENCE( int & ) value );
```

## Implementation

Go to [the implementation](AliasingOptimizations.hpp#L72).
