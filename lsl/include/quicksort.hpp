/*
  Description: A custom quicksort function with lambda and C-style array support
*/
#pragma once
#include "lsl.hpp"

namespace lsl{

   /*
       Created By:    
           - Luke Manuel
     
       function: 
           - quicksort()
     
       Date: 
           - 2025-10–2025-11
     
       Description: 
           - A custom quicksort function with lambda and C-style array support that can be overloaded
     
       Accepts: 
           - typename Container
           - Lambda function
     
       Returns: 
           - void
    */
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

   /*
       Overload:
           - Defaults the sort to (a < b)
     
       Accepts:
           - Container
     
       Returns:
           - void
    */
    template <typename Container>
    void quickSort(Container& con) {
        using T = typename Container::value_type;
        lsl::quickSort(con, [] (const T& a, const T& b) {return a < b;});
    }

   /*
       Overload:
           - Adds support for C-style arrays
     
       Accepts:
           - Pointer to typename T
           - size_t
     
       Returns:
           - void
    */
    template <typename T>
    void quickSort(T* data, size_t size) {

        if (size <= 1) return;

        //Copy C-style array to lsl::vector and sort it
        lsl::vector<T> tempVec;
        tempVec.reserve(size);
        for (size_t i = 0; i < size; i++) {
            tempVec.push_back(data[i]);
        }
        
        lsl::quickSort(tempVec);
        
        //place the sorted vector back into the C-style array
        for (size_t i = 0; i < size; i++) {
            data[i] = tempVec[i];
        }
    }

   /*
       Overload:
           - Adds support for C-style arrays with custom sorting option
     
       Accepts:
           - Pointer to typename T
           - size_t
           - Lambda function
     
       Returns:
           - void
    */
    template <typename T, typename Comparison>
    void quickSort(T* data, size_t size, Comparison comp) {

        if (size <= 1) return;

        //Copy C-style array to lsl::vector and sort it
        lsl::vector<T> tempVec;
        tempVec.reserve(size);
        for (size_t i = 0; i < size; i++) {
            tempVec.push_back(data[i]);
        }
        
        lsl::quickSort(tempVec, comp);
        
        //place the sorted vector back into the C-style array
        for (size_t i = 0; i < size; i++) {
            data[i] = tempVec[i];
        }
    }
}//end namespace

