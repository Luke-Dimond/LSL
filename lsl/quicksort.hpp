
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
        
        //Seperate the halves of the container around a pivot
        size_t pivot = con.size() - 1;

        lsl::vector<type> vecLow;
        lsl::vector<type> vecHigh;

        for (size_t i = 0; i < con.size() - 1; i++) {
            if (con[i] < con[pivot]){
                vecLow.push_back(con[i]);
            } else {
                vecHigh.push_back(con[i]);
            }
        }//end of for

        //Recursive call on the two halves
        quickSort(vecLow);
        quickSort(vecHigh);


        //then readd both halves to the container
        for (size_t i = 0; i < vecLow.size(); i++) {
            con[i] = vecLow[i];
        }

        con[vecLow.size()] = con[pivot];

        for (size_t i = 0; i < vecHigh.size(); i++) {
            con[vecLow.size() + 1 + i] = vecHigh[i];
        }

    }//end of function

}//end namespace

