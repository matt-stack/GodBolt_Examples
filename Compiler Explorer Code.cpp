// Type your code here, or load an example.
#include <string>
#include <stdio.h>
#include <memory>
#include <iostream>

// TypePack Definition
template <typename... Ts>
struct TypePack {
    static constexpr size_t count = sizeof...(Ts);
};

// TypePack Operations
template <typename T, typename... Ts>
struct IndexOf {
    static constexpr int count = 0;
    static_assert(!std::is_same_v<T, T>, "Type not present in TypePack");
};

template <typename T, typename... Ts>
struct IndexOf<T, TypePack<T, Ts...>> {
    static constexpr int count = 0;
};

template <typename T, typename U, typename... Ts>
struct IndexOf<T, TypePack<U, Ts...>> {
    static constexpr int count = 1 + IndexOf<T, TypePack<Ts...>>::count;
};

template <typename T, typename... Ts>
    static constexpr unsigned int TypeIndex() {
    using Types = TypePack<Ts...>;

    using Tp = typename std::remove_cv_t<T>;
    if constexpr (std::is_same_v<Tp, std::nullptr_t>)
        return 0;
    else
       return 1 + IndexOf<Tp, Types>::count;
}


template <typename T>
void fun(){

    std::cout << "Im in reg!\n";
}

template <>
void fun<double>(){

    std::cout << "Im in double!\n";
}

int main(){

fun<int>();
fun<double>();

std::cout << TypeIndex<int, double, int, float,  float>();

}