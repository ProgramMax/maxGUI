# max::Algorithms::IsBetween

API version: [**v0**](../../../Docs/v0.md)

## Note

This function uses an inclusive range.

This function is [pure](../Compiling/MAX_PURE.md).

## Signature

```c++
template< typename T >
MAX_SEMI_PURE(
constexpr bool IsBetween(

	const T Value,
	const max::Containers::Range< T > & Range

) MAX_DOES_NOT_THROW
);
```

## Parameters

* **Value**
    * The value that is potentially inside the range.
* **Range**
	* The range (inclusive) which the value is compared against.

## Returns

Returns whether or not Value is inside Range (inclusive).

## Example

```c++
auto range = max::Containers::Range< int >{ 1, 100 };
if( max::Algorithms::IsBetween( 50, range ) )
```

## Implementation

Go to [the implementation](IsBetween.inl#L13).
