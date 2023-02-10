/*
** EPITECH PROJECT, 2023
** B-OOP-400-NAN-4-1-tekspice-timothee.lesellier-mirror
** File description:
** ComponentFactory
*/

#ifndef COMPONENTFACTORY_HPP_
#define COMPONENTFACTORY_HPP_

#include <unordered_map>
#include <functional>

template<class Key, class Object, class... Args>
class ComponentFactory {
    public:
        using Creator = std::function<Object(Args...)>;

        void register(Key const& key, Creator const& creator);

        Object create(Key const& key, Args &&... args) const;

    private:
        std::unordered_map<Key, Creator> m_creators;
};

#endif /* !COMPONENTFACTORY_HPP_ */
