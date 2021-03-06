﻿#pragma once    // Source encoding: UTF-8 with BOM (π is a lowercase Greek "pi").
#if __cplusplus < 201703L
    static_assert( __cplusplus >= 201703L,
        "Requires C++17 or later. For MSVC use e.g. `/std:c++17 /Zc:__cplusplus /FIiso646.h /wd4459 /utf-8`."
        // https://blogs.msdn.microsoft.com/vcblog/2018/04/09/msvc-now-correctly-reports-__cplusplus/
        );
#   include <C++17-or-later-is-required>
#endif
