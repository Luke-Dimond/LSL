
/*
* Created by: Luke Manuel
* Description: A custom array made to mimic std::array
* 2025, October
*/
#include "lsl.hpp"
#pragma once

namespace lsl{

    template <typename Container, typename Compare>
    void quickSort(Container& con, Compare comp) {
        using T = typename Container::value_type;

        if(con.size() <= 1) return;
        
        //Separate the halves of the container around a pivot
        T pivot = con[con.size() - 1];

        lsl::vector<T> vecLow;
        lsl::vector<T> vecHigh;

        vecLow.reserve(con.size() / 2);
        vecHigh.reserve(con.size() / 2);

        for (size_t i = 0; i < con.size() - 1; i++) {
            if (comp(con[i], pivot)){
                vecLow.push_back(con[i]);
            } else {
                vecHigh.push_back(con[i]);
            }
        }//end of for

        //Recursive call on the two halves
        quickSort(vecLow, comp);
        quickSort(vecHigh, comp);


        //then read both halves to the container
        for (size_t i = 0; i < vecLow.size(); i++) {
            con[i] = vecLow[i];
        }

        con[vecLow.size()] = pivot;

        for (size_t i = 0; i < vecHigh.size(); i++) {
            con[vecLow.size() + 1 + i] = vecHigh[i];
        }

    }//end of function

    //Overload that defaults the sort to a < b;
    template <typename Container>
    void quickSort(Container& con){
        using T = typename Container::value_type;
        lsl::quickSort(con, [] (const T& a, const T& b) {return a < b;});
    }

}//end namespace

