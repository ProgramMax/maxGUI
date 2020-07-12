# MAX_STRINGIFY and MAX_EXPAND_AND_STRINGIFY

API version: [**v0**](../../../Docs/v0.md)

## Note

MAX_STRINGIFY and MAX_EXPAND_AND_STRINGIFY are both used to get a string representation of a macro parameter.

MAX_STRINGIFY produces the name of the parameter.

MAX_EXPAND_AND_STRINGIFY will evaluate the macro parameter's contents and produce a string representation of that.

## Example

```c++
MAX_COMPILER_MESSAGE(MAX_STRINGIFY(__LINE__) " has the value " MAX_EXPAND_AND_STRINGIFY(__LINE__));
// Prints "__LINE__ has the value 1"
```

## Implementation

Go to [the implementation](Macros.hpp#L11).