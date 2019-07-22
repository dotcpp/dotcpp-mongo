/*
Copyright (C) 2003-present CompatibL

This file is part of .C++, a native C++ implementation of
popular .NET class library APIs developed to facilitate
code reuse between C# and C++.

    http://github.com/dotcpp/dotcpp (source)
    http://dotcpp.org (documentation)

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

   http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

#pragma once

#include <dot/system/collections/generic/IEnumerable.hpp>

namespace cl
{
    template <class T> class ICollectionImpl; template <class T> using ICollection = Ptr<ICollectionImpl<T>>;

    /// <summary>
    /// Defines methods to manipulate generic collections.
    /// </summary>
    template <class T>
    class ICollectionImpl : public IEnumerableImpl<T>
    {
        typedef ICollectionImpl<T> self;

    public: // METHODS

        /// <summary>The number of items contained in the list.</summary>
        DOT_DECL_GET(int, Count)

        /// <summary>Adds an item to the end of the lisIt.</summary>
        virtual void Add(const T& item) = 0;

        /// <summary>Removes all items from the list.</summary>
        virtual void Clear() = 0;

        /// <summary>Determines whether the list contains a specific value.</summary>
        virtual bool Contains(const T& item) = 0;
    };
}