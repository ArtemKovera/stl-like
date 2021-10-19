/*
    This allocator is analogous to one example
    from the course "C++ Standard Template Library in Practice" by James Slocum
*/
#pragma once
#include<stdlib.h>
#include<iostream>
#include<new>

namespace STLL
{
    template<class T>
    class DebugAllocator
    {
    public:

        using value_type = T;

        DebugAllocator() noexcept {}

        template <typename U>
        DebugAllocator(const DebugAllocator<U> &other) noexcept {}

        T* allocate(size_t n)
        {
            if (T* ptr = (T*)malloc(size))
            {   
                size_t size = sizeof(T) * n;
                std::cout << size << " bytes are allocated at " << ptr << std::endl;
                return ptr;
            }
               
            throw std::bad_alloc();
        }

        void deallocate(T* ptr, size_t n) noexcept
        {
            size_t size = sizeof(T) * n;
            free(ptr);
            std::cout << size << " bytes are deallocated at " << ptr << std::endl;
        }

        template<typename U, typename ...Args>
        void construct(U* p, Args&& ...args) 
        {
            ::new(p) U(std::forward<Args>(args)...);
            cout << "constructed new " << typeid(decltype(*p)).name() << " at addr: " << p << "\n";
        }        
        
        template<typename U>
        void destroy(U* p) noexcept
        {
            p->~U();
            cout << "destroyed " << typeid(decltype(*p)).name() << " at addr: " << p << "\n";
        }

        template<typename U>
        bool operator==(const DebugAllocator<U>&) noexcept
        {
            return true;
        }

        template<typename U>
        bool operator!=(const DebugAllocator<U>& u) noexcept
        {
            return (*this == u);
        }        

    };

}