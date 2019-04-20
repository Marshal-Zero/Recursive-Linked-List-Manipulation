//	LinkedBag340.cpp
//	Created by: Moataz A

#include<iostream>
#include<cstddef>
#include<ctime>
#include<cstdlib>
#include"LinkedBag.h"


//removeSecondNode340 TEST #2
template<class ItemType>
bool LinkedBag<ItemType>::removeSecondNode340() {
    auto mark = headPtr;
    auto delThis = mark->getNext();

    mark->setNext(mark->getNext()->getNext());
    delThis->setNext(nullptr);
    delete delThis;

    return true;

}

//addEnd340 TEST #3
template<class ItemType>
bool LinkedBag<ItemType>::addEnd340(const ItemType &addNew) {
    Node<ItemType> *mark;

    mark = headPtr;

    do {
        mark = mark->getNext();
    } while (mark->getNext() != nullptr);
    auto ptrNode = new Node<ItemType>();
    mark->setNext(ptrNode);
    ptrNode->setItem(addNew);
    itemCount++;
    return true;
}

//getCurrentSize340Iterative TEST #4
template<class ItemType>
int LinkedBag<ItemType>::getCurrentSize340Iterative() const {
    auto mark = headPtr;
    int sum{};
    do {
        mark = mark->getNext();
        sum++;

    } while (mark != nullptr);
    return sum;
}


// getCurrentSize340Recursive TEST #5
template<class ItemType>
int LinkedBag<ItemType>::getCurrentSize340Recursive() const {
    static auto mark = headPtr;

    if (mark != nullptr) {
        mark = mark->getNext();
        return getCurrentSize340RecursiveHelper(mark);
    } else {
        mark = headPtr;
        return 0;
    }

}

//getCurrentSize340RecursiveHelper TEST #6
template<class ItemType>
int LinkedBag<ItemType>::getCurrentSize340RecursiveHelper(Node<ItemType> *) const {
    auto mark = headPtr;
    int move{};
    if (mark != nullptr) {
        move++;
        return getCurrentSize340Recursive() + move;
    } else {
        return 0;
    }
}


//getCurrentSize340RecursiveNoHelper TEST #7 part 1
template<class ItemType>
int LinkedBag<ItemType>::getCurrentSize340RecursiveNoHelper() const {
    static auto mark = headPtr;
    int move{};
    if (mark != nullptr) {
        mark = mark->getNext();
        move++;
        return getCurrentSize340RecursiveNoHelper() + move;
    } else {
        return 0;
    }

}


//getFrequencyOf340Recursive  TEST #7
template<class ItemType>
int LinkedBag<ItemType>::getFrequencyOf340Recursive(const ItemType &number) const {
    static auto mark = headPtr;
    return mark == nullptr ? 0 : getFrequencyOf340RecursiveHelper(mark, number);

}

//getFrequencyOf340RecursiveHelper TEST #7 HELPER
template<class ItemType>
int LinkedBag<ItemType>::getFrequencyOf340RecursiveHelper(Node<ItemType> *, const ItemType &number) const {
    static auto mark = headPtr;
    int move{};

    if (mark != nullptr) {
        if (!(mark->getItem() == number)) {
            mark = mark->getNext();
            return getFrequencyOf340Recursive(number) + move;
        } else {
            mark = mark->getNext();
            move++;
            return getFrequencyOf340Recursive(number) + move;
        }
    } else {
        mark = headPtr;
        return 0;
    }

}

//getFrequencyOf340RecursiveNoHelper TEST #8
template<class ItemType>
int LinkedBag<ItemType>::getFrequencyOf340RecursiveNoHelper(const ItemType &number) const {
    static auto mark = headPtr;
    int move{};

    if (mark != nullptr) {
        if (!(mark->getItem() == number)) {
            mark = mark->getNext();
            return getFrequencyOf340RecursiveNoHelper(number) + move;
        } else {
            mark = mark->getNext();
            move++;
            return getFrequencyOf340RecursiveNoHelper(number) + move;
        }
    } else {
        mark = headPtr;
        return 0;
    }


}

//removeRandom340 TEST# 9
template<class ItemType>
ItemType LinkedBag<ItemType>::removeRandom340() {

    if (headPtr == nullptr)
        return 0;


    srand(time(nullptr));

    auto randomNode = headPtr->getItem();
    auto mark = headPtr;
    for (int n = 2; mark != nullptr; n++) {
        if (rand() % n == 0)
            randomNode = mark->getItem();
            mark = mark->getNext();
    }
    remove(randomNode);
    return randomNode;

}