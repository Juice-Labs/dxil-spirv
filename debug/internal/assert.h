#pragma once

#include <assert.h>
#include <iostream>

_ACRTIMP void __cdecl _wassert(
    _In_z_ wchar_t const* _Message,
    _In_z_ wchar_t const* _File,
    _In_   unsigned       _Line
    );

static inline void __cdecl assert_internal(
    _In_z_ wchar_t const* _Message,
    _In_z_ wchar_t const* _File,
    _In_   unsigned       _Line
    )
{
    std::cerr << "Assertion failed: " << _Message << ", file " << _File << ", line " << _Line << std::endl;
    //_wassert(_Message, _File, _Line);
}

#undef assert
#define assert(expression) (void)(                                                       \
        (!!(expression)) ||                                                              \
        (assert_internal(_CRT_WIDE(#expression), _CRT_WIDE(__FILE__), (unsigned)(__LINE__)), 0) \
    )
