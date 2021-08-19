#!/bin/sh
set -e
if test "$CONFIGURATION" = "Debug"; then :
  cd /Users/bernardocohen/repos/designPatternsJoshi/cpp/Xcode
  /usr/local/Cellar/cmake/3.21.1/bin/cmake -E cmake_symlink_library /Users/bernardocohen/repos/designPatternsJoshi/cpp/Xcode/Debug/libdpJoshi.dylib /Users/bernardocohen/repos/designPatternsJoshi/cpp/Xcode/Debug/libdpJoshi.dylib /Users/bernardocohen/repos/designPatternsJoshi/cpp/Xcode/Debug/libdpJoshi.dylib
fi
if test "$CONFIGURATION" = "Release"; then :
  cd /Users/bernardocohen/repos/designPatternsJoshi/cpp/Xcode
  /usr/local/Cellar/cmake/3.21.1/bin/cmake -E cmake_symlink_library /Users/bernardocohen/repos/designPatternsJoshi/cpp/Xcode/Release/libdpJoshi.dylib /Users/bernardocohen/repos/designPatternsJoshi/cpp/Xcode/Release/libdpJoshi.dylib /Users/bernardocohen/repos/designPatternsJoshi/cpp/Xcode/Release/libdpJoshi.dylib
fi
if test "$CONFIGURATION" = "MinSizeRel"; then :
  cd /Users/bernardocohen/repos/designPatternsJoshi/cpp/Xcode
  /usr/local/Cellar/cmake/3.21.1/bin/cmake -E cmake_symlink_library /Users/bernardocohen/repos/designPatternsJoshi/cpp/Xcode/MinSizeRel/libdpJoshi.dylib /Users/bernardocohen/repos/designPatternsJoshi/cpp/Xcode/MinSizeRel/libdpJoshi.dylib /Users/bernardocohen/repos/designPatternsJoshi/cpp/Xcode/MinSizeRel/libdpJoshi.dylib
fi
if test "$CONFIGURATION" = "RelWithDebInfo"; then :
  cd /Users/bernardocohen/repos/designPatternsJoshi/cpp/Xcode
  /usr/local/Cellar/cmake/3.21.1/bin/cmake -E cmake_symlink_library /Users/bernardocohen/repos/designPatternsJoshi/cpp/Xcode/RelWithDebInfo/libdpJoshi.dylib /Users/bernardocohen/repos/designPatternsJoshi/cpp/Xcode/RelWithDebInfo/libdpJoshi.dylib /Users/bernardocohen/repos/designPatternsJoshi/cpp/Xcode/RelWithDebInfo/libdpJoshi.dylib
fi

