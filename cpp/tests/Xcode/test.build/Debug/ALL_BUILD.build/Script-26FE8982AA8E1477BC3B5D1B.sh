#!/bin/sh
set -e
if test "$CONFIGURATION" = "Debug"; then :
  cd /Users/bernardocohen/repos/designPatternsJoshi/cpp/tests/Xcode
  echo Build\ all\ projects
fi
if test "$CONFIGURATION" = "Release"; then :
  cd /Users/bernardocohen/repos/designPatternsJoshi/cpp/tests/Xcode
  echo Build\ all\ projects
fi
if test "$CONFIGURATION" = "MinSizeRel"; then :
  cd /Users/bernardocohen/repos/designPatternsJoshi/cpp/tests/Xcode
  echo Build\ all\ projects
fi
if test "$CONFIGURATION" = "RelWithDebInfo"; then :
  cd /Users/bernardocohen/repos/designPatternsJoshi/cpp/tests/Xcode
  echo Build\ all\ projects
fi

