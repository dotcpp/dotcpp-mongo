/*
Copyright (C) 2003-2015 CompatibL

This file is part of DotCpp project, an implementation of
selected .NET class libraries in native C++ available from

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

#ifndef __dot_system_collections_generic_LinkedList_hpp__
#define __dot_system_collections_generic_LinkedList_hpp__

#include <deque>

#include <dot/system/collections/generic/IDotCollection.hpp>
#include <dot/system/collections/generic/IDotEnumerable.hpp>
#include <dot/system/collections/generic/IDotEnumerator.hpp>

namespace dot
{
	///Not finished
	template <typename T>
	class LinkedListNode
	{
	private:

	public:
		LinkedListNode(T Value);
	};
	
	///Not finished
	template <typename T>
	class LinkedList : public detail::std_accessor_<dot::IDotEnumerable<T>
		, std::deque<T> >
	{
	public:
		typedef detail::std_accessor_<dot::IDotEnumerable<T>
			, std::deque<T> > base;

		typedef dot::IDotEnumerable<T> dot_enumerator_type;

		typedef std::deque<T> std_base;

		typedef T& reference_type;

		LinkedList() : base()
		{ }

		inline int get_Count() const
		{
			return this->get().size();
		}


	
	};

}

#endif