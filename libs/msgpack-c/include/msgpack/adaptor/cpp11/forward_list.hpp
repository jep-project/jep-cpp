//
// MessagePack for C++ static resolution routine
//
// Copyright (C) 2014 KONDO-2015 Takatoshi
//
//    Licensed under the Apache License, Version 2.0 (the "License");
//    you may not use this file except in compliance with the License.
//    You may obtain a copy of the License at
//
//        http://www.apache.org/licenses/LICENSE-2.0
//
//    Unless required by applicable law or agreed to in writing, software
//    distributed under the License is distributed on an "AS IS" BASIS,
//    WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
//    See the License for the specific language governing permissions and
//    limitations under the License.
//

#ifndef MSGPACK_CPP11_FORWARD_LIST_HPP
#define MSGPACK_CPP11_FORWARD_LIST_HPP

#include "msgpack/versioning.hpp"
#include "msgpack/object_fwd.hpp"
#include "msgpack/adaptor/check_container_size.hpp"

#include <forward_list>

namespace msgpack {

MSGPACK_API_VERSION_NAMESPACE(v1) {

template <typename T>
inline msgpack::object const& operator>> (msgpack::object const& o, std::forward_list<T>& v)
{
    if(o.type != msgpack::type::ARRAY) { throw msgpack::type_error(); }
    v.resize(o.via.array.size);
    msgpack::object* p = o.via.array.ptr;
    for (auto &e : v) {
        p->convert(e);
        ++p;
    }
    return o;
}

template <typename Stream, typename T>
inline msgpack::packer<Stream>& operator<< (msgpack::packer<Stream>& o, const std::forward_list<T>& v)
{
    uint32_t size = checked_get_container_size(std::distance(v.begin(), v.end()));
    o.pack_array(size);
    for(auto const& e : v) o.pack(e);
    return o;
}

template <typename T>
inline void operator<< (msgpack::object::with_zone& o, const std::forward_list<T>& v)
{
    o.type = msgpack::type::ARRAY;
    if(v.empty()) {
        o.via.array.ptr = nullptr;
        o.via.array.size = 0;
    } else {
        uint32_t size = checked_get_container_size(std::distance(v.begin(), v.end()));
        o.via.array.size = size;
        msgpack::object* p = static_cast<msgpack::object*>(
            o.zone.allocate_align(sizeof(msgpack::object)*size));
        o.via.array.ptr = p;
        for(auto const& e : v) *p++ = msgpack::object(e, o.zone);
    }
}

}  // MSGPACK_API_VERSION_NAMESPACE(v1)

} // namespace msgpack

#endif // MSGPACK_CPP11_FORWARD_LIST_HPP
