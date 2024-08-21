Example project showing issue with returning swift:: types back to swift from C++.


```bash
cmake -B build -GNinja
ninja -C build
```

Tested with:

swift-driver version: 1.113 Apple Swift version 6.0 (swiftlang-6.0.0.7.6 clang-1600.0.24.1)
Target: arm64-apple-macosx14.0

this should produce an error similar to:

```
ninja: Entering directory `build'
[1/2] Building Swift Module 'ExeShlib' with 1 source
FAILED: exe/CMakeFiles/exe.dir/Helper.swift.o 
/Applications/Xcode-beta.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/swiftc -j 12 -num-threads 12 -c  -module-name ExeShlib  -sdk /Applications/Xcode-beta.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX15.0.sdk -incremental -Xcc -std=c++23 -cxx-interoperability-mode=default -output-file-map exe/CMakeFiles/exe.dir//output-file-map.json -I /Applications/Xcode-beta.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/include -I /Users/andrew/Source/test/swift-return-swift-type/exe -I /Users/andrew/Source/test/swift-return-swift-type/build/shlib -I /Users/andrew/Source/test/swift-return-swift-type/shlib -I /Users/andrew/Source/test/swift-return-swift-type/build/shlib/include -I /Users/andrew/Source/test/swift-return-swift-type/build/exe/include /Users/andrew/Source/test/swift-return-swift-type/exe/Helper.swift
/Users/andrew/Source/test/swift-return-swift-type/exe/Helper.swift:5:11: error: 'getValue()' is unavailable: return type is unavailable in Swift
3 | func printThings()
4 | {
5 |     print(getValue())
  |           `- error: 'getValue()' is unavailable: return type is unavailable in Swift
6 |     print(getString())
7 | }

exe.getValue:2:13: note: 'getValue()' has been explicitly marked unavailable here
1 | @available(*, unavailable, message: "return type is unavailable in Swift")
2 | public func getValue() -> Never
  |             `- note: 'getValue()' has been explicitly marked unavailable here

/Users/andrew/Source/test/swift-return-swift-type/exe/Helper.swift:6:11: error: 'getString()' is unavailable: return type is unavailable in Swift
4 | {
5 |     print(getValue())
6 |     print(getString())
  |           `- error: 'getString()' is unavailable: return type is unavailable in Swift
7 | }
8 | 

exe.getString:2:13: note: 'getString()' has been explicitly marked unavailable here
1 | @available(*, unavailable, message: "return type is unavailable in Swift")
2 | public func getString() -> Never
  |             `- note: 'getString()' has been explicitly marked unavailable here
ninja: build stopped: subcommand failed.
```
