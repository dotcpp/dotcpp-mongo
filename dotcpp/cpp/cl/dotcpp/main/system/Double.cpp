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

#include <cl/dotcpp/main/implement.hpp>
#include <cl/dotcpp/main/system/Double.hpp>
#include <cl/dotcpp/main/system/String.hpp>
#include <cl/dotcpp/main/system/Type.hpp>

namespace cl
{
    bool DoubleImpl::Equals(Object obj)
    {
        if (this == &(*obj)) return true;

        if (obj.is<Ptr<DoubleImpl>>())
        {
            return value_ == obj.as<Ptr<DoubleImpl>>()->value_;
        }

        return false;
    }

    size_t DoubleImpl::GetHashCode()
    {
        return std::hash<double>()(value_);
    }

    String DoubleImpl::ToString()
    {
        return std::to_string(value_);
    }

    Type DoubleImpl::typeof()
    {
        return cl::typeof<double>();
    }

    Type DoubleImpl::GetType()
    {
        return typeof();
    }
}