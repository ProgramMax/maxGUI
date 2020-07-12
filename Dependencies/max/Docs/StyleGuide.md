# Parameters:

                 | Cheap or impossible to copy (e.g., int, unique_ptr) | Cheap to move (e.g., vector<T>, string) or Moderate cost to move (e.g. array<vector>, BigPOD) or Don't know (e.g., unfamiliar type, template) | Expensive to move (e.g., BigPOD[], array<BigPOD>)
-----------------|-----------------------------------------------------|-----------------------------------------------------------------------------------------------------------------------------------------------|--------------------------------------------------
Out              | X f()                                               | X f()                                                                                                                                         | f(X&)
In/Out           | f(X&)                                               | f(X&)                                                                                                                                         | f(X&)
In               | f(X)                                                | f(const X&)                                                                                                                                   | f(const X&)
In & retain copy | f(X)                                                | f(X) & f(X&&)                                                                                                                                 | f(const X&)
In & move from   | f(X)                                                | f(X) & f(X&&)                                                                                                                                 | f(const X&)


Parameter category | Recommendation
-------------------|---------------------------------------------------------------------------------------
Read-only input    | For small objects, pass by value. Otherwise, pass by const ref.
Sink input         | Pass by const ref and rvalue ref overloads.
Output             | Return by value.
Input/Output       | Use a stateful algorithm object (initial state is a sink argument to the constructor).

There was a lot of talk about this after C++11 was released. There was a large amount of concern around combinatorial explosion of sink parameters. 1 sink parameter meant 2 overloads. 2 sinks parameters meant 4 overloads. 3 sink parameters meant 8 overloads. Eric Niebler talks about this [video](https://www.youtube.com/watch?v=zgOF4NrQllo), [slides](https://www.meetingcpp.com/tl_files/2013/talks/Keynote-cxx11-library-design-ericniebler.pdf). However, Herb Sutter argues ([video](http://youtube.com/watch?v=xnqTKD8uD64&t=1h10m57s)) that multiple sink parameters are rarely ever passed together since they normally go to functions like set_x(), enqueue_task(), push_back(). The noteable exception to this is constructors.

		Algorithm state: don't use a param, create an algorithm object (Initial state is a sink argument to the constructor)


Return a range rather than fill a buffer...maybe not all values are going to be use




make types regular
make moves noexcept