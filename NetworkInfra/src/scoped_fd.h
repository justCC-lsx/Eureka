/*
 @ 0xCCCCCCCC
*/

#ifndef SCOPED_FD_H_
#define SCOPED_FD_H_

#include <unistd.h>

#include "kbase/scoped_handle.h"

namespace network {

struct FDTraits {
    using Handle = int;

    FDTraits() = delete;
    ~FDTraits() = delete;

    static Handle NullHandle() noexcept
    {
        return -1;
    }

    static bool IsValid(Handle handle) noexcept
    {
        return handle != -1;
    }

    static void Close(Handle handle) noexcept
    {
        close(handle);
    }
};

using ScopedFD = kbase::GenericScopedHandle<FDTraits>;

}   // namespace network

#endif  // SCOPED_FD_H_
