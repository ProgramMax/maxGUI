# maxGUI

maxGUI allows for easy, light-weight, and cross-platform* GUI coding.

[![MSBuild](https://github.com/ProgramMax/maxGUI/actions/workflows/msbuild.yml/badge.svg)](https://github.com/ProgramMax/maxGUI/actions/workflows/msbuild.yml)

maxGUI is VERY new and deliberately missing features to focus on the core. If you need a feature, submit a [feature request](https://github.com/ProgramMax/maxGUI/issues/new?assignees=&labels=&template=feature_request.md&title=).

maxGUI has been through a handful of rewrites. It turns out designing an easy-to-use C++ GUI library takes more design experience then I had when I first started this in ~2006, when I was in college. I'm proud enough of the current design approach. It is what I wanted for other projects of mine.

That said, expect the APIs to change. Like I said, this is very new.

## Examples

Start with the [simple example](https://github.com/ProgramMax/maxGUI/blob/master/Code/Examples/1%20-%20SimpleExample/EntryPoint.cpp). It shows the basics in an easy-to-follow way.

## Support

* Compilers:
    * GCC*
    * Clang*
    * Visual C++
* OSes:
    * Windows
    * MacOS*
    * Android*
    * iOS*
	* Some Linux compositors*

*coming soon

If you would like maxGUI to support more contacts us and let us know.

## Deprecation Schedule

We know transitioning a codebase to a new technology takes time. And we know customers may still be on an old OS.

In order to ease transition pressure, maxGUI will continue to provide support for 5 years after a replacement is available.

As an example, when a new version of Clang comes out you will have 5 years to migrate off the now-old version.

You can reference the full [deprecation schedule](DeprecationSchedule.md) for exact dates.

## Dependencies

maxGUI depends on [max](https://github.com/ProgramMax/max), which also has a [BSD 3-Clause license](https://github.com/ProgramMax/max/blob/master/LICENSE).
You can find some parts of max under [Dependencies/max](https://github.com/ProgramMax/maxGUI/blob/master/Dependencies/max).

## Engage

* **Community:** We have a welcoming community which follows the [Code of Conduct](https://github.com/ProgramMax/maxGUI/blob/master/Docs/code_of_conduct.md).
* **Contribute:** We accept pull requests. Take a look at some [good first tasks](https://github.com/ProgramMax/maxGUI/issues?q=is%3Aissue+is%3Aopen+label%3A"good+first+issue").
* **Support:** You can [report bugs](https://github.com/ProgramMax/maxGUI/issues/new?assignees=&labels=&template=bug_report.md&title=) and [request changes](https://github.com/ProgramMax/maxGUI/issues/new?assignees=&labels=&template=feature_request.md&title=) using GitHub issues.