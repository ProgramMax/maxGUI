# MAX_SEMI_PURE

API version: [**v0**](../../../Docs/v0.md)

## Note

MAX_SEMI_PURE allows a developer to provide aliasing information to the compiler.
A developer will want to be familiar with [pointer aliasing optimizations](AliasingOptimizations.md) in order to use MAX_SEMI_PURE.

A semi-pure function is one that references or modifies only locals, arguments, and first-level indirections of arguments.
This means param1->foo is okay.
But param1->member1->foo isn't okay. This is a second-level indirection.
A semi-pure function also cannot access globals.

Methods / member functions which reference fields / member variables are following a first-level indirection via the 'this' pointer.
So member1->foo isn't okay but simply accessing member1 is okay.

Use [MAX_PURE](MAX_PURE.md) instead if the code does not need to follow first-level indirections.

Use [MAX_PURE_WITH_GLOBALS](MAX_PURE_WITH_GLOBALS.md) instead if the code needs to follow first-level indirections and access globals.

## Example

```c++
template< typename T >
MAX_SEMI_PURE_DECLARATION( T Max( const T & lhs, const T & rhs ) );

template< typename T >
MAX_SEMI_PURE_DEFINITION( T Max( const T & lhs, const T & rhs ) )
{
	if ( lhs >= rhs )
		return lhs;
	return rhs;
}
```

## Implementation

Go to [the implementation](AliasingOptimizations.hpp#L50).
