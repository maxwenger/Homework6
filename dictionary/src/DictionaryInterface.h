#pragma once

template<class KeyType, class ValueType>
class DictionaryInterface {
public:
    virtual bool isEmpty() = 0;

    virtual int size() = 0;

    virtual bool add(KeyType const &key, ValueType const &value) = 0;

    virtual bool remove(KeyType const &key) = 0;

    virtual bool get(KeyType const &key, ValueType &value) = 0;

    virtual bool contain(KeyType const &key) = 0;

    virtual void traverse() = 0;

    virtual ~DictionaryInterface() {};
};
