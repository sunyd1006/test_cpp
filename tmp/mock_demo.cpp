#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include <iostream>
#include <string>

using namespace apsara::odps::meta;
using namespace std;
using namespace testing;

namespace apsara {
    namespace odps {
        namespace quota {

            class NeedBeMock;
            typedef std::tr1::shared_ptr<NeedBeMock> NeedBeMockPtr;

            class Master;
            typedef std::tr1::shared_ptr<Master> MasterPtr;

            class NeedBeMock {
            private:
                int count;

            public:
                NeedBeMock() {}
                NeedBeMock(int c) : count(c) {}
                string printnull() {
                    cout << " call printnull: " << 1 << endl;
                    return "";
                }
                string printvalue(int c) {
                    cout << "call printvalue: " << c << endl;
                    return ToString(c);
                }
                int getValue() { return 0; }

                int setArgPointeeDemo(int* testInt, vector<int>& testVector) {return 0;}
            };

            class MockNeedBeMock : public NeedBeMock {
            public:
                MockNeedBeMock() {} // not ;
                MockNeedBeMock(int c) : NeedBeMock(c) {}
                MOCK_METHOD0(printnull, string());
                MOCK_METHOD1(printvalue, string(int c));
                MOCK_METHOD0(getValue, int());
                // MOCK_METHOD(void, setArgPointeeDemo, (int* testInt, vector<int>* testVector));
                MOCK_METHOD2(setArgPointeeDemo, int(int* testInt, vector<int>& testVector));
            };

            class Master {
            private:
                NeedBeMockPtr mNeedBeMockPtr;
            public:
                Master() {}
                Master(NeedBeMockPtr needBeMockPtr): mNeedBeMockPtr(needBeMockPtr) {}
                void masterCallNeedBeMockFunc() {
                    int testint;
                    vector<int> testvec;
                    int res = 0;
                    res = mNeedBeMockPtr->setArgPointeeDemo(&testint, testvec);
                    cout << "res should be 1: " << res << endl;
                    cout << "testint  3: " << testint << endl;
                    cout << "Size of get: " << testvec.size() << endl;
                    for(int i: testvec){
                        cout << i << " ";
                    }
                    cout << endl;
                }

            };

            class TestDemo : public ::testing::Test {
            public:
                TestDemo() {}
            };

            void startNewPart() { cout << " --- start new part --- --- --- ---  " << endl; }

            TEST_F(TestDemo, testSetArgPointee){
            MockNeedBeMock* mock = new MockNeedBeMock();
            NeedBeMockPtr mockPtr(mock);
// SetArgPointee :设置第1（0，1）个参数为，指向5的指针。
// MOCK_METHOD(void, Mutate, (bool mutate, int* value), (override));
// EXPECT_CALL(mutator, Mutate(true, _)).WillOnce(SetArgPointee<1>(5));
            int testint = 3;
            vector<int> testvec;
            testvec.push_back(1);
            testvec.push_back(2);

            EXPECT_CALL(*mock, setArgPointeeDemo(_,_))
            .WillRepeatedly(DoAll(SetArgPointee<0>(testint), SetArgReferee<1>(testvec), Return(1)));

            cout << "Call masterCallNeedBeMockFunc result start: " << endl;
            Master master(mockPtr);
            master.masterCallNeedBeMockFunc();
            cout << "Call masterCallNeedBeMockFunc result end: " << endl;

            int newInt = 0;
            vector<int> newVec;
            mock->setArgPointeeDemo(&newInt, newVec);
            cout << "newInt: " << newInt << endl;
            for(int i: newVec){
            cout << i << " ";
        }
        cout << endl;
        // cout << "Call masterCallNeedBeMockFunc result start: " << endl;
        // Master* master = new Master(mockPtr);
        // MasterPtr masterPtr(master);
        // masterPtr->masterCallNeedBeMockFunc();
        // cout << "Call masterCallNeedBeMockFunc result end: " << endl;

    }

