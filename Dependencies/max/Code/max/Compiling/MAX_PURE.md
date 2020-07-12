# MAX_PURE

API version: [**v0**](../../../Docs/v0.md)

## Note

MAX_PURE allows a developer to provide aliasing information to the compiler.
A developer will want to be familiar with [pointer aliasing optimizations](AliasingOptimizations.md) in order to use MAX_PURE.

A pure function is one that references or modifies only locals and arguments.
It cannot follow first-level indirections. This means no pointers or references.
A pure function also cannot access globals.

MAX_PURE should not be used on methods / member functions.
Methods have a hidden 'this' first parameter. Accessing a field / member variable happens through the 'this' pointer, which is a first-level indirection. This goes against the idea of MAX_PURE.
MAX_PURE only applies to static methods and free functions.

Use [MAX_SEMI_PURE](MAX_SEMI_PURE.md) instead if the code needs to follow first-level indirections.

Use [MAX_PURE_WITH_GLOBALS](MAX_PURE_WITH_GLOBALS.md) instead if the code needs to access globals.

## Example

```c++
template< typename T >
MAX_PURE_DECLARATION( inline T Max( const T lhs, const T rhs ) );

template< typename T >
MAX_PURE_DEFINITION( inline T Max( const T lhs, const T rhs ) )
{
	if ( lhs >= rhs )
		return lhs;
	return rhs;
}
```

## Implementation

Go to [the implementation](AliasingOptimizations.hpp#L10).
