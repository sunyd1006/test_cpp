//
// Created by sun yin dong on 2021/6/6.
//

#ifndef TEST_CPP_TEMPLATEDEMO_H
#define TEST_CPP_TEMPLATEDEMO_H

namespace templateDemo {

    /**
     * 模板类，模板函数一般放在  .h 文件中
     */

    template<typename T>
    T MaxTemplate(T a, T b) {
        return a > b ? a : b;
    }

    template<typename T>
    T MaxTemplate(T a, T b, T c) {
        int n = (a > b ? a : b);
        return n > c ? n : c;
    }

    // 模板类
    template<typename T>
    class ArrayTemplate {
    public:
        ArrayTemplate(int s);

        virtual ~ArrayTemplate();

        virtual const T &Entry(int index) const;

        virtual void Enter(int index, const T &value);

    private:
        int size;
        T *element;
    };

    template<typename T>
    ArrayTemplate<T>::ArrayTemplate(int s) {
        if (s > 1) size = s;
        else size = 1;
        element = new T[size];
    }

    template<typename T>
    ArrayTemplate<T>::~ArrayTemplate() { delete[]element; }

    template<typename T>
    const T &ArrayTemplate<T>::Entry(
            int index) const { return element[index]; }

    template<typename T>
    void ArrayTemplate<T>::Enter(
            int index, const T &value) { element[index] = value; }

}
#endif //TEST_CPP_TEMPLATEDEMO_H
