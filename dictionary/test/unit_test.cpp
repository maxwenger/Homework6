#include "ArrayDictionary.h"
#include "gtest/gtest.h"

#define PRINT

TEST(dict, array_dict_basic) {
    ArrayDictionary<int, int> hashTable;

    ASSERT_TRUE(hashTable.isEmpty());

    ASSERT_TRUE(hashTable.add(1, 2));
    ASSERT_EQ(hashTable.size(), 1);
    ASSERT_FALSE(hashTable.isEmpty());

    ASSERT_TRUE(hashTable.add(8, 4));
    ASSERT_EQ(hashTable.size(), 2);

    ASSERT_TRUE(hashTable.add(11, 4));
    ASSERT_EQ(hashTable.size(), 2);
#ifdef PRINT
    hashTable.print();
#endif
}

TEST(dict, array_dict_add_overwrite) {
    ArrayDictionary<int, int> hashTable;

    ASSERT_TRUE(hashTable.add(2, 2));
    ASSERT_TRUE(hashTable.add(2, 4));
#ifdef PRINT
    hashTable.print();
#endif

    ASSERT_EQ(hashTable.size(), 1);
}

TEST(dict, array_dict_value_set_size) {
    ArrayDictionary<int, int> hashTable;

    ASSERT_TRUE(hashTable.add(2, 9));
    ASSERT_TRUE(hashTable.add(3, 4));
    ASSERT_TRUE(hashTable.add(12, 8));
#ifdef PRINT
    hashTable.print();
#endif

    ASSERT_EQ(hashTable.valueSetSize(5), 0);
    ASSERT_EQ(hashTable.valueSetSize(2), 2);
    ASSERT_EQ(hashTable.valueSetSize(3), 1);
}

TEST(dict, array_dict_add_get) {
    ArrayDictionary<int, int> hashTable;

    ASSERT_TRUE(hashTable.add(2, 9));
    ASSERT_TRUE(hashTable.add(3, 4));
    ASSERT_TRUE(hashTable.add(12, 8));
#ifdef PRINT
    hashTable.print();
#endif

    int val = 0;
    ASSERT_TRUE(hashTable.get(2, val));
    ASSERT_EQ(val, 9);
    ASSERT_TRUE(hashTable.get(12, val));
    ASSERT_EQ(val, 8);
    ASSERT_TRUE(hashTable.get(3, val));
    ASSERT_EQ(val, 4);
    ASSERT_FALSE(hashTable.get(7, val));
    ASSERT_EQ(val, 4);
}

TEST(dictContains, emptyDictReturnsFalse) {
    ArrayDictionary<int, int> hashTable;

	ASSERT_FALSE(hashTable.contain(-1));
	ASSERT_FALSE(hashTable.contain(0));
	ASSERT_FALSE(hashTable.contain(1));
}

TEST(dictContains, singleItemDictDoesNotHaveItem) {
    ArrayDictionary<int, int> hashTable(1);
	hashTable.add(0, 103);

	ASSERT_FALSE(hashTable.contain(2));
}

TEST(dictContains, singleItemDictHasItem) {
    ArrayDictionary<int, int> hashTable(1);
	hashTable.add(0, 103);

	ASSERT_TRUE(hashTable.contain(0));
}

TEST(dictContains, doubleItemDictDoesNotHaveItem) {
	ArrayDictionary<int, int> hashTable(2);
	hashTable.add(0, 103);
	hashTable.add(1, 105);

	ASSERT_TRUE(hashTable.contain(0));
	ASSERT_TRUE(hashTable.contain(1));
}

TEST(dictContains, doubleItemDictHasItem) {
	ArrayDictionary<int, int> hashTable(2);
	hashTable.add(0, 103);
	hashTable.add(1, 105);

	ASSERT_FALSE(hashTable.contain(2));
	ASSERT_FALSE(hashTable.contain(3));
}

TEST(dictContains, doubleItemTrippleCapacityDoesNotHaveItem) {
	ArrayDictionary<int, int> hashTable(3);
	hashTable.add(0, 103);
	hashTable.add(1, 105);

	ASSERT_FALSE(hashTable.contain(3));
}

TEST(dictContains, trippleItemTrippleCapacityHasItem) {
	ArrayDictionary<int, int> hashTable(3);
	hashTable.add(0, 103);
	hashTable.add(1, 105);
	hashTable.add(2, 206);

	ASSERT_TRUE(hashTable.contain(1));
}

TEST(dictContains, quadItemTrippleCapacityHasItem) {
	ArrayDictionary<int, int> hashTable(3);
	hashTable.add(0, 103);
	hashTable.add(1, 105);
	hashTable.add(2, 206);
	hashTable.add(4, 407);

	ASSERT_TRUE(hashTable.contain(1));
	ASSERT_TRUE(hashTable.contain(4));
}

TEST(dictContains, quadItemTrippleCapacityDoesNotHaveItem) {
	ArrayDictionary<int, int> hashTable(3);
	hashTable.add(0, 103);
	hashTable.add(1, 105);
	hashTable.add(2, 206);
	hashTable.add(4, 407);

	ASSERT_FALSE(hashTable.contain(7));
	ASSERT_FALSE(hashTable.contain(8));
}

TEST(dictRemove, fromEmpty) {
	ArrayDictionary<int, int> hashTable;
	
	ASSERT_FALSE(hashTable.remove(1));
}

TEST(dictRemove, existsWithoutCollision) {
	ArrayDictionary<int, int> hashTable;
	hashTable.add(0, 103);
	hashTable.add(1, 105);
	hashTable.add(2, 206);

	ASSERT_TRUE(hashTable.remove(1));
	ASSERT_FALSE(hashTable.contain(1));
}

TEST(dictRemove, doesNotExistsWithoutCollision) {
	ArrayDictionary<int, int> hashTable;
	hashTable.add(0, 103);
	hashTable.add(1, 105);
	hashTable.add(2, 206);

	ASSERT_TRUE(hashTable.remove(7));
}

TEST(dictRemove, doesNotExistsWithCollision) {
	ArrayDictionary<int, int> hashTable;
	hashTable.add(0, 103);
	hashTable.add(1, 105);
	hashTable.add(1, 105);
	hashTable.add(2, 206);

	ASSERT_TRUE(hashTable.remove(7));
	ASSERT_FALSE(hashTable.contain(7));
}


TEST(dictRemove, existsWithCollision) {
	ArrayDictionary<int, int> hashTable;
	hashTable.add(0, 103);
	hashTable.add(1, 105);
	hashTable.add(1, 105);
	hashTable.add(2, 206);

	ASSERT_TRUE(hashTable.remove(1));
	ASSERT_FALSE(hashTable.contain(1));
}


