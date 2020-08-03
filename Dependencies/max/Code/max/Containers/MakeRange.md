# max::Containers::MakeRange

API version: [**v0**](../../../Docs/v0.md)

## Note

This function is provided as a convenience function.
The [Range ctor](Range_ctor.md) should be called instead if the developer knows which parameter is the minimum and which is the maximum.
When the min/max is not yet known, this function can be called instead.

This function is [pure](../Compiling/MAX_PURE.md).

## Signature

```c++
template< typename T >
MAX_PURE(
Range< T > MakeRange(

	const T Value1,
	const T Value2

) noexcept
);
```

## Parameters

* **Value1**
    * Part of the range.
* **Value2**
	* Part of the range.

## Example

```c++
auto range = max::Containers::MakeRange< int >( 1, 100 );
max::Algorithms::IsBetween( 50, range );
```

## Implementation

Go to [the implementation](Range.inl#L24).