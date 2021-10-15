#pragma once
#include<stdlib.h>
#include<new>

#define CACHE_LINE 64

namespace STLL
{
    template<class T, size_t Alignment = CACHE_LINE>
    class CacheAlignedAllocator
    {   
    public:
        
        using value_type = T;
        

        template<typename U> struct rebind 
        {
            using other = CacheAlignedAllocator<U, Alignment>;
        };

        template <typename U>
        CacheAlignedAllocator(const CacheAlignedAllocator<U, Alignment> &other) noexcept
        { 
            (void) other; 
        }

        CacheAlignedAllocator() = default;

       
        T* allocate(size_t size)
        {
            if (auto ptr = aligned_alloc(Alignment, sizeof(T) * size))
               return static_cast<T*>(ptr);

            throw std::bad_alloc();
        }

        void deallocate(T* ptr, size_t size)
        {   
            (void) size;
            free(ptr);
            ptr = nullptr;
        }
    
    };
}