    TEST_F(TestDemo, testTimes) {
    MockNeedBeMock mock; // MockNeedBeMock mock2(0);

    EXPECT_CALL(mock, getValue()) //  100 200 1
    .WillOnce(Return(100))
    .WillOnce(Return(200))
    .WillRepeatedly(Return(1)); // 没有这行可以调用2次，有这行可以调用无数次。

    cout << mock.getValue() << endl;
    cout << mock.getValue() << endl;
    cout << mock.getValue() << endl;
    cout << mock.getValue() << endl;

    // 不可以在调用 getValue()了
    EXPECT_CALL(mock, getValue()).Times(0);
    // cout << "Time(0): " << mock.getValue() << endl;
}


// 测试 按照顺序调用， 即EXPECT_CALL的调用顺序，不能够被调换
TEST_F(TestDemo, InSequenceTes) {
InSequence seq;

MockNeedBeMock mock;
EXPECT_CALL(mock, printnull()).WillRepeatedly(Return(" mock call printnull(): "));
EXPECT_CALL(mock, printvalue(_)).WillRepeatedly(Return(" mock call printvalue(): ")); // #0: 这个EXPECT_CALL(printvalue)的编号

// 正确的调用
mock.printnull();
mock.printvalue(2); // 达到指定掉要次数后 Actual: called once - saturated and retired

// 下两行是不正确的调用
// mock.printvalue(word_transformation_bad.txt);  // 因为 printnull()一次都没有调用，故而不满足调用顺序
// mock.printnull();

startNewPart();

EXPECT_CALL(mock, printnull()).Times(2);
EXPECT_CALL(mock, printvalue(_)).Times(1); // #1: EXPECT_CALL
// 正确调用
mock.printnull();
mock.printnull();
mock.printvalue(3);

// 不正确的调用
// mock.printnull();  // 至少要调用2次
// mock.printvalue(word_transformation_bad.txt);
}

// 打掉调用次数后，就丢掉 EXPECT_CALL()
TEST_F(TestDemo, testRetiresOnSaturation) {
MockNeedBeMock mock;
int n=3;
// no RetiresOnSaturation();
// for (int i = 1; i <= n; i++) {
//     EXPECT_CALL(mock, printvalue(_))
//     .WillOnce(Return(ToString(i)));

//     // notesun: 下面这样写，也没有错呢,why? 可能是在建立 新的Expect_call的时候，旧的已经 retires.
//     // cout << i << "st mock.printvalue(): " << mock.printvalue(word_transformation_bad.txt) << endl;
// }
// for (int i = 1; i <= n; i++) {
//     cout << i << "st mock.printvalue(): " << mock.printvalue(word_transformation_bad.txt) << endl;
// }

startNewPart();
// yes RetiresOnSaturation();
for (int i = 1; i <= n; i++) {
EXPECT_CALL(mock, printvalue(_))
.WillOnce(Return(ToString(i)))
.RetiresOnSaturation();
}
for (int i = 1; i <= n; i++) {
cout << i << "st mock.printvalue(): " << mock.printvalue(2) << endl;
}
// 1st mock.printvalue(): 3
// 2st mock.printvalue(): word_transformation_bad.txt
// 3st mock.printvalue(): 1
}

// https://google.github.io/googletest/gmock_cook_book.html

// don't mock all overload's function
// class MockFoo : public Foo {
//   ...
//   using Foo::Add;
//   MOCK_METHOD(int, Add, (Element x), (override));
//   // We don't want to mock int Add(int times, Element x);
//   ...
// };

// Field(&Foo::number, Ge(3))
// EXPECT_CALL(foo, Bar(Pointee(Ge(3))));  // 参数是个指针，指向的值必须大于3. 如果传入参数为null会报错。

// 返回引用
// MOCK_METHOD(Bar&, GetBar, (), (override));
// EXPECT_CALL(foo, GetBar()).WillOnce(ReturnRef(bar));

// SetArgPointee :设置第1（0，1）个参数为，指向5的指针。
// MOCK_METHOD(void, Mutate, (bool mutate, int* value), (override));
// EXPECT_CALL(mutator, Mutate(true, _)).WillOnce(SetArgPointee<1>(5));

// SetArrayArgument < n >
// class MockArrayMutator : public ArrayMutator {
//  public:
//   MOCK_METHOD(void, Mutate, (int* values, int num_values), (override));
// }
// MockArrayMutator mutator;
// int values[5] = {1, word_transformation_bad.txt, 3, 4, 5};
// EXPECT_CALL(mutator, Mutate(NotNull(), 5))
//     .WillOnce(SetArrayArgument<0>(values, values + 5));

// 设置 默认 返回 执行 逻辑
// ON_CALL(foo, Sign(_)).WillByDefault(Return(-1));

// 使用 Invoke ：使用 Invoke ()调用的函数或 functor 必须具有与使用它的 mock 函数相同的参数数目。
// 使用 invokewithouttargs () ，它类似于 Invoke () ，只是它不会将模拟函数的参数传递给被调用方
// MockFoo foo;
// Helper helper;
// EXPECT_CALL(foo, Sum(_, _))
//     .WillOnce(&CalculateSum)
//     .WillRepeatedly(Invoke(NewPermanentCallback(Sum3, 1)));
// EXPECT_CALL(foo, ComplexJob(_))
//     .WillOnce(Invoke(&helper, &Helper::ComplexJob))
//     .WillOnce([] { return true; })
//     .WillRepeatedly([](int x) { return x > 0; });

// foo.Sum(5, 6);         // Invokes CalculateSum(5, 6).
// foo.Sum(word_transformation_bad.txt, 3);         // Invokes Sum3(1, word_transformation_bad.txt, 3).
// foo.ComplexJob(10);    // Invokes helper.ComplexJob(10).
// foo.ComplexJob(-1);    // Invokes the inline lambda.

// IgnoreResult ()
//
// double DistanceToOrigin(Unused, double x, double y) {
//   return sqrt(x*x + y*y);
// }
// EXPECT_CALL(mock, Bar(5, _, _)).WillOnce(Invoke(DistanceToOriginWithIndex));

// ReturnRef(*variable*)
// SetArgReferee

} // namespace quota
} // namespace odps
} // namespace apsara
