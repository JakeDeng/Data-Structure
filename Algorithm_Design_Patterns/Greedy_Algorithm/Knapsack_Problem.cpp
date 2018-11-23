#include <iostream>
#include <vector>

//parameters
int c = 150;//max weight
int wi[7] = {35, 30, 60, 50, 40, 10, 25};
int pi[7] = {10, 40, 30, 50, 35, 40 ,30};

//define model
//define struct to represemt objects
typedef struct{
    int weight;
    int price;
    int status;//0:not chosen; 1:chosen; 2: not fit
}OBJECT;

//define struct to represent backpack problem
typedef struct{
    std::vector<OBJECT> objs;//items that can be chosen
    int totalC;//total weight
}PROBLEM;


//define sub-questions
//How to choose: Greedy Algorithm
//1: according to price, choose the highest price item every time
//2: according to weight, choose the lightest item 
//3: accoding to price/weight density

void GreedyAlgo(PROBLEM *problem,  int (*spFunc)(std::vector<OBJECT>& objs, int c))
{
    int idx;
    int ntc = 0;

    //spFunc select item and check 
    while((idx = spFunc(problem->objs, problem->totalC - ntc)) != -1)
    {
        //meet weight requirement?
        if((ntc + problem->objs[idx].weight) <= problem->totalC)
        {
            problem->objs[idx].status = 1;
            ntc += problem->objs[idx].weight;
        }
        else
        {
            //cant choose this item，mark and rechoose
            problem->objs[idx].status = 2; 
        }
    }

    PrintResult(problem->objs);
}

//Function pointer


int  ChooseFunc1(std::vector<OBJECT>& objs, int c)
{
    int index = -1;  //-1 means backpack is full
    int mp = 0;
    for(int i = 0; i < static_cast<int>(objs.size()); i++)
    {
        if((objs[i].status == 0) && (objs[i].price > mp))
        {
            mp = objs[i].price;
            index = i;
        }
    }

    return index;
}

void PrintResult(std::vector<OBJECT> objs)
{

}

