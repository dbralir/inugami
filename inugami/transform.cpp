/*******************************************************************************

Copyright (c) 2012 Jeramy Harrison

This software is provided 'as-is', without any express or implied warranty. In no event will the authors be held liable for any damages arising from the use of this software.

Permission is granted to anyone to use this software for any purpose, including commercial applications, and to alter it and redistribute it freely, subject to the following restrictions:

    1. The origin of this software must not be misrepresented; you must not claim that you wrote the original software. If you use this software in a product, an acknowledgment in the product documentation would be appreciated but is not required.

    2. Altered source versions must be plainly marked as such, and must not be misrepresented as being the original software.

    3. This notice may not be removed or altered from any source distribution.

*******************************************************************************/

#include "transform.hpp"

namespace Inugami {

Transform::Transform() :
    stack{Mat4(1.f)}
{}

Transform::Transform(const Transform& in) :
    stack{in.toMat4()}
{}

Transform::~Transform()
{}

Transform::operator Mat4() const
{
    return toMat4();
}

Transform& Transform::translate(const Vec3& pos)
{
    stack.back() = ::glm::translate(toMat4(), pos);
    return *this;
}

Transform& Transform::scale(const Vec3& vec)
{
    stack.back() = ::glm::scale(toMat4(), vec);
    return *this;
}

Transform& Transform::rotate(float deg, const Vec3& axis)
{
    stack.back() = ::glm::rotate(toMat4(), deg, axis);
    return *this;
}

Transform& Transform::push()
{
    stack.push_back(toMat4());
    return *this;
}

Transform& Transform::pop()
{
    stack.pop_back();
    return *this;
}

Transform& Transform::reset()
{
    stack.clear();
    return *this;
}

auto Transform::toMat4() const -> Mat4
{
    return stack.back();
}

} // namespace Inugami
