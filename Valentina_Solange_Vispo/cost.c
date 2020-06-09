#include <limits.h>
#include <stdio.h>

#include "cost.h"

/**
Returns an infinite cost
*/
cost_t cost_inf(){
    return INT_MAX;
}

/** Checks if a cost is infinite 
@param cost
@return true if cost is infinite, false otherwise 
*/
bool cost_is_inf(cost_t cost){
    return cost == cost_inf();
}

/** Cost Equal relation (c1==c2)
@param c1 first cost
@param c2 second cost
*/
bool cost_eq(cost_t c1, cost_t c2){
    return c1==c2;
}

/** Cost Less or Equal relation (c1<=c2)
@param c1 first cost
@param c2 second cost
*/
bool cost_le(cost_t c1, cost_t c2){
    return c1 <= c2;
}

/** Cost Less Than relation (c1<c2)
@param c1 first cost
@param c2 second cost
*/
bool cost_lt(cost_t c1, cost_t c2){
    return c1 < c2;
}

/** Cost Sum (addition) operation (c1+c2)
@param c1 first cost
@param c2 second cost
*/
cost_t cost_sum(cost_t c1, cost_t c2){
    if (cost_is_inf(c1) || cost_is_inf(c2)){
        return cost_inf();
    }
    else{
        return c1+c2;
    }
}

/** Cost Res (subtraction) operation (c1-c2)
@param c1 first cost
@param c2 second cost
*/
cost_t cost_res(cost_t c1, cost_t c2){
    //int res;
    if (cost_is_inf(c1) || cost_is_inf(c2)){
        return -1;
        //cost_inf(); // ¿Como retorno un inf negativo?
        //res = -costo_inf();
    }
    else{
        return c1-c2;
    }
}

/**
Prints a cost in stdout 
*/
void cost_print(cost_t cost){
    if (cost_is_inf(cost)){
        printf("#");}
    else{
        printf("%d", cost);
    }
}
