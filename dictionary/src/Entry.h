#pragma once

template<class KeyType, class ValueType>
class ArrayDictionary;

template<class KeyType, class ValueType>
class Entry {
    friend class ArrayDictionary<KeyType, ValueType>;

private:
    KeyType key;
    ValueType value;
    Entry<KeyType, ValueType> *next;


public:
    Entry() = delete;

    Entry(const KeyType &key, const ValueType &value) : key(key), value(value), next(nullptr) {}

    ValueType getValue() {
        return value;
    }

    KeyType getKey() {
        return key;
    }

    void setValue(const ValueType &newValue) {
        value = newValue;
    }

    bool operator==(const KeyType &otherKey) {
        return key == otherKey;
    }

    bool operator==(const Entry<KeyType, ValueType> &otherEntry) {
        return key == otherEntry.key && value == otherEntry.value;
    }
};