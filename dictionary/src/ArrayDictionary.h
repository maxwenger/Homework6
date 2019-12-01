#pragma once

#include <vector>
#include "Entry.h"
#include "DictionaryInterface.h"
#include <iostream>

template<class KeyType, class ValueType>
class ArrayDictionary : public DictionaryInterface<KeyType, ValueType> {
private:
    static const int DEFAULT_CAPACITY = 10;
    Entry<KeyType, ValueType> **entries;
    int count;
    int capacity;

    void deleteEntry(Entry<KeyType, ValueType> *node) {
        if (node == nullptr) {
            return;
        }
        deleteEntry(node->next);
        delete node;
    }

public:

    ArrayDictionary() : ArrayDictionary(DEFAULT_CAPACITY) {}

    ArrayDictionary(int capacity) : capacity(capacity), count(0) {
        // () at the end initialize all values to nullptr
        entries = new Entry<KeyType, ValueType> *[capacity]();
    }

    ~ArrayDictionary() {
        for (int i = 0; i < capacity; i++) {
            if (entries[i] == nullptr) {
                continue;
            }
            deleteEntry(entries[i]);
        }
        delete[]entries;
    }

    int hashFunc(KeyType key) {
        return (KeyType) (key % capacity);
    }

    int size() override {
        return count;
    }

    bool isEmpty() override {
        return count == 0;
    }

    bool add(KeyType const &key, ValueType const &value) override {
        int hashedKey = hashFunc(key);

        // when there's no entry yet
        if (entries[hashedKey] == nullptr) {
            if (count == capacity) {
                return false;
            }
            entries[hashedKey] = new Entry<KeyType, ValueType>(key, value);
            count++;
            return true;
        }

        Entry<KeyType, ValueType> *ptr = entries[hashedKey];
        Entry<KeyType, ValueType> *pNewNode = nullptr;
        while (ptr != nullptr) {
            // update value if key already exists
            if (ptr->key == key) {
                ptr->value = value;
                return true;
            }

            pNewNode = ptr;
            ptr = ptr->next;
        }

        pNewNode->next = new Entry<KeyType, ValueType>(key, value);
        return true;
    }

    bool get(KeyType const &key, ValueType &value) override {
        int hashedKey = hashFunc(key);
        Entry<KeyType, ValueType> *ptr = entries[hashedKey];
        while (ptr != nullptr) {
            if (ptr->key == key) {
                value = ptr->value;
                return true;
            }
            ptr = ptr->next;
        }
        return false;
    }

    int valueSetSize(KeyType const &key) {
        int hashedKey = hashFunc(key);
        int valueSize = 0;
        Entry<KeyType, ValueType> *ptr = entries[hashedKey];
        while (ptr != nullptr) {
            ++valueSize;
            ptr = ptr->next;
        }
        return valueSize;
    }

    void print() {
        for (int i = 0; i < capacity; i++) {
            if (entries[i] == nullptr) {
                printf("[%d] = null\n", i);
                continue;
            }
            Entry<KeyType, ValueType> *ptr = entries[i];
            printf("[%d] = {", i);
            while (ptr != nullptr) {
                printf("(%d, %d)", ptr->key, ptr->value);
                ptr = ptr->next;
            }
            printf("}\n");
        }
    }

    bool contain(KeyType const &key) override {
        // homework
        return false;
    }

    void traverse() override {
        // not implemented
    }

    bool remove(KeyType const &key) override {
        // homework
        return false;
    }
};