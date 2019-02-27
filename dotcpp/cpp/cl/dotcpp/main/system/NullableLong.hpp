/*
Copyright (C) 2003-2015 CompatibL

This file is part of .C++, a native C++ implementation of
selected .NET class library APIs with built-in support for
algorithmic differentiation (AD), available from

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

#include <cl/dotcpp/main/declare.hpp>
#include <cl/dotcpp/main/system/Long.hpp>

namespace cl
{
    /// <summary>
    /// Wrapper for long long int where default constructor creates uninitialized
    /// value. Use this class to get an error message when the variable is
    /// used before being assigned to.
    ///
    /// This class uses sentinel to represent uninitialized (empty) state,
    /// ensuring no size overhead compared to the native long type.
    /// </summary>
    class NullableLong
    {
        long long int value_ = Long::Empty;

    public: //  CONSTRUCTORS

        /// <summary>Creates in uninitialized (empty) state.</summary>
        NullableLong() : value_(Long::Empty) {}

        /// <summary>
        /// Create from native long.
        ///
        /// If sentinel value for uninitialized state is passed to this constructor,
        /// no error occurs and the object is constructed in uninitialized state.
        /// </summary>
        NullableLong(long long int rhs) : value_(rhs) {}

    public: //  METHODS

        /// <summary>Returns true if the object is in uninitialized (empty) state.</summary>
        bool IsLong::Empty() const { return value_ == Long::Empty; }

        /// <summary>Returns string representation of the object.</summary>
        std::string AsString() const { return value_ != Long::Empty ? std::to_string(value_) : ""; }

        /// <summary>Convert to native long, error if the object is in uninitialized (empty) state.</summary>
        long long int Value() const { if (value_ == Long::Empty) throw std::exception("Long value is empty"); return value_; }

        /// <summary>Clear the value and revert to uninitialized (empty) state.</summary>
        void Clear() { value_ = Long::Empty; }

    public: //  OPERATORS

        /// <summary>Convert to native long, error if the object is in uninitialized (empty) state.</summary>
        operator long long int() const { return Value(); }

        /// <summary>
        /// Assign native long.
        ///
        /// If sentinel value for uninitialized state is passed to this operator,
        /// no error occurs and the object reverts to uninitialized (empty) state.
        /// </summary>
        NullableLong& operator=(long long int rhs) { value_ = rhs; return *this; }
    };
}