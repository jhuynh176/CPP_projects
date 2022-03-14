#include "NewTests.h"
#include<string>
#include "StringList.h"

using namespace std;

bool testConcatenate3()
{
	StringList list(vector<string>{"Apple", "Mango", "Banana"});
	return list.concatenate("|Fruits|") == "Apple|Fruits|Mango|Fruits|Banana";
}

bool testConcatenate4()
{
	StringList list(vector<string>{ "Just one Node so seprator won't be printed." });
	return list.concatenate("|SEPARATOR|") == "Just one Node so seprator won't be printed.";
}

bool testToString3() {
	StringList list(vector<string>{"*", "*", "*"});
	return list.toString() == "*\n*\n*";
}

bool testToString4() {
	StringList list(vector<string>{"OneValue"});
	return list.toString() == "OneValue";
}
bool testCopyConstructor3() {
    StringList list1(vector<string>{"some", "random", "values"});
    StringList list2;
    list2= list1;
    return list1 == list2;
}

bool testCopyConstructor4() {
    StringList list1(vector<string>{"some", "random", "values"});
    StringList list2 = list1;
    list1.pushFront("asdf");
    return list1 == StringList(vector<string>{"asdf","some", "random", "values" }) &&
        StringList(vector<string>{"some", "random", "values"}) == list2;
}

bool testPushFront3() {
    StringList list(vector<string>{"some", "random", "values"});

    list.pushFront("New");
    return list == StringList(vector<string>{"New", "some", "random", "values"});
}

bool testPushFront4() {
    StringList list;

    list.pushFront("");
    return list == StringList(vector<string>{""});
}

bool testPopFront3() {
    StringList list(vector<string>{"some", "random"});

    list.popFront();
    return list == StringList(vector<string>{"random"});
}

bool testPopFront4() {
    StringList list(vector<string>{"some"});
    list.pushBack("Values");
    list.popFront();
    return list == StringList(vector<string>{"Values"});
}

bool testFront3() {
    StringList list(vector<string>{"random", "values"});
    return list.front() == "random";
}

bool testFront4() {
    StringList list(vector<string>{" "});

    return list.front() == " ";
}

bool testOperatorPlus3() {
    StringList list1(vector<string>{"\t", "\n", "\t"});
    StringList list2(vector<string>{"Something", "else"});
    StringList list = list1 + list2;
    return list == StringList(vector<string>{"\t", "\n", "\t", "Something", "else"});
}

bool testOperatorPlus4() {
    StringList list1(vector<string>{"Something", "else"});
    StringList list2;
    StringList list = list1 + list2;
    return list == StringList(vector<string>{"Something", "else"});
}

bool testReverse3() {
    StringList list(vector<string>{" "});
    list.reverse();
    return list == StringList(vector<string>{" "});
}

bool testReverse4() {
    StringList list(vector<string>{"1","2","3"});
    list.reverse();
    return list == StringList(vector<string>{"3","2","1"});
}

bool testInsert3() {
    StringList list(vector<string>{"v0", "v1", "v2", "v3", "v4"});
    bool success = list.insert("new value", 1);
    return success && list == StringList(vector<string>{ "v0", "new value", "v1", "v2", "v3", "v4"});
}

bool testInsert4() {
    StringList list(vector<string>{"v0", "v1","v2"});
    bool success = list.insert("new value", 3);
    return success && list == StringList(vector<string>{"v0", "v1","v2", "new value"});
}

bool testRemove3() {
    StringList list(vector<string>{"v0", "v1", "v2", "v3", "v4"});
    bool success = list.remove(4);
    return success && list == StringList(vector<string>{"v0", "v1", "v2", "v3"});
}

bool testRemove4() {
    StringList list(vector<string>{"v0", "v1","v2"});
    bool success = list.remove(1);
    return success && list == StringList(vector<string>{"v0","v2"});
}


