## Finish the contain(key) and remove(key) in the ArrayDictionary class (50pt)

Use folder ```dictionary```.

### 1. (20pt) Finish the contain() function in src/ArrayDictionary.h with unit tests 

```c++
bool contain(KeyType &key) override {
    return false;
}
```

This function returns true if the dictionary contains an entry with the given key, and false otherwise. This given key is the key of the entry, not the hash key in the dictionary. 

Finish the unit test for contain() in test/unit_test.cpp

```c++
TEST(dict, contain) {
    // homework
    ASSERT_TRUE(false); // placeholder
}
```

The following cases **MUST** be tested to receive any point. 

Allow me repeat: ***If any of the following cases is missing, no point is given for this problem.*** 

OK to split the above function with each set of tests:

set 1:
- empty dictionary<int, int>, contain returns false with key -1 
- empty dictionary<int, int>, contain returns false with key 0 
- empty dictionary<int, int>, contain returns false with key 1 

set 2:
- dictionary<int, int>, capacity 1, init values {0:103}, key=2 returns false 
- dictionary<int, int>, capacity 1, init values {0:103}, key=0 returns true 

set 3:
- dictionary<int, int>, capacity 2, init values {0:103, 1:105}, key=0 returns true 
- dictionary<int, int>, capacity 2, init values {0:103, 1:105}, key=1 returns true 
- dictionary<int, int>, capacity 2, init values {0:103, 1:105}, key=2 returns false 
- dictionary<int, int>, capacity 2, init values {0:103, 1:105}, key=3 returns false 

set 4:
- dictionary<int, int>, capacity 3, init values {0:103, 1:105}, key=3 returns false 
- dictionary<int, int>, capacity 3, init values {0:103, 1:105, 2:206}, key=1 returns true 

set 5:
- dictionary<int, int>, capacity 3, init values {0:103, 1:105, 2:206, 4:407}, key=1 returns true 
- dictionary<int, int>, capacity 3, init values {0:103, 1:105, 2:206, 4:407}, key=4 returns true 
- dictionary<int, int>, capacity 3, init values {0:103, 1:105, 2:206, 4:407}, key=7 returns false 
- dictionary<int, int>, capacity 3, init values {0:103, 1:105, 2:206, 4:407}, key=8 returns false 

### 2. (20pt) Finish the remove(...) function in src/ArrayDictionary.h 
```c++
bool remove(KeyType &key) override {
    // homework
    return false;
}
```

As the name indicates, remove(key) deletes **ALL** entries with the provided key. This include all entries in the chain whose keys match the given key but mapped to the same hash key.

Remove(key) returns true when any entry was removed, false if none.

### 3. (10pt) Finish the remove(key) function in src/ArrayDictionary.h with unit tests 

Add unit tests to your remove(key) function. The following cases need to be tested:
- empty dictionary
- key exists in a dictionary that has no collision
- key does not exists in a dictionary that has no collision
- key exists in a dictionary that has collision, key is in the collision.
- key does not exists in a dictionary that has collision

You can have these in separate TEST() or if you choose to have one TEST(), please add comments indicating which case of these are being tested.

***Same rule as problem 1. If any of these cases is missing, 0pt is given for task 3.***
