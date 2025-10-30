
/*
* Created by: Luke Manuel
* Description: A custom array made to mimic std::array
* 2025, October
*/
#include "lsl.hpp"
#pragma once

namespace lsl{

    template <typename Container>
    void quickSort(Container& con) {
        using type = typename Container::value_type;

        if(con.size() <= 1) return;
        
        //Separate the halves of the container around a pivot
        type pivot = con[con.size() - 1];

        lsl::vector<type> vecLow;
        lsl::vector<type> vecHigh;

        vecLow.reserve(con.size() / 2);
        vecHigh.reserve(con.size() / 2);

        for (size_t i = 0; i < con.size() - 1; i++) {
            if (con[i] < pivot){
                vecLow.push_back(con[i]);
            } else {
                vecHigh.push_back(con[i]);
            }
        }//end of for

        //Recursive call on the two halves
        quickSort(vecLow);
        quickSort(vecHigh);


        //then read both halves to the container
        for (size_t i = 0; i < vecLow.size(); i++) {
            con[i] = vecLow[i];
        }

        con[vecLow.size()] = pivot;

        for (size_t i = 0; i < vecHigh.size(); i++) {
            con[vecLow.size() + 1 + i] = vecHigh[i];
        }

    }//end of function

}//end namespace

