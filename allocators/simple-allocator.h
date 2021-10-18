#pragma once
#include<stdlib.h>
#include<new>

namespace STLL
{
    template<class T>
    class SimpleAllocator
    {
    public:

        using value_type = T;

        SimpleAllocator() = default;
        
        
        template <typename U>
        SimpleAllocator(const SimpleAllocator<U> &other) noexcept
        { 
            (void) other; 
        }
        
        
        T* allocate(size_t size)
        {
            if (auto ptr = malloc(sizeof(T) * size))
               return static_cast<T*>(ptr);

            throw std::bad_alloc();
        }

        void deallocate(T* ptr, size_t size)
        {   
            (void) size;
            free(ptr);
            ptr = nullptr;
        }

        bool operator==(const SimpleAllocator<T> &)
        { 
            return true; 
        }

        bool operator!=(const SimpleAllocator<T> &)
        { 
            return false; 
        }

    };
}